#include <iostream>

using namespace std;

#define MAX_N 100000

// 入力
int n;
int a[MAX_N];

int main(void) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long sum1 = 0, sum2 = 0;
    bool positive1 = true, positive2 = false;
    long long opeNum1 = 0, opeNum2 = 0;
    for (int i = 0; i < n; ++i) {
//        cout << opeNum1 << " " << opeNum2 << endl;
        sum1 += a[i];
        if (positive1) {
            if (sum1 <= 0) {
                opeNum1 += abs(1 - sum1);
                sum1 = 1;
            }
            positive1 = false;
        } else {
            if (sum1 >= 0) {
                opeNum1 += abs(-1 - sum1);
                sum1 = -1;
            }
            positive1 = true;
        }

        sum2 += a[i];
        if (positive2) {
            if (sum2 <= 0) {
                opeNum2 += abs(1 - sum2);
                sum2 = 1;
            }
            positive2 = false;
        } else {
            if (sum2 >= 0) {
                opeNum2 += abs(-1 - sum2);
                sum2 = -1;
            }
            positive2 = true;
        }
    }

    cout << min(opeNum1, opeNum2) << endl;
    return 0;
}