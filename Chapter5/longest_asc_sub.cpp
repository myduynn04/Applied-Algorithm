#include <bits/stdc++.h>
using namespace std;
#define MAX 1e6
int n;
int a[1005];
int mem[1005];

int main(){
	cin>>n;
	for(int i=1; i<=n; i++){cin>>a[i];}
	memset(mem, 0, sizeof(mem));
	//base case:
	mem[1]=1;
	int result=0;
	for (int i=2; i<=n; i++){
		int temp=1; // mem[i] lu do dai day con tang lon nhat khoong can lien ke ma ket thuc o A[i]
		for (int j=i-1; j>0; j--){
			if (a[j]<a[i]) temp= max(temp, mem[j]+1);
		}
		mem[i] = temp;
		result = max (result, temp);}
	cout << result<<endl;}

//vector <int> a
//lower_bound (a.begin(), b.end(), k) : tra ve chi so ma k co the dc cho vao day
// lower_bound (a.begin(), b.end(), k, [](int a, int b){return a>b;}) - a.begin();  => truong hop tim kiem nhi phan ma day giam dan
//
