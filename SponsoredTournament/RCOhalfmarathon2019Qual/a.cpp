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
	
	int n;
	cin >> n;
	double x[n], y[n];
	rep(i, n) cin >> x[i] >> y[i];
	
	vector<tuple<double, int, int>> d;
	vector<double> distance;
	rep(i, n) {
		rep(j, n) {
			if (i != j) {
				d.push_back(make_tuple(sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2)), i, j));
				distance.push_back(sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2)));
			}
		}
	}
	
	sort(ALL(d));
	sort(ALL(distance));
//	reverse(ALL(d));
//	cout << "sort" << endl;
	double average = accumulate(distance.begin(), distance.end(), 0) / distance.size();
	int averageindex = lower_bound(ALL(distance), average) - distance.begin();
	
	vector<int> ans;
	bool path[n];
	rep(i, n) path[i] = false;
	int start1 = get<1>(d[averageindex]), start2 = get<2>(d[averageindex]);
	path[start1] = true, path[start2] = true;
	d.erase(d.begin());
	int cnt = 1;
	int index = averageindex;
	int plusminus = -1;
	rep (i, (n * n - n) / 2 - 1) {
		index = index + plusminus;
		int one = get<1>(d[index]), two = get<2>(d[index]);
//		cout << one << " " << two << endl;
		if (path[one] and not path[two]) {
//			cout << "two" << endl;
			path[two] = true;
			if (cnt == 1) {
				if (one == start1) {
					ans.push_back(start2);
				} else { // one==start2
					ans.push_back(start1);
				}
				ans.push_back(one);
			}
			ans.push_back(two);
			cnt++;
		} else if (not path[one] and path[two]) {
//			cout << "one" << endl;
			path[one] = true;
			if (cnt == 1) {
				if (two == start1) {
					ans.push_back(start2);
				} else { // two==start2
					ans.push_back(start1);
				}
				ans.push_back(two);
			}
			ans.push_back(one);
			cnt++;
		}
		if (cnt == n - 1) {
			for (auto &c: ans) {
				cout << c << endl;
			}
			break;
		}
		if (plusminus < 0) {
			plusminus = -1 * plusminus + 1;
		} else {
			plusminus = -1 * plusminus - 1;
		}
	}
	
	return 0;
}