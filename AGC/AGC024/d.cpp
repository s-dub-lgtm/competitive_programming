#include <iostream>

using namespace std;

int main(void) {
    int N;
    cin>>N;
    int d[N+1] = {}; // 頂点の次数
    for (int i = 0; i < N - 1; ++i) {
        int a,b;
        cin>>a>>b;
        d[a]++, d[b]++;
    }

    bool dim[100];
    for (int i = 0; i < 100; ++i) {
        dim[i] = false;
    }

    for (int i = 1; i <= N; ++i) {
        dim[d[i]] = true;
    }

    int leaf = 0;
    int color = 0;
    return 0;
}