#include <string>
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