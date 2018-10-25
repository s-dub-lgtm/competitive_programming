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

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n, d, k;
	cin >> n >> d >> k;
	int l[d], r[d];
	rep(i, d) cin >> l[i] >> r[i];
	
	rep(i, k) {
		int s, t;
		cin >> s >> t;
//		cout << s << t << endl;
		
		int l_min = INF, r_max = 0;
		int ans1 = INF;
		rep(j, d) {
			if (l_min == INF && r_max == 0) {
				if (l[j] <= s && s <= r[j]) {
					l_min = min(l[j], l_min);
					r_max = max(r[j], r_max);
				}
			} else {
				if (r_max >= l[j]) {
					l_min = min(l[j], l_min);
					r_max = max(r[j], r_max);
				}
			}
			
//			cout << l_min << " " << r_max << endl;
			
			if (l_min <= t && t <= r_max) {
//				cout << j + 1 << endl;
//				break;
				ans1 = j + 1;
				break;
			}
			
		}
		
		l_min = INF, r_max = 0;
		int ans2 = INF;
		rep(j, d) {
			if (l_min == INF && r_max == 0) {
				if (l[j] <= s && s <= r[j]) {
					l_min = min(l[j], l_min);
					r_max = max(r[j], r_max);
				}
			} else {
				if (l_min <= r[j]) {
					l_min = min(l[j], l_min);
					r_max = max(r[j], r_max);
				}
			}
			
//			cout << l_min << " " << r_max << endl;
			
			if (l_min <= t && t <= r_max) {
//				cout << j + 1 << endl;
//				break;
				ans2 = j + 1;
				break;
			}
			
		}
		
		cout << max(ans1, ans2) << endl;
	}
	
	return 0;
}