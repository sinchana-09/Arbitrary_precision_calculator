#include "apc.h"

void multiplication(node *tail1, node *tail2 , node **headR , node **tailR)
{
    //result initialised to 0
    *headR=NULL;
    *tailR=NULL;
    insert_last(headR, tailR, 0);

    node *t2 = tail2;
    int zero_count = 0; //tracks trailing zeros to append for each digit position

    //loop through each digit of operand 2 from right to left
    while(t2!=NULL)
    {
        node *t1 = tail1;
        node *head_curr=NULL;
        node *tail_curr=NULL;
        int carry=0;

        //multiply t2->data with every digit of operand 1(right to left)
        while(t1 !=NULL)
        {
            int mul = (t1->data *t2->data)+carry;
            if(mul>9)
            {
                carry=mul/10;
                mul=mul%10;
            }
            else
            {
                carry = 0;
            }
            insert_first(&head_curr , &tail_curr, mul);
            t1=t1->prev;
        }
        //if any carry remains after multiplying all digits of operand 1
        if(carry>0)
        {
            insert_first(&head_curr, &tail_curr, carry);
        }
        //append trailing zeros based on position
        for(int i=0 ; i<zero_count; i++)
        {
            insert_last(&head_curr , &tail_curr, 0);
        }
        //if this is the first iteration , copy curr result to main result(head/tail)
        if(zero_count == 0)
        {
            delete_list(headR , tailR);
            *headR=head_curr;
            *tailR=tail_curr;
        }
        else
        {
            node *head_temp=NULL;
            node *tail_temp=NULL;

            addition(*tailR, tail_curr, &head_temp, &tail_temp);

            delete_list(headR, tailR);
            delete_list(&head_curr , &tail_curr);

            *headR=head_temp;
            *tailR=tail_temp;
        }
        zero_count++;
        t2=t2->prev;
    }
    remove_pre_zeros(headR);
}