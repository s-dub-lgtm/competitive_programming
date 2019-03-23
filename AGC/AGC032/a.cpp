#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define FORE(i, a, b) for(int i=(a);i<=(b);++i)
#define FORR(i, a, b) for(int i=(b-1);i>=(a);--i)
#define FORRE(i, a, b) for(int i=(b);i>=(a);--i)
#define rep(i, n) for(int i=0;i<(n);++i)
#define repe(i, n) for(int i=0;i<=(n);++i)
#define repr(i, n) for(int i=(n-1);i>=0;--i)
#define repre(i, n) for(int i=(n);i>=0;--i)
#define ALL(v) (v).begin(),(v).end()
#define SP cout<<fixed<<setprecision(10)
typedef pair<int, int> P;
const int INF = (int) 1e9;
const int MOD = (int) 1e9 + 7;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	int b[n];
	rep(i, n) cin >> b[i];
	
	bool ok1 = true;
	rep(i, n) {
//		cout << b[i] << endl;
		if (b[i] != 1) {
			if (i != 0) {
				if (b[i - 1] >= b[i]) {
					continue;
				}
			}
			int cnt = 0;
			repr(j, i) {
				if (b[j] < b[i]) cnt++;
				else break;
			}
//			cout << cnt << endl;
			if (cnt < b[i] - 1) ok1 = false;
		}
		if (!ok1) {
			cout << -1 << endl;
			return 0;
		}
	}
	
	priority_queue<int, vector<int>, greater<int>> pque;
	priority_queue<int, vector<int>, greater<int>> pque2;
	int must = 0;
	int one_cnt = 0;
	repr(i, n) {
//		cout << " " << must << " ";
		if (b[i] == 1) {
			one_cnt++;
			if (must == 0) {
				cout << 1 << endl;
				one_cnt = 0;
				continue;
			}
			if (one_cnt == must - 1) {
//				cout << endl;
				if (one_cnt == 1 and b[i + 1] == 1) {
					cout << 1 << endl;
				} else {
					int cnt = 0;
					int before_cnt = 0;
					while (1) {
						if (must == pque.top()) {
							if (before_cnt > pque.top() - 1) {
								pque2.push(pque.top());
								pque.pop();
								if (pque.empty()) break;
							}
							if (before_cnt == pque.top() - 1) {
								cout << pque.top() << endl;
								pque.pop();
								cnt++;
								if (pque.empty()) break;
							} else {
								cout << 1 << endl;
								cnt++;
								before_cnt++;
							}
						} else {
							if (cnt > pque.top() - 1) {
								pque2.push(pque.top());
								pque.pop();
								if (pque.empty()) break;
							}
							if (cnt == pque.top() - 1) {
								cout << pque.top() << endl;
								pque.pop();
								cnt++;
								if (pque.empty()) break;
							} else {
								cout << 1 << endl;
								cnt++;
								before_cnt++;
							}
						}
					}
					while (!pque2.empty()) {
						cout << pque2.top() << endl;
						pque2.pop();
					}
					must = 0;
					one_cnt = 0;
				}
			}
		} else {
			must = b[i];
			pque.push(b[i]);
		}
	}
	
	return 0;
}