#include <bits/stdc++.h>
using namespace std;

#define M 10005
#define MAXN 1e9
int n,m;
int par[N]; //danh dau node do dang thuoc tp lien thong nao
vector<pair<pair<int,int>, int> > sto; //pair dau tien la 2 dinh, int con lai la trong so
int res=0;



int main(){
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int a,b,c; cin>>a>>b>>c;
        sto.push_back(make_pair(make_pair(a,b),c));

    }
    //sap xep canh tang dan ve do lon
    sort(sto.begin(), sto.end(), [](auto  a, auto b){
         a.second<b.second;
         })
    //ban dau moi node la mot tplt roi rac
    for(int i=1; i<=n; i++){
        par[i]= i;
    }
    //to chuc dang cay, ban dau moi node la mot tplt roi rac,
    for (auto edge : sto){
        //kiem tra edge nay co dang noi 2 dinh thuoc cung 1 tp lien thong k
        if (check (edge.first.first, edge.first.second)){
            //gom 2 thanh phan lien thong lai voi nhau
            S_union(edge.first.first, edge.first.second)
        }
    }
}


/*
#include<bits/stdc++.h>
using namespace std;

#define N 10000

int n, m;
vector<pair<pair<int, int>, int> > sto;
int high[N];
int par[N];
int res = 0;

int check(int a, int b) {
  int par_a = a;
  while(par_a != par[par_a]) {
    par_a = par[par_a];
  }
  int par_b = b;
  while(par_b != par[par_b]) {
    par_b = par[par_b];
  }
  if (par_a != par_b) return 1;
  return 0;
}

void S_union(int a, int b) {
  int root_a = a;
  while(root_a != par[root_a]) {
    root_a = par[root_a]; //
  }
  int root_b = b;
  while(root_b != par[root_b]) {
    root_b = par[root_b];
    par[b] = root_a;
    b = root_b; //tien len duyet cha
  }
  par[b] = root_a;
}


int main() {
  cin >> n >> m;
  for (int i = 0; i<m; i++) {
    int a, b, c; cin >> a >> b >> c;
    sto.push_back(make_pair(make_pair(a, b), c));
  }
  sort(sto.begin(), sto.end(), [](auto a, auto b) {
    return a.second < b.second;
  });
  for (int i = 1; i<=n; i++) {
    par[i] = i;
    high[i] = 1;
  }

  for (auto edge : sto) {
    if (check(edge.first.first, edge.first.second)) {
      res += edge.second;
      S_union(edge.first.first, edge.first.second);
    }
  }
  cout << res << endl;

}
*/
