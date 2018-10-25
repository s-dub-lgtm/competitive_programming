#include <iostream>

using namespace std;

int main(void) {
    int x, a, b;
    cin >> x >> a >> b;

    x -= a;
    int res = x % b;

    cout << res << endl;
    return 0;
}