// Test case path: [path]
// url

#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;

int N, K;

vector<int> lengths;

bool test(int num) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += lengths[i] / num;
        if (sum >= K) {
            return true;
        }
    }
    return sum >= K;
}

void printAsFloat(int num) {
    cout << num / 100 << "." << (num / 10) % 10 << num % 10 << endl;
}

int main() {
    cin >> N >> K;
    lengths = vector<int>(N);
    int lower = 1;
    int upper = 1000000;
    for (int i = 0; i < N; i++) {
        double a;
        cin >> a;
        lengths[i] = a * 100;
        upper = min(upper, lengths[i]);
    }
    while (lower < upper - 1) {
        int mid = (lower + upper) / 2;
        if (test(mid)) {
            lower = mid;
        } else {
            upper = mid;
        }
    }
    if (test(upper)) {
        printAsFloat(upper);
    } else {
        printAsFloat(lower);
    }
    return 0;
}