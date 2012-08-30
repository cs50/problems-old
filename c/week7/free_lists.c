/*****************************************************
* free_lists.c
*
* Rob Bowden
* Computer Science 50
*
* Free all elements of a linked list, both recursively
* and iteratively
*******************************************************/

#include <stdio.h>
#include <stdlib.h>

// single node in a linked list
struct node
{
    int val;
    struct node* next;
};

void free_list2(struct node* list2);
void free_list1(struct node* list1);

int
main(void)
{
    struct node* list1 = NULL;
    struct node* list2 = NULL;

    // allocate 100 elements for both of our lists
    for (int i = 0; i < 100; i++)
    {
        struct node* new1 = malloc(sizeof(struct node));
        struct node* new2 = malloc(sizeof(struct node));

        new1->next = list1;
        list1 = new1;

        new2->next = list2;
        list2 = new2;

        new1->val = i;
        new2->val = i;
    }

    free_list1(list1);
    free_list2(list2);
}


void free_list1(struct node* list1)
{
    // TODO: implement free_list1, which should free *all* elements
    // of list1 *recursively
}

void free_list2(struct node* list2)
{
    // TODO: implement free_list2, which should free *all* elements
    // of list2 *recursively
}
