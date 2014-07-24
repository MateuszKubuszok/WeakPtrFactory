weak_ptr_factory
===============

Minimalistic weak_ptr_factory class inspired by Chromium's base::WeakPtrFactory (require C++11).

This small project was made as an exercise and for fun. Its practical usage is at least debatable.

How to use
---------------

Just include `weak_ptr_factory.hpp` header. Class will be available as `std::weak_ptr_factory`.

If you want to use boost's implementations instead of C++11 std ones use:

    #define shared_ptr_type ::boost::shared_ptr
    #define weak_ptr_type   ::boost::weak_ptr
    #define WEAK_PTR_FACTORY_NAMESPACE_BEGIN namespace boost {
    #define WEAK_PTR_FACTORY_NAMESPACE_END }  // nameospace boost
    #include "weak_ptr_factory.hpp"

Then it will be available under `boost::weak_ptr_factory`.

Example
---------------

    using std::weak_ptr;
    using std::weak_ptr_factory;

    class Test {
      weak_ptr_factory<Test> weak_ptr_factory_;

    public:
      explicit Test() :
        weak_ptr_factory_(this)
        {}

      weak_ptr<Test> get_weak_ptr() const {
        return weak_ptr_factory_.get_weak_ptr();
      }
    };

Factory is initiated with `this` and will create weak_ptrs to its owner with `get_weak_ptr()`
method. On object's destruction all weak_ptrs will be invalidated.

Problems
---------------

std::weak_ptr allows creation of std::shared_ptr to the same object. While it doesn't prevent
deletion of reffered object it might cause situation when weak_ptrs are not invalidated though
object is no longer existing. I don't know how that would be fixed without rewritting pointers
to resemble Chromium's base::shared_ptr and base::weak_ptr.
