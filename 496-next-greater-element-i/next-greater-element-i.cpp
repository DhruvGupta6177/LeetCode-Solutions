class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // stack<int> stk;
        // vector<int> result;
        
        
        // for (int i = 0; i < nums1.size(); i++) {
            
        //     bool found = false;
        //     for (int j = 0; j < nums2.size(); j++) {
        //         if (nums2[j] == nums1[i]) {
                    
        //             while (j + 1 < nums2.size() && nums2[j + 1] <= nums2[j]) {
        //                 j++; 
        //             }
        //             if (j + 1 < nums2.size()) {
        //                 result.push_back(nums2[j + 1]); 
        //             } else {
        //                 result.push_back(-1); 
        //             }
        //             found = true;
        //             break;
        //         }
        //     }
        //     if (!found) {
        //         result.push_back(-1);  
        //     }
        // }
        
        // return result;



        unordered_map<int, int> m;
        stack<int> s;

        for(int i = nums2.size()-1; i >= 0; i--){
            while(s.size() > 0 && s.top() <= nums2[i]){
                s.pop();
            }

            if(s.empty()) {
                m[nums2[i]] = -1;
            }

            else{
                m[nums2[i]] = s.top();
            }

            s.push(nums2[i]);
        }

        vector<int> ans;
        for(int i = 0; i < nums1.size(); i++){
            ans.push_back(m[nums1[i]]);
        }

        return ans;
    }
};