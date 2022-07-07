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

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    LinkedListNode<int> *prev, *current, *next1;
    prev = NULL;
    current = head;
    
    while (current != NULL)
    {
        next1 = current->next;
        current->next = prev;
        prev = current;
        current = next1;
    }
    return prev;
}

// TC -> O(N)
// SC -> O(1)