#include <iostream>
using namespace std;

int main() {
    int a, c, n;
    cin >>  n;
    while (n--) {
        cin >>  a;
        c = 0;
        for (int i = 2; i*i < a; i++) {
            if(a%i == 0){
                cout << "Not Prime\n";
                c++;
                break;
            }
        }
        if(c == 0) cout << "Prime\n";        
    }
    
    return 0;
}