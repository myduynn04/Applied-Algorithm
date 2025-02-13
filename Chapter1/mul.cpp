//Cho hai số nguyên dương a và b rất lớn (số chữ số có thể lên tới 10000). Hãy tính và in ra tích của 2 số đó.
/* Ý tưởng: Hai số lớn được lưu dưới dạng string
Kết quả được lưu dưới dạng vector
*/

#include <bits/stdc++.h>
using namespace std;

/*
Trước hết, mảng result sẽ có độ dài là a.size() + b.size()
Ta thấy nếu a[i].b[j] thì kết quả sẽ ảnh hưởng tới hai phần từ trong mảng
là result [i+j+1] và result[i+j]:
mul= (a[i]-'0')* (b[j]-'0')
sum= mul + result[i+j+1]  -> cộng thêm biến nhớ từ phép tính trước và cả kết quả của phép nhân ở phía trên
result [i+j+1] = sum%10  -> đơn vị
 result[i + j] += sum / 10;

*/

string multiply (string a, string b){
int len1= a.size();
int len2= b.size();

if (a=="0" || b=="0") return "0"; //Do a và b đang là xâu 
if (len1=='0' || len2=='0') return "No answer";


vector <int> result (len1+len2);
for (int i=len1-1; i>=0; i--){
    for (int j=len2-1; j>=0; j--){
        int mul = (a[i]-'0')* (b[j]-'0');
        int sum = mul + result[i+j+1];
        result [i+j+1] = sum % 10 ;
         result[i + j] += sum / 10;
    }
}

string product="";
bool leadingZero = true; //cờ kiểm tra xem số 0 ở đầu có cần bỏ qua không, ban đầu được đặt là true --> đang ở trạng thái bỏ qua số 0 ở đầu
for (int num: result){
    if (leadingZero && num==0) continue;
    leadingZero = false; // từ đây trở đi mọi chữ số sẽ được thêm vào chuỗi kết quả
    product += to_string(num);

}
return product;
}


int main(){
    string a, b;
    cin>>a>>b;
    cout<< multiply(a,b)<<endl;
    return 0;
}