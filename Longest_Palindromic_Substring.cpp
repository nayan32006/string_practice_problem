#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        string res = "";

        for (int i = 0; i < n; i++) {
            // 1. Odd length palindrome (Center is i)
            // Example: "aba", i is at 'b'
            int st = i, end = i;
            while (st >= 0 && end < n && s[st] == s[end]) {
                st--;
                end++;
            }
            // st+1 और end-st-1 इसलिए क्योंकि लूप टूटने से पहले st और end 
            // एक कदम ज्यादा बाहर निकल चुके होते हैं
            string temp = s.substr(st + 1, end - st - 1);
            if (temp.size() > res.size()) res = temp;

            // 2. Even length palindrome (Center is i and i+1)
            // Example: "abba", i is at first 'b', i+1 at second 'b'
            st = i;
            end = i + 1;
            while (st >= 0 && end < n && s[st] == s[end]) {
                st--;
                end++;
            }
            temp = s.substr(st + 1, end - st - 1);
            if (temp.size() > res.size()) res = temp;
        }

        return res;
    }
};

int main() {
    Solution sol;
    
    string input = "babad";
    string result = sol.longestPalindrome(input);
    
    cout << "Input String: " << input << endl;
    cout << "Longest Palindromic Substring: " << result << endl; // Output: "bab" or "aba"

    string input2 = "cbbd";
    cout << "\nInput String: " << input2 << endl;
    cout << "Longest Palindromic Substring: " << sol.longestPalindrome(input2) << endl; // Output: "bb"

    return 0;
}