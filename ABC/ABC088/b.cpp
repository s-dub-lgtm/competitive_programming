#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int a_in;
        cin >> a_in;
        a.push_back(a_in);
    }

    sort(a.begin(), a.end());

    int alicescore = 0, bobscore = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            alicescore += a[n - i - 1];
        } else {
            bobscore += a[n - i - 1];
        }
    }

    cout << alicescore - bobscore << endl;
    return 0;
}