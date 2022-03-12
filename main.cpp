/**
 * @attention Copyright (c) 2022, Creator, Inc. All rights reserved.
 *
 * @file main.hpp
 * @date March 12, 2022
 * @author elgeeko
 * @license MIT
 * @copyright Copyright (c) 2022, Creator, Inc. All rights reserved.
 * @brief Hello world application. Prints "hello world" and returns 0.
 **/

// example of including an external library that will be in build cache
#include "lib-external/nfactorial.hpp"

#include <iostream>
#include <memory>
#include <functional>

class AbstractMessenger {
public:
  virtual ~AbstractMessenger(void) {
    std::cout << "world!" << std::endl;
  }

protected:
  AbstractMessenger(void) = default;

  virtual void operator ()() const {
    std::cout << "Hello";
  }
};

class Messenger : private AbstractMessenger {
public:
  static std::function<std::unique_ptr<const AbstractMessenger> (void)> factory(void) {
    return []() {
      return std::move(
        std::unique_ptr<const AbstractMessenger>(
          static_cast<const AbstractMessenger *>(new const Messenger())));
    };
  }

private:
  Messenger(void) = default;

  virtual ~Messenger(void){
    (*this)();
  };

  void operator ()() const override final {
    AbstractMessenger::operator ()();
    std::cout << ", ";
  }
};

static const auto messenger(Messenger::factory()());

int main(void) {
  return nfactorial::fact5 == 120 ? 0 : 1;
}
