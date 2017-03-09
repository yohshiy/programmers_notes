///
/// Enumerable Mixin クラス
///
///

#ifndef __ENUMERABLE_MIXIN_H__
#define __ENUMERABLE_MIXIN_H__

#include <boost/coroutine2/coroutine.hpp>

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
        m_source = new coroutine_type([&](auto & yield){each(yield);});
        
        return boost::coroutines2::detail::begin(*m_source);
    }

    inline iterator end()
    {
        if (m_source) {
            return boost::coroutines2::detail::end(*m_source);
        }
        else {
            return iterator::iterator();
        }
    }
        
    
  protected:
    virtual void each(yield_type &yield) = 0;


  private:
    coroutine_type *m_source = nullptr;

};




#endif
