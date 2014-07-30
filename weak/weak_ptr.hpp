#ifndef WEAK_PTR_DEFINED_
#define WEAK_PTR_DEFINED_

#include <utility>

#include "weak/common.hpp"

namespace weak {

template <class T>
class weak_ptr_factory;

/// Alternative weak_ptr implementation - can be used like shared_ptr
/// except it can be invalidated at any time.
template <class T>
class weak_ptr {
  weak_ptr_type<T> ptr_;

public:
  weak_ptr();
  weak_ptr(weak_ptr<T>& ptr);
  weak_ptr(weak_ptr<T>&& ptr);

  T* get() const;

  bool expired() const;

  void swap(weak_ptr<T>& ptr);

  T& operator*() const;

  T* operator->() const;
  
  weak_ptr<T>& operator=(weak_ptr<T>& ptr);
  weak_ptr<T>& operator=(weak_ptr<T>&& ptr);
  weak_ptr<T>& operator=(const weak_ptr<T>& ptr);
  weak_ptr<T>& operator=(const weak_ptr<T>&& ptr);

  bool operator==(weak_ptr<T>& ptr) const;

  operator bool() const;

private:
  friend weak_ptr_factory<T>;
  weak_ptr(const shared_ptr_type<T>& ptr);

  shared_ptr_type<T> recover() const;
};

template <class T>
void swap(weak_ptr<T>& lhs, weak_ptr<T>& rhs);

#include "weak/weak_ptr.ipp"

}  // namespace weak

#include "weak/weak_ptr_factory.hpp"

#endif // WEAK_PTR_DEFINED_
