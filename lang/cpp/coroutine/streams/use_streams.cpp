///
/// Enumerable Mixin 使用例 (C++14 Streams)
///
///

#include <iostream>
#include <fstream>
#include <regex>

#pragma warning( disable : 4101 )
#include <Stream.h>
#include <StreamTerminators.h>
#pragma warning( default : 4101 )

#include "EnumerableMixin.h"

using namespace stream;
using namespace stream::op;
using namespace std;

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

    regex re("\\d+");
    auto seq = MakeStream::from(reader.begin(), reader.end())
               | map_([&](const auto &line) {  // マッチした数字か空文字
                       cmatch match;
                       return ((regex_search(line, match, re)) ? match.str() : string());
                   })
               | filter([](auto str) { return !str.empty(); })    // 空文字を取り除く
               | map_([](auto str) { return stoi(str); })         // 数値に変換
               | for_each([](auto num){ cout << num << endl; });  // 出力

    cout << endl;

    return 0;
}

