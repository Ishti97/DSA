#include<bits/stdc++.h>
using namespace std;
 string longestPalindrome(string s) {
        int n = s.length(), start = 0 , maxLen = 1;

        for(int i=1;i<n;i++){
            int left = i , right = i; // we will check for odd length substring

            // if we are not out bound & character are matching
            // and we will calculate current length and compare with longest length
            while(left >= 0 && right < n && s[left] == s[right]){
                int currLen = right - left + 1;  // current length
                if(currLen > maxLen){
                    maxLen = currLen;
                    start = left;
                }
                left--; right++;  // move pointers to left and right
            }

            left = i-1 , right = i;          // we will check for even length substring

            // if we are not out bound & character are matching
            // and we will calculate current length
            // and compare with longest length
            while(left >= 0 && right < n && s[left] == s[right]){
                int currLen = right - left + 1;         // current length

                // if current length is greater than maximum Length
                // we will we will assign current length to maxLen
                // and change starting index of longest substring
                if(currLen > maxLen){
                    maxLen = currLen;
                    start = left;
                }
                left--; right++;                  // move pointers to left and right
            }
        }
        return s.substr(start,maxLen);   // return longest substring
    }

int main(){
    cout<<longestPalindrome("cbabd");
    return 0;
}
