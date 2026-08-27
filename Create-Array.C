#include <stdio.h>
#include <stdlib.h>


int main() {
    int a[100], n, i, choice, pos, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\n1. Insert at Beginning");
    printf("\n2. Insert at End");
    printf("\n3. Insert at Any Position");
    printf("\n4. Delete from Beginning");
    printf("\n5. Delete from End");
    printf("\n6. Delete from Any Position");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);

            for(i = n; i > 0; i--)
                a[i] = a[i-1];

            a[0] = value;
            n++;
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &value);

            a[n] = value;
            n++;
            break;

        case 3:
            printf("Enter position: ");
            scanf("%d", &pos);

            printf("Enter value: ");
            scanf("%d", &value);

            for(i = n; i >= pos; i--)
                a[i] = a[i-1];

            a[pos-1] = value;
            n++;
            break;

        case 4:
            if(n == 0) {
                printf("Array is empty");
                return 0;
            }

            for(i = 0; i < n-1; i++)
                a[i] = a[i+1];

            n--;
            break;

        case 5:
            if(n == 0) {
                printf("Array is empty");
                return 0;
            }

            n--;
            break;

        case 6:
            printf("Enter position: ");
            scanf("%d", &pos);

            if(pos < 1 || pos > n) {
                printf("Invalid position");
                return 0;
            }

            for(i = pos-1; i < n-1; i++)
                a[i] = a[i+1];

            n--;
            break;

        default:
            printf("Invalid choice");
            return 0;
    }

    printf("\nArray after operation:\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}