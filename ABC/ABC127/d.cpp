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
	
	priority_queue<ll> pq1;
	rep(i, n) {
		ll a;
		cin >> a;
		pq1.push(a);
	}
	
	vector<pair<ll, ll>> p;
	rep(i, m) {
		ll b_in, c_in;
		cin >> b_in >> c_in;
		p.push_back(make_pair(c_in, b_in));
	}
	
	sort(ALL(p));
	reverse(ALL(p));
	
	priority_queue<ll> pq2;
	ll cnt = 0;
	for (auto &t: p) {
		ll v = t.first;
		ll num = t.second;
		rep(i, num) {
			pq2.push(v);
			cnt++;
		}
		if (cnt > n) {
			break;
		}
	}
//	rep(i, m) {
//		ll b, c;
//		cin >> b >> c;
//		rep(j, b) {
//			pq2.push(c);
//		}
//
//		if (cnt > n)
//			break;
//		cnt++;
//	}
	
	ll sum = 0;
	rep(i, n) {
		if (pq1.empty()) {
			sum += pq2.top();
			pq2.pop();
		} else if (pq2.empty()) {
			sum += pq1.top();
			pq1.pop();
		} else {
			if (pq1.top() >= pq2.top()) {
				sum += pq1.top();
				pq1.pop();
			} else {
				sum += pq2.top();
				pq2.pop();
			}
		}
//		cout << sum << endl;
	}
	
	cout << sum << endl;
	
	return 0;
}