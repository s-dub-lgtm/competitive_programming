#include <iostream>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    string S[N];
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }

    int leaderNum = 0;
    int leaderCnt = 0;
    for (int i = 0; i < N; ++i) {
        string name = S[i];
        int cnt = 0;
        for (int j = 0; j < N; ++j) {
            if (name == S[j]) {
                cnt++;
            }
        }
        if (cnt > leaderCnt) {
            leaderCnt = cnt;
            leaderNum = i;
        }
    }

    cout << S[leaderNum] << endl;
    return 0;
}