#include <stdio.h>
//claim malloc head file
#include <stdlib.h>

#include "list_toll.h"




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

//将值为b的节点插在值为a的节点前，若a不存在，则将b插入到表尾
void Insrt_bfta_List(ILLST ** head_ptr)
{
    int a,b;
    //输入你想要的b
    printf("tap the b you need\n");
    if (scanf("%d", &b) != 1) 
    {
        printf("输入错误！\n");
        return;
    }
    ILLST *data_b = (ILLST*)malloc(sizeof(ILLST));
    if (data_b == NULL) 
    {
        printf("内存分配失败！\n");
        return;
    }

    data_b->integer_node = b;
    data_b->next = NULL;
    //输入你想要的a
    printf("tap the a you need\n");
    if (scanf("%d", &a) != 1) 
    {
        printf("输入错误！\n");
        free(data_b); // 释放已分配的b节点，避免内存泄漏
        return;
    }

    //检索链表寻找a
    ILLST *prev = NULL;   // 记录a的前驱节点
    ILLST *curr = *head_ptr; // 遍历指针，从表头开始

    while((curr != NULL) && (curr->integer_node != a))
    {
        prev = curr;
        curr = curr->next;
    }

    if(curr != NULL)
    {
        data_b->next = curr;
        //if head_ptr is a
        if(prev == NULL)
        {
            *head_ptr = data_b;
        }
        else
        {
            prev->next = data_b;
        }
        printf("insert front of a successfully\n");
    }
    else
    {
        //空链表
        if(prev == NULL)
        {
            *head_ptr = data_b;
            printf("empty\n");
        }
        else
        {
            ILLST *tail = *head_ptr;
            while (tail->next != NULL) 
            {
                tail = tail->next;
            }
            tail->next = data_b;
        }
        printf("insert after tail\n");
    }
}