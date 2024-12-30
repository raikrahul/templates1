#include <iostream>

template <unsigned int A, unsigned int B> struct GCD {
  static constexpr unsigned int value = GCD<B, A % B>::value;
};

template <unsigned int A> struct GCD<A, 0> {
  static constexpr unsigned int value = A;
};

int main() {

  std::cout << GCD<10, 5>::value << std::endl;
  std::cout << GCD<10, 3>::value << std::endl;
  std::cout << GCD<10, 2>::value << std::endl;

  std::cout << GCD<18, 12>::value << std::endl;

  std::cout << std::endl;

  return 0;
}

// // For GCD<10,5>:
// struct GCD<10,5> { static constexpr unsigned int value = GCD<5,0>::value; };
// struct GCD<5,0> { static constexpr unsigned int value = 5; };

// // For GCD<10,3>:
// struct GCD<10,3> { static constexpr unsigned int value = GCD<3,1>::value; };
// struct GCD<3,1> { static constexpr unsigned int value = GCD<1,0>::value; };
// struct GCD<1,0> { static constexpr unsigned int value = 1; };

// // For GCD<10,2>:
// struct GCD<10,2> { static constexpr unsigned int value = GCD<2,0>::value; };
// struct GCD<2,0> { static constexpr unsigned int value = 2; };
