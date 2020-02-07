// http://poj.org/problem?id=3320

#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    int P;
    cin >> P;
    vector<int> pages = vector<int>(P);
    set<int> topics;
    for (int i = 0; i < P; i++) {
        cin >> pages[i];
        topics.insert(pages[i]);
    }
    int numTopics = topics.size();
    topics = set<int>();
    int ans = P;
    int left = 0;
    int right = 0;
    while (left < P) {
        while (right < P && topics.size() < numTopics) {
            topics.insert(pages[right]);
            right++;
        }
        if (right < P) {
            ans = min(ans, right - left);
        }
        topics.erase(pages[left]);
        left++;
    }
    cout << ans << endl;
    return 0;
}