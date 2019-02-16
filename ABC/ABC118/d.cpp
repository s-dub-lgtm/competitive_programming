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
	
	int n, m;
	cin >> n >> m;
	int a[m];
	rep(i, m) cin >> a[i];
	
	int num[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	int b[m];
	rep(i, m) b[i] = a[i];
	sort(b, b + m);
	reverse(b, b + m);
	int main = b[0];
	FOR(i, 1, m) {
		if (2 * num[b[i]] <= num[main] or (num[b[i]] < num[main] and num[b[i]] * num[main] <= n)) {
			main = b[i];
		}
//		cout << main << endl;
	}
//	cout << main << endl;
	
	int cnt[10] = {};
	cnt[main] = n / num[main];
//	cout << cnt[main] << endl;
	n = n % num[main];
//	cout << n << endl;
	while (n != 0) {
		cnt[main]--;
		n += num[main];
//		cout << n << endl;
		bool flag2 = false;
		rep(i, m) {
			if (n % num[b[i]] == 0) {
				cnt[b[i]] += n / num[b[i]];
				flag2 = true;
			}
		}
		if (flag2) break;
		while (1) {
			bool flag = false;
			rep(i, m) {
				if (!flag) {
					if (num[main] != num[b[i]] and n > num[b[i]]) {
						cnt[b[i]]++;
						n -= num[b[i]];
						flag = true;
					}
				} else {
					if (num[main] != num[b[i]] and n >= num[b[i]]) {
						cnt[b[i]]++;
						n -= num[b[i]];
					}
				}
			}
			if (n == 0 or !flag) break;
		}
	}
	
	repr(i, 10) {
		rep(j, cnt[i]) {
			cout << i;
		}
	}
	cout << endl;
	
	return 0;
}