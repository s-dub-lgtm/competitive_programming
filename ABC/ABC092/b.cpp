#include <iostream>

using namespace std;

int main(void) {
    int n, d, x;
    cin >> n >> d >> x;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int sum = x;
    for (int i = 0; i < n; ++i) {
        if (d % a[i] == 0) {
            sum += d / a[i];
        } else {
            sum += (d / a[i]) + 1;
        }
    }

    cout << sum << endl;
    return 0;
}