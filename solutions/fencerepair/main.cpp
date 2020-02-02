// http://poj.org/problem?id=3253

#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    priority_queue<long long, vector<long long>, greater<long long>> lengths;
    int length = 0;
    for (int i = 0; i < N; i++) {
        long long a;
        cin >> a;
        lengths.emplace(a);
    }
    
    return 0;
}