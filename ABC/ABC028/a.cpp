#include <iostream>

using namespace std;

int main(void) {
    int N;
    cin >> N;

    if (N == 100) cout << "Perfect" << endl;
    else if (90 <= N) cout << "Great" << endl;
    else if (60 <= N) cout << "Good" << endl;
    else cout << "Bad" << endl;
    return 0;
}