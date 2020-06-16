#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

//fast approach better than the naive one, more time efficient
//checks from 2 to lesser of a and b, as gcd is will be within 2 to smaller number, otherwise 1
int gcd_fast(int a, int b) {
  int current_gcd = 1, range;
  	
	//find smaller of a and b and assign to range
	if (a < b)
		range = a;
	else
		range = b;

 	 for (int d = 2; d <= range; d++)
	{
	 if (a % d == 0 && b % d == 0)
	    {
		if (d > current_gcd)
		 current_gcd = d; 
	    }
	}
  return current_gcd;
}

//using euclidian approach to find the gcd of a and b, most time efficient
int gcd_euclid(int a, int b) {
	int gcd;
	//greater between a and b is the the divisor
    int divisor = a >= b ? a : b;
	//smaller between a and b is the dividend
    int dividend = a <= b ? a : b;
    while (divisor != 0) {
        int remainder = dividend % divisor;
        dividend = divisor;
        divisor = remainder;
    }
	//gcd is the dividend
	gcd = dividend;
    return dividend;
}



int main() {
  int a, b;
  std::cin >> a >> b;
  //std::cout << gcd_naive(a, b) << std::endl;
  //std::cout << gcd_fast(a, b) << std::endl;
  std::cout << gcd_euclid(a, b) << std::endl;
  return 0;
}
