#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define SP cout<<fixed<<setprecision(10)

typedef pair<int, int> P;

const int INF = (int) 1e9;
const int MOD = (int) 1e9 + 7;

template<class T>
bool chmax(T &a, const T &b) {
	if (a < b) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T>
bool chmin(T &a, const T &b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	string s;
	cin >> s;
	
	bool ac = true;
	int cnt = 0;
	REP(i, s.length()) {
		if (i == 0) {
			if (s[i] != 'A') ac = false;
		}
		if (2 <= i && i <= s.length() - 2) {
			if (s[i] == 'C') {
				cnt++;
			} else {
				if (s[i] - 'a' >= 26) {
					ac = false;
				}
			}
		}
//		if (i == 1 || i == s.length() - 1) {
//			if (s[i] - 'A' <= 25) {
//				ac = false;
//			}
//		}
		if (s[i] != 'A' && s[i] != 'C') {
			if (s[i] - 'A' <= 25) {
				ac = false;
			}
		}
	}
	
	if (cnt != 1) ac = false;
	
	if (ac) cout << "AC" << endl;
	else cout << "WA" << endl;

//	cout << 'a' - 'A' << endl;
	
	return 0;
}