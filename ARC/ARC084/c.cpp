#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 入力
int N;
vector<int> A, B, C;

int main(void) {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int a_in;
        cin >> a_in;
        A.push_back(a_in);
    }
    for (int i = 0; i < N; ++i) {
        int b_in;
        cin >> b_in;
        B.push_back(b_in);
    }
    for (int i = 0; i < N; ++i) {
        int c_in;
        cin >> c_in;
        C.push_back(c_in);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        long long a_num = (long long) (lower_bound(A.begin(), A.end(), B[i]) - A.begin());
        long long c_num = (long long) N - (long long) (upper_bound(C.begin(), C.end(), B[i]) - C.begin());
        sum += a_num * c_num;
    }

    cout << sum << endl;
    return 0;
}