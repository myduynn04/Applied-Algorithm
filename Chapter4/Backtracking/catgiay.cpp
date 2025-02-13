/*
Description
Given a material having the shape rectangle with height H and width W.
We need to cut this material into n smaller rectangle submaterials of
size (h1,w1), (h2, w2), ..., (hn, wn). Write a program to check if we
can perform this cut.
Input
Line 1: contains two positive integers H, W (1 <= H, W <= 10)
Line 2: contains a positive integer n (1 <= n <= 10)
Line i+2 (i= 1,...,n): contains two positive integer hi and wi (1 <= hi, wi <= 10)
Output
Write 1 if we can perform the cut and write 0, otherwise.
Example
Input
7 5
4
1 5
6 2
2 2
4 3
Output
1
*/

//Backtracking
#include <bits/stdc++.h>
using namespace std;

int H,W;
int n;
int psize[2][11]; // chieu 1 la dai hay rong, chieu 2 la luot
int res=0; // xem co ket qua chua
int grid[11][11]={0}; //kiem tra trang thai tung ô
//check xem co xep duoc vao bang khong
bool check(int i, int j, int r, int k ){
	int h= psize[r][k];
	int w = psize[1-r][k];
	if ( i +h > H || j+w >W ) return false;
	for (int a=i; a<i+h; a++){
		for (int b=j; b<j+w; b++){
			if ( (grid[a][b])==1 )return false;}}
	return true;}
void upd (int i, int j, int r, int k ){
	int h= psize[r][k];
	int w = psize[1-r][k];
	for (int a=i; a<i+h; a++){
		for (int b=j; b<j+w; b++){
			grid[a][b]=1;}}}
void release (int i, int j, int r, int k ){
	int h= psize[r][k];
	int w = psize[1-r][k];
	for (int a=i; a<i+h; a++){
		for (int b=j; b<j+w; b++){
			grid[a][b]=0;}}}
void Try (int k){
	//duyet theo tung mieng
	//for theo 2 cach xep : 0: nguyen ban, 1: xoay
	for (int r=0; r<2; r ++){
		for (int i=0; i<H; i++){
			for(int j=0; j<W; j++){
				if (check(i, j , r, k)){
					//update
					upd(i,j,r,k);
					//dieu kien stop
					if (k == (n-1)){res=1;}
					else {Try(k+1);}
					//release
					release(i,j,r,k);}}}}}
int main(){
	cin >>H>>W;
	cin>>n;
	for (int i=0; i<n; i++) {cin >>psize[0][i]>>psize[1][i];}
	Try(0);
    cout <<res<<endl;
	return 0;}
















