/*
Given a string T and a pattern P which is also a string. Find the number of occurrences of P in T.
Input
Line 1: contains string P (length is less than or equals to 10 5)
Line 2: contains the string T (length is less than or equals to 10 6)
Output
Write the number of occurrences of P in T
Example
Input
computer
There are so many kinds of computers today including high performance computers, laptop computers. Mobile phones are also computers
Output
4
*/

#include <bits/stdc++.h>
using namespace std;
#define MAXP 10005
#define MAXT 100005
string P,T;
int last[256]; //luu vi tri xuat hien cuoi cung cua ki tu
int res=0;


void BoyerMoore(string &A, string &B){
    int a = A.size();
    int b = B.size();

    //tim vi tri cuoi cung xuat hien cua tung ki tu trong mang A
    memset(last, -1, sizeof(last));

    for (int i=0; i< a; i++ ){
        last[A[i]] = i;
    }

    int s=0; //vi tri bat dau so sanh

    while( s < b - a ){
        //so sanh tu phai qua trai
        int i = a - 1; //vi tri cuoi mang A

        while ( i>= 0 && A[i]== B[s+i]) i--;

        if (i<0) {
            res++; // khop hoan toan
            s+= 1;
        }
        else{
            //TH1: last[c] < i
            char n = B[s+i]; // ki tu hien tai cua chuoi B dang khong khop

            if (last[n] < i && last[n]!=-1){
                s += i - last[n];
            }
            else{ //neu last[c] >i hoac khong ton tai
                s += i + 1;
            }
        }
    }
}


int main(){

    getline(cin, P);
    getline(cin, T);
    BoyerMoore(P,T);
    cout<<res<<endl;
}
