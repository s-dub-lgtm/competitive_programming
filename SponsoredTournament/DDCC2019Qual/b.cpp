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
	
	double n;
	cin >> n;
	
	
	double x = -100;
	double y = 100;
	cout << x << " " << y << endl;
	int cnt = 0;
	rep(i, n) {
		rep(j, n) {
			double x1 = x + (((double) (i)) * (100 / (n / 2)));
			double y1 = y - (((double) (j)) * (100 / (n / 2)));
			double x2 = x + (((double) (i + 1)) * (100 / (n / 2)));
			double y2 = y - (((double) (j)) * (100 / (n / 2)));
			double x3 = x + (((double) (i)) * (100 / (n / 2)));
			double y3 = y - (((double) (j + 1)) * (100 / (n / 2)));
			double x4 = x + (((double) (i + 1)) * (100 / (n / 2)));
			double y4 = y - (((double) (j + 1)) * (100 / (n / 2)));
			cout << x1 << y1 << x2 << y2 << x3 << y3 << x4 << y4 << endl;
			if ((y1 <= x1 + 100) and (y2 <= -x2 + 100) and (y3 >= -x3 - 100) and (y4 >= x4 - 100)) {
				cout << "true" << endl;
				cnt++;
			}
		}
	}
	
	cout << cnt << endl;
	
	return 0;
}