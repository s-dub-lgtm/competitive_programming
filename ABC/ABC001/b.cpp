#include <iostream>

using namespace std;

int main(void) {
    double m;
    cin >> m;

    double km = m / 1000;
    int vv;
    if (km < 0.1) {
        cout << "00" << endl;
    } else if (km <= 5) {
        if (km < 1) {
            cout << "0" << (int) (km * 10) << endl;
        } else {
            cout << (int) (km * 10) << endl;
        }
    } else if (km <= 30) {
        cout << (int) (km + 50) << endl;
    } else if (km <= 70) {
        cout << (int) ((km - 30) / 5 + 80) << endl;
    } else {
        cout << "89" << endl;
    }

    return 0;
}