/*
There are n passengers 1, 2, …, n. 
The passenger i want to travel from point i to point i + n (i = 1,2,…,n). 
There is a bus located at point 0 and has k places for transporting the passengers (it means at any time, there are at most k passengers on the bus). 
You are given the distance matrix c in which c(i,j) is the traveling distance from point i to point j (i, j = 0,1,…, 2n). 
Compute the shortest route for the bus, serving n passengers and coming back to point 0. 
Input
Line 1 contains n and k (1=n=11,1=k=10)
Line i+1 (i=1,2,…,2n+1) contains the (i-1)th
line of the matrix c (rows and columns are indexed from 0,1,2,..,2n).
Output
Unique line contains the length of the shortest route.
Example
Input
3  2
0  8  5  1  10  5  9
9  0  5  6  6  2  8
2  2  0  3  8  7  2
5  3  4  0  3  2  7
9  6  8  7  0  9  10
3  8  10  6  5  0  2
3  4  4  5  2  2  0
Output
25
*/

//Branching: tinh tong do dai ngan nhat
#include <bits/stdc++.h>
using namespace std;
#define MAXN  1e9
int n, K;
int C[25][25]={0};
int f=0;
int fbest= MAXN ;
int cmin;
int cap =0; //dung luong hien tai cua xe
int visited[12]={0}; //so khach da duyet
int loaded[11]= {0}; //tren xe dang co hanh khach nao 
int location[25]={0}; // luu cac dia diem da di qua

int check1(int j){
	if (visited[j]==1) return 0;
	else return 1;
}

int check2(int j){
	if (loaded[j]) return 1;
	return 0;
}

void Try(int i){
	//duyet theo hanh khach 
	//hanh khach i len dc xe neu xe con du kha nang de cho
	
	if (cap<K) {
		//Them hanh khach
		for (int j=1; j<=n; j++){
			if (check1(j)) {
				f+= C[location[k]][j];
				location [k+1] =1;
				visited[j] = 1;
				
				//Them khach vao ghe trong
				int index =0;
				for (; index<K; temp++){
					if (!loaded[temp])break
				}
				loaded[temp]=j;
				cap++;
				
				if (  f+ (cmin*(2*n -k)) < fbest )
				{Try(k+1);} // duyet tiep
				
				
				//loai bo thong tin
				f -= C[location[k]][j];
				location [k+1] =0;
				visited[j] = 0;
				loaded[temp]=0;
				cap--;			
			}
		}
	}
    if (cap>0){
    	//Bo hanh khach
    	for (int j=0; j<K; j++){
    		if (check2(j)){
    			cap--;
    			int t = loaded[j]; //t la nguoi ngoi o vi tri j
    			f += C[location[k]][n+t];
    			loaded[j]=0;
    			location[i+1]= n+t;
    			
    			if ( k == 2*n -1 ){
    				fbest= min ((fbest, f) + c[location[n+t]][0]);
				}
    			else if (f+ (cmin*(2*n -k)) < fbest){
				Try(k+1)
				}
				
				cap++;
    			
    			f -= C[location[k]][n+t];
    			loaded[j]=t;
    			location[i+1]= 0;
				 
			}
		}
    	
	}
	
	for (int v = 0; v <= n; v++){
    	
	}	
}

int main(){
	cin>>n>>K;
	cmin =MAXN;
	for (int i=0; i<= (2*n) ; i++){
		for (int j=0; j<= (2*n) ; j++) cin >> c[i][j];
		if(c[i][j] >0) cmin = min (cmin, c[i][j]);
	}
	
	Try(0);
	cout<<fbest;
	return 0;
} 
