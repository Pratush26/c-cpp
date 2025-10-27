#include <iostream>
using namespace std;
void halfPattern (int i, int n) {
    int x = 0;
    for (int j = 0; j < i; j++) cout <<  "* ";
    for (int s = 0; s < 2*(n - i) - 1; s++) cout <<  "  ";
    if (i == n) x++;
    for (int j = x; j < i; j++) cout <<  "* ";
    cout <<  "\n";
}
int main() {
    int n;
    cin >>  n;
    n /= 2;
    for (int i = 1; i <= n; i++) halfPattern(i, n);
    for (int i = n; i > 0; i--) halfPattern(i, n);
    return 0;
}