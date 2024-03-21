// #include <stdio.h>
// struct Node
// {
//     int value;
//     int val2;
//     struct Node *next;
// };

// struct Node *CreateNode()
// {
//     struct Node *current = (struct Node *)malloc(sizeof(struct Node));
//     printf("Put a value: ");
//     scanf("%d %d", &current->value, &current->val2);
//     current->next = NULL;
//     return current;
// }
// int main()
// {
//     struct Node *temp = CreateNode();
//     printf("%d %d\n", temp->value, temp->val2);
//     return 0;
// }

#include <stdio.h>
struct Node
{
    int value;
    struct Node *next;
};
struct Node *CreateNode()
{
    struct Node *current = (struct Node *)malloc(sizeof(struct Node));
    scanf("%d", &current->value);
    current->next = NULL;
    return current;
}
struct Node *InsertNode(struct Node *head)
{
    struct Node *temp = CreateNode();
    if (head == NULL)
        head = temp;
    else
    {
        while (head->next != NULL)
        {
            head = head->next;
        }
        head->next = temp;
    }
}
int main()
{
    struct Node *head = NULL;

    return 0;
}