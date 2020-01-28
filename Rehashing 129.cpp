/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */    
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        // write your code here
        int n = hashTable.size();
        vector<ListNode*> ans(2*n);
        for(int j = 0; j < n; j++){
            ListNode *p = hashTable[j];
            ListNode *p1, *h1;
            h1 = p1 = new ListNode();
            ListNode *p2, *h2;
            h2 = p2 = new ListNode();
            while(p){
                if( (p->val - j)%(2*n) == 0 ){
                    p1->next = new ListNode(p->val);
                    p1 = p1->next;
                } else {
                    p2->next = new ListNode(p->val);
                    p2 = p2->next;
                }
                p = p->next;
            }
            ans[j] = h1->next;
            ans[j+n] = h2->next;                
        }
        return ans;
    }
};
