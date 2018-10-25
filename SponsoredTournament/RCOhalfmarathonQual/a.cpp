#include <iostream>
#include <random>

using namespace std;

char row[100][50][50];

int main(void) {
    int N, K, H, W, T;
    cin >> N >> K >> H >> W >> T;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < H; ++j) {
            for (int k = 0; k < W; ++k) {
                cin >> row[i][j][k];
            }
        }
    }

    vector<int> M;
    int cnt=0;
    while(cnt<K){

    }

    for (int i = 0; i < T; ++i) {
        int direct = rand() % 4;
        switch (direct) {
            case 0 :
                cout << "U";
                break;
            case 1 :
                cout << "D";
                break;
            case 2 :
                cout << "L";
                break;
            case 3 :
                cout << "R";
                break;
        }
        if (i == T - 1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }

    return 0;
}