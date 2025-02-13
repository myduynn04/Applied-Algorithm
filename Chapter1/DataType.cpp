#include <bits/stdc++.h>
using namespace std;



int main(){
//VECTOR
cout<<"VECTOR"<<endl;
	vector<int> a;
	a.push_back(0);
	a.push_back(1);


	for (int i=0; i<a.size(); i++){
		cout<<a[i]<< " ";
	}

	a.pop_back();

	a.insert(a.begin()+1, 2); //chen vao vi tri a[1]=2;

	//Xoa mot phan tu maf khong phai o cuoi vector : xoa phan tu o vi tri i
	a.erase(a.begin()+i,a.begin()+ i +2 )  //2 o day la so phan tu muon xoa
	//=> day la xoa mot khoang

	//xoa het
	a.clear( );






//SET
cout<<"SET"<<endl;
	//la kieu du lieu su dung bang bam de truy van phan tu
	//mot phan tu chi xuat hien duy nhat mot lan trong kieu du lieu
	//co the coi la 1 tap cac phan tu
	//truy van trong thoi gian O(1)

	set<int> b;

	b.insert(0); //them vao set
	b.insert(0);
	b.insert(1); //


	//Tim kiem phan tu:
	//b.find(2) != b.end() => 2 co ton tai trong set
		if (b.find(2) != b.end()){
			cout<<"co phan tu trong set\n";
		}
		else cout<<"k co phan tu trong set\n";

	//duyet hoac co the hieu
		for(int i : b){
			cout<<i << " ";
		}
		cout<<endl;
        //ket qua chi la 0 1 mac du insert 2 lan


	//Xoa phan tu
		b.erase(0);
		for(int i : b){
			cout<<i << " ";
		}
		cout<<endl; //da: 1




//MAP
cout<<"MAP"<<endl;
    //(key-value)
    //Là kiểu dữ liệu gồm một cặp key-value, truy vân tới key tốn O (1)
    //Các key khác nhau đôi một

    map <int, int>  c;
    int key=1;
    int value =2;

    //Thêm giá trị mới
    c[key]=value;
    cout <<c[key]<<endl;
    c[key]+= 5;

    //Truy van xem có tồn tại key trong map không
    if (c.find(key)!= c.end()){
        cout<<"co phan tu"<<endl;
    }

    //Them phan tu
    if (c.find(a[i])== c.end()){
        c[a[i]]=0; //khoi tao neu key=a[i] chua ton tai

    }

    //Truy van trong phan tu map
    for (auto i : c ){
        cout << i.first << " "<< i.second<<endl;
    } //first la key, second la value









//PAIR
cout<<"PAIR"<<endl;
    pair <int, int> x;
    make_pair (0,1);
    pair <int, int> y;
    y.first=2;
    y.second=4;

    vector <pair<int,int> > k;
    k.push_back(make_pair(2,3));

    //Ham in ra
    for (auto i: k){
       cout << i.first << " "<< i.second<<endl;
    }


// Ham sort: cho vector va mang tinh
int arr[n];
sort(arr, arr+n); //sort theo thu tu tang dan

//sort theo thu tu giam dan
sort(arr, arr+n, [](int a, int b){
     return a>b;
     });

vector<int> q
sort(q.begin(), q.end() , [](int a, int b ){
     return a>b;
     });


pair <int,int> k
sort(k, arr+n, [](pair <int,int> a, pair <int,int> b ){
     return a.first > b.first ;
     });











}
