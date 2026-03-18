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

    //check the content of Linked List
    Pt_LinkedList(head);

    Insrt_bfta_List(&head);
    //check the content
    Pt_LinkedList(head);

    LikLstFree(&head);
    return 0;
}


