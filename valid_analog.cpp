#include<iostream>
#include<string>
#include<algorithm>


using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
       sort(s.begin(), s.end());
       sort(t.begin(), t.end());
       
       
       return s == t;
    }
};

int main() {
    Solution sol;

   
    string s1 = "anagram", t1 = "nagaram";
    if (sol.isAnagram(s1, t1)) {
        cout << "Test 1 Passed: '" << s1 << "' and '" << t1 << "' are anagrams." << endl;
    } else {
        cout << "Test 1 Failed." << endl;
    }

    
    string s2 = "rat", t2 = "car";
    if (!sol.isAnagram(s2, t2)) {
        cout << "Test 2 Passed: '" << s2 << "' and '" << t2 << "' are not anagrams." << endl;
    } else {
        cout << "Test 2 Failed." << endl;
    }

    return 0;
}