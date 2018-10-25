#include <iostream>

using namespace std;

int main(void) {
    int total = 0;
    for (int i = 0; i < 3; ++i) {
        int s, e;
        cin >> s >> e;
        total += s * e / 10;
    }

    cout << total << endl;
    return 0;
}