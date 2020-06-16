#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}


//finding gcd using euclidian approach
int gcd_euclid(long a, long b) {
	//divisor is the greater between a and b
    int divisor = a >= b ? a : b;
	//dividend is the smaller one
    int dividend = a <= b ? a : b;

    while (divisor != 0) {
        int remainder = dividend % divisor;
        dividend = divisor;
        divisor = remainder;
    }
	//dividend is the gcd
    return dividend;
}


//using gcd_euclid to find the lcm of a and b
long long lcm_fast_euclid(long long a, long long b) {
	//product of a and b divided by the gcd of a and b, is lcm of a and b
    return (a * b) / gcd_euclid(a, b);
}


int main() {
  long long a, b;
  std::cin >> a >> b;
  //std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_fast_euclid(a, b) << std::endl;
  return 0;
}
