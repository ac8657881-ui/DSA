#include<stdio.h>
#include<stdlib.h>

void multiMatrix() {
    int a[10][10],b[10][10],result[10][10];
    int r1,c1,r2,c2;
    
    printf("Enter the rows and coloms of first matrix:");
    scanf("%d %d",&r1,&c1);

    printf("Enter the rows and coloms of second matrix:");
    scanf("%d %d", &r2,&c2);

    if (c1 != r2) {
        printf("Matrix multiplication is not possible:");
        return ;
    }
    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter elements of  second matrix:\n");
    for (int i = 0; i < r2; i++){
        for (int j = 0; j < c2; j++){
            scanf("%d",&b[i][j]);
        }
    }
    for (int i = 0; i < r1; i++){
        for (int j = 0; j < r2; j++){
            result[i][j] = 0;
            for(int k = 0; k < c1; k++){
                result[i][j] = a[i][k] * b[k][j];

            }
        }
    }

    printf("\nResult of Matrix Multiplication:\n");
    for (int i = 0; i < r1; i++){
        for(int j = 0; j < c2; j++){
            printf("%d\t",result[i][j]);
            
        }
        printf("\n");
    }

}

void diffDiag() {
    int arr[10][10];
    int n;
    int priDiag = 0;
    int secDiag = 0;

    printf("Enter the size of square matrix:");
    scanf("%d",&n);

    printf("Enter elements of matrix:\n");
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d",&arr[i][j]);
        }
    }
    for (int i =0; i < n; i++) {
        priDiag += arr[i][i];
        secDiag += arr[i][n - i - 1]; 
    }
    printf("\n Main Diagonal sum = %d", priDiag);
    printf("\nsecondary Diagonal sum = %d", secDiag);
    printf("\nDifference = %d\n", priDiag - secDiag);
}

int main() {
    int choice;
    do {
        printf("---MENU---\n");
        printf("1. Matrix Multiplication\n");
        printf("2. Difference of Diagonals\n");
        printf("3. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice) {
           case 1:
               multiMatrix();
               break;
          case 2:
               diffDiag();
               break;
          case 3:
              printf("Exiting program\n");
              break;
          default:
              printf("Invalid choice! please try again.\n");


        }
    }
    while (choice != 3);
    printf("Ajay Chauhan 2501920100063\n");
    return 0;
}