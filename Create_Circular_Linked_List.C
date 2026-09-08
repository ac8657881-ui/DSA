#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void insertBeg(struct Node **head)
{
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (*head == NULL)
    {
        newNode->next = newNode;
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    }
    printf("Node inserted successfully.\n");
}
void insertEnd(struct Node **head)
{
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (*head == NULL)
    {
        newNode->next = newNode;
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
    }
    printf("Node inserted successfully.\n");
}
void insertPos(struct Node **head)
{
    int data, pos, i;
    printf("Enter data: ");
    scanf("%d", &data);
    printf("Enter position: ");
    scanf("%d", &pos);
    if (pos < 1)
    {
        printf("Invalid position.\n");
        return;
    }
    if (pos == 1)
    {
        insertBeg(head);
        return;
    }
    if (*head == NULL)
    {
        printf("Invalid position.\n");
        return;
    }
    struct Node *temp = *head;
    for (i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp == *head)
        {
            printf("Invalid position.\n");
            return;
        }
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node inserted successfully.\n");
}
void deleteBeg(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = *head;
    if (temp->next == *head)
    {
        *head = NULL;
        free(temp);
        return;
    }
    struct Node *last = *head;
    while (last->next != *head)
    {
        last = last->next;
    }
    *head = temp->next;
    last->next = *head;
    free(temp);
    printf("Node deleted successfully.\n");
}
void deleteEnd(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    if ((*head)->next == *head)
    {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node *temp = *head;
    struct Node *prev;
    while (temp->next != *head)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = *head;
    free(temp);
    printf("Node deleted successfully.\n");
}
void deletePos(struct Node **head)
{
    int pos, i;
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("Enter position: ");
    scanf("%d", &pos);
    if (pos < 1)
    {
        printf("Invalid position.\n");
        return;
    }
    if (pos == 1)
    {
        deleteBeg(head);
        return;
    }
    struct Node *temp = *head;
    for (i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp == *head)
        {
            printf("Invalid position.\n");
            return;
        }
    }
    struct Node *del = temp->next;
    if (del == *head)
    {
        printf("Invalid position.\n");
        return;
    }
    temp->next = del->next;
    free(del);
    printf("Node deleted successfully.\n");
}
void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}
int main()
{
    struct Node *head = NULL;
    int choice;
    while (1)
    {
        printf("\n----- Circular Linked List -----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Any Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Any Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertBeg(&head);
            break;
        case 2:
            insertEnd(&head);
            break;
        case 3:
            insertPos(&head);
            break;
        case 4:
            deleteBeg(&head);
            break;
        case 5:
            deleteEnd(&head);
            break;
        case 6:
            deletePos(&head);
            break;
        case 7:
            display(head);
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}