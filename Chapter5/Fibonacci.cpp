#include <bits/stdc++.h>
using namespace std;

map <int, int> M;
int Fib(int n){
	if (n == 0) return 0; // base case
	if (n == 1 || n== 2) return 1; //base
	
	if (M.find(n)!= M.end()) return M[n]; //Duyet xem co chua
	
	int result =Fib(n-1)+Fib(n-2);
	M[n] = result;
    return result;
}

int main(){
	int n;
	cin>>n;
	cout<<Fib(n);
	return 0;
}


/*const int N = 1e4 + 5;
int mem[N];
memset(mem, -1, sizeof(mem));

int Fib(int n) {
    if (n <= 2) return 1;
    if (mem[n] != -1) // Ki?m tra xem giá tr? Fibonacci dã du?c tính chua
        return mem[n];
    int res = Fib(n - 1) + Fib(n - 2);
    mem[n] = res; // Luu k?t qu? vào m?ng
    return res;
}*/
