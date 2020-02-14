// http://poj.org/problem?id=3276

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<bool> line;
int N;

int countFlips(int windowSize) {
    int flips = 0;
    // window sliding
    // have a flag that reverses
    // until it hits a point
    // might work, might not, don't know yet
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    line.resize(N);
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        line[i] = c == 'F';
    }
    pair<int, int> ans = {0, INFINITY};
    for (int i = 1; i <= N; i++) {
        int flips = countFlips(i);
        if (flips >= 0 && flips < ans.second) {
            ans.first = i;
            ans.second = flips;
        }
    }
    cout << ans.first << " " << ans.second << endl;
    return 0;
}