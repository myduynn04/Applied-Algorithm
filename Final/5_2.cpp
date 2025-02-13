#include <bits/stdc++.h>
using namespace std;

int n1,n2;
int L, M, P;
int A[24][24]={0};
int res=0;
set <int> M1; // luu cac phieu ma1 da co
set <int> M2; //luu cac phieu ma 2 da co
int visited[26]={0};

//check phieu ma 1 thoa man khong
//1. Khong dau tu qua M co phieu loai nay
//2. Khong dau tu neu bi xung dot trong M2
//3. Ma nay chua tung duoc chon
int check1(int i){

    if(M1.size()==M)return 0;
    for(auto u: M2){
        if(A[u][i]==1 || A[i][u]==1) return 0;}
    return 1;}

int check2(int i){
    if(M2.size()==M)return 0;
    for(auto u: M1){
        if(A[u][i]==1 || A[i][u]==1) return 0;}
    return 1;}

//Dieu kien la moi loai ma deu phai dau tu it nhat 1 ma co phieu
int check(){
    if(M2.size()<1 || M1.size()<1) return 0;
    return 1;}

void Try(int k,int kt1, int kt2){
    for(int i=kt1+1; i <= n1+n2; i++ ){
        if(i<=n1){//phieu ma 1
            if (check1(i)){
                M1.insert(i);
                if(k<=L && check())res++;
                if(k<L) Try(k+1,i,kt2);
                M1.erase(i);}}

        else if (kt2+1<=i){
            if (check2(i)){
                M2.insert(i);
                if(k<=L && check()){res++;}
                if(k<L) Try(k+1,kt1,i);
                M2.erase(i);}}}}

int main(){
    cin>>n1>>n2;
    cin>>L>>M>>P;
    for (int i=1; i<=P; i++){
        int a,b;
        cin>>a>>b;
        A[a][b]=1;A[b][a]=1;}
    Try(1,0, n1);
    cout<<res/2<<endl;
}
