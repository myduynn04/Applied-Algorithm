#include <bits/stdc++.h>
using namespace std;

int solve_case(const vector<int>& list1, const vector<int>& list2) {
    unordered_map<int, int> freq1, freq2;
    for (int num:list1) {freq1[num]++;}
    for (int num:list2) {freq2[num]++;}

    int count= 0;
    for (const auto& pair:freq1) {
        int element =pair.first;
        if (freq2.find(element) != freq2.end()) {
            count+=min(pair.second, freq2[element]);
        }}
    int r = (list1.size()+list2.size())- 2*count;

    return r;
}

int main() {
    int t;
    cin >>t; 

    while (t--){
        int n,m;
        cin>>n>>m; 

        vector<int> list1(n), list2(m);      
        for (int i=0; i<n; i++) {
            cin >> list1[i];}
        for (int i=0; i<m; i++) {
            cin >>list2[i]; }

        cout << solve_case(list1, list2) << endl;
    }
    return 0;
}
