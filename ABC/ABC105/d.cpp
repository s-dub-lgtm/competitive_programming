#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define SP cout<<fixed<<setprecision(10)

typedef pair<int, int> P;

const int INF = (int) 1e9;
const int MOD = (int) 1e9 + 7;

template<class T>
bool chmax(T &a, const T &b) {
	if (a < b) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T>
bool chmin(T &a, const T &b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	int a[n];
	REP(i, n) cin >> a[i];
	
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		int sum = 0;
		for (int j = i; j < n; ++j) {
			sum += a[j] % m;
			if (sum % m == 0) {
				cout << sum << endl;
				cout << i << " " << j << endl;
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	
	int sum = 0;
	REP(i, n) {
		cout << a[i] % m << " ";
		sum += a[i] % m;
		cout << sum << " ";
		if (sum % m == 0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	return 0;
}