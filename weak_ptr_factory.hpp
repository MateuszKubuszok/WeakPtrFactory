#ifndef WEAK_PTR_FACTORY_DEFINED_
#define WEAK_PTR_FACTORY_DEFINED_


// By default use std::shared_ptr and std::weak_ptr implementation and
// place weak_ptr_factory under std namespace, though allows to change that.

#ifndef   shared_ptr_type
#include  <memory>
#define   shared_ptr_type ::std::shared_ptr
#endif // shared_ptr_type

#ifndef   weak_ptr_type
#include  <memory>
#define   weak_ptr_type ::std::shared_ptr
#endif // weak_ptr_type

#ifndef   WEAK_PTR_FACTORY_NAMESPACE_BEGIN
#define   WEAK_PTR_FACTORY_NAMESPACE_BEGIN namespace std {
#endif // WEAK_PTR_FACTORY_NAMESPACE_BEGIN

#ifndef   WEAK_PTR_FACTORY_NAMESPACE_END
#define   WEAK_PTR_FACTORY_NAMESPACE_END }  // nameospace std
#endif // WEAK_PTR_FACTORY_NAMESPACE_END



WEAK_PTR_FACTORY_NAMESPACE_BEGIN

namespace {
/// Make sure that the object is not destroyed by the shared_ptr.
template<class T>
void mock_deleter(T*) {}
}  // namespace


/// Creates weak_ptrs (mainly) for self managing object.
/// Idea taken from Chromium's base::WeakPtrFactory.
template<class T>
class weak_ptr_factory {
  shared_ptr_type<T> ptr_;

public:
  /// Initializes factory with this.
  explicit weak_ptr_factory(T* instance);

  /// Returns weak_ptr to the instance.
  weak_ptr_type<T> get_weak_ptr() const;

private:
  /// No copy constructor.
  weak_ptr_factory(const weak_ptr_factory&) = delete;

  /// No move constructor.
  weak_ptr_factory(const weak_ptr_factory&&) = delete;

  /// No assignment.
  weak_ptr_factory& operator=(const weak_ptr_factory&) = delete;
};


// Tmplementation

template<class T>
weak_ptr_factory<T>::weak_ptr_factory(T* instance) :
  ptr_(instance, mock_deleter<T>)
  {}

template<class T>
weak_ptr_type<T> weak_ptr_factory<T>::get_weak_ptr() const {
  return weak_ptr_type<T>(ptr_);
}

WEAK_PTR_FACTORY_NAMESPACE_END

#endif // WEAK_PTR_FACTORY_DEFINED_
