#include <stdio.h>
#include <stdlib.h>

#include "list_toll.hpp"



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

    //你想解决的问题：
    /*
    第几题选数字几；
    */
   int nqs;
   printf("the question you need to resolve\n");
   scanf("%d", &nqs);
   switch (nqs)
    {
    case 1:
    {
        // check the content of Linked List
        Pt_LinkedList(head);

        Insrt_bfta_List(&head);

        // check the content
        Pt_LinkedList(head);

        break;
    }

    case 2:
    {
        // 改成循环链表
        Circle_List(&head);

        // 打印循环链表
        Pt_cir_List(&head);

        // 选择节点
        ILLST *ptr_rnd = rand_ptr(head);
        printf("current point content is : %d", ptr_rnd->integer_node);

        break;
    }

    default:
    {
        printf("invalid input\n");
        break;
    }
    }

    

    LikLstFree(&head);
    return 0;
}


