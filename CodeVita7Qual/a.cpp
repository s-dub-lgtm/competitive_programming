#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define FORE(i, a, b) for(int i=(a);i<=(b);++i)
#define rep(i, n) for(int i=0;i<(n);++i)
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
	double d;
	cin >> n >> d;
	vector<pair<double, int>> light_index;
	rep(i, n) {
		double light;
		cin >> light;
		light_index.push_back(make_pair(light, i));
	}
	
	sort(ALL(light_index));
	reverse(ALL(light_index));
	
	bool lightup[n];
	rep(i, n) {
		lightup[i] = false;
	}
	
	bool use[n];
	rep(i, n) {
		use[i] = false;
	}
	
	rep(i, n) {
		double light = light_index[i].first;
		int index = light_index[i].second;
//		cout << index << endl;
		if (light != 0) {
			use[index] = true;
			lightup[index] = true;
		}
		double half_light = light / 2;
		int cnt = 0;
		while (1) {
			if (half_light < d) break;
			cnt++;
			if (index - cnt >= 0) {
				lightup[index - cnt] = true;
			}
			if (index + cnt < n) {
				lightup[index + cnt] = true;
			}
			half_light -= d;
		}
		
		bool all_lightup = true;
		rep(j, n) {
			if (!lightup[j]) all_lightup = false;
		}
		if (all_lightup) {
			cout << i + 1 << endl;
			bool first = true;
			rep(j, n) {
				if (use[j]) {
					if (first) {
						cout << j + 1;
						first = false;
					} else {
						cout << " " << j + 1;
					}
				}
			}
			cout << endl;
			first = true;
			rep(j, n) {
				if (!use[j]) {
					if (first) {
						cout << j + 1;
						first = false;
					} else {
						cout << " " << j + 1;
					}
				}
				
			}
			cout << endl;
			return 0;
		}
	}
	
	cout << "INSUFFICIENT LAMPS" << endl;
	
	return 0;
}