#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public :
   int firstUniqchar(string a) { 
    unordered_map<char, int>m;
    queue<int> Q;

    for(int i=0; i<a.size(); i++){
        if(m.find(a[i]) == m.end()){
            Q.push(i);
        }
        m[a[i]]++;
        while(Q.size()>0 && m[a[Q.front()]]>1){
            Q.pop();
        }
    }
    return Q.empty() ?-1 : Q.front();
   }
};
int main() {
   Solution sol;
    string test = "leetcode";
    
    int result = sol.firstUniqchar(test);
    
    if (result != -1) {
        cout << "First unique character is '" << test[result] << "' at index " << result << endl;
    } else {
        cout << "No unique character found." << endl;
    }

    return 0;
}