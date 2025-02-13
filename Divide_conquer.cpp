#include <bits/stdc++.h>
using namespace std;


int findFirstOne(const vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;
    int result=-1; 

    while (left<=right) {
        int mid=left+ (right-left)/ 2;
        if (arr[mid] == 1) {
            result = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return result;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i< n; i++) {
        cin >> arr[i];
     
        while (arr[i] != 0 && arr[i] != 1) {
            cout << "Please enter 0 or 1: ";
            cin >> arr[i];
        }
    }
    int index = findFirstOne(arr);

    if (index != -1) {
        cout<<"Index of the first 1-bit: "<<index<<endl;
    } else {
        cout<<"There is no bit 1 in array."<<endl;
    }
    return 0;
}
