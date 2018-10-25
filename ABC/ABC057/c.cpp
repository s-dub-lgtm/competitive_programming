#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    long long int n;
    cin >> n;

    int min_digit = 10 ^6;
    for (int i = 1; i <= sqrt(n); ++i) {
        if ((n % i) != 0) {
            continue;
        }
        long long int j = n / i;
        int max_digit = max(to_string(i).length(), to_string(j).length());
        min_digit = min(min_digit, max_digit);
    }

    cout << min_digit << endl;
    return 0;
}