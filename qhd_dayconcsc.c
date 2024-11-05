#include<stdio.h>
void DP(int a[], int s[], int n) {
    s[0] = 0;
    s[1] = 0;
    for(int i = 2; i < n; i++) {
        if (a[i] - a[i-1] == 1 && a[i-1] - a[i-2] == 1) {
            if (s[i-1] == 0) {
                s[i] = 3;
            }
            else {
                s[i] = s[i-1] + 1;
            }
        }
        else {
            s[i] = 0;
        }
    }
    int max = -1e9;
    int index;
    for(int i = 0; i < n; i++) {
        printf("s[%d] co gia tri %d\n", i, s[i]);
        if (s[i] > max) {
            max = s[i];
            index = i;
        }
    }
    int check;
    for(int i = index; i >= 0 ; i--) {
        if (s[i] == 0) {
            check = i;
            break;
        }
    }
    for(int i = check-1; i <= index; i++) {
        printf("%d ", a[i]);
    }
    printf("Do dai csc lon nhat la : %d", max);
}
int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    int s[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    DP(a,s,n);
    return 0;
}