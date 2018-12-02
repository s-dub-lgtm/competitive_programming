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

map<ll, int> enumpr(ll n) {
	map<ll, int> v;
	
	for (int i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			v[i]++;
			n /= i;
		}
	}
	if (n > 1) v[n]++;
	return v;
}

vector<int> prime_cnt;
int cnt;

void just(int index, int sum) {
	if (sum > 75) return;
	if (index == prime_cnt.size()) {
		if (sum == 75) cnt++;
	} else {
		repe(i, prime_cnt[index]) {
			just(index + 1, sum * (i + 1));
		}
	}
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	ll n;
	cin >> n;
	
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	
	map<ll, int> memo;
	FORE(i, 2, n) {
		auto V = enumpr(i);
		for (auto &v: V) {
//			cout << v.first << " " << v.second << endl;
			memo[v.first] += v.second;
		}
	}
	for (auto &num: memo) {
//		cout << num.first << " " << num.second << endl;
		prime_cnt.push_back(num.second);
	}
	
	cnt = 0;
	just(0, 1);
	
	cout << cnt << endl;
	
	return 0;
}