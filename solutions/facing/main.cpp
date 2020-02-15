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
    // window sliding
    // have a flag that reverses
    // until it hits a point
    // might work, might not, don't know yet
    bool flipFlag = false;
    queue<int> flags;
    for (int i = 0; i <= N - windowSize; i++) {
        if (flags.size() > 0) {
            int top = flags.front();
            if (top == i) {
                flipFlag = !flipFlag;
                flags.pop();
            }
        }
        if (flipFlag) {
            line[i] = !line[i];
        }
        if (!line[i]) {
            if (i + windowSize <= N) {
                flipFlag = !flipFlag;
                line[i] = true;
                flags.push(i + windowSize);
                flips++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << line[i] << " ";
    }
    cout << endl;

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