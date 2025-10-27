#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    printf("Pattern - 1 (increasing)\n");
    // *
    // * *
    // * * *
    // * * * *
    // * * * * *
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++) printf("* ");
        printf("\n");
    }
    printf("Pattern - 2 (decreasing)\n");
    // * * * * *
    // * * * *
    // * * *
    // * *
    // *
    for (int i = n; i >= 0; i--)
    {
        for (int j = 0; j < i; j++) printf("* ");
        printf("\n");
    }  
    printf("Pattern - 3 (pyramid)\n");
    //         *
    //       * * *
    //     * * * * *
    //   * * * * * * *
    // * * * * * * * * *
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < n-i; j++) printf("  ");
        for (int j = 0; j < 2*i-1; j++) printf("* ");
        printf("\n");
    }  
    printf("Pattern - 4 (rotated-square)\n");
    //         *
    //       * * *
    //     * * * * *
    //   * * * * * * *
    // * * * * * * * * *
    return 0;
}