#include <iostream>

using namespace std;

int main(void) {
    long long N, C;
    cin >> N >> C;
    long long x[N + 1], v[N + 1];
    x[0] = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> x[i] >> v[i];
    }

    long long maxcalory = -1;
    long long calory = 0;
    long long point = 0;
//    long long rightpoint = 0, leftpoint = 0;
    for (int i = 0; i < N; ++i) {
        long long rightpoint = point, leftpoint = point;
        while (1) {
            if (rightpoint + 1 > N) {
                rightpoint = 1;
            } else {
                rightpoint = rightpoint + 1;
            }
            if (x[rightpoint] != -1) break;
            rightpoint++;
            if (rightpoint == N) break;
        }
        while (1) {
            if (leftpoint - 1 < 1) {
                leftpoint = N;
            } else {
                leftpoint = leftpoint - 1;
            }
            if (x[leftpoint] != -1) break;
            leftpoint--;
            if (leftpoint == 1) break;
        }
        if (rightpoint > leftpoint) break;
        cout << "p" << point << " " << rightpoint << " " << leftpoint << endl;

        long long right = v[rightpoint] - min(abs(x[rightpoint] - x[point]), abs(x[rightpoint] - x[point] - C));
        long long left = v[leftpoint] - min(abs(x[leftpoint] - x[point]), abs(x[leftpoint] - x[point] - C));
        cout << v[rightpoint] << " " << x[rightpoint] << " " << x[point];
        cout << right << " " << left << endl;
        if (right >= 0 && left >= 0) {
            if (abs(x[rightpoint] - x[point]) <= abs(x[leftpoint] - x[point])) {
                point = rightpoint;
                x[point] = -1;
                calory += right;
                maxcalory = max(maxcalory, calory);
            } else {
                point = leftpoint;
                x[point] = -1;
                calory += left;
                maxcalory = max(maxcalory, calory);
            }
        } else if (right >= 0 && left < 0) {
            point = rightpoint;
            x[point] = -1;
            calory += right;
            maxcalory = max(maxcalory, calory);
        } else if (right < 0 && left >= 0) {
            point = leftpoint;
            x[point] = -1;
            calory += left;
            maxcalory = max(maxcalory, calory);
        } else {
            if (abs(x[1] - point) <= abs(x[N] - point)) {
                point = rightpoint;
                x[point] = -1;
                calory += right;
                maxcalory = max(maxcalory, calory);
            } else {
                point = leftpoint;
                x[point] = -1;
                calory += left;
                maxcalory = max(maxcalory, calory);
            }
        }
        cout << maxcalory << " " << calory << endl;
        cout << point << " " << rightpoint << " " << leftpoint << endl;
    }

    cout << maxcalory << endl;

    return 0;
}