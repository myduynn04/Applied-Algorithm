



int main(){
	vector<pair<int,int>> a;
	for (int i=0; i<n; i++){
		int a, b; cin>>a>>b;
		a.pushback(make_pair(a,b));
	}
	sort (a.begin(), a.end())
	// lay mot phan tu ra khoi mang: arr.erase(a.begin( )+i, a.begin( )+i+1)
	// sort (a.begin(), a.end()) => mac dinh sort theo phan tu dau tien voi pair, tang dan
	
}
