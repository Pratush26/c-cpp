#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n+1];
    arr[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n-i; j++) printf("    ");
        arr[i] = 0;
        for (int j = i-1; j >= 0; j--) {
            if(j!=0) arr[j] = arr[j] + arr[j-1];
            printf("    %d   ", arr[j]);
        }
        printf("\n");
    }
    return 0;
}