#include <bits/stdc++.h>

using namespace std;

//using ll = long long;

#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin(),(v).end()

typedef pair<int, int> P;

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
	cin>>n;
	int a[2][n];
	REP(i,2){
		REP(j, n){
			cin>>a[i][j];
		}
	}
	
	int maxsum=0;
	maxsum+=a[0][0];
	REP(i,n) maxsum+=a[1][i];
	
	int sum=maxsum;
	REP(i,n-1){
		sum-=a[1][i];
		sum+=a[0][i+1];
		chmax(maxsum, sum);
	}
	
	cout<<maxsum<<endl;
	
	return 0;
}