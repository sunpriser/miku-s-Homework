#include <stdio.h>
#include <stdlib.h>

#include "list_toll.hpp"



//main func
int main()
{
    system("chcp 65001");
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
            LikLstFree(&head);

            break;
        }

        case 2:
        {
            Circle_List(&head);
            Pt_cir_List(&head);
            printf("\n选择节点\n");
            ILLST *ptr_rnd = rand_ptr(head);
            printf("current point content is : %d\n", ptr_rnd->integer_node);
            dele_ft_pit(ptr_rnd);
            printf("删除后:\n");
            Pt_cir_List(&head);
            ILLST *tail = head;
            //free一下
            while(tail->next != head)
            {
                tail = tail->next;
            }
            tail->next = NULL;
            LikLstFree(&head);
            break;
        }
        case 3 :
        {
            fd_List_min(&head);
            Pt_LinkedList(head);
            break;
        }
        default:
        {
            printf("invalid input\n");
            break;
        }
    }

    

    
    return 0;
}


