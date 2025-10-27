#include <iostream>
using namespace std;

int main() {
    int a, n;
    cin >> n;
    while (n--) {
        cin >> a;
        for (int i = 1; i*i <= a; i++) {
            if(a/i == i) cout << i;
            else if(a%i == 0) cout << i << " " << a/i << " ";
        }
        cout << "\n";
    }
    return 0;
}