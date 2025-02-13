#include <bits/stdc++.h>
using namespace std;

int n;
int a[101];
int mem[2][101] = {0};
int main (){
	int res=0;
	cin>>n;
	for ( int i=1; i<=n; i++) cin >> a[i];
	for (int i=1; i<=n; i++){
		if(a[i]%2==0)
			mem[0][i]= mem[0][i-1] + 1;
			mem[1][i] = mem[1][i-1];}
		else{
			mem[0][i]= mem[1][i-1] ;
			mem[1][i]= mem [0][i-1] +1 ;}
	res += mem[0][i];	}
	cout<<res<<endl;}
