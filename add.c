#include "apc.h"

void addition(node *tail1, node *tail2, node **headR, node **tailR)
{
    int carry=0;
    node *t1=tail1;
    node *t2=tail2;

    //traverse from right to left using prev pointer
    while(t1 !=NULL || t2 !=NULL)
    {
        int val1=(t1 != NULL)? t1->data : 0;
        int val2=(t2!=NULL)? t2->data : 0;

        int sum = val1 + val2 + carry;

        if(sum > 9)
        {
            carry=1;
            sum=sum%10;
        }
        else
        {
            carry=0;
        }
        insert_first(headR,tailR, sum);

        if(t1 != NULL) 
        {
            t1=t1->prev;
        }
        if(t2 != NULL)
        {
            t2=t2->prev;
        }
    }

    //if carry remains after final addition
    if(carry>0)
    {
        insert_first(headR, tailR, carry);
    }
}