#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> p;

int main(void) {
    int N;
    cin >> N;
    vector<p> red, blue;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        red.emplace_back(make_pair(a, b));
    }
    for (int i = 0; i < N; ++i) {
        int c, d;
        cin >> c >> d;
        blue.emplace_back(make_pair(c, d));
    }

    sort(red.begin(), red.end());
    sort(blue.begin(), blue.end());

    int cnt = 0;
    bool flag[N];
    for (int i = 0; i < N; ++i) {
        flag[i] = false;
    }
    for (auto b:blue) {
        int maxtmp = -1;
        int argmax = -1;
        for (int i = 0; i < N; ++i) {
            if (red[i].first > b.first) break;
            if (red[i].second < b.second && !flag[i]) {
                if (red[i].second > maxtmp) {
                    argmax = i;
                    maxtmp = red[i].second;
                }
            }
        }
        if (argmax >= 0) {
            flag[argmax] = true;
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}