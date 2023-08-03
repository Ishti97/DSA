 #include<bits/stdc++.h>
using namespace std;

/// Brute-force
vector<int> func(vector<int>& v){            /// O(n^2) SC - O(1)
    vector<int> lst;
    for(int i=0;i<v.size();i++){
        if(lst.empty() || v[i] != lst[0]){              /// empty list hole kaj suru, r same value skip kre diff val check kre, cz same value already cnt krse
            int cnt = 0;
            for(int j=0;j<v.size();j++){
                if(v[j]==v[i])
                    cnt++;
            }
            if(cnt > n/3)
                lst.push_back(v[i]);
        }
        if(lst.size()==2) break;                         /// for any n value n/3 krle, max 2 ta number thkbe countable
    }
    return lst;
}

/// Hashing O(n)+ map check logn --- SC O(n) for mpp
/// same loop a hash inc++  r check value >n/3 or not, hole list add
 vector<int> majorityElement(vector<int>& v) {
        vector<int> ls;
        map<int, int> mpp;
        int n = v.size();
        int mini = (int)(n/3) + 1;

        for(int i=0;i<n;i++) {                           /// O(n)
            mpp[v[i]]++;

            if(mpp[v[i]] == mini)
                ls.push_back(v[i]);

            if(ls.size() == 2) break;
        }

        sort(ls.begin(), ls.end()); //logn
        return ls;
    }


/// Optimum - improve of brute force jst essyyy           O(2n)
vector<int> majorityElement(vector<int> v) {
    int n = v.size();

    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN, el2 = INT_MIN;

    // applying the Extended Boyer Moore's Voting Algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && el2 != v[i]) {
            cnt1 = 1;
            el1 = v[i];
        }
        else if (cnt2 == 0 && el1 != v[i]) {
            cnt2 = 1;
            el2 = v[i];
        }
        else if (v[i] == el1) cnt1++;
        else if (v[i] == el2) cnt2++;
        else {
            cnt1--, cnt2--;
        }
    }

    vector<int> ls; // list of answers

    // Manually check if the stored elements in el1 and el2 are the majority elements:
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el1) cnt1++;
        if (v[i] == el2) cnt2++;
    }

    int mini = int(n / 3) + 1;
    if (cnt1 >= mini) ls.push_back(el1);
    if (cnt2 >= mini) ls.push_back(el2);

    return ls;
}

int main(){
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    vector<int> ans = majorityElement(arr);
     for(auto& it : ans)
        cout<<it<<" ";
     return 0;
}
