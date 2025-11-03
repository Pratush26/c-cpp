#include <stdio.h>

int main() {
    int arr[9] = {2,5,4,7,2,1,9,8,6}, l = sizeof(arr)/sizeof(arr[0]), temp;
    for (int i = 0; i < l; i++) {
        for (int j = i+1; j < l; j++) {
            if(arr[i] > arr[j]){
             temp = arr[i];
             arr[i] = arr[j];
             arr[j] = temp;   
            }
        }        
        printf("%d ", arr[i]);
    }
    return 0;
}