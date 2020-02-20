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

map<long long, int>::iterator findClosest(map<long long, int> &sets, long long num) {
    map<long long, int>::iterator iter = sets.lower_bound(num);
    map<long long, int>::iterator ans = iter;
    if (iter != sets.begin()) {
        iter--;
        if (ans == sets.end() || absVal(iter->first - num) < absVal(ans->first - num)) {
            ans = iter;
        }
    }
    return ans;
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
        // cout << "===" << endl;
        if (N == 1) {
            cout << nums[0] << " " << 1 << endl;
        } else {
            int leftSize = N / 2;
            int rightSize = N - leftSize;
            map<long long, int> sets;
            for (int bits = 1; bits < (1 << leftSize); bits++) {
                int used = 0;
                long long sum = 0;
                for (int i = 0; i < leftSize; i++) {
                    if (get(bits, i)) {
                        sum += nums[i];
                        used++;
                    }
                }
                if (sets[sum] == 0) {
                    sets[sum] = used;
                } else {
                    sets[sum] = min(sets[sum], used);
                }
            }
            /*
            for (auto p : sets) {
                cout << p.first << "," << p.second << " ";
            }
            cout << endl;
            */
            pair<long long, int> ans = *findClosest(sets, 0);
            sets[0] = 0;
            for (int bits = 1; bits < (1 << rightSize); bits++) {
                int used = 0;
                long long sum = 0;
                for (int i = 0; i < rightSize; i++) {
                    if (get(bits, i)) {
                        sum += nums[leftSize + i];
                        used++;
                    }
                }
                pair<long long, int> closest = *findClosest(sets, -sum);
                // cout << "Closest to " << sum << " was " << closest.first << endl;
                if (absVal(closest.first + sum) < ans.first || (absVal(closest.first + sum) == ans.first && closest.second + used < ans.second)) {
                    ans.first = absVal(closest.first + sum);
                    ans.second = closest.second + used;
                }
            }
            cout << ans.first << " " << ans.second << endl;
        }
    }
    return 0;
}