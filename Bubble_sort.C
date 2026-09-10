#include<stdio.h>
#include<stdlib.h>
int main() {
    int a[100],n,i,j,temp;
    printf("Enter no of elements:\n");
    scanf("%d",&n);

    printf("Enter %d elements:\n",n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-1; j++)
        {
            if(a[i] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        } 
        
    }
    printf("Enter sorted array in ascending order:\n");
    for(int i = 0; i < n; i++){
        scanf("%d",a[i]);
    }
    return 0;

}