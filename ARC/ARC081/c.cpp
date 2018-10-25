#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 入力
int N;
vector<int> a;

int main(void) {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int a_in;
        cin >> a_in;
        a.push_back(a_in);
    }

    sort(a.begin(), a.end());

    int longest1 = 0, longest2 = 0;
    long long ans = 0;
    for (int i = N - 1; i >= 0; --i) {
        if (a[i] == a[i - 1] && longest1 != 0) {
            longest2 = a[i];
            ans = (long long) longest1 * longest2;
            break;
        }
        if (a[i] == a[i - 1] && longest1 == 0) {
            longest1 = a[i];
            --i;
        }
    }

    cout << ans << endl;
    return 0;
}
