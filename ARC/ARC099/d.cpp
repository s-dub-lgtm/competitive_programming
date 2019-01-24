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

ll s(ll n) {
	if (n == 0) return 0;
	return n % 10 + s(n / 10);
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	ll k;
	cin >> k;
	
	ll x=1;
	ll p=1;
	while(k>0){
		cout<<x<<endl;
		k--;
		ll nx1=x+p;
		ll nx2=x+p*10;
		if(nx1*s(nx2) <= nx2*s(nx1)){
			x = nx1;
		} else {
			x = nx2;
			p *= 10;
		}
	}
	
	return 0;
}