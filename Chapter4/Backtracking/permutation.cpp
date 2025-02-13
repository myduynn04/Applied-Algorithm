#include <bits/stdc++.h>
using namespace std;
int n;
int a[15];
int visited[15] ={0};


void Try(int k){
	//duyet theo day duoc in ra
	for (int i=1; i<=n; i++){
		//i la cac phan tu tu 1 den n
		if(!visited[i]){
			//update
			visited[i]=1;
			a[k]= i;
			
			//dung
			if (k== n) { 
			for (int i=1; i<=n; i++) {
				cout<<a[i]<<"\t" ;
			}
			cout<<endl;
			}
			else Try(k+1);
			
			//release
			visited[i]=0;
			
			}
		}
	}





int main(){
	cin>>n;
	
	Try(1);
	return 0;
}

