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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result(k, NULL);

        int n = 0;
        ListNode* temp = head;
        while(temp){
            n++;
            temp = temp->next;
        }

        int size = n/k;
        int extra = n % k;

        temp = head;

        for(int i = 0;i < k; i++){
            if(temp == NULL){
                result[i] = NULL;
                continue;
            }

            result[i] = temp;

            int currsize = size + (i < extra ? 1 : 0);
            for(int j = 1; j < currsize; j++){
                temp = temp->next;
            }

            ListNode* nextPart = temp->next;
            temp->next = NULL;
            temp = nextPart;
        }

        return result;

    }
};