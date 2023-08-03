
#include<bits/stdc++.h>
using namespace std;

 string longestCommonPrefix(vector<string>& strs) { // O(n * log n + m).
        if (strs.size() == 0) {
            return ""; // Empty vector, so there is no common prefix.
        } else if (strs.size() == 1) {
            return strs[0]; // Only one string in the vector, return it as it is.
        } else {
            sort(strs.begin(), strs.end());
            string first = strs[0];
            string last = strs[strs.size() - 1];
            string s = "";
            for (int i = 0; i < first.length(); i++) {
                if (first[i] == last[i]) {
                    s += first[i];
                } else {
                    return s;
                }
            }
            return s; // Return the common prefix after the loop completes.
            // Alternatively, you can return `first` or `last` here.
        }
    }

    int main()
{
    vector<string> ss = {"flow", "flower"};
    cout<<longestCommonPrefix(ss);
    return 0;
}
