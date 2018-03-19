void DelKNode(pLinkList pList, int k)
{
    pLinkNode front = NULL;
    pLinkNode back = NULL;
    pLinkNode del = NULL;

    assert(pList);
    if (pList->pHead == NULL)
    {
        printf("链表为空！！\n");
        return;
    }
    if (k == 1)
    {
        printf("K应当大于1\n");
        return;
    }
    front = back = pList->pHead;
    while (front != NULL)
    {
        k--;
        if (k < 0)
        {
            back = back->next;
        }
        front = front->next;
    }
    if (k <= 0)
    {
        back->data = back->next->data;
        del = back->next;
        back->next = back->next->next;
        free(del);
    }



}
