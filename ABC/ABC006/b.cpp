#include <iostream>

using namespace std;

int mem[1000001];

int fib(int n) {
    if (n == 1 || n == 2) {
        return mem[n] = 0;
    }
    if (n == 3) {
        return mem[n] = 1;
    }
    if (mem[n] != 0) {
        return mem[n];
    }
    return mem[n] = (fib(n - 1) + fib(n - 2) + fib(n - 3)) % 10007;
}

int main(void) {
    int n;
    cin >> n;

    cout << fib(n) << endl;

    return 0;
}