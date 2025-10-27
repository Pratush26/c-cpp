#include <iostream>
using namespace std;

int gcd (int a, int b) {
    if(b == 0) return a;
    return gcd (b, a%b);
}
int main() {
    int n, a, b;\
    
    cin >>  n;
    while (n--) {
        cout <<  "Enter two number : ";
        cin >>  a >> b;
        cout << "Great Common Divisor:" << gcd(a, b) << "\n";
        cout << "Least Common Multiple:" << a*b/gcd(a, b) << "\n";
    }
    return 0;
}