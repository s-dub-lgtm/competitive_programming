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
	
	int n;
	ll l;
	cin >> n >> l;
	ll a[n];
	rep(i, n) cin >> a[i];
	
	bool able = false;
	int last = -1;
	rep(i, n - 1) {
		if (a[i] + a[i + 1] >= l) {
			able = true;
			if (last == -1) last = i;
		}
	}
	if (!able) {
		cout << "Impossible" << endl;
		return 0;
	}
	
	cout << "Possible" << endl;
	rep(i, last) cout << i + 1 << endl;
	for (int i = n - 1; i > last; --i) cout << i << endl;

//	ll sum = 0;
//	rep(i, n) sum += a[i];
//
//	vector<int> order;
//	int left = 0, right = n - 1;
//	rep(i, n - 1) {
//		if (sum >= l) {
//			if (a[left] < a[right]) {
//				order.push_back(left);
//				sum -= a[left];
//				left++;
//			} else {
//				order.push_back(right - 1);
//				sum -= a[right];
//				right--;
//			}
//		} else {
//			cout << "Impossible" << endl;
//			return 0;
//		}
//	}
//
//	cout << "Possible" << endl;
//	for (auto &t: order) cout << t + 1 << endl;
	
	return 0;
}