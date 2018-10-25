#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    int T[N];
    for (int i = 0; i < N; ++i) {
        cin >> T[i];
    }

    sort(T, T + N);

    cout << T[0] << endl;
    return 0;
}