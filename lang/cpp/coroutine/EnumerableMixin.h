///
/// Enumerable Mixin クラス
///
///

#ifndef __ENUMERABLE_MIXIN_H__
#define __ENUMERABLE_MIXIN_H__

#include <boost/coroutine2/coroutine.hpp>

/// Enumerable Mixin.
/// 継承して Each メソッドを実装すると
/// イテレーターを返す begin(), end() が使えるようになる
template <typename ElementType>
class EnumerableMixin
{
    using coroutine_type = typename boost::coroutines2::coroutine<ElementType>::pull_type;

  public:
    using yield_type = typename boost::coroutines2::coroutine<ElementType>::push_type;
    using iterator = typename boost::coroutines2::detail::pull_coroutine<ElementType>::iterator;
    
    EnumerableMixin()
            :m_source(nullptr) {}

    virtual ~EnumerableMixin() {delete m_source; }
    
    inline iterator begin()
    {
        delete m_source;
        m_source = new coroutine_type([&](auto & yield){this->Each(yield);});
        
        return boost::coroutines2::detail::begin(*m_source);
    }

    inline iterator end()
    {
        if (m_source == nullptr) {
            return boost::coroutines2::detail::end(*m_source);
        }
        return iterator::iterator();
    }
    
  protected:
    /// 要素を逐次返すメソッド.
    /// @param yield 値を返すためのコルーチンオブジェクト
    /// 
    /// yield を関数オブジェクト yield(elem) のように使い、
    /// 要素を返す.
    /// 返す要素は ElementType で指定した型
    /// 
    virtual void Each(yield_type &yield) = 0;


  private:
    coroutine_type *m_source;

};



#endif
