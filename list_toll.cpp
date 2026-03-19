#include <stdio.h>
//claim malloc head file
#include <stdlib.h>

#include "list_toll.hpp"




//Linked List Create func
/*
    input : Head Pointer, tail Pointer, amount of the List you need to creat;
    Init Linked List
*/ 
void LikLstCrt(ILLST** head_ptr, ILLST** tail_ptr, int n)
{
    if(n < 0)
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

//将一个链表改为循环链表
void Circle_List(ILLST ** head_ptr)
{
    // 1. 校验入参：头指针地址为空 或 链表本身为空，直接返回
    if (head_ptr == NULL || *head_ptr == NULL) 
    {
        printf("链表为空，无法构建循环链表\n");
        return;
    }
    // 2. 找到链表的最后一个节点
    ILLST *current = *head_ptr;  // 从链表头开始遍历
    while (current->next != NULL) 
    {
        current = current->next;
    }

    // 3. 将尾节点的 next 指向链表头，形成循环
    current->next = *head_ptr;
}

//打印循环链表
void Pt_cir_List(ILLST ** head_ptr)
{
    ILLST * Ptr_1 = NULL;
    Ptr_1 = *head_ptr;
    if (head_ptr == NULL || *head_ptr == NULL) 
    {
        printf("循环链表为空，无需打印\n");
        return;
    }

    printf("循环链表内容");
    do
    {
        printf("%d ", Ptr_1->integer_node);
        Ptr_1 = Ptr_1->next;
    } while (Ptr_1 != *head_ptr);
}

//选择链表节点
ILLST *rand_ptr(ILLST *head)
{
    int num;
    scanf("%d", &num);

    ILLST *ptr = head;

    for(int i = 0; i < num; i++)
    {
        ptr = ptr->next;
    }

    return ptr;
}

//delete the point front of ptr;
void dele_ft_pit(ILLST *ptr)
{
    if(ptr == NULL || ptr->next == ptr)
        return;

    ILLST *ptr_fft = ptr;

    while(ptr_fft->next->next != ptr)
    {
        ptr_fft = ptr_fft->next;
    }

    ILLST *ptr_tmp = ptr_fft->next;
    ptr_fft->next = ptr;
    free(ptr_tmp);
}

//找链表最小值，并返回奇数偶数信息
int fd_List_min(ILLST * head_ptr)
{
    ILLST * pt_pa, * pt_mi;
    pt_pa = head_ptr; pt_mi = head_ptr;
    int temp = head_ptr->integer_node;
    while(pt_pa != NULL)
    {
        if(temp < pt_pa->integer_node)
        {
            temp = pt_pa->integer_node;
        }
        pt_pa = pt_pa->next;
    }
    printf("最小值为: %d", temp);
    pt_pa = head_ptr;
    if(temp % 2 == 0)
    {
        return 2;
    }
    else
    {
        while(pt_pa != NULL)
        {
            if(pt_pa->next->integer_node = temp)
            {
                pt_mi = pt_pa->next;
                pt_pa->next = pt_mi->next;
                free(pt_mi);
                printf("已删除一个最小值\n");
            }
            pt_pa = pt_pa->next;
        }
    }

}