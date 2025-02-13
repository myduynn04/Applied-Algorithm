#include <bits/stdc++.h>
using namespace std;

int n,m;

int main(){
	cin>>n>>m;
	int a[n+1], b[m+1];
	for (int i=1; i<=n; i++) cin>>a[i];
	for (int i=1; i<=m; i++) cin>>b[i];
	int mem[n+1][m+1];
	memset(mem, 0, sizeof(mem));
	int best =0;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			int temp =0;
			temp= max (mem[i][j-1], mem[i-1][j]);
			if (a[i]==b[j]) temp = max (temp, mem[i-1][j-1] +1 );
			mem[i][j]= temp;
			best = max (best, temp);}	}
	cout << best << endl;}



