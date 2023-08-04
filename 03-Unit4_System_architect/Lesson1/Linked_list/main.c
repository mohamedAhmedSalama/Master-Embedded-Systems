#include <stdio.h>
#include <stdlib.h>
#include "LL.h"
#include"string.h"
int main()
{
    struct Data data={0,20,3,"mohamed ahmed"} ;
    struct Data d1 ={0,22,5,"ali ahmed"};
    struct Data d2 = {0,19,2,"taha ali"} ;
    struct Data d3 = {0,21,4,"mohamed ali"} ;
    struct Data d4 = {0,23,6,"karim mhamed"};
    Student_t* head = NULL;
    head = Create_List(data);
    printf("\n");
    Print_List(head);
    Insert_Student(&head,d1);
    Insert_Student(&head,d2);
    Add_FirstNode(d3,&head);
    printf("\n\n");
    Print_List(head);
    Remove_StudentByID(16,&head);
    printf("\n\n");
    Print_List(head);
    Insert_Student(&head,d1);
    printf("\n\n");
    Print_List(head);
    data.Age=21;
    data.Level=4;
    Edit_StudentByID(15,&head,data);
    printf("\n\n");
    Print_List(head);
    printf("list size is :%d \n\n",List_Size(head));
    Insert_Student_AfterNth(&head,50,d4);
    printf("\n\n");
    Print_List(head);
    printf("list size is :%d \n\n",List_Size(head));
    Delete_WholeList(&head);
    if(Print_List(head) == EMPTY )
        printf("empty list!!\n\n");
    printf("list size is :%d \n\n",List_Size(head));
   /* head = Create_List(data);
    printf("\n");
    Print_List(head);
    Add_Student(d1,&head);
    printf("\n");
    Print_List(head);*/

   // Add_Student(d2,&head1);


    return 0;
}
