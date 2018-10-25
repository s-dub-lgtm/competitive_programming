#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a, a + n);

    int ai = a[n - 1];

    double half = (double) (ai) / 2;
//    cout << half << endl;
    int aj;
    int ajdiff = 1000000000;
    for (int i = 0; i < n - 1; ++i) {
        double diff = abs((double) (a[i]) - half);
//        cout << diff << endl;
        if (diff < ajdiff) {
            aj = a[i];
            ajdiff = diff;
        }
    }

    cout << ai << " " << aj << endl;
    return 0;
}