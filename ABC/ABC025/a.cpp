#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    string S;
    int N;
    cin >> S >> N;

    vector<char> c;
    for (int i = 0; i < 5; ++i) {
        c.push_back(S[i]);
    }

    sort(c.begin(), c.end());

    cout << c[(N - 1) / 5] << c[(N - 1) % 5] << endl;

    return 0;
}