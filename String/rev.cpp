#include<bits/stdc++.h>
using namespace std;
string result(string s)
{
    string res;
    int i = 0;
    int n = s.length();
    while(i < n)
    {
        while(i < n && s[i] == ' ') i++;
        if(i >= n) break;
        int j = i + 1;
        while(j < n && s[j] != ' ') j++;
        string sub = s.substr(i, j-i);
        if(res.length() == 0) res = sub;
        else res= sub + " " + res;
        i = j + 1;
    }
    return res;
}
int main()
{
    string st="TUF is great for interview preparation";
    cout<<"Before reversing words: "<<endl;
    cout<<st<<endl;
    cout<<"After reversing words: "<<endl;
    cout<<result(st);
    return 0;
}
