int getLen(ListNode *head)  
{  
    int count=0;  
    ListNode *p=head;  
    while(p != NULL)  
    {  
        count++;  
        p=p->next;  
    }  
    return count;         
}  
  
ListNode* FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) {  
    if(pHead1==NULL || pHead2==NULL) return NULL;  
    int len1=getLen(pHead1);  
    int len2=getLen(pHead2);  
      
    if(len1 >= len2)  
    {  
        int gap=len1-len2;  
        while(gap--) pHead1=pHead1->next;  
    }  
    else {  
        int gap=len2-len1;  
        while(gap--) pHead2=pHead2->next;              
    }  
    while(pHead1 != pHead2)  
    {  
        pHead1=pHead1->next;  
        pHead2=pHead2->next;  
    }  
    return pHead1;  
}  
