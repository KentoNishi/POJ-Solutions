// http://poj.org/problem?id=3253

#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> lengths;
    lengths.resize(N);
    int length = 0;
    for (int i = 0; i < N; i++) {
        cin >> lengths[i];
        length += lengths[i];
    }
    sort(lengths.begin(), lengths.end(), greater<int>());
    long long cost = 0;
    for (int i = 0; i < N - 1; i++) {
        cost += length;
        length -= lengths[i];
    }
    cout << cost << endl;
    return 0;
}