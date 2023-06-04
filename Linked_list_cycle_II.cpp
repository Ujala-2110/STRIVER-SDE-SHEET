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
Node *firstNode(Node *head)
{
	//    Write your code here.
        Node *fast = head;
        Node *slow = head;

        do
        {
            if(fast == NULL || fast->next == NULL) return NULL;
            slow = slow->next;
            fast = fast->next->next;
        } while(fast != slow);

        fast = head;
        while(fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
}









