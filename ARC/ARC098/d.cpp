#include <iostream>
#include <cmath>

using namespace std;

int N;
long long A[200001];

int binary(int bina) {
    int ans = 0;
    for (int i = 0; bina > 0; i++) {
        ans = ans + (bina % 2) * pow(10, i);
        bina = bina / 2;
    }
    return ans;
}

/*
bool alldif(int l, int r) {
    bool allzero = true;
    for (int i = l; i <= r; ++i) {
        if (A[i] != 0) {
            allzero = false;
            break;
        }
    }
    if (allzero) return true;
    bool dif = true;
    long long sum = A[l];
//    cout << sum << endl;
    for (int i = l + 1; i <= r; ++i) {
        long long b = A[i];
        long long c = sum;
        while (b != 0 && c != 0) {
//            cout << b << endl;
            if (b % 10 == 1 && c % 10 == 1) {
                dif = false;
                break;
            }
            c /= 10;
            b /= 10;
        }
        if (!dif) break;
        sum += A[i];
    }
    return dif;
}
 */

int main(void) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        int a;
        scanf("%d", &a);
        A[i] = binary(a);
    }

    long long cnt = N;
    for (int l = 0; l < N; ++l) {
//        cout << "cnt" << cnt << endl;
        int r = 1;
        bool sum[30] = {};
        for (int i = 0; i < 30; ++i) {
            sum[i] = (bool) (A[l] % 10);
            A[l] /= 10;
        }
//        long long sum = A[l];
        bool alldif = true;
        while (alldif) {
//            cout << "alldif" << endl;
            if (l + r < N) {
                long long b = A[l + r];
//                long long c = sum;
                bool dif = true;
                /*
                while (b != 0 && c != 0) {
//            cout << b << endl;
                    if (b % 10 == 1 && c % 10 == 1) {
                        dif = false;
                        break;
                    }
                    c /= 10;
                    b /= 10;
                }
                 */
                for (int i = 0; i < 30; ++i) {
                    if (b == 0) break;
                    if (b % 10 == 1 && sum[i] == 1) {
                        dif = false;
                        break;
                    }
                    sum[i] = b % 10;
                    b /= 10;
                }
//                if ((b xor c) != (b + c)) dif = false;
                if (!dif) break;
//                sum += A[l + r];
                cnt++;
            } else {
                break;
            }
            r++;
        }
    }

    cout << cnt << endl;
    return 0;
}