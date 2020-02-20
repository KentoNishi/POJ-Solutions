// http://poj.org/problem?id=3977

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
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

// abs() with long long doesn't exist before C++ 11
long long absVal(long long num) {
    return num < 0 ? (-num) : num;
}

pair<long long, int> findClosest(map<long long, int> &items, int num) {
    map<long long, int>::iterator it = items.lower_bound(num);
    pair<long long, int> ans = *it;
    if (it != items.begin()) {
        it--;
        if (absVal(it->first - num) < absVal(ans.first - num) || (absVal(it->first - num) == absVal(ans.first - num) && it->second < ans.second)) {
            ans = *it;
        }
        it++;
    }
    if (it != items.end()) {
        it++;
        if (absVal(it->first - num) < absVal(ans.first - num) || (absVal(it->first - num) == absVal(ans.first - num) && it->second < ans.second)) {
            ans = *it;
        }
        it--;
    }
    return ans;
}

pair<long long, int> tryZeros(map<long long, int> &possibleOnLeft, map<long long, int> &possibleOnRight) {
    pair<long long, int> ans = findClosest(possibleOnLeft, 0);
    ans.first = absVal(ans.first);
    pair<long long, int> right = findClosest(possibleOnRight, 0);
    if (absVal(right.first) < absVal(ans.first) || (absVal(right.first) == absVal(ans.first) && right.second < ans.second)) {
        ans.first = absVal(right.first);
        ans.second = right.second;
    }
    return ans;
}

void solve(int N, vector<int> &nums) {
    int leftSize = N / 2;
    int rightSize = N - leftSize;
    map<long long, int> possibleOnLeft;
    for (int bits = 1; bits < (1 << leftSize); bits++) {
        int used = 0;
        long long sum = 0;
        for (int i = 0; i < leftSize; i++) {
            if (get(bits, i)) {
                used++;
                sum += nums[i];
            }
        }
        if (possibleOnLeft[sum] == 0) {
            possibleOnLeft[sum] = used;
        } else {
            possibleOnLeft[sum] = min(possibleOnLeft[sum], used);
        }
    }
    map<long long, int> possibleOnRight;
    for (int bits = 1; bits < (1 << rightSize); bits++) {
        int used = 0;
        long long sum = 0;
        for (int i = 0; i < rightSize; i++) {
            if (get(bits, i)) {
                used++;
                sum += nums[leftSize + i];
            }
        }
        if (possibleOnRight[sum] == 0) {
            possibleOnRight[sum] = used;
        } else {
            possibleOnRight[sum] = min(possibleOnRight[sum], used);
        }
    }
    pair<long long, int> ans = tryZeros(possibleOnLeft, possibleOnRight);
    for (map<long long, int>::iterator it = possibleOnRight.begin(); it != possibleOnRight.end(); it++) {
        pair<long long, int> right = *it;
        pair<long long, int> left = findClosest(possibleOnLeft, -right.first);
        if (absVal(right.first + left.first) < ans.first || (absVal(right.first + left.first) == ans.first && left.second + right.second < ans.second)) {
            ans.first = absVal(right.first + left.first);
            ans.second = left.second + right.second;
        }
    }
    cout << ans.first << " " << ans.second << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    while (cin >> N) {
        if (N == 0) {
            break;
        }
        vector<int> nums = vector<int>(N);
        for (int i = 0; i < N; i++) {
            cin >> nums[i];
        }
        if (N == 1) {
            cout << nums[0] << " " << 1 << endl;
            continue;
        }
        solve(N, nums);
    }
    return 0;
}