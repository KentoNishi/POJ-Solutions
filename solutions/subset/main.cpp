// http://poj.org/problem?id=3977

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void set(int &arr, int bit) {
    arr = arr | (1 << bit);
}

void toggle(int &arr, int bit) {
    arr = arr ^ (1 << bit);
}

void clear(int &arr, int bit) {
    arr = arr & (~(1 << bit));
}

bool get(int arr, int bit) {
    return (arr & (1 << bit)) ? 1 : 0;
}

string bitStr(int arr, int digits = 0) {
    string s = "";
    int current = 1;
    int digit = 0;
    while ((digits == 0 && current <= arr) || digit < digits) {
        current *= 2;
        s = (get(arr, digit) ? "1" : "0") + s;
        digit++;
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (true) {
        int N;
        cin >> N;
        if (N == 0) {
            break;
        }
        vector<int> nums = vector<int>(N);
        for (int i = 0; i < N; i++) {
            cin >> nums[i];
        }
        int leftSize = N / 2;
        vector<pair<int, int>> leftSums;
        for (int left = 0; left < pow(2.0, leftSize); left++) {
            long long sum = 0;
            int used = 0;
            for (int i = 0; i < leftSize; i++) {
                if (get(left, i)) {
                    used++;
                    sum += nums[i];
                }
            }
            leftSums.push_back(make_pair(sum, used));
        }
        sort(leftSums.begin(), leftSums.end());
        for (int right = pow(2.0, leftSize); right < N; right++) {
            long long sum = 0;
            for (int i = leftSize; i < N; i++) {
                if (get(right, i)) {
                    sum += nums[i];
                }
            }
            vector<pair<int, int>>::iterator lowerBound = lower_bound(leftSums.begin(), leftSums.end(), make_pair(-sum, numeric_limits<long long>::min()));
            if (lowerBound != leftSums.end()) {
            }
        }
    }
    return 0;
}