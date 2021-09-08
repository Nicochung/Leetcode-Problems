class Solution {
public:
    // bool containsDuplicate(vector<int>& nums) {
    //     unordered_map<int,int> myMap;
    //     for (int a: nums) {
    //         myMap[a]++;
    //     }
    //     for (auto [first, second]: myMap){
    //         if (second > 1) return true;
    //     }
    //     return false;
    // }
    
	// bool containsDuplicate(vector<int>& nums) {
	// 	unordered_set<int> s(nums.begin(),nums.end());
	// 	return s.size()==nums.size() ? false : true;
	// }
        bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n - 1; i++){
            if(nums[i] == nums[i + 1]){
                return true;
            }
        }
        
        return false;
    }
};
