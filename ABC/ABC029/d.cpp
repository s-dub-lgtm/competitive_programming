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

int cnt(int x){
	int res=0;
	while(x){
		if(x%10==1) res++;
		x /= 10;
	}
	return res;
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	ll ans = 0;
	ll digit = 1;
	while (n) {
		ans += (n+9)/10 * digit;
		while(n%10 != 9 && n){
			ans += cnt(n/10)*digit;
			--n;
		}
		n /= 10;
		digit *= 10;
	}
	
	cout << ans << endl;
	
	return 0;
}