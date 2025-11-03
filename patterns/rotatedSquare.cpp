#include <iostream>
using namespace std;

int main()
{
  int n, odd = 1;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int s = 0; s < n - i - 1; s++) cout << " ";
    if (i != 0) {
      cout << "*";
      for (int s = 0; s < odd; s++) {
        cout << " ";
      }
      odd += 2;
    }
    cout << "*\n";
  }
  odd -= 4;
  for (int i = 1; i < n; i++) {
    for (int s = 0; s < i; s++) cout << " ";
    cout << "*";
    for (int s = 0; s < odd; s++) {
      cout << " ";
    }
    odd -= 2;
    if (i == n-1) continue;
    cout << "*\n";
  }
  return 0;
}