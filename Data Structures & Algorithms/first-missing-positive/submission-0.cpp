class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> st;

        for(int num : nums){
            st.insert(num);
        }

        for(int i = 1; ; i++){
            if(st.find(i) == st.end()){ // element is not present
                return i;
            }
        }
    }
};