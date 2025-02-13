/*
Description
There are  n tasks 1,. . .,n and m staffs 1, . . , m. T(i) is the set of
staffs that can perform the task i (i=1, . . ., n). Compute an assignment
of staffs to tasks such that each task is assigned to at most one staff and
each staff cannot be assigned to more than one task and the number of tasks
assigned is maximal.
Input
Line 1: contains 2 positive integer n và m (1 <=  n,m <= 10000)
Line i+1 (i=1, . . .,n) contains a positive integer k and k integer of T(i)
Output
Write the maximum number of tasks that are assigned to staffs.
Example
Input
3 4
2 1 4
2 1 3
1 2

Output
3
*/

#include <bits/stdc++.h>
using namespace std;

#define N 10005
#define M 10005
#define MAXN 1000000000

int n,m;
set<int> visited;
map<int, map<int,int> > sto;
vector <int> flow;
int c=1;
int trace[N+M+5];
int s=0;
int t;
queue <int> Q;
int res =0;


void bfs(int u){
    queue <int> Q;
    visited.insert(u);
    Q.push(u);
    trace[u]=u;//diem trc no - tuong duong voi cha
    trace[t]=-1;

    while(!Q.empty()){
        int top = Q.front();
        Q.pop();
        if(top == t) break;
        for (auto v : sto[top]){
            int a= v.first;
            //Tham roi hoac khong co dg di thi bo
            if(visited.find(a)!= visited.end() || sto[top][a]==0) continue;
            visited.insert(a);
            trace[a]=top;
            Q.push(a);
        }

    }
    visited.clear();//xoa het phan tu
}


void update(int v){
    if(trace[v]==-1){
        //k con dg di den node dich ->btoan ket thuc
        c=0;
        return;
    }

    int pre = trace[v];
    int v_now = v;
    //tim kha nang thong qua be nhat
    int temp=1;
    while (pre!=s){
        sto[pre][v_now]-= temp;
        sto[v_now][pre]+=temp;
        v_now=pre;
        pre= trace[pre];
    }
    sto[pre][v_now]-= temp;
    sto[v_now][pre]+=temp;
    c=temp;
    res+=c;

}


int main(){

    cin>>n>>m;

    t=n+m+1;
    for (int i=1; i<=n; i++){
        sto[s][i]=1;
        sto[i][s]=0;
        int a;
        cin>>a;
        for (int j=1; j<=a; j++){
            int b;
            cin>>b;
            sto[i][b+n]= 1;
            sto[b+n][i]=0;
        }
    }
    //Tao duong di tu cac node nguoi den t
    for (int i= n+1; i<=n+m; i++){
        sto[i][t]=1;
        sto[t][i]=0;
    }


    while(c){
        bfs(s);
        update(t);

    }
    cout<<res<<endl;
}


/*
#include <bits/stdc++.h>
using namespace std;

int n, m;
map<int, map<int, int> > task;
int res = 0;
int par[20005] = {0};
set<int> visited;

void update(int start) {
    int u = m+n+1;
    while (u != start) {
        task[par[u]][u] -= 1;
        task[u][par[u]] += 1;
        u = par[u];
    }
}

int bfs(int start) {
    queue<int> Q;
    Q.push(start);
    while (!Q.empty()) {
        auto u = Q.front(); Q.pop();
        visited.insert(u);
        for (auto v : task[u]) {
            if (visited.find(v.first) == visited.end() && task[u][v.first] > 0) {
                par[v.first] = u;
                if (v.first == m+n+1) {
                    update(start);
                    visited.clear();
                    return 1;
                }
                Q.push(v.first);
                par[v.first] = u;
            }
        }
    }
    return 0;
}

int main() {
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		int t; cin >> t;
		int temp;
        task[0][i+1] = 1;
		for (int j=0; j<t; j++) {
			cin >> temp;
			task[i+1][n+temp] = 1;
            task[n+temp][i+1] = 0;
		}
	}

    for (int i=0; i<m; i++) {
        task[n+i+1][n+m+1] = 1;
    }

    for (int i=0; i<n; i++) {
        res += bfs(i+1);
        if (res == min(m, n)) {
            break;
        }
    }

    cout << res;
}

*/



