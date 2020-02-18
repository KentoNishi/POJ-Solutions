// http://poj.org/problem?id=2785

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int N;
vector<vector<int>> vals;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    vals = vector<vector<int>>(4, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> vals[j][i];
        }
    }
    vector<int> sumsAB;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int a = vals[0][i];
            int b = vals[1][j];
            sumsAB.push_back(-(a + b));
        }
    }
    sort(sumsAB.begin(), sumsAB.end());
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int c = vals[2][i];
            int d = vals[3][j];
            vector<int>::iterator lower = lower_bound(sumsAB.begin(), sumsAB.end(), c + d);
            if (lower != sumsAB.end()) {
                vector<int>::iterator upper = upper_bound(sumsAB.begin(), sumsAB.end(), c + d);
                ans += distance(lower, upper);
            }
        }
    }
    cout << ans << endl;
    return 0;
}