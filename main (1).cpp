#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
void distributeApples() {
    vector<int> appleWeights;
    int weight;
    cout << "Enter apple weight in grams (-1 to stop): ";
    while (cin >> weight && weight != -1) {
        appleWeights.push_back(weight);
        cout << "Enter apple weight in grams (-1 to stop): ";
    }
    const int totalAmount = 100;
    const int ramAmount = 50;
    const int shamAmount = 30;
    const int rahimAmount = 20;
    int totalWeight = 0;
    for (int w : appleWeights) {
        totalWeight += w;
    }
    double ramTarget = (double)ramAmount / totalAmount * totalWeight;
    double shamTarget = (double)shamAmount / totalAmount * totalWeight;
    double rahimTarget = (double)rahimAmount / totalAmount * totalWeight;
    sort(appleWeights.rbegin(), appleWeights.rend());
    vector<int> ramApples;
    vector<int> shamApples;
    vector<int> rahimApples;

    double ramCurrent = 0;
    double shamCurrent = 0;
    double rahimCurrent = 0;
    for (int w : appleWeights) {
        if (ramCurrent + w <= ramTarget) {
            ramApples.push_back(w);
            ramCurrent += w;
        } else if (shamCurrent + w <= shamTarget) {
            shamApples.push_back(w);
            shamCurrent += w;
        } else if (rahimCurrent + w <= rahimTarget) {
            rahimApples.push_back(w);
            rahimCurrent += w;
        }
    }
    cout << "Distribution Result:" << endl;

    // Print Ram's apples
    cout << "Ram : ";
    for (size_t i = 0; i < ramApples.size(); ++i) {
        if (i > 0) cout << " ";
        cout << ramApples[i];
    }
    cout << endl;

    // Print Sham's apples
    cout << "Sham : ";
    for (size_t i = 0; i < shamApples.size(); ++i) {
        if (i > 0) cout << " , ";
        cout << shamApples[i];
    }
    cout << endl;

    // Print Rahim's apples
    cout << "Rahim : ";
    for (size_t i = 0; i < rahimApples.size(); ++i) {
        if (i > 0) cout << " , ";
        cout << rahimApples[i];
    }
    cout << endl;
}
int main() {
    distributeApples();
    return 0;
}
