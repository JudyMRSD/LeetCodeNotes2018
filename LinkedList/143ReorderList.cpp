#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printLinkedList(ListNode* head) {
    while(head) {
        cout<<head->val<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}





ListNode* myReverse(ListNode* head){
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* nextNode = NULL;

    while(curr){
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}




void myMerge(ListNode* l1, ListNode* l2){
    while(l1){
        ListNode* n1 = l1->next;
        ListNode* n2 = l2->next;
        l1->next = l2;
        if(!n1){
            break;
        }
        l2->next = n1;
        l1 = n1;
        l2 = n2;
    }
}


void reorderList(ListNode* head) {
    if (head==NULL || head->next==NULL){
        return;
    }

    ListNode* prev = NULL;
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* l1 = head;

    while(fast && fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = NULL;
    ListNode* l2 = myReverse(slow);
    myMerge(l1, l2);
    printLinkedList(l1);
}



int main() {
    cout<<"main"<<endl;
    ListNode node1 = ListNode(1);
    ListNode node2 = ListNode(2);
    ListNode node3 = ListNode(3);
    ListNode node4 = ListNode(4);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    // printLinkedList(&node1);
    reorderList(&node1);
    return 0;
}