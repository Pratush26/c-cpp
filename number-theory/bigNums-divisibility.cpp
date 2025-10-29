#include <iostream>
using namespace std;

bool modCheck(const string &s, int mod) {
    int r = 0;
    for (char c : s)
    r = (r * 10 + (c - '0')) % mod;
    return r == 0;
}

int main() {
    int target;
    string y;
    cin >> y >> target;
    cout << modCheck(y, target);
    return 0;
}