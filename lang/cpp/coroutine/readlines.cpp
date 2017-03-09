﻿///
/// Boost コルーチン サンプル(ファイル読み取り)
///
///

#include <iostream>
#include <fstream>
#include <boost/coroutine2/coroutine.hpp>

class ReadLines
{
    static const size_t BufSiz = 1024;
    char m_buf[BufSiz];
    std::istream &m_in;
    const char m_demiliter;

  public:

    ReadLines(std::istream &in, const char demiliter = '\n')
            : m_in(in), m_demiliter(demiliter) {}
    
    void operator()(boost::coroutines2::coroutine<const char*>::push_type& yield)
    {        
        for (;;) {
            m_in.getline(m_buf, BufSiz, m_demiliter);
            if (m_in.bad() || m_in.eof()) {
                break;
            }
            yield(m_buf);
        }
    }
    
};


class Reader
{
    static const size_t BufSiz = 1024;
    char m_buf[BufSiz];
    std::istream &m_in;
    const char m_demiliter;

  public:

    Reader(std::istream &in, const char demiliter = '\n')
            : m_in(in), m_demiliter(demiliter) {}

    
    auto ReadLines()
    {
        return std::move(
            boost::coroutines2::coroutine<const char*>::pull_type(
                [&](auto & yield){each(yield);}));
    }
        

    
  private:
    void each(boost::coroutines2::coroutine<const char*>::push_type& yield)
    {        
        for (;;) {
            m_in.getline(m_buf, BufSiz, m_demiliter);
            if (m_in.bad() || m_in.eof()) {
                break;
            }
            yield(m_buf);
        }
    }
    
};






static void testFuncObj()
{
    std::ifstream fin("text.txt");
    ReadLines lines(fin);
    boost::coroutines2::coroutine<const char *>::pull_type source(lines);
    
    for (auto str : source) {
        std::cout << str << std::endl;
    }
}

static void testReturnCoroutine()
{
    std::ifstream fin("text.txt");
    Reader reader(fin);
    for (auto str : reader.ReadLines()) {
        std::cout << str << std::endl;
    }
}



int main()
{
    testFuncObj();
    
    std::cout << std::endl;
    std::cout << "================" << std::endl;
    std::cout << std::endl;

    testReturnCoroutine();
    
    return 0;
}

