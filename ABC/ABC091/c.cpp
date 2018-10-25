#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

int vector_finder(vector<int> vec, int number) {
    auto itr = find(vec.begin(), vec.end(), number);
    size_t index = distance(vec.begin(), itr);
    if (index != vec.size()) { // 発見できたとき
        return 1;
    } else { // 発見できなかったとき
        return 0;
    }
}

int main(void) {
    int n;
    cin >> n;
    int a[n], b[n], c[n], d[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i] >> d[i];
    }

    pair<int, int> cnt_r[n]; // pair<要素数, 赤のID>
    for (int i = 0; i < n; ++i) {
        cnt_r[i].first = 0;
    }
    for (int i = 0; i < n; ++i) {
        cnt_r[i].second = i;
    }
    vector<vector<int>> friend_r(n); // 赤のID<青のID>
    pair<int, int> cnt_b[n];
    for (int i = 0; i < n; ++i) {
        cnt_b[i].first = 0;
    }
    for (int i = 0; i < n; ++i) {
        cnt_b[i].second = i;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (c[j] - a[i] > 0 && d[j] - b[i] > 0) {
                cnt_r[i].first++;
                friend_r[i].push_back(j);
                cnt_b[j].first++;
            }
        }
    }

    sort(cnt_r, cnt_r + n);
    sort(cnt_b, cnt_b + n);

    int friend_num = 0;
    for (int i = 0; i < n; ++i) {
        if (cnt_r[i].first == 0) { // 仲良しペアできない
            continue;
        } else {
            friend_num++;
//            random_device rd;
//            int friend_pair = rd() % friend_r[cnt_r[i].second].size();
//            int friend_pair = friend_r[cnt_r[i].second][0]; // 青のID取得
            int friend_pair;
            for (int j = 0; j < n; ++j) {
                int candidate = cnt_b[j].second;
                if (vector_finder(friend_r[cnt_r[i].second], candidate) == 1) {
                    friend_pair = candidate;
                    break;
                }
            }
//            int friend_pair = friend_r[cnt_r[i].second][friend_r[cnt_r[i].second].size() - 1];
            for (int j = 0; j < n; ++j) {
                if (vector_finder(friend_r[j], friend_pair) == 1) {
//                    friend_r[j].erase(find(friend_r[j].begin(), friend_r[j].end(), friend_pair));
                    friend_r[j].erase(remove(friend_r[j].begin(), friend_r[j].end(), friend_pair), friend_r[j].end());

                    for (int k = 0; k < n; ++k) {
                        if (j == cnt_r[k].second) {
                            cnt_r[k].first--;
                        }
                    }
                }
            }
        }
    }

    cout << friend_num << endl;
    return 0;
}