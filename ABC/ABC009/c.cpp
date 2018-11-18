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

char s[101], t[101];

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n, k;
	cin >> n >> k;
	cin >> s;
	vector<int> tcnt(26);
	rep(i, n) tcnt[s[i] - 'a']++;
	rep(i, n) {
		FORE(a, 'a', 'z') {
			if (tcnt[a - 'a'] > 0) {
				t[i] = a;
				tcnt[a - 'a']--;
				int x = 0;
				rep(j, i + 1) x += s[j] != t[j];
				vector<int> scnt(26);
				FOR(j, i + 1, n) {
					scnt[s[j] - 'a']++;
				}
				int y = 0;
				rep(j, 26) y += max(scnt[j], tcnt[j]) - min(scnt[j], tcnt[j]);
				x += y / 2;
				if (x <= k) break;
				tcnt[a - 'a']++;
				t[i] = '?';
			}
		}
	}
	
	cout << t << endl;
	
	return 0;
}