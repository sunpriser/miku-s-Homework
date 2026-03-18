#include <stdio.h>
//claim malloc head file
#include <stdlib.h>

//链表结构体
/*
    structure body content：Integer
    define name: ILLST

*/

typedef struct I_Linked_List
{
    int integer_node;
    struct I_Linked_List *next;
    /* data */
}ILLST;




//Linked List Create func
/*
    input : Head Pointer, tail Pointer, amount of the List you need to creat;
    Init Linked List
*/ 
void LikLstCrt(ILLST** head_ptr, ILLST** tail_ptr, int n)
{
    if(n <= 0)
    {
        printf("n must be a non-negative integer");
        return;
    }

    ILLST *p = NULL;
    p = (ILLST*)malloc(sizeof(ILLST));
    if (p == NULL) 
    {
        printf("Error: Memory allocation failed!\n");
        return;
    }
    
    for(int i = 0; i < n; i++)
    {
        p = (ILLST*)malloc(sizeof(ILLST));
        if (p == NULL) 
        {
            printf("Error: Memory allocation failed!\n");
            return;
        }

        printf("Please input the %d-th integer: ", i+1);
        scanf("%d", &(p->integer_node));
        p->next = NULL; 

        if (*head_ptr == NULL) 
        {
            *head_ptr = p;
            *tail_ptr = p;
        } 
        else 
        {
            (*tail_ptr)->next = p;
            *tail_ptr = p;
        }
    }
}

//print Linked List Func
void Pt_LinkedList(ILLST *Pointer)
{
    ILLST *Pto = Pointer;
    
    printf("The data of your List\n");
    while(Pto != NULL)
    {
        printf("%d ",Pto->integer_node);
        Pto = Pto->next;
    }
}

//free Linked List
void LikLstFree(ILLST** head_ptr)
{
    ILLST *temp = *head_ptr;
    while (temp != NULL) 
    {
        *head_ptr = (*head_ptr)->next;
        free(temp);
        temp = *head_ptr;
    }
    *head_ptr = NULL;
}

//main func
int main()
{
    //添加结构体指针
    ILLST *head = NULL, *tail = NULL;



    //how long of the List you want to creat
    int lgth;
    printf("The Length of the initial List : \n");
    scanf("%d", &lgth);

    LikLstCrt(&head, &tail, lgth);

    //check the content of Linked List
     Pt_LinkedList(head);



    LikLstFree(&head);
    return 0;
}



