/*
Given a network G = (V, E) which is a directed weighted graph. Node s is the source and node t is the target.
c(u,v) is the capacity of the arc (u,v). Find the maximum flow on G.
Input
•Line 1: two positive integers N and M (1 <= N <= 10
4
, 1 <= M <= 10
6
)
•Line 2: contains 2 positive integers s and t
•Line i+2 (I = 1,. . ., M): contains two positive integers u and v which are endpoints of i
th
 arc
Output
  Write the value of the max-flow found
Example
Input
7 12
6 7
1 7 7
2 3 6
2 5 6
3 1 6
3 7 11
4 1 7
4 2 4
4 5 5
5 1 4
5 3 4
6 2 8
6 4 10
Output
17
*/
#include <bits/stdc++.h>
using namespace std;
#define N 10005
#define M 1000005
#define MAXN 1000000000
int n,m;
map <int, map<int,int> > sto; //luu cac canh, tien cho truy van nhanh
int visited[N]={0};
vector<int> flow;
int s;
int t;
int c=MAXN; //luu gia tri duong tang luong
queue < int > Q;
int trace[N];
int res=0;
void bfs (int u){
    fill_n(visited, N, 0);  //dat lai la chua tham sau khi tim duoc duong tang luong
    fill_n(trace, N, -1);
    queue<int> empty; // Tạo một hàng đợi rỗng
    Q.swap(empty);    // Hoán đổi với hàng đợi rỗng
    Q.push(u);
    visited[u] =1;
    trace[u]=u;
    while (!Q.empty()){
        auto top =Q.front();
        if (top==t){break;}
        Q.pop();
        for ( auto v : sto[top] ){
           if (visited[v.first] || sto[top][v.first]==0)continue;
           visited[v.first]=1;
           trace[v.first]=top;
           Q.push(v.first);}}}

void back_to_s(int v){
    if(trace[v]==-1){
        c=0;
        return;}
    int temp=MAXN;
    int pre = trace[v];
    int v_now=v;
    while (pre != s){
        int weight = sto[pre][v_now];
        temp = min(temp, weight);
        int a= pre;
        pre= trace[pre];
        v_now = a;}
    v_now=v;
    pre = trace[v_now];
    while (pre!=s){
        sto[v_now][pre]+=temp;
        sto[pre][v_now] -= temp;
        int a= pre;
        pre= trace[pre];
        v_now = a;}
    sto[pre][v_now]-= temp;
    sto[v_now][pre]+=temp;
    c=temp;
    flow.push_back(c);}

int main(){
    cin>>n>>m;
    cin>>s>>t;
    for (int i=1; i<=m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        sto[a][b] = c;
        sto[b][a] = 0;}
    while(c){ // khi nao luong hien tai =0 -> k con duong di den t -> dung lai
        fill_n(trace, N, -1);
        bfs(s);
        back_to_s(t);}
    for (auto i : flow){
        res+=i;}
    cout<<res<<endl;}
















