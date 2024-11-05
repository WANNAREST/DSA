#include<stdio.h>
void DP(int a[], int s[],int n){
    s[0] = 0;
    for(int i = 1; i <= n-1; i++) {
        if (a[i] > a[i-1]) {
            if (s[i-1] == 0) s[i] = 2;
            else s[i] = s[i-1] + 1;
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
    for(int i = check; i <= index; i++) {
        printf("%d ", a[i]);
    }
    printf("Do dai day tang la : %d", max);
}
int main(){
     int n;
     printf("Nhap do dai day : ");
     scanf("%d", &n);
     int a[n];
     int s[n];
     printf("Nhap cac phan tu: \n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    // for(int i = 0; i < n; i++) {
    //     printf("a[%d] co gia tri %d\n", i, a[i]);
    // }
    DP(a,s,n);
    return 0;
}