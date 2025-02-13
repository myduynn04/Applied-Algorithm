/*tim day con co tong lon nhat, day con can lien tuc*/ 

#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int mem[N];
int a[N];


int maxsub(int n, int *a){
	if(n==1) return a[1];
	if (mem[n] != -1) return mem[n];
	int result = max(a[n], a[n] + maxsub(n-1, a));
	mem[n]= result;
	return result;
}

int main(){
	int n;
	cin>>n;
	int a[n];
	memset (mem, -1, sizeof(mem));
	for (int i=1; i<=n; i++) cin >>a[i];
	int ans=0;
	for(int i=1; i<=n; i++) ans = max(ans, maxsub(i, a));
	cout<<ans<<endl;
	return 0;
	
}



