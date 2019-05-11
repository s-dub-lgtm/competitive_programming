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
	string s[n];
	rep(i, n) {
		cin >> s[i];
	}
	
	ll cnt = 0;
	rep(i, n) {
		rep(j, s[i].length() - 1) {
			if (s[i][j] == 'A' and s[i][j + 1] == 'B') {
				cnt++;
				s[i][j] = 'C';
				s[i][j + 1] = 'C';
			}
		}
	}
	
	bool allba = true;
	ll bcnt = 0;
	ll acnt = 0;
	rep(i, n) {
		if (s[i][0] == 'B') {
			bcnt++;
			if (s[i][s[i].length() - 1] != 'A') {
				allba = false;
			}
		}
		if (s[i][s[i].length() - 1] == 'A') {
			acnt++;
			if (s[i][0] != 'B') {
				allba = false;
			}
		}
	}
//	cout << allba << endl;
	
	if (n == 1) {
		cout << cnt << endl;
	} else if (bcnt == 0 or acnt == 0) {
		cout << cnt << endl;
	} else if (allba) {
		cout << cnt + bcnt - 1 << endl;
	} else {
		cout << cnt + min(bcnt, acnt) << endl;
	}
	
	return 0;
}