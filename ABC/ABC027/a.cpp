#include <iostream>

using namespace std;

int main(void) {
    int l1, l2, l3;
    cin >> l1 >> l2 >> l3;

    int l4;
    if (l1 == l2) {
        l4 = l3;
    } else if (l1 == l3) {
        l4 = l2;
    } else {
        l4 = l1;
    }
    cout << l4 << endl;
    return 0;
}