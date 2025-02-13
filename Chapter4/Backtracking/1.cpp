//Bai tim max

#include <bits/stdc++.h> 
using namespace std;

int n;
int a[1005];
int c = 0;


int main(){
	cin >> n;
	for (int i=1; i<=n ; i++){
		cin>>a[i];
		c = max (c, a[i]);
	}
	cout<<c<<endl;
	return 0;
}
