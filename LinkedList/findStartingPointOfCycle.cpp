#include<bits/stdc++.h>
using namespace std;
/// Easy -- not optimal -- Hashing -- TC- O(N) SC-O(N)

/// Best -- optimal -- Two Pointer -- TC- O(N) SC-O(1)
ListNode *detectCycle(ListNode *head) {
    if (head== NULL || head->next == NULL) return NULL;

    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *entry = head;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
            if (slow == fast) {
            while(slow != entry) {
                slow = slow->next;
                entry = entry->next;
            }
            return entry;
            }
    }
        return NULL;
    }
