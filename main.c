/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define size 10
int arr[size];
int stack[size];
int queue[size];
int rere = -1, front = -1;
int top = -1;
int i = -1;

struct node1
{
    int data;
    struct node1 *next;
};
struct node1 *head, *temp;

struct node2
{
    int data;
    struct node2 *prev;
    struct node2 *next;
};
struct node2 *head2, *temp2;

struct node3
{
    int data;
    struct node3 *next;
};
struct node3 *head3, *temp3;

struct node_t
{
    int data;
    struct node_t *left;
    struct node_t *right;
};
struct node_t *root;
void insertion()
{
    int temp;
    if (i < size - 1)
    {
        i++;
        system("cls");
        printf("Enter which element you want to insert: ");
        scanf("%d", &temp);
        arr[i] = temp;
        printf("Element insert in the array Succusfully!!\n");
    }
    else
    {
        printf("array is complety full\n");
    }
    system("cls");
}
void traverse()
{
    system("cls");
    if (i >= 0)
    {
        printf("Elements are present in the array: \n");
        for (int j = 0; j <= i; j++)
        {
            printf("%d\t", arr[j]);
        }
        printf("\n");
    }
    else
    {
        printf("No element present in the array\n");
    }
}
void delete_element()
{
    system("cls");
    int choice;
    printf("1. for delete element from end\n");
    printf("2. for delete element from beg\n");
    printf("3. for exit\n");
    printf("Please enter your choice: ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        if (i >= 0)
        {
            i--;
            printf("last element deleted from an array succusfully!!\n");
        }
        else
        {
            printf("Array is Empty\n");
        }
    }
    else if (choice == 2)
    {
        if (i >= 0)
        {
            for (int j = 0; j < i; j++)
            {
                arr[j] = arr[j + 1];
            }
            i--;
            printf("begning element deleted from an array succusfully!!\n");
        }
        else
        {
            printf("Array is Empty\n");
        }
    }
    else
    {
        printf("You entered wrong choice...pls try again\n");
    }
}

