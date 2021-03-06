﻿///
/// Enumerable Mixin 使用例
///
///

#include <iostream>
#include <fstream>

#include "EnumerableMixin.h"


class Reader : public EnumerableMixin<const char *>
{
    static const size_t BufSiz = 1024;
    char m_buf[BufSiz];
    std::istream &m_in;
    const char m_demiliter;

  public:

    Reader(std::istream &in, const char demiliter = '\n')
            :m_in(in), m_demiliter(demiliter) {}

    virtual ~Reader() {}
        
    
  protected:
    /// 要素を逐次返すメソッドの実装
    virtual void Each(yield_type &yield) override
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
    Reader reader(fin);
    for (auto str : reader) {
        std::cout << str << std::endl;
    }

    std::cout << std::endl;
    
    return 0;
}

