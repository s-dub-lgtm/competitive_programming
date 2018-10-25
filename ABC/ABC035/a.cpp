#include <iostream>

using namespace std;

int main(void) {
    int W, H;
    cin >> W >> H;

    if (W / 4 == H / 3) cout << "4:3" << endl;
    else cout << "16:9" << endl;
    return 0;
}