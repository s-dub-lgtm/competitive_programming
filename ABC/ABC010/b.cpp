#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int total = 0;
    for (int i = 0; i < n; ++i) {
        int number = a[i];
        int remove = 0;
        while ((number % 2 == 0) || (number % 3 == 2)) {
            remove++;
            number--;
        }
        total += remove;
    }

    cout << total << endl;
    return 0;
}