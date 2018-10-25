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
	
	ll n;
	cin >> n;
	
	if (n == 0) {
		cout << 0 << endl;
		return 0;
	}
	
	ll s[40];
	REP(i, 40) {
		s[i] = (ll) pow(-2, i);
//		cout << s[i] << endl;
	}
	
	bool ans[40];
	REP(i, 40) ans[i] = false;
	
	if (n % 2 == 1 || n % 2 == -1) {
		ans[0] = true;
		n -= 1;
	}
	cout << n % 2 << endl;
	cout << n << endl;
	
	
	if (n > 0) {
		for (int i = 39; i >= 0; --i) {
			if (i % 2 == 0) {
				if (n > s[i]) {
					cout << s[i] << endl;
					ans[i] = true;
					n -= s[i];
				}
			}
			if (n <= 0) break;
		}
		cout << n << endl;
		return 0;
		/*
		if(n < 0){
			for (int i=1;i<40;++i){
				if(i%2==1){
					if(n<s[i]){
						ans[i]=true;
						n-=s[i];
					}
				}
			}
		}
		*/
	}
	for (int i = 39; i >= 0; --i) {
		if (n == s[i]) {
			ans[i] = true;
			break;
		}
		
		if (i % 2 == 1) {
			if (n < s[i]) {
				cout << i << endl;
				ans[i] = true;
				n -= s[i];
			} else {
				if (i > 2 && n > s[i - 2]) {
					ans[i - 1] = true;
					n -= s[i];
				}
			}
		} else {
			if (n > s[i]) {
				cout << i << endl;
				ans[i] = true;
				n -= s[i];
			} else {
				if (i > 2 && n < s[i - 2]) {
					ans[i - 1] = true;
					n -= s[i];
				}
			}
		}
	}
	
	int endIndex;
	REP(i, 40) {
		if (ans[i]) endIndex = i;
	}
	
	for (int i = endIndex; i >= 0; --i) {
		if (ans[i]) cout << 1;
		else cout << 0;
	}
	cout << endl;
	
	return 0;
}