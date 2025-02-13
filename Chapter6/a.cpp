/*Given a set of points P1, P2, ..., Pn on the plane: point Pi has coordinate (xi,yi).
Compute the convex hull of the given points: The convex hull is a subset of the given points that forms a convex polygon that contains all the given points.

Input
Line 1: contains a positive integer n (3 <= n <= 100000)
Line i+1 (i = 1, 2, ..., n): contains 2 integers xi, yi (-1000 <= xi, yi <= 1000)

Output
Line 1: writes the number of points of the convex hull found
Subsequent lines, each line contains 2 integers which are the x-coordinate and y-coordinate of a point of the convex hull found

Example
Input
6
4 5
5 3
5 6
2 5
8 7
3 7

Output
4
5 3
8 7
3 7
2 5 */


#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int n;
struct Point{ //toa do
    int x;
    int y;
} ;
stack <int> S;
Point P[MAXN];
vector <pair<int,long long>> cos1;

long long cosine (Point A, Point B){
    int xa= A.x;
    int ya= A.y;
    int xb= B.x;
    int yb= B.y;
    long long dis1 = sqrt(xa*xa + ya*ya);
    long long dis2 = sqrt(xb*xb + yb*yb);
    return (xa*xb+ya*yb)/(dis1*dis2);

}

long long cross_product(int a, int b, int c){
    //vector Pi Pi-1  (i o day la ptu dau stack)
    int x1 = P[a].x - P[b].x;
    int y1 = P[a].y - P[b].y;

    //vector Pa Pi
    int x2 = P[b].x - P[c].x;
    int y2 = P[b].y - P[c].y;

    return  y1*x2 - x1*y2;

}

int main(){
    cin>>n;

    for (int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        P[i].x=a;
        P[i].y=b;

    }

    sort(P, P + n ,[](Point a, Point b) {
    if (a.y==b.y) return a.x < b.x;
    return a.y < b.y;
    });

    for (int i=0; i< n; i++){
        int a;
        long long b;
        a=i;
        b = cosine(P[0], P[i]);
        cos1.push_back(make_pair(a,b));
    }

    sort (cos1.begin(), cos1.end(), [](auto a, auto b){
          return a.second >b.second;
          });

    S.push(0); //cho P0 vao
    S.push(cos1[1].first) ;    //Cho P1 vao
    for (int i=2; i<n; i++){
        int b = S.top();
        S.pop();
        int a= S.top();

        while (cross_product(a,b,cos1[i].first)<0){
            b = a;
            S.pop();
            a = S.top();
        }
        S.push(b);
        S.push(cos1[i].first);
    }
    cout<< S.size()<<endl;
    while(!S.empty()){
        int a= S.top();
        S.pop();
        cout << P[a].x<< " "<< P[a].y<<endl;
    }


}
