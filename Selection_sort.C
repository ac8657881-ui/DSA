#include<stdio.h>
#include<stdlib.h>
int main() {
    int a[100], n, i,j,min,temp;
    printf("Enter no of elements:");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < n-1; i++){
        min = i;
        for(int j = i + 1; j < n; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
         
    }

    printf("sorted array ascending order:\n");
    for(int i = 0; i < n; i++){
        printf("%d", &a[i]);
    }
     return 0;
}