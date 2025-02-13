
#include <bits/stdc++.h>
using namespace std;
int n,K;
int cap=0; //luu so luong khach tren xe hien tai
int c[21][21];
int fbest= 1e9;
int f= 0;
int cmin =1e9;
int visited[12]={0}; // 0 la chua don
int location[22]={0}; // luu cac thanh pho da di qua
int load[12]={0};

int check1(int i){
	if (visited[i]) return 0;
	return 1;}

int check2(int i){
	if (load[i]) return 1;
	return 0;}

int check3(int cap){
	int count=0;
	for (int i = 1; i<=n; i++){
		if (visited[i]) count++;}
	if (count == n  && cap ==0) return 1;
	return 0;}

void Try(int k){//duyet theo luot don xe bus
	//don khach
	if(cap<K){
		for (int i=1; i<=n; i++){
		if (check1(i)){
			//update	
			visited[i] = 1;
			location[k+1]= i;
			f += c[location[k]][i];
			cap++;
			int temp =-1;
			for (int j=0; j<K; j++){
				if (!load[j]) {
					temp = j; break;}}
			if (temp!=-1) load[temp]= i; 
			if( f + cmin * (2*n - k) < fbest ) Try(k+1);
		
			//release
			visited[i] = 0;
			location[k+1]= 0;
			f -= c[location[k]][i];
			cap--;
			load[temp]= 0;
		}}}
	//tra khach
	if ( cap> 0){
		for (int j=0; j<K; j++){
			if (check2(j)){
				//update
				int t = load[j]; //t la nguoi ngoi o vi tri j
				cap--; load[j]=0;
				f += c[location[k]][t+n];		
				if ( k == 2*n -1){		
					fbest= min(fbest, f+ c[t+n][0]); // phai cong them doan di ve 
				}
				else {
				if( f + cmin * (2*n - k) < fbest ) Try(k+1);}
				
				
				//release
				cap++;
				load[j]=t;
				f -= c[location[k]][t+n];
				
				
			}
		}
		
	}
	
	

} 

int main(){
	cin>>n>>K;
	for (int i=0; i<=2*n; i++){
		for (int m=0; m<=2*n; m++) {
		cin>>c[i][m];
		if(c[i][m] >0) cmin = min (cmin, c[i][m]);}
	}
	
	Try(0);
    cout<<fbest<<endl;	
	
	return 0;
	
}
