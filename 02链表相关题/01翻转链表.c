#include <stdio.h>
class Node
{
public:
	Node* next;
	int val;
};
Node* reverse(Node* pRoot)
{
	Node* p3 = NULL;
	Node* p2 = pRoot;
	Node* p1 = p2->next;
	while (p1 != NULL)
	{
		p2->next = p3;
		p3 = p2;
		p2 = p1;
		p1 = p1->next;
	}
	return p2;
}
