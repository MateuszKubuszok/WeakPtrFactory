#include <iostream>

#include "weak_ptr_factory.hpp"

using std::cout;
using std::endl;
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

int main(int, char**) {
  weak_ptr<Test> test_ptr;
  cout << "weak_ptr is empty: " << !test_ptr.expired() << endl;

  {
    Test test_instance;
    test_ptr = test_instance.get_weak_ptr();
    cout << "weak_ptr initialized with factory: " << !test_ptr.expired() << endl;
  }

  cout << "weak_ptr invalidated: " << !test_ptr.expired() << endl;
}
