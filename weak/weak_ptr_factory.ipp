namespace {
/// Make sure that the object is not destroyed by the shared_ptr.
template <class T> void mock_deleter(T*) {}
}  // namespace

template <class T>
weak_ptr_factory<T>::weak_ptr_factory(T* instance) :
  ptr_(instance, mock_deleter<T>)
  {}

template <class T>
weak_ptr<T> weak_ptr_factory<T>::get_weak_ptr() const {
  return ptr_;
}

template <class T>
void weak_ptr_factory<T>::invalidate_all_ptrs() {
  T* tmp = ptr_.get();
  ptr_.reset();
  ptr_.reset(tmp, mock_deleter<T>);
}
