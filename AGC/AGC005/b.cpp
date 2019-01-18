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
const int inf = (int) 1e9;
const int mod = (int) 1e9 + 7;

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
	
	int n;
	cin >> n;
	ll a[n];
	int pos[n];
	rep(i, n) {
		cin >> a[i];
		pos[a[i] - 1] = i;
	}
	
	set<int> st;
	st.insert(-1);
	st.insert(n);
	
	ll sum = 0;
	rep(i, n) {
		auto iter = st.lower_bound(pos[i]);
		ll right = (*iter) - pos[i];
		iter--;
		ll left = pos[i] - (*iter);
		sum += a[pos[i]] * left * right;
		st.insert(pos[i]);
	}
	
	cout << sum << endl;
	
	return 0;
}