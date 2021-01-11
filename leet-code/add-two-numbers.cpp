/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      auto currentNode1 = l1;
      auto currentNode2 = l2;
      auto l3 = new ListNode();
      auto currentNode3 = l3;
      int sum = 0, carry = 0, val = 0;
      while(currentNode1 != NULL and currentNode2 != NULL) {
        sum = currentNode1 -> val + currentNode2 -> val + carry;
        val = sum % 10;
        currentNode3 -> val = val;
        currentNode1 = currentNode1 -> next;
        currentNode2 = currentNode2 -> next;
        if(currentNode1 != NULL and currentNode2 != NULL){
          currentNode3 -> next = new ListNode();
          currentNode3 = currentNode3 -> next;  
        }
        carry = sum / 10;
      }
      if(currentNode1 != NULL or currentNode2 != NULL) {
        currentNode3 -> next = new ListNode();
        currentNode3 = currentNode3 -> next;
      }
      while(currentNode1 != NULL) {
        sum = currentNode1 -> val + carry;
        val = sum % 10;
        currentNode3 -> val = val;
        currentNode1 = currentNode1 -> next;
        if(currentNode1 != NULL) {
          currentNode3 -> next = new ListNode();
          currentNode3 = currentNode3 -> next;
        }
        carry = sum / 10;
      }
      while(currentNode2 != NULL) {
        sum = currentNode2 -> val + carry;
        val = sum % 10;
        currentNode3 -> val = val;
        currentNode2 = currentNode2 -> next;
        if(currentNode2 != NULL) {
          currentNode3 -> next = new ListNode();
          currentNode3 = currentNode3 -> next;
        }
        carry = sum / 10;
      }
      if(carry != 0){
        currentNode3 -> next = new ListNode(carry);
      }
      return l3;
    }
};
