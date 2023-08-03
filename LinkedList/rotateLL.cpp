/// Suppose rotate length=5 while k=10... 1-2-3-4-5
/// k 5 bar ghurle same hocche, so mane 2 bar rotate kra==k10;
/// k>=len hole ajnno k%len use krbo bar bar k prjnto rotae na kre. K<len holeo same
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* rotateRight(ListNode* head, int k) {   ///O(n)
    if(!head || !head->next || k==0) return head;

    int len = 1;
    ListNode *curr = head;

    while(curr->next && ++len)
        curr = curr->next;

    curr->next = head;

    k = k%len;
    k = len-k;

    while(k--)
        curr = curr->next;

    head = curr->next;
    curr->next = NULL;

    return head;
}



int main(){
     ListNode * head = new ListNode(1);
     head->next = new ListNode(2);
     head->next->next = new ListNode(3);
     head->next->next->next =  new ListNode(4);
     head->next->next->next->next  =   new ListNode(5);

     ListNode *ans = rotateRight(head, 2);
     ListNode *tmp = ans;

       while(tmp->next){
            cout<<tmp->val<<" ";
            tmp=tmp->next;
        }

    return 0;
}
