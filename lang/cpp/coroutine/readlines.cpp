///
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



int main()
{
    std::ifstream fin("text.txt");
    ReadLines lines(fin);
    boost::coroutines2::coroutine<const char *>::pull_type source(lines);
    
    for (auto str : source) {
        std::cout << str << std::endl;
    }
    
    return 0;
}

