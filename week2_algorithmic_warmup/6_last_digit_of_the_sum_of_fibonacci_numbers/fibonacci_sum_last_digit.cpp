#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}


int get_fibonacci_last_digit_fast(int n) {
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


//returns the last digit of sum of the nth fibonacci terms
int fibonacci_sum_fast(long long n) {
    int n2 = (n + 2) % 60;
    int last = get_fibonacci_last_digit_fast(n2);
    if (last == 0) {
        return 9;
    } else {
        return last - 1;
    }
}

int main() {
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_naive(n);
    std::cout << fibonacci_sum_fast(n);
}
