#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
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
long long fibonacci_huge_fast(long long n, long long m) {
//to find F(n) mod m, it will be same and efficient to find  F(remainder) % m
	//find the remainder by dividing n(nth fibonacci term) by period length
    long long remainder = n % period_length(m);
	//find F(remainder) % m
    long long F1 = 0, F2 = 1, F=remainder;
    for (int i = 1; i < remainder; i++) {
        F = (F1 + F2) % m;
        F1 = F2;
        F2 = F;
    }
	//return the value of F(remainder) % m
    return F % m;
}


int main() {
    long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << fibonacci_huge_fast(n, m) << '\n';
}
