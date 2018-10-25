#include <iostream>

using namespace std;

int prime[55555];
bool is_prime[55556];

int main(void) {
    int p = 0;
    for (int i = 0; i <= 55555; ++i) {
        is_prime[i] = true;
    }
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= 55555; ++i) {
        if (is_prime[i]) {
            prime[p++] = i;
            for (int j = 2 * i; j <= 55555; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int N;
    cin >> N;
    int pos = 0;
    for (int i = 0; i < N; ++i) {
        if (i != 0) {
            cout << " ";
        }
        while (prime[pos] % 5 != 1) {
            pos++;
        }
        cout << prime[pos];
        pos++;
    }
    return 0;
}