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
        ListNode* reverseHead = nullptr;
        ListNode* current = head;
        // Create a linked-list with reverse value
        while(current != nullptr) {
            ListNode *node = new ListNode(current->val, reverseHead);
            reverseHead = node;
            current = current->next;
        }
        // Copy reverse list to actual list
        current = head;
        while(reverseHead != nullptr) {
            current->val = reverseHead->val;
            reverseHead = reverseHead->next;
            current = current->next;
        }
        return head;
    }
};

int main(int argc, char** argv)
{
    struct proc_t usage;
    clock_t tStart = clock();

    // Variables
    ListNode* result;

    // Input
    ListNode head(1);
    ListNode* current = &head;
    for(int i = 2; i <= 5; ++i) {
        current->next = (ListNode*)malloc(sizeof(ListNode));
        current->next->val = i;
        current->next->next = nullptr;
        current = current->next;
    }
    // removeNthFromEnd
    // Main
    Solution solution;
    // result = solution.removeNthFromEnd(&head, 2);
    result = solution.reverseList(&head);
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