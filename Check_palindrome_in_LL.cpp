#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
LinkedListNode<int>* Reverse(LinkedListNode<int> * head)
{
    LinkedListNode<int> *prev = NULL;;
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *next1;
    
    while(curr != NULL)
    {
        next1 = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next1;
    }
    
    return prev;
}

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    if(head == NULL || head ->next == NULL) return true;
    LinkedListNode<int> *fast = head;
    LinkedListNode<int> *slow = head;
    

    //Code to find middle element
    while(fast->next != NULL && fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    
    slow->next = Reverse(slow->next);;
    slow = slow->next;
    
    while(slow != NULL)
    {
        if(head->data != slow->data) return false;
        head = head->next;
        slow = slow->next;
    }
    
    return true;
    
}

//Algorithm
// --> firstly find the middle element then reverse the right half and then compare left and right half for palindrome








