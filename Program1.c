#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE, *PNODE, **PPNODE;
void InsertFirst(PPNODE Head, int no)
{
    PNODE newN = NULL;
    newN = (PNODE)malloc(sizeof(NODE));
    newN->data = no;
    newN->next = NULL;
    if (*Head == NULL)
    {
        *Head = newN;
    }
    else
    {
        newN->next = *Head;
        *Head = newN;
    }
}
void InsertLast(PPNODE Head, int no)
{
    PNODE newN = NULL;
    PNODE temp = *Head;
    newN = (PNODE)malloc(sizeof(NODE));
    newN->data = no;
    newN->next = NULL;
    if (*Head == NULL)
    {
        *Head = newN;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newN;
}
void DeleteFirst(PPNODE Head)
{
    PNODE temp = *Head;
    if (*Head != NULL)
    {
        *Head = (*Head)->next;
        free(temp);
    }
}
void DeleteLast(PPNODE Head)
{
    PNODE temp = *Head;
    if (*Head == NULL)
    {
        return;
    }
    else if ((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}
void Display(PNODE Head)
{
    if (Head == NULL)
    {
        printf("Linked List is Empty");
        return;
    }
    while (Head != NULL)
    {
        printf("|%d|->", Head->data);
        Head = Head->next;
    }
    printf("NULL");
}
int Count(PNODE Head)
{
    int iCnt = 0;
    if (Head == NULL)
    {
        printf("Linked List is Empty\n");
        return iCnt;
    }

    while (Head != NULL)
    {
        iCnt++;
        Head = Head->next;
    }
    return iCnt;
}
void InsertAtPos(PPNODE Head, int no, int iPos)
{
    int size = 0;
    size = Count(*Head);
    if ((iPos > 1) || (iPos > size + 1))
    {
        printf("Invalid Postions");
        return;
    }
    else if (iPos == 1)
    {
        InsertFirst(Head, no);
    }
    else if (iPos == size)
    {
        InsertLast(Head, no);
    }
    else
    {

        PNODE newN = NULL;
        PNODE temp = *Head;
        int i = 0;

        newN = (PNODE)malloc(sizeof(NODE));
        newN->data = no;
        newN->next = NULL;
        for (i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        newN->next = temp->next;
        temp->next = newN;
    }
}
DeleteAtPos(PPNODE Head, int iPos)
{
    int size = 0, i = 0;
    PNODE Target = NULL;
    size = Count(*Head);
    if ((iPos < 1) || (iPos > size + 1))
    {
        printf("Invalid Postion");
        return;
    }
    else if (iPos == 1)
    {
        DeleteFirst(Head);
    }
    else if (iPos == size)
    {
        DeleteLast(Head);
    }
    else
    {
        PNODE temp = *Head;
        for (i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        Target = temp->next;
        temp->next = Target->next;
        free(Target);
    }
}
void Help()
{
    printf("1:Insert the node at First Postion\n");
    printf("2: Insert the node at Last Postion\n");
    printf("3:Delete First Postion Elements\n ");
    printf("4: Delete Last Postion Elements\n");
    printf("5: Display the Linked List\n");
    printf("6: Count The element of linked List\n");
    printf("0: Terminate The Application\n");
    printf("\n______________________________________________________________________\n");
}

int main()
{
    PNODE first = NULL;
    int iRet = 0, value = 0, iChoose = 1, pos = 0;

    while (iChoose != 0)
    {
        printf("\n______________________________________________________________________\n");
        printf("1:Insert the node at First Postion\n");
        printf("2: Insert the node at Last Postion\n");
        printf("3:Delete First Postion Elements\n ");
        printf("4: Delete Last Postion Elements\n");
        printf("5: Display the Linked List\n");
        printf("6: Count The element of linked List\n");
        printf("7:Insert At Postion\n");
        printf("8:Delete At Postion");
        printf("0: Terminate The Application\n");
        printf("\n______________________________________________________________________\n");
        scanf("%d", &iChoose);
        switch (iChoose)
        {
        case 1:
            printf("Enter The Elemnts Insert");
            scanf("%d", &value);
            InsertFirst(&first, value);
            break;
        case 2:
            printf("Enter the Elements to Insert");
            scanf("%d", &value);
            InsertLast(&first, value);
            break;

        case 3:
            DeleteFirst(&first);
            break;
        case 4:
            DeleteLast(&first);
            break;
        case 5:
            Display(first);
            break;

        case 6:
            iRet = Count(first);
            printf("Linked List Elements Count are:%d", iRet);
            break;
        case 7:
            printf("Enter The node data to insert");
            scanf("%d", &value);
            printf("Enter The Postion to insert the node");
            scanf("%d", &pos);
            InsertAtPos(&first, value, pos);
            break;
        case 8:
            printf("Enter The Postion to insert the node");
            scanf("%d", &pos);
            DeleteAtPos(&first, pos);
            break;
        case 0:
            printf("Thank You For Using Rohan Rohokale Linked List\n");
            break;
        default:
            printf("Please Enter Proper Choice\n");
            Help();
        }
    }
    return 0;
}
