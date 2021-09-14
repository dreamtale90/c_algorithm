#include <stdio.h>
#include <stdlib.h>
#include "base/list.h"

struct list* reverse_list(struct list *lst)
{
	struct list *head, *tail, *temp;
	head = tail = lst;
	while (lst) {
		temp = lst;
		lst = lst->next;
		temp->next = head;
		head = temp;
	}

	tail->next = NULL;
	return head;
}

int main()
{
	struct list lst = {0, NULL};
	for (size_t i = 0; i < 10; i++) {
		add_item(&lst, i+1);
	}

	print(&lst);
	struct list *head = reverse_list(&lst);
    printf("after reverse list:\n");
	print(head);
}
