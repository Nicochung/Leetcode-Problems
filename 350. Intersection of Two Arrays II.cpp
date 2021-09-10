class Solution {
public:
//     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> ans;
//         map<int,int> hash1,hash2;
//         for (int i = 0; i < nums1.size(); ++i) {
//             hash1[nums1[i]]++;
//         }
//         for (int i = 0; i < nums2.size(); ++i) {
//             hash2[nums2[i]]++;
//         }
//         if (hash1.size() < hash2.size()) {
//             for(auto [num, occur]: hash1) {
//                 if (hash2.find(num) != hash2.end()) {
//                     ans.insert(ans.end(), min(hash2[num], occur), num);
//                 }
//             }
//         } else {
//             for(auto [num, occur]: hash2) {
//                 if (hash1.find(num) != hash1.end()) {
//                     ans.insert(ans.end(), min(hash1[num], occur), num);
//                 }
//             }            
//         }
//         return ans;
//     }
    
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();int n2=nums2.size();
        vector<int>v;
        map<int,int>mp;
        for(int i=0;i<n1;i++)
          mp[nums1[i]]++;
        
        for(int i=0;i<n2;i++)
        {
            if(mp.find(nums2[i])!=mp.end() && mp[nums2[i]]>0)
                v.push_back(nums2[i]);
            mp[nums2[i]]--;
        }
       return v;
    }
};
