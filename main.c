#include "apc.h"

int main(int argc, char *argv[])
{
    node *head1=NULL;
    node *tail1=NULL;
    node *head2=NULL;
    node *tail2=NULL;
    node *headR=NULL;
    node *tailR=NULL;

    //validation
    if(cla_validation(argc, argv)==FAILURE)
    {
        return FAILURE;
    }

    //create 2 lists of operands
    create_list(argv[1], &head1 , &tail1);
    create_list(argv[3], &head2, &tail2);

    //Remove pre zeros from operands
    remove_pre_zeros(&head1);
    remove_pre_zeros(&head2);

    char oper=argv[2][0];

    switch(oper)
    {
        case '+':
            addition(tail1 , tail2, &headR, &tailR);
            printf("Result: ");
            print_list(headR);
            break;

        case '-':
            subtraction(tail1, tail2, &headR, &tailR);
            break;

        case 'x':
        case 'X':
            multiplication(tail1 , tail2, &headR , &tailR);
            printf("Result: ");
            print_list(headR);
            break;

        case '/':
            division(head1 , head2, &headR, &tailR);
            printf("Result: ");
            print_list(headR);
            break;
        default:
            printf("Invalid operator\n");
    }
    return SUCCESS;
}