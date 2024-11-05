#include<stdio.h>
int main(){
    int n, Q;
    scanf("%d%d", &n, &Q);
    int a[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int start = 0;
    int end = 0;
    int current_sum = 0;
    int min_length = 1e9;
    while (end < n) {
        int cnt = 0;
        printf("end = %d\n",end);
        current_sum += a[end];
    //    printf("current sum = %d\n", current_sum);
        while (current_sum >= Q) {
         int cnt = end-start+1;
      //     printf("count = %d\n", cnt);
            if (min_length >= cnt) {
                min_length = cnt;
            }
            current_sum -= a[start];
            start++;
        }
        //printf("start = %d\n", start);
        end++;
    }
    if (min_length == 1e9) {
        printf("-1");
    } else {
        printf("%d", min_length);
    }
    return 0;
}