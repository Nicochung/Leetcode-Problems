class Solution {
public:
//     vector<int> getRow(int rowIndex) {
//         vector<int> prev(rowIndex+1, 1);
//         vector<int> ans(rowIndex+1, 1);
        
//         for (int i = 1; i < rowIndex; ++i) {
//             for (int j = 1; j <= i; ++j)
//                 ans[j] = prev[j-1] + prev[j];
//             prev = ans;
//         }
        
//         return ans;
//     }
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1, 1);
        
        for (int i = 0; i < rowIndex; ++i) {
            for (int j = 1; j < rowIndex-i; ++j) {
                if (j / 2 < rowIndex-i) ans[j] = ans[j] + ans[j-1];
                else ans[j] = ans[j] + ans[j+1]; 
            }
        }
        
        return ans;
    }
};
