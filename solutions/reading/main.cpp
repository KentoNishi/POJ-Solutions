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
    int P;
    cin >> P;
    vector<int> pages = vector<int>(P);
    set<int> bookTopics;
    for (int i = 0; i < P; i++) {
        cin >> pages[i];
        bookTopics.insert(pages[i]);
    }
    int numTopics = bookTopics.size();
    map<int, int> topics;
    int ans = P;
    int left = 0;
    int right = 0;
    while (left < P) {
        while (right < P && topics.size() < numTopics) {
            topics[pages[right]]++;
            right++;
        }
        if (right < P) {
            ans = min(ans, right - left + 1);
        } else {
            right = P - 1;
            topics[pages[right]]--;
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