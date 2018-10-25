#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i * 10000;
    }

    cout << sum / n << endl;
    return 0;
}