// http://poj.org/problem?id=3276

#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int N;

int countFlips(vector<bool> line, int windowSize) {
    int flips = 0;
    bool flipped = false;
    vector<int> toFlip = vector<int>(N + 1);
    for (int i = 0; i < N; i++) {
        if (toFlip[i] % 2 == 1) {
            flipped = !flipped;
        }
        if (flipped) {
            line[i] = !line[i];
        }
        if (!line[i] && i + windowSize <= N) {
            line[i] = true;
            toFlip[i + windowSize]++;
            flipped = !flipped;
            flips++;
        }
    }
    for (int i = 0; i < N; i++) {
        if (!line[i]) {
            return -1;
        }
    }
    return flips;
}

int main() {
    vector<bool> line;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    line.resize(N);
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        line[i] = c == 'F';
    }
    pair<int, int> ans = make_pair(0, N);
    for (int i = 1; i <= N; i++) {
        int flips = countFlips(line, i);
        if (flips >= 0 && flips < ans.second) {
            ans.first = i;
            ans.second = flips;
        }
    }
    cout << ans.first << " " << ans.second << endl;
    return 0;
}