#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    Node<int> *newhead = new Node<int>(-1);
    Node<int> *temp = newhead;

    while(first != NULL && second != NULL){
        
        if(first->data <= second->data){
            temp->next = first;
            first = first->next;
            temp = temp->next;
        }

        else{
            temp->next = second;
            second = second->next;
            temp = temp->next;
        }
    }

    while(first != NULL){
        temp->next = first;
        first = first->next;
        temp = temp->next;
    }

    while(second != NULL){
        temp->next = second;
        second = second->next;
        temp = temp->next;
    }
    
    return newhead->next;
}

//************************************************************
Node<int>* sortTwoLists(Node<int>* l1, Node<int>* l2)
{
    // Write your code here.
        if(l1 == NULL) return l2; 
        if(l2 == NULL) return l1;
        if(l1->data > l2->data) std::swap(l1,l2);

        Node<int>* res = l1;

        while(l1 != NULL && l2 != NULL) {
 
            Node<int>* temp = NULL;

            while(l1 != NULL && l1->data <= l2->data) {

                temp = l1;
                l1 = l1->next;
            }
            temp->next = l2;
            std::swap(l1,l2);
        }

        return res;
    }










