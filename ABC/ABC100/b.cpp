#include <iostream>

using namespace std;

using ll = long long;

#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin(),(v).end()

typedef pair<int, int> P;

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
	
	int d, n;
	cin >> d >> n;
	
	if (d == 0) {
		if (n == 100) {
			cout << 101 << endl;
		} else {
			cout << n << endl;
		}
	}
	if (d == 1) {
		if (n == 100) {
			cout << 10100 << endl;
		} else {
			cout << 100 * n << endl;
		}
	}
	if (d == 2) {
		if (n == 100) {
			cout << 1010000 << endl;
		} else {
			cout << 10000 * n << endl;
		}
	}
	
	return 0;
}