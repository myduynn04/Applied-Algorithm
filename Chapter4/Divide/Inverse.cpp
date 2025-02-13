//C++ 

/*
Given a sequence of integers a
1
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

//Dung merge sort

const int MOD = 1e9+7;

long long merge_and_count(vector<int>& a, vector<int>& temp, int left , int mid, int right){
    int i=left; //chi so trai
    int j= mid +1; // chi so bat dau cho mang phai
    int k = left; // chi so bat dau cua temp
    long long count =0;
    
    while( i<= mid && j <= right){
    	if (a[i]<=a[j]){
    		temp[k++]= a[i++];	
		}
		else{
		
			temp[k++] =  a[j++];
			count = (count +  (mid -i +1) )% MOD;
		}
	}
	
	while (i<= mid) temp[k++]= a[i++];
	while (j<=right) temp[k++]= a[j++];	
    
    for (int m =left; m<=right; m++) a[m]=temp[m];
    
    return count;
}

long long merge_sort_and_count( vector<int>& a, vector<int>& temp,int left,int right){
	long long count =0;
	
	if (left<right){
		int mid = (right+left)/2;
		count =  (count + merge_sort_and_count(a,temp,left, mid) ) %MOD;
		count =  (count + merge_sort_and_count(a,temp,mid+1, right) ) %MOD;
		count =  (count + merge_and_count(a,temp,left, mid, right) ) %MOD;
	}
	return count;
	
}


int main() 
{
    int n;
    cin >> n;
    vector<int> a(n), temp(n);
    
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    
    long long result = merge_sort_and_count(a, temp, 0, n-1 );
    
    cout<< result << endl;
    return 0;
}
