#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define FORE(i, a, b) for(int i=(a);i<=(b);++i)
#define rep(i, n) for(int i=0;i<(n);++i)
#define repr(i, n) for(int i=0;i<=(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define SP cout<<fixed<<setprecision(10)
typedef pair<int, int> P;
const int INF = (int) 1e9;
const int MOD = (int) 1e9 + 7;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int Deg, Dis;
	cin >> Deg >> Dis;
	int t = int(Dis * 10. / 60. + .5000000001);
	int v[] = {2, 15, 33, 54, 79, 107, 138, 171, 207, 244, 284, 326};
	int s;
	for (s = 0; s < 12; s++)
		if (t <= v[s])
			break;
	const char *d[] = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW",
	                   "NNW", "N"};
	cout << (s == 0 ? "C" : d[(Deg * 10 + 1124) / 2250]) << " " << s << endl;
	
	return 0;
}