#include <iostream>

using namespace std;

int main(void) {
    int A, B, C;
    cin >> A >> B >> C;

    int oA, oB, oC;
    if (A > B) {
        if (A > C) {
            oA = 1;
            if (B > C) {
                oB = 2, oC = 3;
            } else {
                oB = 3, oC = 2;
            }
        } else {
            oC = 1, oA = 2, oB = 3;
        }
    } else {
        if (A > C) {
            oB = 1, oA = 2, oC = 3;
        } else {
            oA = 3;
            if (B > C) {
                oB = 1, oC = 2;
            } else {
                oB = 2, oC = 1;
            }
        }
    }
    cout << oA << endl << oB << endl << oC << endl;
    return 0;
}