#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        // अगर सिर्फ 1 रो है, तो Zigzag संभव नहीं, स्ट्रिंग वैसी ही रहेगी
        if (numRows == 1 || s.length() <= numRows) {
            return s;
        }

        // हर Row के लिए एक स्ट्रिंग का वेक्टर
        vector<string> rows(min(int(s.length()), numRows));
        int currRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currRow] += c; // वर्तमान रो में अक्षर डालो

            // अगर पहली या आखरी रो पर हैं, तो दिशा बदलें
            if (currRow == 0 || currRow == numRows - 1) {
                goingDown = !goingDown;
            }

            // दिशा के हिसाब से अगली रो पर जाएँ
            currRow += goingDown ? 1 : -1;
        }

        // सारी Rows को जोड़कर फाइनल रिजल्ट बनाएं
        string result = "";
        for (string row : rows) {
            result += row;
        }
        return result;
    }
};

int main() {
    Solution sol;
    string s = "PAYPALISHIRING";
    int numRows = 3;

    string result = sol.convert(s, numRows);
    cout << "Original: " << s << endl;
    cout << "Zigzag:   " << result << endl; // Output: "PAHNAPLSIIGYIR"

    return 0;
}