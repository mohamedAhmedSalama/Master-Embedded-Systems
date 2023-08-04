#include "LL.h"
#include "string.h"
#include "stdlib.h"

Student_t* Create_List(struct Data node)
{
    static int id_counter=15;
    Student_t* new_node = malloc(sizeof(Student_t));
    if(new_node == NULL)
    {
        return 0;
    }
    else
    {
        strcpy(new_node->stuData.Name,node.Name);
        new_node->stuData.Age = node.Age;
        new_node->stuData.Level = node.Level;
        new_node->stuData.ID = id_counter;
        new_node->PNextStu = NULL;
        id_counter++;
        return new_node;
    }
}
LinkedList_status Insert_Student(Student_t** Phead, struct Data node)
{
    Student_t* new_node = Create_List(node);
    if(!new_node)
    {
       return NOK;
    }
    Student_t* current_node = *Phead;
    if(*Phead == NULL)
    {
        *Phead = new_node;
        return EMPTY;
    }
    else
    {
        while(current_node->PNextStu != NULL)
            current_node = current_node->PNextStu;
        current_node->PNextStu = new_node;
        return OK;
    }
}

LinkedList_status Add_FirstNode(struct Data node,Student_t** Phead)
{
    Student_t* new_node = Create_List(node);
    if(!new_node)
        return NOK;
    else
    {
       new_node->PNextStu = *Phead;
      *Phead = new_node;
      return OK;
    }
}

LinkedList_status Remove_StudentByID(int id ,Student_t** Phead)
{
   if(!*Phead)
        return NOK;

   Student_t* current_node=*Phead, *temp;
   if(current_node->stuData.ID == id)
   {
       *Phead=current_node->PNextStu;
       free(current_node);
       return OK;
   }
   while(current_node->PNextStu)
   {
        if(current_node->PNextStu->stuData.ID == id)
        {
            temp=current_node->PNextStu;
            current_node->PNextStu=current_node->PNextStu->PNextStu;
            free(temp);
            return OK;
        }
        current_node = current_node->PNextStu;
   }
}

LinkedList_status Edit_StudentByID(int id , Student_t** Phead , struct Data new_data)
{
    Student_t* current_node =*Phead;
    if(!*Phead)
        return EMPTY;
    else
    {
        while(current_node)
        {
            if(current_node->stuData.ID == id)
            {
                current_node->stuData.Age = new_data.Age;
                current_node->stuData.Level = new_data.Level;
                strcpy( current_node->stuData.Name,new_data.Name);
                return OK;
            }
            current_node = current_node->PNextStu;
        }
        return NOK;
    }
}

LinkedList_status Insert_Student_AfterNth(Student_t** Phead, int pos, struct Data node)
{
    Student_t* current_node = *Phead;
    Student_t* new_node = Create_List(node);
    if(!*Phead)
    {
        *Phead = new_node;
        return EMPTY;
    }
    else
    {
        if(0 == pos)
        {
            new_node->PNextStu = *Phead;
            *Phead = new_node;
            return OK;
        }
        else
        {
            for(int i = 1 ; i < pos ; i++)
            {
                current_node = current_node->PNextStu;
                if(!current_node)
                    break;
            }
            if(current_node)
            {
                new_node->PNextStu = current_node->PNextStu;
                current_node->PNextStu = new_node;
                return OK;
            }
            else
            {
                Insert_Student(Phead,node);
                return END;
            }
        }
    }
}

LinkedList_status Print_List(Student_t* head)
{
    int i = 1;
    Student_t* current_node = head;
    if(!head)
        return EMPTY;
    while(current_node)
    {
        printf(" (%d)\n Name: %s\n ID: %d\n Age: %d\n Level: %d\n\n",i,current_node->stuData.Name,current_node->stuData.ID,current_node->stuData.Age,current_node->stuData.Level);
        current_node = current_node->PNextStu;
        i++;
    }
    printf(" ================================\n");
    return OK;
}

LinkedList_status Delete_WholeList(Student_t** Phead)
{
    Student_t* current_node = *Phead ,*next_node;
    if(!*Phead)
        return EMPTY;
    else
    {
        while(current_node)
        {
            next_node = current_node->PNextStu;
            free(current_node);
            current_node = next_node;
        }
        *Phead = NULL;
        return NOK;
    }
}

int List_Size(Student_t* head)
{
    int counter = 0;
    Student_t* current_node = head;
    if(!head)
        return counter;
    else
    {
        while(current_node)
        {
            counter++;
            current_node = current_node->PNextStu;
        }
        return counter;
    }
}
