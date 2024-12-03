/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode *slow=head,*fast=head;
    while(fast!= NULL && fast->next!= NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
        if(fast!=NULL){
            slow=slow->next;
        }
    struct ListNode *reverseList(struct ListNode *start){
        struct ListNode *prev=NULL,*curr=start,*next=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev; 
    }
    slow=reverseList(slow);
    fast=head;

    while(slow!=NULL){
        if(slow->val!=fast->val){
            return false;
            
        }
        fast=fast->next;
        slow=slow->next;    
    }
    return true;
}

/* Output:
Input
head =
[1,2,2,1]
Output
true
Expected
true


Input
head =
[1,2]
Output
false
Expected
false

*/
