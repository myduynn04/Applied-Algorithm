/*Slick
The input contains several test cases, each one corresponding to a different satellite image.
The first line of each case contains two integers that indicate the number of rows (N) and
columns (M) in the image (1 <= N, M <= 250). Then N lines follows with M integers each,
containing the information of the image.

The end of input is indicated by a test case with N = M = 0. This case should not
be processed.

Output
For each image, output the number of slicks in the sea. Additionally, output the size of
each slick in ascending order and the number of slicks of that size.

Example
Input:
10 10
1 1 1 1 1 1 1 1 1 1
1 1 1 1 0 0 0 0 0 0
1 1 1 0 0 0 0 1 1 1
1 1 0 0 1 0 0 1 1 1
1 0 1 0 0 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1
0 0

Output:
7
1 2
2 1
6 1
10 2
20 1
*/
//output gom size cua vet dau loang va co bao nhieu vet dau loang co size nay
#include <bits/stdc++.h>
using namespace std;
#define N 255
int n,m;
int A[N][N];
int visited[N][N];
queue <pair <int, int> > Q;
int num_slick=0; //so luong vet dau loang
vector <int> slick;




void check(int i, int j){

    if (A[i+1][j] && !visited[i+1][j] && i+1<=n){
        Q.push(make_pair(i+1,j));
        visited[i+1][j]=1;
        slick[num_slick]++;
    }
    if (A[i][j+1] && !visited[i][j+1] && j+1 <=m){
        Q.push(make_pair(i,j+1));
        visited[i][j+1]=1;
        slick[num_slick]++;
    }
    if (A[i-1][j] && !visited[i-1][j] && i-1>=1){
        Q.push(make_pair(i-1,j));
        visited[i-1][j]=1;
        slick[num_slick]++;
    }
    if (A[i][j-1] && !visited[i][j-1] && j-1 >=1){
        Q.push(make_pair(i,j-1));
        visited[i][j-1]=1;
        slick[num_slick]++;
    }

}


void bfs(int i, int j){
    slick.push_back(1);
    num_slick++;  //tang so luong tplt
    visited[i][j]=1;
    Q.push(make_pair(i,j));

    while (!Q.empty()){
        auto top= Q.front();
        Q.pop();
        check(top.first, top.second);
    }

}



int main(){
    slick.push_back(0);
    memset(A, 0, sizeof(A));
    memset(visited, 0, sizeof(visited));
    cin>>n>>m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin>>A[i][j];
        }
    }
    int a,b;
    cin>>a>>b;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if(!visited[i][j] && A[i][j]) bfs(i,j);
        }
    }
    cout<<num_slick<<endl;

    //ta se sap xep lai slick theo size
    sort (slick.begin(), slick.end());
    int temp=0;
    int c=0;
    for (int i=1; i<slick.size(); i++){
        if (slick[i]!=temp){
            //if(temp!=0) cout<<temp<<" "<<c<<endl;
            temp=slick[i];
            c=1;
        }
        else c++;
    }
    if(temp!=0) cout<<temp<<" "<<c<<endl; //in phan tu cuoi cung

    return 0;
}












