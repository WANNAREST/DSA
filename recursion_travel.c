#include <stdio.h>
#include <string.h>
#define MAXN 10000
int Xau(int *arr, int n) {
    int dp[MAXN] = {0}; 
    for (int i = n - 1; i >= 0; i--) {
        int prev = 0; 
        for (int j = i; j < n; j++) {
            int temp = dp[j]; 
            if (i == j) {
                dp[j] = 1; 
            } else if (arr[i] == arr[j]) {
                dp[j] = prev + 2; 
            } else {
                dp[j] = (dp[j] > dp[j-1]) ? dp[j] : dp[j-1]; 
            }
            prev = temp; 
        }
    }
    
    return dp[n-1];
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int result = Xau(arr, n);
    printf("%d\n", result);
    return 0;
}

