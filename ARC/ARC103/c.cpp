#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define FORE(i, a, b) for(int i=(a);i<=(b);++i)
#define rep(i, n) for(int i=0;i<(n);++i)
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
	int v[n];
	rep(i, n) cin >> v[i];
	
	bool allsame = true;
	rep(i, n - 1) {
		if (v[i] != v[i + 1]) allsame = false;
	}
	if (allsame) {
		cout << n / 2 << endl;
		return 0;
	}
	
	
	map<int, int> m1, m2;
	rep(i, n) {
		if (i % 2 == 0) {
			if (m1.find(v[i]) == m1.end()) {
				m1.insert(P(v[i], 1));
			} else {
				m1[v[i]]++;
			}
		} else {
			if (m2.find(v[i]) == m2.end()) {
				m2.insert(P(v[i], 1));
			} else {
				m2[v[i]]++;
			}
		}
	}
	
	
	int maxcnt1 = 0, maxcnt12 = 0;
	int maxvalue1;
	for (auto t:m1) {
		if (t.second >= maxcnt1) {
			maxcnt12 = maxcnt1;
			maxcnt1 = t.second;
			maxvalue1 = t.first;
		} else if (t.second >= maxcnt12) {
			maxcnt12 = t.second;
		}
	}
	
	int maxcnt2 = 0, maxcnt22 = 0;
	int maxvalue2;
	for (auto t:m2) {
		if (t.second >= maxcnt2) {
			maxcnt22 = maxcnt2;
			maxcnt2 = t.second;
			maxvalue2 = t.first;
		} else if (t.second >= maxcnt22) {
			maxcnt22 = t.second;
		}
	}
	
//	cout << maxcnt1 << " " << maxcnt12 << " " << maxcnt2 << " " << maxcnt22 << endl;
	
	if (maxvalue1 != maxvalue2) {
		cout << n - maxcnt1 - maxcnt2 << endl;
	} else {
		cout << min(n - maxcnt1 - maxcnt22, n - maxcnt2 - maxcnt12) << endl;
	}
	
	return 0;
}