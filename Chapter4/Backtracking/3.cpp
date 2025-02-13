#include <bits/stdc++.h>
using namespace std;
int m; //so giang vien
int n; // so lop hoc
int crd[40]; // khoi luong tin chi moi mon
map <int , vector <int> > courses; // danh sach cacs giao vien day mon i
int LB [35]; // so mon toi thieu ma gv i phai day
int cmin = 1e9;

int k;
vector<int> asigned[15];  // luu danh sach cac mon ma gv i day
int conflict[15][15]={0};

int cv[11] ={0}; //luu khoi luong cong viec hien tai cua tung gv

int check1(int k, int i){
	for (int j : asigned[i]){ //j la value cua cac phan tu trong mang
	    if (conflict[k][j])return 0;
	}
	return 1;
}

void upd(){
	for (int i=0; i<=m; i ++){
		if (LB[i]>0) return;
	} // check dieu kien xem gv da lam du toi thieu chua
	int c = 0;//max do chenh lech cv
	for (int i=0; i<=m; i ++){
		c =max (c, cv[i]);
	}
	cmin= min (cmin, c);
}

int check2(int i){
	if( cv[i]  > cmin ) return 0;
	return 1;
}


//duyet theo khoa hoc
void Try(int k){
	for (int i: courses[k]){ // duyet cac gv co the day mon k
		if (check1(k,i)){
			//update
			asigned[i].push_back(k);
			cv[i] += crd[k];
			LB[i] -= 1;

			if (k == m){
				upd();
			} else if (check2(i)){ Try(k+1);}


			//release
			asigned[i].pop_back( );
			cv[i] -= crd[k];
			LB[i] += 1;
		}
	}

}

int main(){
	cin>>m>>n;
	//vao mon nao duoc gv nao day
	for (int i=1; i<=m; i++){
		int somon; cin>>somon;
		for(int j =0; j< somon; j++){
			int mon;cin>> mon;
			courses[mon].push_back(i);}}
	//nhap vao so tin chi moi mon hoc
	for (int i=1; i<=n; i++) cin>> crd[i];


	//So lop toi thieu
	for (int i=1; i<=m; i++) cin >> LB[i];

	int k; cin>>k; //so cap mon hoc conflict
	for (int i=1; i<=k; i++){
		int a, b; cin>>a>>b;
		conflict[a][b]=1;
		conflict[b][a]=1;
	}

	Try(1);
	cout<<cmin<<endl;
	return 0;



}

