#include <iostream>
using namespace std;

void reverseArray (int arr[]) {
    int s = 0, e = 9;
    while (s < e) {
        e--;
        swap(arr[s], arr[e]);
        s++;
    }
}
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    reverseArray(arr);
    for (int i = 0; i < 9; i++) {
        cout <<  arr[i] << " ";
    }
    return 0;
}