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

int board[3][3];
int b[3][3], c[3][3];

P dfs(int turn) {
	if (turn == 9) {
		int dai = 0, ko = 0;
		rep(i, 2)
			rep(j, 3) {
				if (board[i][j] == board[i + 1][j]) dai += b[i][j];
				else ko += b[i][j];
			}
		rep(i, 3)
			rep(j, 2) {
				if (board[i][j] == board[i][j + 1]) dai += c[i][j];
				else ko += c[i][j];
			}
		return P(dai, ko);
	}
	
	P best(-INF, -INF);
	rep(i, 3) rep(j, 3) {
			if (board[i][j] == 0) {
				board[i][j] = turn % 2 + 1;
				P tmp = dfs(turn + 1);
				board[i][j] = 0;
				if (turn % 2 == 0) {
					if (best.first < tmp.first) best = tmp;
				} else {
					if (best.second < tmp.second) best = tmp;
				}
			}
		}
	return best;
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	rep(i, 2)rep(j, 3) cin >> b[i][j];
	rep(i, 3)rep(j, 2) cin >> c[i][j];
	
	P p = dfs(0);
	cout << p.first << endl << p.second << endl;
	
	return 0;
}