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

int n, a, b, c;
int l[10];
int ans = INF;

void dfs(int *use, int cnt) {
	if (cnt == n) {
		int suma = 0, sumb = 0, sumc = 0;
		int cnta = 0, cntb = 0, cntc = 0;
		rep(i, n) {
			if (use[i] == 0) {
				suma += l[i];
				cnta++;
			} else if (use[i] == 1) {
				sumb += l[i];
				cntb++;
			} else if (use[i] == 2) {
				sumc += l[i];
				cntc++;
			}
		}
		
		if (cnta == 0 or cntb == 0 or cntc == 0) return;
		
		int sum = 0;
		sum += (cnta - 1) * 10 + (cntb - 1) * 10 + (cntc - 1) * 10;
		sum += abs(a - suma) + abs(b - sumb) + abs(c - sumc);
		ans = min(sum, ans);
//		cout << " " << ans << endl;
		return;
	}
	rep(i, 4) {
//		cout << i << endl;
		use[cnt] = i;
		dfs(use, cnt + 1);
	}
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n >> a >> b >> c;
	rep(i, n) cin >> l[i];
	
	int use[n];
	dfs(use, 0);
	
	cout << ans << endl;
	
	return 0;
}