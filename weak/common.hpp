#ifndef WEAK_COMMON_DEFINED_
#define WEAK_COMMON_DEFINED_

#if defined(WEAK_PTR_TOOLS_USE_BOOST)
#include <boost/shared_ptr.hpp>
#else
#include <memory>
#endif


// By default uses std::shared_ptr and std::weak_ptr implementation and
// places weak_ptr_factory under std namespace, though allows to change that
// to boost.

namespace weak {

#if defined(WEAK_PTR_TOOLS_USE_BOOST)
template<class T> using shared_ptr_type = boost::shared_ptr<T>;
template<class T> using weak_ptr_type   = boost::weak_ptr<T>;
#else
template<class T> using shared_ptr_type = std::shared_ptr<T>;
template<class T> using weak_ptr_type   = std::weak_ptr<T>;
#endif

}  // namespace weak

#endif // WEAK_COMMON_DEFINED_
