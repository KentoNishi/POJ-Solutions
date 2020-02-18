// url

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
    vector<map<int, int>> counts = vector<map<int, int>>(4);
    for (int i = 0; i < N; i++) {
        counts[0][vals[0][i]]++;
    }
    for (int slot = 1; slot < 4; slot++) {
        for (int choice = 0; choice < N; choice++) {
            for (map<int, int>::iterator it = counts[slot - 1].begin(); it != counts[slot - 1].end(); ++it) {
                pair<int, int> p = *it;
                int prevSum = p.first;
                int prevCount = p.second;
                int thisSum = prevSum + vals[slot][choice];
                counts[slot][thisSum] += prevCount;
            }
        }
    }
    cout << counts[3][0] << endl;
    return 0;
}