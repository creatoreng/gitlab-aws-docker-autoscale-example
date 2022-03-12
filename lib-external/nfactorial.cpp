/**
 * @attention Copyright (c) 2022, Creator, Inc. All rights reserved.
 **/

 #include "nfactorial.hpp"

namespace nfactorial {

template <int n> struct Factorial {
  static constexpr int k = Factorial<n-1>::k*n;
};

template <> struct Factorial<0> {
  static constexpr int k = 1;
};

constexpr int fact5 = Factorial<5>::k;

} // namespace nfactorial
