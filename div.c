#include "apc.h"

int is_zero(node *head)
{
    node *temp=head;
    while(temp!=NULL)
    {
        if(temp->data != 0)
            return 0;
        temp=temp->next;
    }
    return 1;
}

void division (node *head1 , node *head2, node **headR , node **tailR)
{
    //Division by zero validation
    if(is_zero(head2))
    {
        printf("Error: Division by zero is not allowed.\n");
        return ;
    }
    node *h1=head1;
    node *h2=head2;
    remove_pre_zeros(&h1);
    remove_pre_zeros(&h2);

    int len1 = list_len(h1);
    int len2=list_len(h2);

    //initialize result list to 0
    *headR=NULL;
    *tailR=NULL;

    //if dividend < divisior , quotient is 0
    if(len1 < len2 || (len1 == len2 &&compare_list(h1,h2)==OPERAND2))
    {
        insert_last(headR , tailR , 0);
        return ;
    }
    //if dividend == divisior , quotient is 1
    if(len1==len2 && compare_list(h1, h2)==SAME)
    {
        insert_last(headR, tailR,1);
        return ;
    }
    //repeated sub count
    long long num1 =0 , num2=0;
    node *t = h1;
    while (t != NULL)
    {
        num1 = num1 * 10 + t->data;
        t = t->next;
    }

    t = h2;
    while (t != NULL)
    {
        num2 = num2 * 10 + t->data;
        t = t->next;
    }

    long long quotient = num1 / num2;

    // Insert quotient into result list digit by digit
    if (quotient == 0)
    {
        insert_last(headR, tailR, 0);
    }
    else
    {
        long long temp_q = quotient;
        int digits[20], count = 0;
        while (temp_q > 0)
        {
            digits[count++] = temp_q % 10;
            temp_q /= 10;
        }
        for (int i = count - 1; i >= 0; i--)
        {
            insert_last(headR, tailR, digits[i]);
        }
    }
}

    