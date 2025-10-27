#include <iostream>
#include <vector>
using namespace std;

int BinarySearch (vector<int> arr, int t) {
    int s = 0, e = arr.size()-1, mid;
    while (s<=e) {
        mid = s + (e-s)/2;
        if(t>arr[mid]) s = mid + 1;
        else if(t<arr[mid]) e = mid - 1;
        else return mid;
    }
    return -1;
}
int main() {
    vector<int> test1 = {-1, 0, 3, 4, 5, 9, 12};
    int target1 = 12;
    vector<int> test2 = {-1, 0, 3, 5, 9, 12};
    int target2 = 0;
    cout <<  BinarySearch(test1, target1) << "\n";
    cout <<  BinarySearch(test2, target2) << "\n";
    return 0;
}