#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, n, p;
    cin >> n;
    while (n--) {
        cin >> a;
        p = 0;
        if(a == 0 || a == 1 || a == -1) {
            cout << a << " nao eh primo" << "\n";
            continue;
        }
        for (int i = 2; i*i <= a; i++) {
            if(a%i==0) {
                cout << a << " nao eh primo" << "\n";
                p++;
                break;
            }
        }
        if(!p) cout << a << " eh primo" << "\n";
    }
    return 0;
}