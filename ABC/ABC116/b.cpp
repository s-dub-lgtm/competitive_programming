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
	
	int s;
	cin >> s;
	
	bool exist[1000001];
	rep(i, 1000001) exist[i] = false;
	exist[s] = true;
	
	int cnt = 1;
	while (1) {
		if (s % 2 == 0) s = s / 2;
		else s = 3 * s + 1;
		
		if (exist[s]) {
			cout << cnt + 1 << endl;
			return 0;
		}
		exist[s] = true;
		cnt++;
	}
	
	return 0;
}