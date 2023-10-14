#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int> nums;
        vector<int> result;
        int n = words.size();
        int j =-1;

        for(int i=0; i<n; i++) {
            if(words[i] != "prev") {
                nums.push_back(stoi(words[i]));
                j=nums.size()-1; 
            }
            else{
                if(j<0){
                result.push_back(-1);
                }
                else{
                    result.push_back(nums[j]);
                }
                j--;
            }
        }

        return result;
    }
};

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for(int i=0; i<n; i++) {
        cin >> words[i];
    }
    Solution obj;
    vector<int> ans = obj.lastVisitedIntegers(words);
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}