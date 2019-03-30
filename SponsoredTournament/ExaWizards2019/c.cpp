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
	
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	char t[q], d[q];
	rep(i, q) {
		cin >> t[i] >> d[i];
	}
	
	int leftindex = 0;
	bool isstopleft = false;
	int stopleftindex = 0;
	repr(i, q) {
		if (s[leftindex] == t[i] and d[i] == 'L') {
			if (isstopleft) isstopleft = false;
			leftindex++;
			stopleftindex = leftindex;
		} else if (s[leftindex] == t[i] and d[i] == 'R') {
			if (!isstopleft) {
				isstopleft = true;
				stopleftindex = leftindex;
			}
		}
	}
	int rightindex = n - 1;
	bool isstopright = false;
	int stoprightindex = n - 1;
	repr(i, q) {
		if (s[rightindex] == t[i] and d[i] == 'R') {
			if (isstopright) isstopright = false;
			rightindex--;
			stoprightindex = rightindex;
		} else if (s[rightindex == t[i] and d[i] == 'L']) {
			if (!isstopright) {
				isstopright = true;
				stoprightindex = rightindex;
			}
		}
	}
	
//	cout << leftindex << " " << rightindex << endl;
	cout << n - (stopleftindex + (n - stoprightindex - 1)) << endl;
	
	return 0;
}