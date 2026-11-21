#include "apc.h"

void subtraction(node *tail1, node *tail2, node **headR, node **tailR)
{
    int borrow=0;

    node *t1 = tail1;
    node *t2 = tail2;
    node *h1 = NULL, *h2 = NULL; // To track heads for comparison if needed

    // Find heads from tails for comparison
    node *temp = tail1;
    while (temp != NULL && temp->prev != NULL) temp = temp->prev;
    h1 = temp;

    temp = tail2;
    while (temp != NULL && temp->prev != NULL) temp = temp->prev;
    h2 = temp;

    int len1 = list_len(h1);
    int len2 = list_len(h2);
    int swap_flag = 0;

    // Compare operands based on notes:
    // If len1 < len2, or (len1 == len2 and list2 > list1), swap and result is negative
    if (len1 < len2)
    {
        swap_flag = 1;
    }
    else if (len1 == len2)
    {
        int cmp = compare_list(h1, h2);
        if (cmp == OPERAND2) // operand 2 is greater
        {
            swap_flag = 1;
        }
        else if (cmp == SAME)
        {
            // If both numbers are identical, result is 0
            insert_first(headR, tailR, 0);
            return;
        }
    }

    // If swap is required, swap pointers so larger number is t1
    if (swap_flag)
    {
        node *temp_t = t1; t1 = t2; t2 = temp_t;
    }


    //tarverse from right to left using prev pointers
    while(t1 != NULL || t2 != NULL)
    {
        int val1=(t1 != NULL) ? t1->data:0;
        int val2=(t2 != NULL) ? t2->data:0;

        //Apply borrow from the previous digit operation
        val1-= borrow;

        if(val1 < val2)
        {
            val1+=10;
            borrow=1;
        }
        else
        {
            borrow=0;
        }
        int sub = val1-val2;

        insert_first(headR , tailR , sub);

        if(t1 != NULL) t1 = t1->prev;
        if(t2 != NULL) t2= t2->prev;
    }
    //clean up any leading zeros in the result
    remove_pre_zeros(headR);

    //print result with proper sign 
    printf("Result: ");
    if (swap_flag)
    {
        printf("-");
    }
    print_list(*headR);
}