#include <iostream>

using namespace std;

int main(void) {
    int N;
    cin >> N;

    int mod4cnt = 0;
    int mod2cnt = 0;
    int othercnt = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (a % 4 == 0) mod4cnt++;
        else if (a % 2 == 0) mod2cnt++;
        else othercnt++;
    }

    if ((mod4cnt + 1 >= othercnt && mod2cnt == 0) || (mod4cnt >= othercnt && mod2cnt >= 1)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}