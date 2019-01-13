#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define FORE(i, a, b) for(int i=(a);i<=(b);++i)
#define rep(i, n) for(int i=0;i<(n);++i)
#define repe(i, n) for(int i=0;i<=(n);++i)
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
	
	if (s == "keyence" or s.substr(0, 7) == "keyence") {
		cout << "YES" << endl;
		return 0;
	}

//	cout << s.length() << endl;
	string tmp = s;
	rep(i, s.length()) {
//		cout << s.erase(i, s.length() - 7) << endl;
		if (s.erase(i, s.length() - 7) == "keyence") {
			cout << "YES" << endl;
			return 0;
		}
		s = tmp;
	}
	
//	rep(i, s.length()-6)
	
	cout << "NO" << endl;
	
	return 0;
}