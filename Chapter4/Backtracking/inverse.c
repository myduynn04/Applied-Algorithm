/*Given a sequence of integers a1
, a
2
, ..., a
n
. A pair (i, j) is call an inversion if i < j and a
i
 > a
j
. Compute the number Q of inversions
Input
Line 1: contains a positive integer n (1 <= n <= 10
6
)
Line 2: contains a
1
, a
2
, ..., a
n
 (0 <= a
i
<= 10
6
)
Output
Write the value Q modulo 10
9
+7

Example
Input
6
3 2 4 5 6 1
Output
6*/


#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> a;
#define MOD 1e6
//tri
int merge_and_count( vector <int> a, vector <int> temp, int l,int mid, int r )
{
    int l2 = mid +1 ; //chi so bat dau cua mang phai
    int k = l; //chi so bat dau cuar mang temp;
    int count =0;

    while (l<=r){
        if (a[l]<= a[l2]){
            temp[k]= a[l];
            k++; l++;
        }
        else{
            count += mid - l + 1;
            temp [k]= a[l2];
            k++; l2++;
        }
    }
    while (l<= mid )temp[k++]= a[l++];
    while (l2<=r)temp[k++]= a[l2++];



  for (int k=l; k< r, k++){
    a[k]= temp[k];
  }

    return count;
}


//chia
int merge_sort_and_count( vector <int> a, vector <int> temp, int l,int r ){
int mid = (l-r)/2;
int count =0;

count = (count + merge_sort_and_count(a, temp, r,mid))%MOD;
count = (count + merge_sort_and_count(a, temp, mid+1; l))%MOD;
count = (count + merge_and_count(a, temp, r,mid,l))%MOD;

return count;

}



int main(){
    cin<<n;
    for (int i=0; i<=n; i++) cin>>a[i];
    vector<int> temp; ///mang luu day a duoc sap xep

    int res= merge_sort_and_count(a, temp, 0; n-1);
    cout<<res<<endl;
    return 0;



}
