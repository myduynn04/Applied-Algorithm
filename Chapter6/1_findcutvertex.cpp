#include <bits/stdc++.h>
using namespace std;
#define N 10005
#define M 100000
int n, m;
vector <int> adj[N]; //duyet
int timeDFS =0;
int num[N]={0};
int tail[N]={0};
int low [N]= {0};
int numcut=0; //luu so cut vertex
int visited[N]= {0}; // danh dau dinh nay da duoc tham chua

void dfs( int u, int pre){
	visited[u]= 1; //da tham dinh u
	low[u] = num[u]= ++timeDFS;


	int numchild=0;
	int check=0;
	for ( int v : adj[u] ){
		if( v == pre) continue;
		if ( visited[v]==0){ // day la truong hop v k tao ra canh nguoc voi u
			dfs(v,u);
			low[u]= min(low[u], low[v]);
			numchild++;
			if (low[v]>= num[u]) check =1;
		}
		else {
			low[u]= min(low[u], num[v]);
		}
	}
	if ( pre==u && numchild >1) numcut++;
	if (pre!=u && check) numcut++;

	tail[u] = timeDFS;

}

int main(){
	cin>>n>>m;

	for (int i=1; i<=m; i++){
		int a=0;
		int b=0;
		cin >> a >>b;
		adj[a].push_back(b); // dinh b ke voi dinh a => hang xom
		adj[b].push_back(a); // do la do thi vo huong nen di nguoc lai duoc
	}

	for (int i=1; i<=n; i++ ){
		if (!visited[i]) dfs(i,i);  // vi do thi co the khong lien thon => duyet tat ca thanh phan lien thong
	}
	cout<<numcut<<endl;
}
