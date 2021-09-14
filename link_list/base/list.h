#ifndef MY_LIST_H
#define MY_LIST_H

struct list {
	int val;
	struct list *next;
};

void print(struct list *head);
void add_item(struct list *head, int val);

#endif //MY_LIST_H
