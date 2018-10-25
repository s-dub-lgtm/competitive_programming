#include <iostream>

using namespace std;

int main(void) {
    int a, b;
    cin >> a >> b;

    int buy;
    if (a % b == 0) buy = 0;
    else buy = b - (a % b);

    cout << buy << endl;
    return 0;
}