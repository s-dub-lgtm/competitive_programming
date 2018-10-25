#include <iostream>
#include <cmath>

using namespace std;

// 入力
long long N;

int main(void) {
    cin >> N;

    long long tmp = N;
    int digit = 0;
    bool all_nine = true;
    bool only_last_not_nine = false;
    while (N != 0) {
        if (all_nine && N / 10 == 0) {
            only_last_not_nine = true;
        }
        if (N % 10 != 9) {
            all_nine = false;
        }
//        cout << N / 10 << endl;
        N /= 10;
        digit++;
    }
    N = tmp;


    int sum = 0;
    for (int i = 1; i < digit; ++i) {
        if (N % (long long) (pow(10, i)) == 9) {
            sum += 9;
        } else {
            sum += 9;
            N -= (long long) (pow(10, i));
        }
//        cout << i << endl;
//        cout << N << endl;
//        cout << sum << endl;
    }
    N = tmp;
    if (all_nine && N >= 100) {
        sum += N / (long long) (pow(10, digit - 1));
    } else if (all_nine) {
        sum += N / (long long) (pow(10, digit - 1));
    } else {
        sum += N / (long long) (pow(10, digit - 1)) - 1;
    }
//    cout << false << endl;
//    cout << only_last_not_nine << endl;
    if (!all_nine && only_last_not_nine) {
        sum++;
    }
    cout << sum << endl;
    return 0;
}