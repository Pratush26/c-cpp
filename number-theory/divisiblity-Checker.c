#include <stdio.h>
#include <string.h>

int main() {
    int n, res = 0, d = 3;
    scanf("%d", &n);
    char nums[n];
    scanf("%s", nums);
    for (int i = 0; i < strlen(nums); i++) {
        res = (nums[i]-48+res)%d;
    }
    if(res == 0) printf("YES");
    else printf("NO");
    return 0;
}