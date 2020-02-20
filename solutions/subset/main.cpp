// http://poj.org/problem?id=3977

#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <vector>
using namespace std;

void set(long long &arr, long long bit) {
    arr = arr | (1 << bit);
}

void toggle(long long &arr, long long bit) {
    arr = arr ^ (1 << bit);
}

void clear(long long &arr, long long bit) {
    arr = arr & (~(1 << bit));
}

bool get(long long arr, long long bit) {
    return (arr & (1 << bit)) ? 1 : 0;
}

string bitStr(long long arr, long long digits = 0) {
    string s = "";
    long long current = 1;
    long long digit = 0;
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

pair<long long, long long> findClosest(map<long long, long long> &items, long long num) {
    map<long long, long long>::iterator it = items.lower_bound(num);
    pair<long long, long long> ans;
    if (it == items.end()) {
        ans = make_pair(numeric_limits<long long>::max(), 0);
    } else {
        ans = *it;
    }
    if (it != items.begin()) {
        it--;
        if (absVal(it->first - num) < absVal(ans.first - num) || (absVal(it->first - num) == absVal(ans.first - num) && it->second < ans.second)) {
            ans = *it;
        }
        it++;
    }
    it++;
    if (it != items.end()) {
        if (absVal(it->first - num) < absVal(ans.first - num) || (absVal(it->first - num) == absVal(ans.first - num) && it->second < ans.second)) {
            ans = *it;
        }
    }
    return ans;
}

pair<long long, long long> tryZeros(map<long long, long long> &possibleOnLeft, map<long long, long long> &possibleOnRight) {
    pair<long long, long long> ans = findClosest(possibleOnLeft, 0);
    ans.first = absVal(ans.first);
    pair<long long, long long> right = findClosest(possibleOnRight, 0);
    if (absVal(right.first) < absVal(ans.first) || (absVal(right.first) == absVal(ans.first) && right.second < ans.second)) {
        ans.first = absVal(right.first);
        ans.second = right.second;
    }
    return ans;
}

void solve(long long N, vector<long long> &nums) {
    long long leftSize = N / 2;
    long long rightSize = N - leftSize;
    map<long long, long long> possibleOnLeft;
    for (long long bits = 1; bits < (1 << leftSize); bits++) {
        long long used = 0;
        long long sum = 0;
        for (long long i = 0; i < leftSize; i++) {
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
    map<long long, long long> possibleOnRight;
    for (long long bits = 1; bits < (1 << rightSize); bits++) {
        long long used = 0;
        long long sum = 0;
        for (long long i = 0; i < rightSize; i++) {
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
    pair<long long, long long> ans = tryZeros(possibleOnLeft, possibleOnRight);
    for (map<long long, long long>::iterator it = possibleOnRight.begin(); it != possibleOnRight.end(); it++) {
        pair<long long, long long> right = *it;
        pair<long long, long long> left = findClosest(possibleOnLeft, -right.first);
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
    long long N;
    while (cin >> N) {
        if (N == 0) {
            break;
        }
        vector<long long> nums = vector<long long>(N);
        for (long long i = 0; i < N; i++) {
            cin >> nums[i];
        }
        if (N == 1) {
            cout << absVal(nums[0]) << " " << 1 << endl;
            continue;
        }
        solve(N, nums);
    }
    return 0;
}