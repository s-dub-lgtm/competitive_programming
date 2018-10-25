#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    int X, K;
    cin >> X >> K;

    int cost;
    if (X % (int) pow(10, K) == 0) {
        cost = X + (int) pow(10, K);
    } else {
        cost = (int) (X / pow(10, K)) * pow(10, K) + pow(10, K);
    }

    cout << cost << endl;
    return 0;
}