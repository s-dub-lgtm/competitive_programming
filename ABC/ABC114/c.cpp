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

vector<ll> memo;
vector<int> candidate = {3, 5, 7};

void make_candidate(int digit, ll num) {
	if (digit == 0) {
		memo.push_back(num);
	} else {
		for (auto &n: candidate) {
			make_candidate(digit - 1, num * 10 + n);
		}
	}
}


int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	ll n;
	cin >> n;
	ll tmp = n;
	
	int digit = 0;
	while (n > 0) {
		digit++;
		n /= 10;
	}
//	cout << digit << endl;
	n = tmp;
	
	FORE(i, 3, digit) {
		make_candidate(i, 0);
	}
	
	int cnt = 0;
	rep(i, memo.size()) {
		if (memo[i] > n) break;
		bool three = false, five = false, seven = false;
		while (memo[i] > 0) {
			if (memo[i] % 10 == 3) three = true;
			else if (memo[i] % 10 == 5) five = true;
			else seven = true;
			memo[i] /= 10;
		}
		if (three && five && seven) cnt++;
	}
	
	cout << cnt << endl;
	
	return 0;
}