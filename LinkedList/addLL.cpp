#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

     // 😉😉😉😉Please upvote if it helps 😉😉😉😉

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
     {
        ListNode *ans=new ListNode();
        ListNode *temp = ans;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry==1)
        {
            int sum=0;
            if(l1!=NULL)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                sum+=l2->val;
                l2=l2->next;
            }

           sum +=carry;
           carry=sum/10;
           ListNode *node = new ListNode(sum%10);
           temp->next=node;
           temp=temp->next;
        }
        return ans->next;
    }



int main(){


}
