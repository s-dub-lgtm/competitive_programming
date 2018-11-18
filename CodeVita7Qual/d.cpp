#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

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
	
	int n;
	cin >> n;
	rep(i, n) {
		ll e, c;
		cin >> e >> c;
		ll cash[e];
		rep(j, e) cin >> cash[j];
		
		rep(j, e) {
			ll sum = cash[j] / 10;
			rep(k, e) {
				if (j != k) {
					sum += cash[k];
				}
			}
			if (sum == c) {
				cout << cash[j] / 10;
				return 0;
			}
			
			ll num = cash[j];
			ll cnt = 0;
			while (1) {
				if (num / 10 == 0) break;
				num /= 10;
				cnt++;
			}
			sum = cash[j] - pow(num, cnt);
			rep(k, e) {
				if (j != k) {
					sum += cash[k];
				}
			}
			if (sum == c) {
				cout << cash[j] - pow(num, cnt);
				return 0;
			}
		}
		
	}
	
	return 0;
}