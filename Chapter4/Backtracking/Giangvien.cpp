/*Balanced Courses Assignments
Description
At the beginning of the semester, the head of a computer science department D have to assign courses to teachers in a balanced way. The department D has m teachers T={1,2,...,m} and n courses C={1,2,...,n}. Each teacher t?T has a preference list which is a list of courses he/she can teach depending on his/her specialization. We known a list of pairs of conflicting two courses that cannot be assigned to the same teacher as these courses have been already scheduled in the same slot of the timetable. The load of a teacher is the number of courses assigned to her/him. How to assign nn courses to mm teacher such that each course assigned to a teacher is in his/her preference list, no two conflicting courses are assigned to the same teacher, and the maximal load is minimal.
Input
The input consists of following lines
Line 1: contains two integer m and n (1=m=10, 1=n=30)
Line i+1: contains an positive integer k and k positive integers indicating the courses that teacher i can teach (?i=1,…,m)
Line m+2: contains an integer k
Line i+m+2: contains two integer i and j indicating two conflicting courses (?i=1,…,k)
Output
The output contains a unique number which is the maximal load of the teachers in the solution found and the value -1 if not solution found.
Example
Input
4 12
5 1 3 5 10 12
5 9 3 4 8 12
6 1 2 3 4 9 7
7 1 2 3 5 6 10 11
25
1 2
1 3
1 5
2 4
2 5
2 6
3 5
3 7
3 10
4 6
4 9
5 6
5 7
5 8
6 8
6 9
7 8
7 10
7 11
8 9
8 11
8 12
9 12
10 11
11 12

Output
3 */
#include <bits/stdc++.h>
using namespace std;

#define MAX 1e9
int m, n; //m giang vien, n khoa hoc
int k;
map <int, vector<int>> course; //mon hoc i, sau la danh sach cac gv cpo the day mon i
int conflict[35][35] ={0}; // luu cac cap mon hoc bi xung dot
vector<int> asigned[25];  //vector luu cac mon hoc ma giang vien i da duoc phan cong
int best =MAX;



bool check (int k, int i){
 for (int a: asigned[i]){
    if (conflict[k][a]) return 0;
 }
 return 1;

}

void upd_Best( ){
    int temp=0;
    for (int i=0; i<m; i++){
        int e= asigned[i].size();
        temp= max (temp, e);
    } //temp luu gv co nhieu mon hoc nhat

    best = min (temp,best) ;

}

int check2(int i)
{
    if (asigned[i].size() > best) return 0;
	return 1;

}
//duyet theo khoa hoc
void Try(int k){
    for (int i: course[k]) {
        if (check(k,i)){
            //se check xem giang vien co bi xung dot khong
            //update
            asigned[i].push_back(k);


            //dieukien dung
            if(k==n){
                upd_Best();
            }
            else if ( check2(i) ) {

                Try(k+1);
            }

            //release
            asigned[i].pop_back();

        }
    }

}


int main(){
	cin>>m>>n;
	//doan nay bat dau nhap giao vien i va ten cac mon day dc
	for (int i=1; i<=m; i++){
        int num; cin>>num; //num la so mon ma giang vien do co the day, sau do la input ma cac mon
        for (int j=0; j<num; j++ ){
            int temp; cin>>temp;
            course[temp].push_back(i); //them giang vien thu i vao danh sach co the day mon temp
        }
	}

	cin>>k;
	for (int i=0; i<k; i++){
        int s1, s2;
        cin>>s1>>s2;
        conflict[s1][s2]=1;
        conflict[s2][s1]=1;
	}

	Try(1);
	cout<<best<<endl;
	return 0;


}
















