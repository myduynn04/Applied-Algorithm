#include <bits/stdc++.h>
using namespace std;


int main(){
    int n; cin>>n;
    int a[n+2]={0};
    for (int i=1; i<=n; i++) cin>>a[i];
    int mem[n+2]={0};
    mem[1]=1;
    for (int i=1; i<=n; i++){
     for (int j=1; j<i; j++){

        if(a[i]>=a[j]){
            mem[i]= max(mem[j]+1, mem[i]);
        }
        mem[i]= max(mem[i], mem[j]);

     }
     //cout<<mem[i]<<endl;
    }
    cout<<mem[n]<<endl;

}
