#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin(),(v).end()

typedef pair<string, string> P;

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
	P time[n];
	REP(i, n) {
		string s;
		cin >> s;
		string start = s.substr(0, 4);
		if (start[3] != '0' && start[3] != '5') {
			if (start[3] < '5') {
				start[3] = '0';
			} else {
				start[3] = '5';
			}
		}
		string end = s.substr(5, 4);
		if (end[3] != '0' && end[3] != '5') {
			if (end[3] < '5') {
				end[3] = '5';
			} else {
				end[3] = '0';
				end[2] += 1;
				if (end[2] == '6') {
					end[2] = '0';
					if (end[1] == '9') {
						end[1] = '0';
						end[0] += 1;
					} else {
						end[1] += 1;
					}
				}
			}
		}
		time[i].first = start, time[i].second = end;
//		cout << time[i].first << " " << time[i].second << endl;
	}
	
	sort(time, time + n);
//	REP(i, n) cout << time[i].first << "-" << time[i].second << endl;
	
	if (n == 1) {
		cout << time[0].first << "-" << time[0].second << endl;
		return 0;
	}
	
	string startTime = time[0].first;
	string endTime = time[0].second;
	FOR(i, 1, n) {
		if (time[i].first <= endTime) {
//			cout << "1" << endl;
			chmax(endTime, time[i].second);
			if (i == n - 1) {
				cout << startTime << "-" << endTime << endl;
			}
		} else {
//			cout << "2" << endl;
			cout << startTime << "-" << endTime << endl;
			startTime = time[i].first;
			endTime = time[i].second;
			if (i == n - 1) {
				cout << startTime << "-" << endTime << endl;
			}
		}
	}
	
	return 0;
}