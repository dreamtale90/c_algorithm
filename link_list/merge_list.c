#include <stdio.h>
#include <stdlib.h>
#include "base/list.h"

struct list* merge_list(struct list *l1, struct list *l2)
{
    struct list *head = NULL;
    if (l1->val < l2->val) {
        head = l1;
        l1 = l1->next;
    } else {
        head = l2;
        l2 = l2->next;
    }

    struct list *temp = head;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            temp->next = l1;
            temp = temp->next;
            l1 = l1->next;
        } else {
            temp->next = l2;
            temp = temp->next;
            l2 = l2->next;
        }
    }

    if (!l1) {
        temp->next = l2;
    } else {
        temp->next = l1;
    }

    return head;
}

int main()
{
    struct list l1 = {0, NULL};
    for (size_t i = 0; i < 10; i++) {
        add_item(&l1, (i + 1)*2);
    }
    print(&l1);

    struct list l2 = {1, NULL};
    for (size_t i = 0; i < 10; i++) {
        add_item(&l2, (i + 1)*2 + 1);
    }
    print(&l2);

    struct list *head = merge_list(&l2, &l1);
    printf("after merge list:\n");
    print(head);

    return 0;
}
