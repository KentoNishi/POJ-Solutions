// url

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<double> cables;
int N, K;

bool test(double m) {
    int res = 0;
    for (int i = 0; i < N; i++) {
        res += (int)(cables[i] / m);
        if (res >= K) {
            return true;
        }
    }
    return res >= K;
}

void print(double num) {
    printf("%.2f\n", floor(num * 100) / 100.0);
}

int main() {
    cin >> N >> K;
    cables.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> cables[i];
    }
    double lower = 0;
    double upper = 100000;
    while (upper - lower >= 1e-3) {
        double mid = (lower + upper) / 2;
        if (test(mid)) {
            lower = mid;
        } else {
            upper = mid;
        }
    }
    print(upper);
    return 0;
}