#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string ,int>freq,curr;
        for(string word: words)
        freq[word]++;

        int l = s.size();
        int n = words.size();
        int wordSize= words[0].size();
        int windowSize= wordSize*n;

        vector<int> ans;
        for(int startPos=0; startPos<wordSize; ++startPos){
            int start = startPos;

            do{
                curr = freq;
                string currWord ;
                bool matched = true ;
                for(int i=0; i<n; ++i){
                    currWord = s.substr(start + i * wordSize, wordSize);

                    if(!curr.count(currWord) or curr[currWord] == 0){
                        matched = false;
                        break;

                    }
                    curr[currWord]--;
                }
                if( matched == true )
                   ans.push_back(start);
                start += wordSize;
            }while(start + windowSize-1<l);
        }





        return ans;
    }
};

// --- VS CODE MAIN FUNCTION ---
int main() {
    Solution sol;

    // Example 1
    string s1 = "barfoothefoobarman";
    vector<string> words1 = {"foo", "bar"};
    vector<int> result1 = sol.findSubstring(s1, words1);

    cout << "Test Case 1: ";
    for (int idx : result1) cout << idx << " "; // Expected: 0 9
    cout << endl;

    // Example 2 (Testing the edge case that likely crashed your code)
    string s2 = "wordgoodgoodgoodbestword";
    vector<string> words2 = {"word", "good", "best", "word"};
    vector<int> result2 = sol.findSubstring(s2, words2);

    cout << "Test Case 2: ";
    for (int idx : result2) cout << idx << " "; // Expected: [] (Empty)
    cout << endl;

    return 0;
}
