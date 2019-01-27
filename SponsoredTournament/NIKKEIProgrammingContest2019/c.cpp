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
	/*
	int n;
	cin >> n;
	ll a[n], b[n];
	vector<pair<ll, int>> taka;
	vector<pair<ll, int>> aoki;
	priority_queue<ll> same;
	int takalesscnt = 0;
	int aokilesscnt = 0;
	int samecnt = 0;
	rep(i, n) {
		cin >> a[i] >> b[i];
		if (a[i] == b[i]) {
			same.push(a[i]);
			samecnt++;
		}
		taka.push_back(make_pair(a[i] - b[i], i));
		aoki.push_back(make_pair(b[i] - a[i], i));
		if (a[i] < b[i]) takalesscnt++;
		else if (a[i] > b[i]) aokilesscnt++;
	}
	cout << takalesscnt << " " << aokilesscnt << endl;
	
	sort(ALL(taka));
	sort(ALL(aoki));
	reverse(ALL(aoki));
	
	ll takasum = 0;
	ll aokisum = 0;
	
	while (1) {
		if (takalesscnt == 0) {
			cout << "taka" << endl;
			if (same.empty()) break;
			takasum += same.top();
			same.pop();
		} else {
			takalesscnt--;
		}
		
		if (aokilesscnt == 0) {
			cout << "aoki" << endl;
			if (same.empty()) break;
			aokisum += same.top();
			same.pop();
		} else {
			aokilesscnt--;
		}
	}
	cout << takasum << " " << aokisum << endl;
	cout << "flag" << endl;
	
	bool eat[n];
	rep(i, n) eat[i] = false;
	int takaindex = 0;
	int aokiindex = 0;
	rep(i, n) {
		if (i % 2 == 0) {
			while (eat[taka[takaindex].second]) {
				takaindex++;
			}
			if (taka[takaindex].first != 0) {
				eat[taka[takaindex].second] = true;
				takasum += a[taka[takaindex].second];
			}
		} else {
			while (eat[aoki[aokiindex].second]) {
				aokiindex++;
			}
			if (aoki[aokiindex].first != 0) {
				eat[aoki[aokiindex].second] = true;
				aokisum += b[aoki[aokiindex].second];
			}
		}
		cout << takasum << " " << aokisum << endl;
	}
	
	cout << takasum - aokisum << endl;
	*/
	
	int n;
	cin >> n;
	vector<tuple<ll, ll, int>> taka;
	vector<tuple<ll, ll, int>> aoki;
	rep(i, n) {
		ll a, b;
		cin >> a >> b;
		taka.push_back(make_tuple(a, b, i));
		aoki.push_back(make_tuple(b, a, i));
	}
	sort(ALL(taka));
	reverse(ALL(taka));
	sort(ALL(aoki));
	reverse(ALL(aoki));
	
	ll takasum = 0, aokisum = 0;
	bool eat[n];
	rep(i, n) eat[i] = false;
	int takaindex = 0;
	int aokiindex = 0;
	rep(i, n) {
		if (i % 2 == 0) {
			while (eat[get<2>(taka[takaindex])]) {
				takaindex++;
			}
			eat[get<2>(taka[takaindex])] = true;
			takasum += get<0>(taka[takaindex]);
		} else {
			while (eat[get<2>(aoki[aokiindex])]) {
				aokiindex++;
			}
			eat[get<2>(aoki[aokiindex])] = true;
			aokisum += get<0>(aoki[aokiindex]);
		}
//		cout << takasum << " " << aokisum << endl;
	}
	
	cout << takasum - aokisum << endl;
	
	return 0;
}