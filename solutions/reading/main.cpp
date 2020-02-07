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
    set<int> allTopics;
    for (int i = 0; i < N; i++) {
        cin >> pages[i];
        allTopics.insert(pages[i]);
    }
    int numTopics = allTopics.size();
    int left = 0;
    int right = 0;
    int ans = N;
    map<int, int> topics;
    while (left < N) {
        while (right < N && topics.size() != numTopics) {
            topics[pages[right]]++;
            right++;
        }
        if (right == N && topics.size() != numTopics) {
            break;
        }
        right--;
        // cout << left << " - " << right << " has " << topics.size() << " topics" << endl;
        if (topics.size() == numTopics) {
            ans = min(ans, right - left + 1);
        }
        topics[pages[left]]--;
        if (topics[pages[left]] == 0) {
            topics.erase(pages[left]);
        }
        left++;
        right++;
    }
    cout << ans << endl;
    return 0;
}