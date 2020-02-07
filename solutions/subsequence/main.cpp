// http://poj.org/problem?id=3061

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int ans(int N, int S, vector<int> nums) {
    vector<int> sums = vector<int>(N + 1);
    for (int i = 0; i < N; i++) {
        sums[i + 1] = sums[i] + nums[i];
    }
    if (sums[N] - sums[0] < S) {
        return 0;
    }
    int left = 0, right = 0;
    int ans = N;
    while (left <= N) {
        while (right <= N && sums[right] - sums[left] < S) {
            right++;
        }
        if (right > N) {
            right = N;
        }
        if (sums[right] - sums[left] >= S) {
            ans = min(ans, right - left);
        }
        left++;
    }
    return ans;
}

int main() {
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int N, S;
        cin >> N >> S;
        vector<int> nums = vector<int>(N);
        for (int j = 0; j < N; j++) {
            cin >> nums[j];
        }
        cout << ans(N, S, nums) << endl;
    }
    return 0;
}