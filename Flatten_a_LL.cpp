#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/
Node *Merge(Node *a , Node *b)
{
    Node *temp = new Node(0);
    Node *res = temp;
    
    while(a != NULL && b!= NULL)
    {
        if(a->data < b->data)
        {
            temp->child = a;
            temp = temp->child;
            a = a->child;
        }
        
        else{
            temp->child = b;
            temp = temp->child;
            b = b->child;
        }
        
    }
        if(a) temp->child = a;
        else temp->child = b;
        
        return res->child;
}

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
    if(head == NULL || head->next == NULL) return head;
    
    head->next = flattenLinkedList(head->next);
    //Merge
    head = Merge(head,head->next);
    
    return head;
}

// Time Complexity: O(N*N*M) – where N is the no of nodes in main linked list (reachable using right pointer) and M is the no of node in a single sub linked list (reachable using down pointer). 

// Explanation: As we are merging 2 lists at a time,

// After adding first 2 lists, time taken will be O(M+M) = O(2M).
// Then we will merge another list to above merged list -> time = O(2M + M) = O(3M).
// Then we will merge another list -> time = O(3M + M).
// We will keep merging lists to previously merged lists until all lists are merged.
// Total time taken will be O(2M + 3M + 4M + …. N*M) = (2 + 3 + 4 + … + N)*M
// Using arithmetic sum formula: time = O((N*N + N – 2)*M/2)
// Above expression is roughly equal to O(N*N*M) for large value of N
// Space Complexity: O(N*M) – because of the recursion. The recursive functions will use recursive stack of size equivalent to total number of elements in the lists, which is N*M.