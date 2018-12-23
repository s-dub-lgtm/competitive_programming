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

int a, b, c;

double f(double t) {
	return a * t + b * sin(c * t * M_PI);
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> a >> b >> c;
	
	double lb = 0.1, ub = 1000;
	
	rep(i, 1000) {
		double mid = (lb + ub) / 2;
		if (f(mid) < 100) lb = mid;
		else ub = mid;
	}
	
	SP;
	cout << ub << endl;
	
	return 0;
}