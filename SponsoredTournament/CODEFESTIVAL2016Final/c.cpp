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
const int inf = (int) 1e9;
const int mod = (int) 1e9 + 7;

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
	
	int n, m;
	cin >> n >> m;
	
	vector<int> can[n], lang[m];
	rep(i, n) {
		int k;
		cin >> k;
		rep(j, k) {
			int l;
			cin >> l;
			l--;
			can[i].push_back(l);
			lang[l].push_back(i);
		}
	}
	
	bool people[n], langs[m];
	memset(people,0, sizeof(people));
	memset(langs,0, sizeof(langs));
	queue<int> q;
	people[0]=true;
	for(int l: can[0]){
		langs[l]=true;
		q.push(l);
	}
	while(!q.empty()){
		int v=q.front();
		q.pop();
		for(int person: lang[v]){
			if(people[person]) continue;
			people[person]=true;
			for(int l:can[person]){
				if(langs[l]) continue;
				langs[l]=true;
				q.push(l);
			}
		}
	}
	
	rep(i,n){
		if(not people[i]){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	
	cout<<"YES"<<endl;
	
	return 0;
}