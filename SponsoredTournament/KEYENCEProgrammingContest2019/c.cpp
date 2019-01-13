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
	cin >> n;
	ll a[n], b[n];
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	
	ll suma = 0, sumb = 0;
	rep(i, n) {
		suma += a[i];
		sumb += b[i];
	}
	if (suma < sumb) {
		cout << -1 << endl;
		return 0;
	}
	
	priority_queue<ll> bigger;
	int cnt = 0;
	ll sum = 0;
	rep(i, n) {
		if (a[i] - b[i] < 0) {
			sum += abs(a[i] - b[i]);
			cnt++;
		} else if (a[i] - b[i] > 0) bigger.push(a[i] - b[i]);
	}
//	cout << sum << endl;
	
	while (sum > 0) {
//		cout << bigger.top() << endl;
		sum -= bigger.top();
		bigger.pop();
		cnt++;
	}
	
	cout << cnt << endl;
	
	return 0;
}