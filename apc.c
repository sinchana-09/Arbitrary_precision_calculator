#include "apc.h"

// 1. Command Line Argument Validation
int cla_validation(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Error: Invalid number of arguments.\n");
        printf("Usage: ./apc <operand1> <operator> <operand2>\n");
        return FAILURE;
    }

    // Validate Operand 1
    char *op1 = argv[1];
    int i = (op1[0] == '+' || op1[0] == '-') ? 1 : 0;
    if (op1[i] == '\0') return FAILURE;
    for (; op1[i] != '\0'; i++)
    {
        if (!isdigit(op1[i]))
        {
            printf("Error: Invalid operand 1. Must contain only digits.\n");
            return FAILURE;
        }
    }

    // Validate Operator
    char op = argv[2][0];
    if (strlen(argv[2]) != 1 || (op != '+' && op != '-' && op != 'x' && op != 'X' && op != '/'))
    {
        printf("Error: Invalid operator. Supported: +, -, x, /\n");
        return FAILURE;
    }

    // Validate Operand 2
    char *op2 = argv[3];
    i = (op2[0] == '+' || op2[0] == '-') ? 1 : 0;
    if (op2[i] == '\0') return FAILURE;
    for (; op2[i] != '\0'; i++)
    {
        if (!isdigit(op2[i]))
        {
            printf("Error: Invalid operand 2. Must contain only digits.\n");
            return FAILURE;
        }
    }

    return SUCCESS;
}

// 2. Create Doubly Linked List from String (Inserting at Last)
void create_list(char *opr, node **head, node **tail)
{
    int i = (opr[0] == '+' || opr[0] == '-') ? 1 : 0;

    for (; opr[i] != '\0'; i++)
    {
        insert_last(head, tail, opr[i] - '0');
    }
}

// 3. Insert Node at First
int insert_first(node **head, node **tail, int data)
{
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) return FAILURE;

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = *head;

    if (*head == NULL)
    {
        *head = *tail = new_node;
    }
    else
    {
        (*head)->prev = new_node;
        *head = new_node;
    }
    return SUCCESS;
}

// 4. Insert Node at Last
int insert_last(node **head, node **tail, int data)
{
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) return FAILURE;

    new_node->data = data;
    new_node->prev = *tail;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = *tail = new_node;
    }
    else
    {
        (*tail)->next = new_node;
        *tail = new_node;
    }
    return SUCCESS;
}

// 5. Remove Leading Zeros (e.g., 00012 -> 12)
void remove_pre_zeros(node **head)
{
    while (*head != NULL && (*head)->data == 0 && (*head)->next != NULL)
    {
        node *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }
}

// 6. Print List
void print_list(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// 7. Delete List (Memory Cleanup)
int delete_list(node **head, node **tail)
{
    node *temp = *head;
    while (temp != NULL)
    {
        node *next_node = temp->next;
        free(temp);
        temp = next_node;
    }
    *head = NULL;
    *tail = NULL;
    return SUCCESS;
}

// 8. Calculate Length of Linked List
int list_len(node *head)
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// 9. Compare Two Lists Digit by Digit from Head (Left to Right)
int compare_list(node *head1, node *head2)
{
    node *t1 = head1;
    node *t2 = head2;

    while (t1 != NULL && t2 != NULL)
    {
        if (t1->data > t2->data)
        {
            return OPERAND1;
        }
        else if (t1->data < t2->data)
        {
            return OPERAND2;
        }
        t1 = t1->next;
        t2 = t2->next;
    }
    return SAME;
}