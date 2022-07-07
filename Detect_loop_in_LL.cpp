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

bool detectCycle(Node *head)
{
	//	Write your code here
    unordered_set<Node *>s;
    while(head != NULL)
    {
        if(s.find(head) != s.end()) return true;
        s.insert(head);
        head = head->next;
    }
    
    return false;
}


//Floyd’s Cycle-Finding Algorithm 

bool detectCycle(Node *head)
{
	//	Write your code here
        Node *fast = head;
        Node *slow = head;

        while(fast != NULL && fast->next!=NULL &&slow != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow) return true;
        }

        return false;
}
// TC-> O(N)
// SC-> O(1)

// Using visited node

bool detectCycle(Node *head)
{
	//	Write your code here
     Node *temp = new Node(0);
     
    while(head != NULL)
    {
        if(head-> next == NULL) return false;
        if(head-> next == temp) return true;
        
        Node *next = head->next;
        head->next = temp;
        head = next;
    }
     return false;   
}







