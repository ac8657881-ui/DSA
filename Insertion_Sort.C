#include<stdio.h>
#include<stdlib.h>
int main() {
    int a[100],n,i,j,key;
    printf("Enter no of elements");
    scanf("%d",&n);

    printf("Enter %d elemens:\n",n);
    for(int i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }
    for(int i = 1; i < n; i++) {
        key = a[i];
        j = i-1;
        while(j >=0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;

        }
        a[j + 1] = key;
    }
    printf("Enter the sorted array in ascending order:\n");
    for(int i = 0; i < n; i++) {
        printf("%d",a[i]);
    }
    return 0;
}