#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 0) return 0;
        int res = 0;

        // Har ek index 'i' se start hone wali substring check karte hain
        for (int i = 0; i < n; i++) {
            // ASCII characters ke liye 128 size ka boolean vector
            vector<bool> vis(128, false);

            for (int j = i; j < n; j++) {
                // Agar character pehle hi dekh chuke hain (duplicate), toh break kar do
                if (vis[s[j]]) {
                    break;
                }
                else {
                    // Agar unique hai, toh result update karo aur mark kar do
                    res = max(res, j - i + 1);
                    vis[s[j]] = true;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    string input = "abcabcbb";
    
    int output = sol.lengthOfLongestSubstring(input);
    
    cout << "Input string: " << input << endl;
    cout << "Longest Substring length without repeating characters: " << output << endl;

    return 0;
}