#include <iostream>
#include <cassert>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

long long get_fibonacci_last_digit_fast(int n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
    }

    return current % 10;
}

void test_solution()
{
    assert(get_fibonacci_last_digit_fast(3) == get_fibonacci_last_digit_naive(3));

    for (int i = 1; i < 49; i++) {
        assert(get_fibonacci_last_digit_fast(i) == get_fibonacci_last_digit_naive(i));
    }
}

int main() {
    int n;
    std::cin >> n;
    std::cout << get_fibonacci_last_digit_fast(n) << std::endl;
    return 0;
}

