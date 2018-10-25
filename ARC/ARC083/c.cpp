#include <iostream>
#include <vector>

using namespace std;

// 入力
int A, B, C, D, E, F;

int main(void) {
    cin >> A >> B >> C >> D >> E >> F;

    vector<int> water;
    vector<int> sugar;

    for (int i = 0; i <= F / (100 * A); ++i) {
        for (int j = 0; j <= F / (100 * B); ++j) {
            water.push_back(100 * A * i + 100 * B * j);
        }
    }
    for (int i = 0; i <= F / C; ++i) {
        for (int j = 0; j <= F / D; ++j) {
            sugar.push_back(C * i + D * j);
        }
    }

//    for (int i = 0; i < water.size(); ++i) {
//        cout << water[i] << " ";
//    }
//    cout << endl;
//    for (int i = 0; i < sugar.size(); ++i) {
//        cout << sugar[i] << " ";
//    }
//    cout << endl;
    int maxSugarWaterWeight = 0, maxSugarWeight = 0;
    double maxConcentration = 0;
    for (int i = 0; i < water.size(); ++i) {
        for (int j = 0; j < sugar.size(); ++j) {
            int waterWeight = water[i];
            int sugarWeight = sugar[j];
            if (waterWeight + sugarWeight <= F) {
                if (waterWeight * ((double) (E) / 100) >= sugarWeight) {
                    if (waterWeight + sugarWeight != 0) {
                        double concentration = (double) (100 * sugarWeight) / (waterWeight + sugarWeight);
                        if (concentration >= maxConcentration) {
                            maxConcentration = concentration;
                            maxSugarWaterWeight = waterWeight + sugarWeight;
                            maxSugarWeight = sugarWeight;
                        }
                    }
                }
            }
        }
    }

    cout << maxSugarWaterWeight << " " << maxSugarWeight << endl;
    return 0;
}