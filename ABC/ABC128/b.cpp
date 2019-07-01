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

bool cmp(const pair<string, int> &a, const pair<string, int> &b) {
	if (a.first == b.first) {
		return a.second > b.second;
	} else {
		return a.first < b.first;
	}
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	string s[n];
	int p[n];
	rep(i, n) cin >> s[i] >> p[i];
	
	vector<pair<string, int>> vp;
	rep(i, n) {
		vp.push_back(make_pair(s[i], p[i]));
	}
	
	sort(ALL(vp), cmp);
	
	for (auto &evp: vp) {
		rep(i, n) {
			if (evp.first == s[i] and evp.second == p[i]) {
				cout << i + 1 << endl;
				continue;
			}
		}
	}
	
	return 0;
}