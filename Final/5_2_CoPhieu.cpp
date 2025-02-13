#include <bits/stdc++.h>
using namespace std;

int n1,n2;
int L, M, P;
vector<int> sto[26]; //luu cac cap ma khong duoc trung nhau

int res=0;
set <int> M1; // luu cac phieu ma1 da co
set <int> M2; //luu cac phieu ma 2 da co
int visited[26]={0};

//check phieu ma 1 thoa man khong
//Co cac dieu kien:
//1. Khong dau tu qua M co phieu loai nay
//2. Khong dau tu neu bi xung dot trong M2
//3. Ma nay chua tung duoc chon
int check1(int i){
    //if (visited[i]==1) return 0;
    if(M1.size()==M)return 0;
    for(auto u: M2){
        for (auto v: sto[u]){
            if(v==i) return 0;
        }
    }
    return 1;
}

//check phieu ma 2 thoa man khong
int check2(int i){
    //if (visited[i]==1) return 0;
    if(M2.size()==M)return 0;
    for(auto u: M1){
        for (auto v: sto[u]){
            if(v==i) return 0;
        }
    }
    return 1;
}

//check dieu kien dung
//Dieu kien laf moi loai ma deu phai dau tu it nhat 1 ma co phieu
int check(){
    if(M2.size()<1 || M1.size()<1) return 0;
    return 1;
}
void Try_print(){

    for(auto u: M1) {cout<<u<<" ";}
    cout<<"Hai"<<" ";
    for(auto u: M2) {cout<<u<<" ";}
    cout<<endl;
}
void Try(int k,int kt1, int kt2){
    for(int i=kt1+1; i <= n1+n2; i++ ){
        if(i<=n1){//phieu ma 1
            if (check1(i)){
                //update
                M1.insert(i);
                //visited[i]=1;

                if(k<=L && check()){
                    res++;
                    //cout<<"k: " <<k<<endl;
                    //Try_print();
                }
                if(k<L) Try(k+1,i,kt2);

                //release
                M1.erase(i);
                //visited[i]=0;
            }
        }

        else if (kt2+1<=i){
            if (check2(i)){
                //update
                M2.insert(i);
                //visited[i]=1;

                if(k<=L && check()){
                    res++;
                    //cout<<"k2: " <<k<<endl;
                    //Try_print();
                }
                if(k<L) Try(k+1,kt1,i);

                //release
                M2.erase(i);
                //visited[i]=0;
            }

        }
    }

}

int main(){
    cin>>n1>>n2;
    cin>>L>>M>>P;
    for (int i=1; i<=P; i++){
        int a,b;
        cin>>a>>b;
        sto[a].push_back(b);
        sto[b].push_back(a);
    }
    cout<<"sto"<<endl;

    for(int i=1; i<=n1+n2; i++){
        cout<<i<<" ";
        for (auto u:sto[i]){
        cout<<u<<" ";
        }
        cout<<endl;
    }

    cout<<"Batdau"<<endl;
    Try(1,0, n1);
    cout<<res/2<<endl;
}
