#include <iostream>

#include "weak/weak_ptr.hpp"

using std::cout;
using std::endl;
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

void expiration_on_destrution_test() {
  cout << "expiration on destrution test" << endl;

  weak_ptr<Test> test_ptr;
  cout << "weak_ptr is empty: " << !test_ptr.expired() << endl;

  {
    Test test_instance;
    test_ptr = test_instance.get_weak_ptr();
    cout << "weak_ptr initialized by factory: " << !test_ptr.expired() << endl;
  }

  cout << "weak_ptr invalidated: " << !test_ptr.expired() << endl;

  cout << endl;
}

void expiration_on_invalidation_test() {
  cout << "expiration on invalidation test" << endl;

  weak_ptr<Test> test_ptr;
  Test test_instance;
  
  cout << "weak_ptr is empty: " << !test_ptr.expired() << endl;

  test_ptr = test_instance.get_weak_ptr();
  cout << "weak_ptr initialized by factory: " << !test_ptr.expired() << endl;
  
  test_instance.invalidate_all_ptrs();
  cout << "weak_ptr invalidated: " << !test_ptr.expired() << endl;

  test_ptr = test_instance.get_weak_ptr();
  cout << "weak_ptr initialized  again: " << !test_ptr.expired() << endl;

  cout << endl;
}

int main(int, char**) {
  expiration_on_destrution_test();
  expiration_on_invalidation_test();
}
