#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000000
int n;
int a[100005];
int imax=0;
    int imin= MAXN;

int main(){
    cin>>n;
    for(int i=1; i<=n;i++) {
        cin>>a[i];
        imax=max(imax,a[i]);
        imin= min(imin,a[i]);
    }
    cout<<imin<<" "<<imax<<endl;

}
