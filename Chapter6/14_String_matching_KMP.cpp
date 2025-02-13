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
int pi[MAXP];
int res=0;
//bai nay thuat toan dang bat dau tu 1

void computePi(string &A){
    int a = A.size();
    pi[1]=0;
    int k=0; //do dai cua tien to(prefix) dai nhat , la hau to (suffix) dung tai thoi diem q-1
    for (int q=2; q<=a; q++){
        while (k >0 && A[k+1]!= A[q] ){
            k = pi[k]; //quay lui de check
        }
        if (A[k+1]== A[q]) k++;
        pi[q]=k;

    }
}


void KMP(string &A, string &B){
    A = "-" + A;
    B = "-" + B;
    int a = A.size()-1; //vi ta da them mot ki tu gia vao dau nen phai tru no
    int b = B.size()-1;
    computePi(A);
    int q=0;
    for(int i=1; i<=b; i++){
        while (q> 0 && A[q+1]!= B[i]){
            q=pi[q];
        }

        if  (A[q+1]==T[i]) q++;
        if(q==a) {
            res++;
            q=pi[q];
        }
    }
}

int main(){
    getline(cin, P);
    getline(cin, T);
    KMP (P,T);
    cout<<res<<endl;
}
