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

//添加结构体指针
ILLST *p, *head, *tail;

//StructPointer Init
void Pointer_Init()
{
    //Pointer Init
    p = (ILLST*)malloc(sizeof(ILLST));
    head = p;
    tail = p;
    tail->next = NULL;
}

//Linked List Create func
/*
    input : Struct Pointer, Head Pointer, tail Pointer, amount of the List you need to creat;
    Init Linked List
*/ 
void LikLstCrt(ILLST* p, ILLST* head, ILLST* tail, int n)
{
    if(n <= 0)
    {
        printf("n must be a non-negative integer");
        return;
    }
    
    for(int i = 0; i < n; i++)
    {
        p = (ILLST*)malloc(sizeof(ILLST));
        printf("The integer number you want to input\n");
        scanf("%d", &(p->integer_node));
        tail->next = p;
        tail->next = NULL;
    }
}

//main func
int main()
{
    //point Init
    Pointer_Init();


    //how long of the List you want to creat
    int lgth;
    printf("The Length of the initial List : \n");
    scanf("%d", &lgth);

    LikLstCrt(p, head, tail, lgth);


    return 0;
}



