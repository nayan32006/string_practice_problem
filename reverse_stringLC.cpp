// Write a function that reverses a string. The input string is given as an array of characters s.

// You must do this by modifying the input array in-place with O(1) extra memory.

 

// Example 1:

// Input: s = ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]

//Example 2:

// Input: s = ["H","a","n","n","a","h"]
// Output: ["h","a","n","n","a","H"]
 

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
         int start=0;
          int end= s.size() -1 ;

        while(start<end){

            swap(s[start],s[end]);
            start++;
            end--;
        }

    }
};

int main() {
    Solution sol;
    // Use single quotes for chars
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    // Call the function directly
    sol.reverseString(s);

    // Print the result
    cout << "Reversed string: ";
    for (char c : s) {
        cout << c;
    }
    cout << endl;

    return 0;

}