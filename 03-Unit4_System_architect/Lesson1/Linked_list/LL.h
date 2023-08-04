#ifndef LL_H_
#define LL_H_

#define NULL (void*)0
#define LENGTH  50

struct Data{
    int ID;
    int Age;
    int Level;
    char Name[LENGTH];
};
 typedef struct Student{
    struct Data stuData;
     struct Student* PNextStu;
}Student_t;

typedef enum{
    NOK,
    OK,
    EMPTY,
    END
}LinkedList_status;

Student_t* Create_List(struct Data node);
LinkedList_status Insert_Student(Student_t** Phead, struct Data node);
LinkedList_status Add_FirstNode(struct Data node,Student_t** Phead);
LinkedList_status Remove_StudentByID(int id ,Student_t** Phead);
LinkedList_status Edit_StudentByID(int id , Student_t** Phead , struct Data new_data);
LinkedList_status Insert_Student_AfterNth(Student_t** Phead, int pos, struct Data node);
LinkedList_status Print_List(Student_t* head);
LinkedList_status Delete_WholeList(Student_t** Phead);
int List_Size(Student_t* head);



#endif // LL_H_
