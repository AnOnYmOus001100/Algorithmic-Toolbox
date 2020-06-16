#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}


//fibonacci series iterative
int fibonacci_fast(int n) {
	int f0 = 0, f1 = 1, nf, f;	//f0 is the first term f1 is the second term, nf is the next term found by adding f0 and f1, and f is result f0
	if (n <= 1)
		return n;
	for(int i=0;i<n;i++)
	{
		//finding the next fibonacci term by adding the first and second terms
		nf = f0 + f1;
		//the next first term is the current second term
		f0 = f1;
		//the next second term is the sum of the current first and second terms
		f1 = nf;
		//assigning the resultant f0 as the nth fibonacci term
		f = f0;
	}

    return f;
}


//find the period length(pisano period) in the sequence of F(n) mod m
long long period_length(long long m) {
    long long F1 = 0, F2 = 1, F = F1 + F2;
	//find the period
//period length will be less than to m^2, so iterating till m*m
    for (int i = 0; i < m * m; i++) {
	//F = F(i) % m
        F = (F1 + F2) % m;
        F1 = F2;
        F2 = F;
	//when F1 and F2 gets to initial values, return current number of fibonacci term
        if (F1 == 0 && F2 == 1) return i + 1;
    }
}


//find F(n) % m	
int fibonacci_huge_fast(long long n, long long m) {
    long long remainder = n % period_length(m);

//return the value of F(remainder) % m
    return fibonacci_fast(remainder) % m;
}


//finding the last digit
int fibonacci_last_digit_fast(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous%10 + current%10;	//only storing the last digits of the two terms
    }

    return current%10;	//returns only the last digit
}

//find partial sum, from a number to a number, where from <= to
long long fibonacci_partial_sum_fast(long long from, long long to) {
    long long from_last, to_last;
    if (from == to) {
        return fibonacci_last_digit_fast(from % 60);
    } else {
        from = from % 60;
        to = to % 60;

        from_last = fibonacci_huge_fast(from + 1, 10) - 1;
        to_last = fibonacci_huge_fast(to + 2, 10) - 1;
    }
    return (to_last - from_last) % 10;
}



int main() {
    long long from, to;
    std::cin >> from >> to;
    //std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << fibonacci_partial_sum_fast(from, to) << '\n';
}
