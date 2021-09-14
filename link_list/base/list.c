#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void add_item(struct list *head, int val)
{
    while (head->next)
        head = head->next;

    struct list *item = malloc(sizeof(struct list));
    item->val = val;
    item->next = NULL;
    head->next = item;
}

void print(struct list *head)
{
    size_t i = 0;
    while (head->next) {
        printf("No.%lu = %d\n", i++, head->val);
        head = head->next;
    }
}
