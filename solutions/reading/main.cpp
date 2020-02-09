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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> pages = vector<int>(N);
    set<int> allTopics;
    for (int i = 0; i < N; i++) {
        cin >> pages[i];
        allTopics.insert(pages[i]);
    }
    int numTopics = allTopics.size();
    map<int, int> topics;
    int left = 0;
    int right = 0;
    int ans = N;
    while (left < N) {
        // cout << left << "," << right << endl;
        while (right < N && topics.size() != numTopics) {
            topics[pages[right]]++;
            right++;
        }
        if (topics.size() == numTopics) {
            ans = min(ans, right - left);
        } else {
            break;
        }
        topics[pages[left]]--;
        if (topics[pages[left]] == 0) {
            topics.erase(pages[left]);
        }
        left++;
    }
    cout << ans << endl;
    return 0;
}