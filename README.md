weak_ptr_factory
===============

Minimalistic weak_ptr_factory class inspired by Chromium's base::WeakPtrFactory
(require C++11).

This small project was made as an exercise and for fun. Its practical usage is
at least debatable.

How to use
---------------

Just include `weak/weak_ptr_factory.hpp` or `weak/weak_ptr_factory.hpp` header.
Classes will be available as `weak::weak_ptr` and `weak::weak_ptr_factory`.

If you want to use boost's implementations instead of C++11 std ones use:

    #define WEAK_PTR_TOOLS_USE_BOOST
    #include "weak_ptr_factory.hpp"

Then it will be available under `weak::weak_ptr_factory`.

Example
---------------

    using weak::weak_ptr;
    using weak::weak_ptr_factory;

    class Test {
      weak_ptr_factory<Test> weak_ptr_factory_;

    public:
      explicit Test() :
        weak_ptr_factory_(this)
        {}

      weak_ptr<Test> get_weak_ptr() const {
        return weak_ptr_factory_.get_weak_ptr();
      }

      void invalidate_all_ptrs() {
        weak_ptr_factory_.invalidate_all_ptrs();
      }
    };

Factory is initiated with `this` and will create weak_ptrs to its owner with
`get_weak_ptr()` method. On object's destruction all weak_ptrs will be
invalidated.

Problems
---------------

On multithreaded environment one must be careful - since we assume that owner of
a factory manages its lifetime on its own. So it should be used only when we
have certainty that object cannot commit suicide between checking weak_ptr and
calling the object.
