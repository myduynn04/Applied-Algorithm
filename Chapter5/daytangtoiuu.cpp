//C 
#include <bits/stdc++.h>
using namespace std;

int main() 
{ 

    int n; cin >> n;
    int arr[n+1] = {0};
    vector<int> sto;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    int best = 0;
    sto.push_back(arr[0]);
    for (int i=1; i<n; i++) {
        int last = sto.back();
        if (arr[i] > last) {
            sto.push_back(arr[i]);
            best = max(best, (int) (sto.end() - sto.begin()-1));
        }
        else {
            int l = lower_bound(sto.begin(), sto.end(), arr[i]) - sto.begin();
            best = max(best, l+1);
            sto.at(l) = arr[i];
        }
    }
    cout << best;
}
