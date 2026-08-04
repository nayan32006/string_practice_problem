#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string result = "1";

        for (int i = 2; i <= n; i++) {
            string current = "";
            int count = 1;

            for (int j = 0; j < result.length(); j++) {
                if (j + 1 < result.length() && result[j] == result[j + 1]) {
                    count++;
                } else {
                    current += to_string(count) + result[j];
                    count = 1;
                }
            }

            result = current;
        }

        return result;
    }
};

int main() {
    Solution sol;

    int n1 = 1;
    int n2 = 4;

    cout << sol.countAndSay(n1) << endl;
    cout << sol.countAndSay(n2) << endl;

    return 0;
}