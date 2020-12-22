#include <proc/readproc.h>
#include <time.h>

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        for(int i = 1; i <= n + 1; ++i) {
            fast = fast->next;
        }
        while(fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }

    ListNode* reverseList(ListNode* head)
    {
        // // 1rst solution
        // ListNode* reverseHead = nullptr;
        // ListNode* current = head;
        // // Create a linked-list with reverse value
        // while(current != nullptr) {
        //     ListNode *node = new ListNode(current->val, reverseHead);
        //     reverseHead = node;
        //     current = current->next;
        // }
        // // Copy reverse list to actual list
        // current = head;
        // while(reverseHead != nullptr) {
        //     current->val = reverseHead->val;
        //     reverseHead = reverseHead->next;
        //     current = current->next;
        // }
        // return head;

        // // 2nd solution
        // // Iterate through List and reverse direction of each link
        // ListNode* node = nullptr;
        // ListNode* dummyHead = nullptr;
        // node = head;
        // while (node != nullptr) {
        //     // Move node to next node, use tmp to save current node
        //     ListNode* tmp = node;
        //     node = node->next;
        //     // Reverse direction of each link
        //     tmp->next = dummyHead;
        //     dummyHead = tmp;
        // }
        // head = dummyHead;
        // return head;

        // 3rd solution - recursive
        if((head == nullptr) || (head->next == nullptr)) {
            return head;
        }
        ListNode* dummyHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return dummyHead;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;

        ListNode* c1 = l1;
        ListNode* c2 = l2;
        ListNode* tmp = nullptr;

        while((c1 != nullptr) && (c2 != nullptr)) {
            if((c1->next != nullptr) && (c1->next->val <= c2->val)) {
                c1 = c1->next;
                continue;
            }
            if((c2->next != nullptr) && (c2->next->val < c1->val)) {
                c2 = c2->next;
                continue;
            }
            if(c1->val <= c2->val) {
                tmp = c1->next;
                c1->next = c2;
                c1 = tmp;
            } else {
                tmp = c2->next;
                c2->next = c1;
                c2 = tmp;
            }
        }
        return (l1->val <= l2->val) ? l1 : l2;
    }

    // bool hasCycle(ListNode* head) {}
};

int main(int argc, char** argv)
{
    struct proc_t usage;
    clock_t tStart = clock();

    // Variables
    ListNode* result;

    // Input
    ListNode* head = new ListNode(8);
    head = new ListNode(6, head);
    head = new ListNode(5, head);
    head = new ListNode(2, head);
    head = new ListNode(1, head);
    ListNode* secondHead = new ListNode(10);
    secondHead = new ListNode(7, secondHead);
    secondHead = new ListNode(4, secondHead);
    secondHead = new ListNode(3, secondHead);
    secondHead = new ListNode(1, secondHead);

    // removeNthFromEnd
    // Main
    Solution solution;
    // result = solution.removeNthFromEnd(head, 2);
    // result = solution.reverseList(head);
    result = solution.mergeTwoLists(head, secondHead);
    // Output
    while(result != nullptr) {
        cout << result->val << ' ';
        result = result->next;
    }
    cout << '\n';
    // Runtime
    cout << "------------" << endl;
    printf("Time taken  : %.2f s\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    // Memory usage
    look_up_our_self(&usage);
    printf("Memory usage: %.2f MB\n", static_cast<float>(usage.vsize) / 1024 / 1024);
    return 0;
}