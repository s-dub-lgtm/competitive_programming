#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<bitset>

using namespace std;
typedef bitset<60000> bi;

bool get(vector<int> v, int t) {
	bi x;
	x[30000] = 1;
	for (int i = 0; i < v.size(); i++)x = (x << v[i]) | (x >> v[i]);
	return x[30000 + t];
}

int main() {
	string s;
	cin >> s;
	s.push_back('T');
	int x, y;
	scanf("%d%d", &x, &y);
	vector<int> v1, v2;
	int mode = -1;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'T') {
			if (mode == -1)mode = 1;
			else if (mode == 0)v1.push_back(cnt), mode = 1;
			else v2.push_back(cnt), mode = 0;
			cnt = 0;
		} else {
			if (mode == -1)x--;
			else cnt++;
		}
	}
	if (get(v1, x) && get(v2, y))printf("Yes\n");
	else printf("No\n");
}