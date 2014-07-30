#ifndef WEAK_PTR_FACTORY_DEFINED_
#define WEAK_PTR_FACTORY_DEFINED_

#include "weak/weak_ptr.hpp"

namespace weak {

/// Creates weak_ptrs (mainly) for self managing object.
/// Idea taken from Chromium's base::WeakPtrFactory.
template <class T>
class weak_ptr_factory {
  shared_ptr_type<T> ptr_;

public:
  /// Initializes factory with this.
  explicit weak_ptr_factory(T* instance);

  /// Returns weak_ptr to the instance.
  weak_ptr<T> get_weak_ptr() const;

  /// Invalidate all weak_ptrs.
  void invalidate_all_ptrs();

private:
  /// No copy constructor.
  weak_ptr_factory(const weak_ptr_factory&) = delete;

  /// No move constructor.
  weak_ptr_factory(const weak_ptr_factory&&) = delete;

  /// No assignment.
  weak_ptr_factory& operator=(const weak_ptr_factory&) = delete;
};

#include "weak/weak_ptr_factory.ipp"

}  // namespace weak

#endif // WEAK_PTR_FACTORY_DEFINED_
