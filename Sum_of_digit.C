#include <stdio.h>
int sod(int n) {
    if (n == 0) {
        return 0;
    }
    else {
        return(n%10 + sod(n/10));
    }
}        
    int main(){
        int n;
        printf("Enter the number:");
        scanf("%d",&n);
        printf("the sum of digit of %d is = %d",n,sod(n));
         return 0;


    }
   