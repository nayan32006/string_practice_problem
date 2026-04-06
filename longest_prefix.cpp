#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Required for sort()

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        sort(strs.begin(), strs.end());
        string first = strs[0];
        string last = strs.back();
        string ans = "";

        for (int i = 0; i < min(first.size(), last.size()); i++) {
            if (first[i] == last[i]) {
                ans += first[i];
            } else {
                break;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<string> test = {"flower", "flow", "flight"};
    
    string result = sol.longestCommonPrefix(test);
    
    cout << "Longest Common Prefix: " << result << endl;
    
    return 0;
}