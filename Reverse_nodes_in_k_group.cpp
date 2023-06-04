#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
Node* Reverse(Node *head,int k){
    Node *prev, *current, *next1;
    prev = head;
    current = head->next;

    int cnt = 0;
    while(current!= NULL && cnt != k){
        next1 = current->next;
        current->next = prev;
        prev = current;
        current = next1;
        cnt++;
    }
    
    return current;
}
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
    Node *temp = head;
    for(int i=0;i<n;i++)
    {
        temp = Reverse(temp,b[i]); 
        if(temp == NULL) break;
    }
    
    return head;
}
