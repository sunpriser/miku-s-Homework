#ifndef __LIST_TOLL_H__
#define __LIST_TOLL_H__

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


void LikLstCrt(ILLST** head_ptr, ILLST** tail_ptr, int n);

//print Linked List Func
void Pt_LinkedList(ILLST *Pointer);

//free Linked List
void LikLstFree(ILLST** head_ptr);

//将值为b的节点插在值为a的节点前，若a不存在，则将b插入到表尾
void Insrt_bfta_List(ILLST ** head_ptr);

//将一个链表改为循环链表
void Circle_List(ILLST ** head_ptr);

//打印循环链表
void Pt_cir_List(ILLST ** head_ptr);

//选择链表节点
ILLST * rand_ptr(ILLST * head);



#endif // !__LIST_TOLL_H__