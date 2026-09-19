#include <stdio.h>
int sum(int n) {
    if (n == 0){
        return (n);
    }
    else {
        return(n + sum(n-1));
    }
}

int main() {
    int n;
    printf("Enter how many natural number to print");
    scanf("%d",&n);
    printf("the sum of %d natural number is =%d",n,sum(n));
    return 0;
}