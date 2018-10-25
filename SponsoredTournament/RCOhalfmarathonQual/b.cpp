#include <iostream>

using namespace std;

int r[16000];
int c[16000];

int main(void) {
    int H, W, D, K;
    cin >> H >> W >> D >> K;
    for (int i = 0; i < D; ++i) {
        cin >> r[i] >> c[i];
    }

    bool upper=true,left=true;
    if((H-1-r[0])/2<(H/2)){
        upper = false;
    }
    if((W-1-c[0])/2<(W/2)) {
        left = false;
    }
    for (int i = 0; i < K; ++i) {
        if(upper&&left){

        }
    }

    return 0;
}