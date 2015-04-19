#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct ListNode {
	int val;
	struct ListNode *next;
};
int getLength(struct ListNode *head)
{
	int len = 0;
	struct ListNode *p = head;
	while (p) {
		++len;
		p = p->next;
	}
	return len;
}
void print(struct ListNode *ha, struct ListNode *hb)
{
	struct ListNode *p = getIntersectionNode(ha, hb);
	if (p == NULL)
		printf("NULL\n");
	else
		printf("%d\n", p -> val);
}
struct ListNode * mk_list(struct ListNode **ha, int a[], int n)
{
	struct ListNode *p = malloc(sizeof(*p));
	p->val = a[0];
	p->next = NULL;
	*ha = p;
	for (int i = 1; i < n; ++i) {
		struct ListNode *q = malloc(sizeof(*q));
		q->val = a[i];
		q->next = NULL;
		p->next = q;
		p = q;
	}
	return p;
}
int main(int argc, char **argv)
{
	return 0;
}
