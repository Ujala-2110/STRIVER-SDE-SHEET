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

Node *findMiddle(Node *head) {
    // Write your code here
    if(head == NULL) return head;
    
    int cnt = 0;
    for(Node *temp = head; temp != NULL; temp = temp->next){
        cnt++;
    }
    
    int n = cnt/2;
    int i=0;
    while(i != n){
        head = head->next;
        i++;
    }
    
    return head;
}

// TC -> O(N) + O(N/2)
// SC -> O(1)


// Optimized approach

Node *findMiddle(Node *head) {
    // Write your code here
    if(head == NULL) return head;
    
    Node *fast = head, *slow = head;
    
    while(fast != NULL && fast -> next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}








