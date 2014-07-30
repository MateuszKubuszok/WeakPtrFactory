template <class T>
weak_ptr<T>::weak_ptr() :
  ptr_()
  {}
template <class T>
weak_ptr<T>::weak_ptr(const shared_ptr_type<T>& ptr) :
  ptr_(ptr)
  {}
template <class T>
weak_ptr<T>::weak_ptr(weak_ptr<T>& ptr) :
  ptr_(ptr.ptr_)
  {}
template <class T>
weak_ptr<T>::weak_ptr(weak_ptr<T>&& ptr) :
  ptr_(std::move(ptr.ptr_))
  {}

template <class T>
T* weak_ptr<T>::get() const {
  return recover().get();
}

template <class T>
bool weak_ptr<T>::expired() const {
  return ptr_.expired();
}

template <class T>
void weak_ptr<T>::swap(weak_ptr<T>& ptr) {
  ptr_.swap(ptr.ptr_);
}

template <class T>
T& weak_ptr<T>::operator*() const {
  return recover().operator*();
}

template <class T>
T* weak_ptr<T>::operator->() const {
  return recover().operator->();
}

template <class T>
weak_ptr<T>& weak_ptr<T>::operator=(weak_ptr<T>& ptr) {
  ptr_.operator=(ptr.ptr_);
  return *this;
}
template <class T>
weak_ptr<T>& weak_ptr<T>::operator=(weak_ptr<T>&& ptr) {
  ptr_.operator=(std::move(ptr.ptr_));
  return *this;
}
template <class T>
weak_ptr<T>& weak_ptr<T>::operator=(const weak_ptr<T>& ptr) {
  ptr_.operator=(ptr.ptr_);
  return *this;
}
template <class T>
weak_ptr<T>& weak_ptr<T>::operator=(const weak_ptr<T>&& ptr) {
  ptr_.operator=(std::move(ptr.ptr_));
  return *this;
}

template <class T>
bool weak_ptr<T>::operator==(weak_ptr<T>& ptr) const {
  return ptr_ == ptr.ptr_;
}

template <class T>
weak_ptr<T>::operator bool() const {
  return !expired();
}

template <class T>
shared_ptr_type<T> weak_ptr<T>::recover() const {
  // assert(!ptr_.expired());
  return ptr_;
}

template <class T>
void swap(weak_ptr<T> &lhs, weak_ptr<T> &rhs) {
  lhs.swap(rhs);
}
