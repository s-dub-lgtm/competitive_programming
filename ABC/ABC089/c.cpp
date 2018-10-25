#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    long long m = 0, a = 0, r = 0, c = 0, h = 0;
    for (int i = 0; i < n; ++i) {
        switch (s[i][0]) {
            case 'M':
                m++;
                break;
            case 'A':
                a++;
                break;
            case 'R':
                r++;
                break;
            case 'C' :
                c++;
                break;
            case 'H' :
                h++;
                break;
        }
    }

    long long total = 0;
    total += m * a * r + m * a * c + m * a * h + m * r * c + m * r * h + m * c * h + a * r * c + a * r * h + a * c * h +
             r * c * h;
    cout << total << endl;
    return 0;
}