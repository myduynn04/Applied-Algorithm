/* day doi dau lon be
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int l, u; cin>>l>>u;
	int a[n+1];
	for (int i=1; i<=n; i++) cin>> a[i];
	int mem[3][n+1];
	mem [1][1]=1;
	mem [0][1] =1; //0 la phan tu dung truoc nho hon
	int best =0;
	for (int i=2; i<=n; i++){
		for (int j=1; j<i; j++){
			if ( (abs(i-j)>=l ) && (abs(a[i]-a[j])<=u) ){
				int temp=0;
				if (a[j]<a[j]) {
				temp= max(temp, mem[1][j] +1);
				mem[0][i]=temp;}
				else if (a[j]>a[j])  {
				temp= max(temp, mem[0][j] + 1);
				mem[1][i]=temp;}}}
		best = max(best, mem[0][i]);
		best = max (best, mem[1][i])}
	cout<<best<<endl;

}