void search()
{
    system("cls");
    int a;
    printf("Enter element which you want to search: ");
    scanf("%d", &a);
    int flag = 1;
    for (int j = 0; j <= i; j++)
    {
        if (a == arr[j])
        {
            printf("Element is found in an array at index %d is: %d\n\n", j, a);
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        printf("Element is not found\n");
    }
}
// menu2 functions
void creation_ll()
{
    struct node1 *newnode;
    head = NULL;
    int choice = 1;
    while (choice)
    {
        newnode = (struct node1 *)malloc(sizeof(struct node1));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Do you wnt to insert more node\nIf yes press 1.\nNo press 0.\n");
        scanf("%d", &choice);
    }
    temp = head;
    printf("Element are: ");
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}

void insertion_beg_ll()
{
    struct node1 *newnode;
    // creation_ll();
    newnode = (struct node1 *)malloc(sizeof(struct node1));
    printf("Enter data you want to insert: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->next = head;
    head = newnode;
    temp = head;
    printf("Element are: ");
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}
void insertion_any_ll()
{
    // creation_ll();
    struct node1 *newnode;
    int pos;
    temp = head;
    printf("Enter the value of the position where you want to insert node: ");
    scanf("%d", &pos);
    int i1 = 1;
    int count1 = 1;
    while (temp->next != NULL)
    {
        temp = temp->next;
        count1++;
    }
    if (pos > count1)
    {
        printf("You entered Invalide postion\n");
    }
    else
    {
        newnode = (struct node1 *)malloc(sizeof(struct node1));
        printf("Enter data you want to insert after %d position: ", pos);
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        temp = head;
        while (i1 < pos)
        {
            temp = temp->next;
            i1++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    temp = head;
    printf("Elements are: ");
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}
void insertion_end_ll()
{
    struct node1 *newnode;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newnode = (struct node1 *)malloc(sizeof(struct node1));
    printf("Enter data you want to insert after position: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    temp->next = newnode;
    newnode->next = NULL;
    temp = head;
    printf("Elements are: ");
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}
void deletion_beg_ll()
{
    temp = head;
    if (head == NULL)
    {
        printf("Linked list is Empty!!!\n");
    }
    else
    {
        head = head->next;
        free(temp);
        temp = head;
        printf("Elements are: ");
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n\n");
    }
}
void deletion_any_ll()
{
    struct node1 *prev;
    int pos1 = 1;
    int i1 = 1;
    temp = head;
    printf("Enter postion which you want to delete node\n");
    scanf("%d", &pos1);
    if (pos1 == 1)
    {
        head = head->next;
        free(temp);
        temp = head;
    }
    else
    {
        while (i1 < pos1)
        {
            prev = temp;
            temp = temp->next;
            i1++;
        }
        prev->next = temp->next;
        free(temp);
        temp = head;
    }
    printf("Elements are: ");
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}
void deletion_end_ll()
{
    temp = head;
    if (head == NULL)
    {
        printf("Linked list is Empty!!!\n\n");
    }
    else
    {
        struct node1 *prev;
        temp = head;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
        temp = head;
        printf("Elements are: ");
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n\n");
    }
}

void creation_dl()
{
    struct node2 *newnode;
    head2 = NULL;
    int choice = 1;
    while (choice)
    {
        newnode = (struct node2 *)malloc(sizeof(struct node2));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;
        if (head2 == NULL)
        {
            head2 = temp2 = newnode;
        }
        else
        {
            temp2->next = newnode;
            newnode->prev = temp2;
            temp2 = newnode;
        }
        printf("\nDo you want to add more node\nif yes press 1\nNo press 0\n");
        scanf("%d", &choice);
    }
    temp2 = head2;
    printf("Elements are: \t");
    while (temp2 != NULL)
    {
        printf("%d\t", temp2->data);
        temp2 = temp2->next;
    }
    printf("\n\n");
}

void insertion_beg_dl()
{
    struct node2 *newnode;
    newnode = (struct node2 *)malloc(sizeof(struct node2));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;
    temp2 = head2;
    newnode->next = temp2;
    temp2->prev = newnode;
    head2 = newnode;
    temp2 = head2;
    printf("Elements are: \t");
    while (temp2 != NULL)
    {
        printf("%d\t", temp2->data);
        temp2 = temp2->next;
    }
    printf("\n\n");
}

void insertion_any_dl()
{
    int pos;
    struct node2 *newnode;
    newnode = (struct node2 *)malloc(sizeof(struct node2));
    printf("Enter postion where you want to insert a node : ");
    scanf("%d", &pos);
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;
    temp2 = head2;
    int i = 1;
    if (pos == 1)
    {
        newnode->prev = NULL;
        temp2->prev = newnode;
        newnode->next = temp2;
        head2 = newnode;
        temp2 = head2;
    }
    else
    {
        while (i < (pos - 1))
        {
            temp2 = temp2->next;
            i++;
        }
        newnode->next = temp2->next;
        newnode->prev = temp2;
        temp2->next = newnode;
        temp2 = head2;
    }
    temp2 = head2;
    printf("Elements are: \t");
    while (temp2 != NULL)
    {
        printf("%d\t", temp2->data);
        temp2 = temp2->next;
    }
    printf("\n\n");
}

void insertion_end_dl()
{
    struct node2 *newnode;
    temp2 = head2;
    newnode = (struct node2 *)malloc(sizeof(struct node2));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    newnode->next = NULL;
    newnode->prev = temp2;
    temp2->next = newnode;
    temp2 = head2;
    printf("Elements are: \t");
    while (temp2 != NULL)
    {
        printf("%d\t", temp2->data);
        temp2 = temp2->next;
    }
    printf("\n\n");
}

void deletion_beg_dl()
{
    struct node2 *temp1;
    temp2 = head2;
    head2 = head2->next;
    free(temp2);
    head2->prev = NULL;
    temp2 = head2;
    printf("Elements are: \t");
    while (temp2 != NULL)
    {
        printf("%d\t", temp2->data);
        temp2 = temp2->next;
    }
    printf("\n\n");
}

void deletion_any_dl()
{
    int pos, i = 1;
    struct node2 *temp1;
    temp2 = head2;
    printf("Enter position\n");
    scanf("%d", &pos);
    if (pos == 1)
    {
        head2 = head2->next;
        free(temp2);
        head2->prev = NULL;
        temp2 = head2;
    }
    else
    {
        while (i < (pos))
        {
            temp1 = temp2;
            temp2 = temp2->next;
            i++;
        }
        temp1->next = temp2->next;
        temp2->prev = temp1;
        free(temp2);
        temp2 = head2;
        printf("Elements are: \t");
        while (temp2 != NULL)
        {
            printf("%d\t", temp2->data);
            temp2 = temp2->next;
        }
        printf("\n\n");
    }
}
void deletion_end_dl()
{
    struct node2 *temp1;
    temp2 = head2;
    while (temp2->next != NULL)
    {
        temp1 = temp2;
        temp2 = temp2->next;
    }
    temp1->next = NULL;
    free(temp2);
    temp2 = head2;
    printf("Elements are: \t");
    while (temp2 != NULL)
    {
        printf("%d\t", temp2->data);
        temp2 = temp2->next;
    }
    printf("\n\n");
}

void creation_cl()
{
    struct node3 *newnode;
    temp3 = NULL;
    int choice = 1;
    while (choice)
    {
        newnode = (struct node3 *)malloc(sizeof(struct node3));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (temp3 == NULL)
        {
            temp3 = newnode;
            temp3->next = newnode;
        }
        else
        {
            newnode->next = temp3->next;
            temp3->next = newnode;
            temp3 = newnode;
        }
        printf("\nDo tou want to insert more node\nif yes press 1\nif No press 0\n");
        scanf("%d", &choice);
    }
    struct node3 *p = temp3->next;
    printf("Elements are: \t");
    while (p->next != temp3->next)
    {
        printf("%d\t", temp3->data);
        temp3 = temp3->next;
    }
    printf("%d\t", temp3->data);
    printf("\n\n");
}
void insertion_beg_cl()
{
    struct node3 *newnode;
    temp3 = head3;
    newnode = (struct node3 *)malloc(sizeof(struct node3));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (temp3 == NULL)
    {
        head3 = temp3 = newnode;
        temp3->next = newnode;
    }
    else
    {
        newnode->next = temp3->next;
        temp3->next = newnode;
    }
    struct node3 *p = temp3->next;
    printf("Elements are: \t");
    while (p->next != temp3->next)
    {
        printf("%d\t", temp3->data);
        temp3 = temp3->next;
    }
    printf("%d\t", temp3->data);
    printf("\n\n");
}
void insertion_any_cl()
{
    int pos, i = 1;
    struct node3 *newnode;
    newnode = (struct node3 *)malloc(sizeof(struct node3));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    printf("Enter the value of position where you want to insert node: ");
    scanf("%d", &pos);
    struct node3 *p = temp3->next;
    int length;
    while (p->next != temp3->next)
    {
        temp3 = temp3->next;
        length++;
    }
    if (pos < 1 || pos > length)
    {
        printf("Invalide postion!!!\n");
    }
    else if (pos == 1)
    {
        newnode->next = temp3->next;
        temp3->next = newnode;
    }
    else
    {
        struct node3 *p = temp3->next;
        while (i < (pos - 1))
        {
            temp3 = temp3->next;
            i++;
        }
        newnode->next = temp3->next;
        temp3->next = newnode;
    }
    p = temp3->next;
    printf("Elements are: \t");
    while (p->next != temp3->next)
    {
        printf("%d\t", temp3->data);
        temp3 = temp3->next;
    }
    printf("%d\t", temp3->data);
    printf("\n\n");
}
void insertion_end_cl()
{
    struct node3 *newnode;
    newnode = (struct node3 *)malloc(sizeof(struct node3));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (temp3 == NULL)
    {
        head3 = temp3 = newnode;
        temp3->next = newnode;
    }
    else
    {
        newnode->next = temp3->next;
        temp3->next = newnode;
        temp3 = newnode;
    }
    struct node3 *p = temp3->next;
    printf("Elements are: ");
    while (p->next != temp3->next)
    {
        printf("%d\t", temp3->data);
        temp3 = temp3->next;
    }
    printf("%d\t", temp3->data);
    printf("\n\n");
}
void deletion_beg_cl()
{
    struct node3 *p = temp3->next;
    if (temp3 == NULL)
    {
        printf("circular linked list is empty!!!\n");
    }
    else if (p->next == p)
    {
        temp3 = NULL;
        free(temp);
    }
    else
    {
        temp3->next == p->next;
        free(p);
    }
}

void deletion_any_cl()
{
    struct node3 *p, *p1, *current;
    int count = 0, i = 1, pos;
    p = temp3->next;
    current = temp3->next; //                                           here chacked
    while (p->next != temp3->next)
    {
        count++;
        temp3 = temp3->next;
    }
    printf("Enter position: ");
    scanf("%d", &pos);
    int length;
    while (p->next != temp3->next)
    {
        temp3 = temp3->next;
        length++;
    }
    if (pos < 1 || pos > length)
    {
        printf("Invalide position!!!\n");
    }
    else if (pos == 1)
    {
        deletion_beg_cl();
    }
    else
    {
        while (i < (pos - 1))
        {
            current = current->next; //here chacked
            i++;
        }
        p1 = current->next;
        current->next = p1->next;
        free(p1);
    }
}

void deletion_end_cl()
{
    struct node3 *current, *prev;
    current = temp3->next;
    if (temp3 == NULL)
    {
        printf("Linked list is Empty!!!");
    }
    else if (current->next == current)
    {
        temp3 = NULL;
        free(current);
    }
    else
    {
        while (current->next != temp3->next)
        {
            prev = current;
            current = current->next;
        }
        prev->next = temp3->next;
        temp3 = prev;
        free(current);
    }
}

void push()
{
    system("cls");
    int choice = 1;
    while (choice)
    {
        if (top >= size - 1)
        {
            printf("OVERFLOW CONDITION!!!!\n");
        }
        else
        {
            int a;
            top++;
            printf("Enter data: ");
            scanf("%d", &a);
            stack[top] = a;
        }
        printf("Do you want to insert more element\nIf yes press 1\nIf no press 0: ");
        scanf("%d", &choice);
    }
    printf("Elements are: \t");
    for (int i = 0; i <= top; i++)
    {
        printf("%d\t", stack[i]);
    }
    printf("\n\n");
}
void pop()
{
    system("cls");
    int choice = 1;
    while (choice)
    {
        if (top < 0)
        {
            printf("UNDERFLOW CONDITION!!!!\n");
        }
        else
        {
            top--;
            printf("Top element is poped from stack!!!\n");
        }
        printf("Do you want to insert more element\nIf yes press 1\nIf no press 0: ");
        scanf("%d", &choice);
    }
    printf("Elements are: \t");
    for (int i = 0; i <= top; i++)
    {
        printf("%d\t", stack[i]);
    }
    printf("\n\n");
}
void peek()
{
    system("cls");
    if (top < 0)
    {
        printf("NO Elements are present in the stack!!!\n");
    }
    else
    {
        printf("The Peek Element is: %d\n", stack[top]);
    }
}
void isEmpty()
{
    system("cls");
    if (top < 0)
    {
        printf("Stack is Empty!!!\n");
    }
    else
    {
        printf("Stack is Not Empty!!!\n");
    }
}
void isFull()
{
    system("cls");
    if (top >= (size - 1))
    {
        printf("Stack is Full!!!\n");
    }
    else
    {
        printf("Stack is Not FULL!!!\n");
    }
}
void display()
{
    system("cls");
    if (top < 0)
    {
        printf("Stack is Empty!!!\n");
    }
    else
    {
        printf("Elements are: \t");
        for (int i = 0; i <= top; i++)
        {
            printf("%d\t", stack[i]);
        }
        printf("\n\n");
    }
}
void display1()
{
    if (front == -1 && rere == -1)
    {
        printf("Queue is Empty!!!\n");
    }
    else
    {
        printf("Elements are: \t");
        for (int i = front; i <= rere; i++)
        {
            printf("%d\t", queue[i]);
        }
        printf("\n\n");
    }
}
void enQueue()
{
    int choice = 1;
    while (choice)
    {
        if (rere == size - 1)
        {
            printf("OVERFLOW CONDITION!!!\n");
        }
        else if (rere == -1 && front == -1)
        {
            rere = front = 0;
            int a;
            printf("Enter data: ");
            scanf("%d", &a);
            queue[rere] = a;
        }
        else
        {
            int b;
            printf("Enter data: ");
            scanf("%d", &b);
            rere++;
            queue[rere] = b;
        }
        printf("Do you want to insert more element in queue\nIf yes press 1\nIf No press 0: ");
        scanf("%d", &choice);
    }
    display1();
}
void deQueue()
{
    if (front == -1 && rere == -1)
    {
        printf("UNDERFLOW CONDITION!!!\n");
    }
    else if (front == rere)
    {
        printf("Now Queue is Empty!!!\n");
        rere = front = -1;
    }
    else
    {
        front++;
    }
    display1();
}
void peek1()
{
    if (front == -1 && rere == -1)
    {
        printf("Queue is Empty!!!\n");
    }
    else
    {
        printf("The front element: %d\n", queue[front]);
    }
}

void linear()
{
    int a, b;
    printf("Enter the length of the array: ");
    scanf("%d", &a);
    int array[a];
    for (int i = 0; i < a; i++)
    {
        printf("Enter data: ");
        scanf("%d", &array[i]);
    }
    printf("\nEnter element which you want to search: ");
    scanf("%d", &b);
    int flag = 1;
    for (int i = 0; i < a; i++)
    {
        if (array[i] == b)
        {
            printf("Element are found at position %d is: %d\n", (i + 1), array[i]);
            flag = 0;
        }
    }
    if (flag)
    {
        printf("Element are not found!!!\n");
    }
}
void binary()
{
    int a, b;
    printf("Entre length of the array: ");
    scanf("%d", &a);
    int array[a];
    int flag = 1;
    printf("Enter data in the array in assending order!!!\n");
    for (int i = 0; i < a; i++)
    {
        printf("Enter data: ");
        scanf("%d", &array[i]);
    }
    printf("\nEnter element which you want to search: ");
    scanf("%d", &b);
    int l = 0;
    int r = a;
    while (1)
    {
        int mid = (l + r) / 2;
        if (b > array[mid])
        {
            l = mid + 1;
        }
        else if (b < array[mid])
        {
            r = mid - 1;
        }
        else
        {
            printf("Element are found at position  is: %d\n", mid + 1);
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        printf("Element are not found in the array!!!\n\n");
    }
}
void bubble_sort()
{
    system("cls");
    int a;
    printf("Enter the length of the array: ");
    scanf("%d", &a);
    int array[a];
    for (int i = 0; i < a; i++)
    {
        printf("Enter data: ");
        scanf("%d", &array[i]);
    }
    int flag = 0;
    for (int i = 0; i < a - 1; i++)
    {
        for (int j = 0; j < (a - i - 1); j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }

    printf("\nAfter sorting Element are: \t");
    for (int i = 0; i < a; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n\n");
}
void insertion_sort()
{
    system("cls");
    int a;
    printf("Enter the length of the array!!!: ");
    scanf("%d", &a);
    int array[a];
    for (int i = 0; i < a; i++)
    {
        printf("Enter data: ");
        scanf("%d", &array[i]);
    }

    for (int i = 1; i < a; i++)
    {
        int temp = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > temp)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }

    printf("\nAfter sorting Element are: \t");
    for (int i = 0; i < a; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n\n");
}
void selection_sort()
{
    system("cls");
    int a;
    printf("Enter the length of the array!!!: ");
    scanf("%d", &a);
    int array[a];
    for (int i = 0; i < a; i++)
    {
        printf("Enter data: ");
        scanf("%d", &array[i]);
    }
    for (int i = 0; i < a; i++)
    {
        for (int j = i + 1; j < a; j++)
        {
            if (array[i] > array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    printf("\nAfter sorting Element are: \t");
    for (int i = 0; i < a; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n\n");
}
// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r)
{
   // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}
void merge_sort(int a[], int lb, int ub)
{
    if (ub > lb)
    {
        int mid = (ub + lb) / 2;
        merge_sort(a, lb, mid);
        merge_sort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to find the partition position
int partition(int array[], int low, int high) {
  
  // select the rightmost element as pivot
  int pivot = array[high];
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]);
  
  // return the partition point
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);
    
    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);
    
    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}
void quick_sort(int array[], int lb, int ub)
{
    if (lb < ub)
    {
        int loc = partition(array, lb, ub);
        quick_sort(array, lb, loc - 1);
        quick_sort(array, loc + 1, ub);
    }
}

void preoder_T_BT(struct node_t *n)
{
    if (n == NULL)
    {
        printf("Tree is Completly Empty!!!\n\n");
        return;
    }
    else
    {
        // printf("Elements are after preoder traversal: ");
        printf("\t%d", n->data);
        preoder_T_BT(n->left);
        preoder_T_BT(n->right);
    }
}
struct node_t *creation_BT()
{
    int x;
    struct node_t *newnode;
    newnode = (struct node_t *)malloc(sizeof(struct node_t));
    newnode->left = NULL;
    newnode->right = NULL;
    printf("-1. for No node\n");
    printf("Enter Data: ");
    scanf("%d", &x);
    if (x == -1)
    {
        return 0;
    }
    newnode->data = x;
    printf("Enter Left child of : %d\n ", x);
    newnode->left = creation_BT();
    printf("Enter right child of : %d\n ", x);
    newnode->right = creation_BT();
    preoder_T_BT(newnode);
    return newnode;
}

void inoder_T_BT(struct node_t *n)
{
    if (n == NULL)
    {
        printf("Tree is Completly Empty!!!\n\n");
        return;
    }
    else
    {
        printf("Elements are after inoder traversal: ");
        inoder_T_BT(n->left);
        printf("\t%d", n->data);
        inoder_T_BT(n->right);
    }
}
void postoder_T_BT(struct node_t *n)
{
    if (n == NULL)
    {
        printf("Tree is Completly Empty!!!\n\n");
        return;
    }
    else
    {
        printf("Elements are after postoder traversal: ");
        postoder_T_BT(n->left);
        postoder_T_BT(n->right);
        printf("\t%d", n->data);
    }
}
void menu1()
{
    system("cls");
    int choice = 1;
    while (choice != 6)
    {
        printf("1. for insertion of element in array\n");
        printf("2. for traversing of the array\n");
        printf("3. for deletion of the element from the array\n");
        printf("4. for searching of element from in array\n");
        printf("5. for displaying elements from stack\n");
        printf("6. To exit\n\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertion();
            break;
        case 2:
            traverse();
            break;
        case 3:
            delete_element();
            break;
        case 4:
            search();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("You are exiting from array operation!!!\n\n");
            break;
        default:
            printf("You entred invalide choice... Please try again...\n\n");
            break;
        }
    }
}
void menu2()
{
    system("cls");
    int choice = 1;
    while (choice != 5)
    {
        printf("1. for operation in single linked list\n");
        printf("2. for operation in doubly linked list\n");
        printf("3. for operation in circular linked lis\n");
        printf("4. for operation in doubly circular linked lis\n");
        printf("5. To exit\n\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            system("cls");
            int choice1 = 1;
            while (choice1 != 8)
            {
                printf("1. for creation of single linked list\n");
                printf("2. for insertion at beg linked list\n");
                printf("3. for insertion at any linked list\n");
                printf("4. for insertion at end linked list\n");
                printf("5. for deletion at beg linked list\n");
                printf("6. for deletion at any linked list\n");
                printf("7. for deletion at end linked list\n");
                printf("8. To exit\n\n");
                printf("Please enter your choice: ");
                scanf("%d", &choice1);
                switch (choice1)
                {
                case 1:
                    system("cls");
                    creation_ll();
                    break;
                case 2:
                    system("cls");
                    insertion_beg_ll();
                    break;
                case 3:
                    system("cls");
                    insertion_any_ll();
                    break;
                case 4:
                    system("cls");
                    insertion_end_ll();
                    break;
                case 5:
                    system("cls");
                    deletion_beg_ll();
                    break;
                case 6:
                    system("cls");
                    deletion_any_ll();
                    break;
                case 7:
                    system("cls");
                    deletion_end_ll();
                    break;
                case 8:
                    system("cls");
                    printf("You are exiting from operation of single linked list\n\n");
                    break;
                default:
                    system("cls");
                    printf("Invalide choice... Please try again...\n\n");
                    break;
                }
            }
            break;
        case 2:
            system("cls");
            int choice2 = 1;
            while (choice2 != 8)
            {
                printf("1. for creation of doubly linked list\n");
                printf("2. for insertion at beg in doubly linked list\n");
                printf("3. for insertion at any in doubly linked list\n");
                printf("4. for insertion at end in doubly linked list\n");
                printf("5. for deletion at beg in doubly linked list\n");
                printf("6. for deletion at any in doubly linked list\n");
                printf("7. for deletion at end in doubly linked list\n");
                printf("8. To exit\n\n");
                printf("Please enter your choice: ");
                scanf("%d", &choice2);
                switch (choice2)
                {
                case 1:
                    system("cls");
                    creation_dl();
                    break;
                case 2:
                    system("cls");
                    insertion_beg_dl();
                    break;
                case 3:
                    system("cls");
                    insertion_any_dl();
                    break;
                case 4:
                    system("cls");
                    insertion_end_dl();
                    break;
                case 5:
                    system("cls");
                    deletion_beg_dl();
                    break;
                case 6:
                    system("cls");
                    deletion_any_dl();
                    break;
                case 7:
                    system("cls");
                    deletion_end_dl();
                    break;
                case 8:
                    system("cls");
                    printf("You are exiting from operation of single linked list\n\n");
                    break;
                default:
                    system("cls");
                    printf("Invalide choice... Please try again...\n\n");
                    break;
                }
            }
            break;
        case 3:
            system("cls");
            int choice3 = 1;
            while (choice3 != 8)
            {
                printf("1. for creation of circular linked list\n");
                printf("2. for insertion at beg in circular linked list\n");
                printf("3. for insertion at any in circular linked list\n");
                printf("4. for insertion at end in circular linked list\n");
                printf("5. for deletion at beg in circular linked list\n");
                printf("6. for deletion at any in circular linked list\n");
                printf("7. for deletion at end in circular linked list\n");
                printf("8. To exit\n\n");
                printf("Please enter your choice: ");
                scanf("%d", &choice3);
                switch (choice3)
                {
                case 1:
                    system("cls");
                    creation_cl();
                    break;
                case 2:
                    system("cls");
                    insertion_beg_cl();
                    break;
                case 3:
                    system("cls");
                    insertion_any_cl();
                    break;
                case 4:
                    system("cls");
                    insertion_end_cl();
                    break;
                case 5:
                    system("cls");
                    deletion_beg_cl();
                    break;
                case 6:
                    system("cls");
                    deletion_any_cl();
                    break;
                case 7:
                    system("cls");
                    deletion_end_cl();
                    break;
                case 8:
                    system("cls");
                    printf("You are exiting from operation of single linked list\n\n");
                    break;
                default:
                    system("cls");
                    printf("Invalide choice... Please try again...\n\n");
                    break;
                }
            }
            break;
        case 5:
            system("cls");
            printf("You are exiting from linked list operation!!!\n\n");
            break;
        default:
            system("cls");
            printf("You entered invalid choice... Please try again...\n\n");
            break;
        }
    }
}
void menu3()
{
    system("cls");
    int choice = 1;
    while (choice != 6)
    {
        printf("1. For Push() Operation on stack\n");
        printf("2. For pop() Operation on stack\n");
        printf("3. For Peek() Operation on stack\n");
        printf("4. For IsEmpty() Operation on stack\n");
        printf("5. For IsFull() Operation on stack\n");
        printf("6. To Exit From Stack\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            isEmpty();
            break;
        case 5:
            isFull();
            break;
        case 6:
            printf("Now you are Exiting from stack!!!\n\n");
            break;
        default:
            printf("Invalide choice choice...Try again...\n\n");
            break;
        }
    }
}

void menu4()
{
    system("cls");
    int choice = 1;
    while (choice != 5)
    {
        printf("1. For enQueue() Operation\n");
        printf("2. For deQueue() Operation\n");
        printf("3. For peek() Operation\n");
        printf("4. For display() Operation\n");
        printf("5. To Exit Form Queue\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enQueue();
            break;
        case 2:
            deQueue();
            break;
        case 3:
            peek1();
        case 4:
            display1();
            break;
        case 5:
            printf("You are exiting from Queue operation\n");
            break;
        default:
            printf("You enterde Invalide choice...Pls try again...\n\n");
            break;
        }
    }
}

void menu7()
{
    system("cls");
    int choice = 1;
    while (choice != 3)
    {
        printf("1. For Linear Search\n");
        printf("2. for Binary Search\n");
        printf("3. To Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            linear();
            break;
        case 2:
            binary();
            break;
        case 3:
            printf("Now you are Exiting from Search operation!!!!\n\n");
            break;
        default:
            printf("You Entered invalide choice...Please Try Again...\n\n");
            break;
        }
    }
}

void menu8()
{
    system("cls");
    int choice = 1;
    while (choice != 6)
    {
        printf("1. For Bubble Sort\n");
        printf("2. For Insertion Sort\n");
        printf("3. For Selection Sort\n");
        printf("4. For Merge Sort\n");
        printf("5. For Quick Sort\n");
        printf("6. To Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            bubble_sort();
            break;
        case 2:
            insertion_sort();
            break;
        case 3:
            selection_sort();
            break;
        case 4:
        {
            system("cls");
            int a;
            printf("Enter the length of the array: ");
            scanf("%d", &a);
            int arr[a];
            for (int i = 0; i < a; i++)
            {
                printf("Enter data: ");
                scanf("%d", &arr[i]);
            }
            merge_sort(arr, 0, a - 1);
            printf("\nAfter sorting Element are: \t");
            for (int i = 0; i < a; i++)
            {
                printf("%d\t", arr[i]);
            }
            printf("\n\n");
            break;
        }
        case 5:
        {
            system("cls");
            int a;
            printf("Enter the length of the array: ");
            scanf("%d", &a);
            int arr[a];
            for (int i = 0; i < a; i++)
            {
                printf("Enter data: ");
                scanf("%d", &arr[i]);
            }
            quick_sort(arr, 0, a);
            printf("\nAfter Sorting Element are: \t");
            for (int i = 0; i < a; i++)
            {
                printf("%d\t", arr[i]);
            }
            printf("\n\n");
            break;
        }
        case 6:
            printf("Now we are Exiting form sorting operation!!!\n\n");
            break;
        default:
            printf("Invalide choice...Please try again...\n\n");
            break;
        }
    }
}

void menu5()
{
    system("cls");
    int choice = 1;
    while (choice != 5)
    {
        printf("1. For Creation of Binary Tree\n");
        printf("2. For Preoder Traversal Of binary tree\n");
        printf("3. For Inoder Traversal Of Binary tree\n");
        printf("4. For Post Oder Traversal Of Binary Tree\n");
        printf("5. To Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            creation_BT();
            break;
        case 2:
            // struct node_t *root;
            // root = creation_BT();
            preoder_T_BT(creation_BT());
            break;
        case 3:
            // struct node_t *root;
            root = creation_BT();
            inoder_T_BT(root);
            break;
        case 4:
            // struct node_t *root;
            root = creation_BT();
            postoder_T_BT(root);
            break;
        case 5:
            printf("We are Exiting from tree operation!!!\n\n");
            break;
        default:
            printf("Invalide choice...Please try again...\n\n");
            break;
        }
    }
}
int main()
{
    system("cls");
    printf("Welcome to all in one Menu Driven data structure using C !!\n\n");
    while (1)
    {
        printf("1. For Array Operation\n");
        printf("2. For Linked List Operation\n");
        printf("3. For Stack Operation\n");
        printf("4. For Queue Operation\n");
        printf("5. For Tree Operattion\n");
        printf("6. For Graph Opeeration\n");
        printf("7. For Searching Operation\n");
        printf("8. For Sorting Operation\n");
        printf("9. To Exit\n");
        int choice;
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            menu1();
            break;
        case 2:
            menu2();
            break;
        case 3:
            menu3();
            break;
        case 4:
            menu4();
            break;
        case 5:
            menu5();
            break;
        // case 6:
        //     menu6();
        //     break;
        case 7:
            menu7();
            break;
        case 8:
            menu8();
            break;
        case 9:
            exit(0);
        default:
            printf("Invalide choice...Please tyr again..\n\n");
            break;
        }
    }

    return 0;
}