#include <iostream>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int minimum = 0;
    for (int i = 1; i < N; ++i) {
        if (S[i] == 'E') minimum++;
    }
//    cout << minimum << endl;
    int cnt = minimum;
    for (int i = 1; i < N; ++i) {
        if (S[i - 1] == 'W') cnt++;
//        if (S[i] == 'W') cnt--;
        if (S[i] == 'E') cnt--;
        minimum = min(minimum, cnt);
    }

    cout << minimum << endl;
    return 0;
}