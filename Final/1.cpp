/* Cho một dãy bất kì d: 3 4 6 1 2
Cần chia dãy thành k dãy con liên tiếp.
Tìm chênh lệch nhỏ nhất trong các trường hợp mình chia (trị tuyệt đối của tổng dãy
con lớn nhất trừ nhỏ nhất)*/

#include <bits/stdc++.h>
using namespace std;
#define N 1005
#define MAXN 100000000
int n;
int a[N];
int h_best =MAXN;
int g[25];
int K;
int sum[N]={0};


int check(int k){
for (int u=1; u<k; u++){
    if (abs(g[k]-g[u]) >h_best ) return 0;

}
return 1;
}

void update(){
    int max_distance=0;
    for (int i=1; i<=K; i++){
        for (int j = i+1; j<=K; j++){
            max_distance=max(max_distance,abs(g[j]-g[i]) );
        }
    }

    h_best= min(h_best, max_distance);
}

void Try(int k,int i){
    if (k==K){
            g[k]= sum[n]- sum[i];
            update();
                }
    else{
        for (int j=i+1; j<n; j++){

            g[k] = sum[j]-sum[i];

            if (check(k)){
                Try(k+1, j);
            }

            g[k]=0;

    }
    }


}


int main(){
    cin>>n;
    for (int i=1; i<=n; i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];

    }
    cin>>K;
    Try(1,0); //k=1 la mang con dau tien, 0 la vi tri ket thuc -> duyet tu a[1]

    cout<<h_best<<endl;

    return 0;

}























