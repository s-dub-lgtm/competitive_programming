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
	
	string s;
	cin >> s;
	int cnt[26];
	rep(i, 26) cnt[i] = 0;
	rep(i, s.length()) {
		cnt[s[i] - 'A']++;
	}
	
	bool flag = true;
	rep(i, 26) {
//		cout << cnt[i] << endl;
		if (not(cnt[i] == 0 or cnt[i] == 2)) {
			flag = false;
		}
	}
	
	if (flag) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}