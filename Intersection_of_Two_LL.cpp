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

int findIntersection(Node *headA, Node *headB)
{
    int n = 0;
    int m = 0;

    for(auto temp = headA; temp!= NULL; temp = temp->next) n++;
    for(auto temp = headB; temp!= NULL; temp = temp->next) m++;

    if(n > m){
        int move = n-m;

        Node *dummy = headA;
        Node *dummy1 = headB;
        while(move){
            dummy = dummy->next;
            move--;
        }

        while(dummy != NULL || dummy1 != NULL){
            if(dummy == dummy1) return dummy->data;
            dummy = dummy->next;
            dummy1 = dummy1->next;
        }
    }
    else{
        int move = m-n;

        Node *dummy = headB;
        Node *dummy1 = headA;
        while(move){
            dummy = dummy->next;
            move--;
        }

        while(dummy != NULL || dummy1 != NULL){
            if(dummy == dummy1) return dummy->data;
            dummy = dummy->next;
            dummy1 = dummy1->next;
        }
    }

    return -1;
}


// Another approach
int findIntersection(Node *headA, Node *headB)
{
        if(headA == NULL || headB == NULL) return -1;
        
        Node *a = headA;
        Node *b = headB;
        
        while(a!=b){
            a = a == NULL ? headB : a->next;
            b = b == NULL ? headA : b->next;
        }
        
        if(a == NULL) return -1;
        return a->data; 
}






