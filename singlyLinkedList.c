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
    int val2;
    struct Node *next;
};
struct Node *CreateNode()
{
    struct Node *current = (struct Node *)malloc(sizeof(struct Node));
    scanf("%d %d", &current->value, &current->val2);
    current->next = NULL;
    return current;
}
int main()
{
    struct Node *temp = CreateNode();
    printf("%d %d", temp->value, temp->val2);
    return 0;
}