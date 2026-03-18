#include <stdio.h>

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


