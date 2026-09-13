#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int coeff;
    int power;
    struct Node *next;
};
struct Node* createNode(int coeff, int power)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}
struct Node* insert(struct Node *head, int coeff, int power)
{
    struct Node *newNode = createNode(coeff, power);
    struct Node *temp;
    if(head == NULL)
        return newNode;
    temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}
struct Node* addPolynomial(struct Node *p1, struct Node *p2)
{
    struct Node *result = NULL;

    while(p1 != NULL && p2 != NULL)
    {
        if(p1->power == p2->power)
        {
            result = insert(result,
                            p1->coeff + p2->coeff,
                            p1->power);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if(p1->power > p2->power)
        {
            result = insert(result, p1->coeff, p1->power);
            p1 = p1->next;
        }
        else
        {
            result = insert(result, p2->coeff, p2->power);
            p2 = p2->next;
        }
    }
    while(p1 != NULL)
    {
        result = insert(result, p1->coeff, p1->power);
        p1 = p1->next;
    }
    while(p2 != NULL)
    {
        result = insert(result, p2->coeff, p2->power);
        p2 = p2->next;
    }
    return result;
}
void display(struct Node *head)
{
    while(head != NULL)
    {
        printf("%dx^%d", head->coeff, head->power);
        if(head->next != NULL)
            printf(" + ");
        head = head->next;
    }

    printf("\n");
}

int main()
{
    struct Node *p1 = NULL;
    struct Node *p2 = NULL;
    struct Node *result = NULL;
    p1 = insert(p1, 5, 3);
    p1 = insert(p1, 4, 2);
    p1 = insert(p1, 2, 1);
    p1 = insert(p1, 1, 0);
    p2 = insert(p2, 3, 3);
    p2 = insert(p2, 2, 2);
    p2 = insert(p2, 5, 1);
    p2 = insert(p2, 2, 0);
    printf("First Polynomial: ");
    display(p1);
    printf("Second Polynomial: ");
    display(p2);
    result = addPolynomial(p1, p2);
    printf("Addition: ");
    display(result);

    return 0;
}