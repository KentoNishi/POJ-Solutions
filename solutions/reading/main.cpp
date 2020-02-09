// http://poj.org/problem?id=3320

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> pages = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> pages[i];
    }
    set<int> allTopics;
    for (int i = 0; i < N; i++) {
        allTopics.insert(pages[i]);
    }
    int numTopics = allTopics.size();
    map<int, int> windowTopics;
    int left = 0;
    int right = 0;
    windowTopics[pages[0]]++;
    int ans = N;
    while (left < N) {
        while (right < N - 1 && windowTopics.size() != numTopics) {
            right++;
            windowTopics[pages[right]]++;
        }
        if (windowTopics.size() == numTopics) {
            cout << left << " " << right << endl;
            ans = min(ans, right - left + 1);
        }
        windowTopics[pages[left]]--;
        if (windowTopics[pages[left]] == 0) {
            windowTopics.erase(pages[left]);
        }
        left++;
    }
    cout << ans << endl;
    return 0;
}