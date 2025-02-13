//Bai doanh thu

#include <bits/stdc++.h> 
using namespace std;

int n, D;
int a[1005];
int sum[1005]={0};


int main( ){
	cin >> n >>D;
	for (int i=1; i<=n ; i++){
		cin>>a[i];
		sum[i] = sum[i-1] +a[i];
	}
	int c=0;
	int temp =0;
	for (int i=1; i<=n; i++ ){
		for (int j=0; j<=i; j++){
			temp= sum[i]-sum[j];
			if (temp >=D) c++;
		}
	}
	cout<<c<<endl;
	return 0;	
}
