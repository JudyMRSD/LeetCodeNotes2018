#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printLinkedList(ListNode* head) {
    cout<<"hello"<<endl;
    while(head) {
        cout<<head->val<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

void myReverse(ListNode* head){
    ListNode* prev = NULL;
    while(head!=NULL){
        ListNode* tmp = head->next;
        head->next = prev;
        //move head and prev pointer one step forward
        prev = head;
        head = tmp;

    }
}




void myMerge(ListNode* l1, ListNode* l2){
    ListNode* l1_curr = l1;
    ListNode* l2_curr = l2;
    ListNode* l1_next = NULL;
    ListNode* l2_next = NULL;

    while(l1_curr && l2_curr){
        //save the next pointers
        l1_next = l1_curr->next;
        l2_next = l2_curr->next;
        //make l2_curr as next of l1
        l2_curr->next = l1_next;
        l1_curr->next = l2;
        //update curren pointers for next iteration
        l1_curr = l1_next;
        l2_curr = l2_next;
    }
}



void reorderList(ListNode* head) {
    if (head==NULL || head->next==NULL || head->next->next == NULL){
        return;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* l1 = head;
    ListNode* l2 = head;
    ListNode* mid = l1->next;
    while(fast && fast->next){
        mid = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    mid->next = NULL;
    myReverse(l2);
    myMerge(l1,l2);
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
    printLinkedList(&node1);

    return 0;
}