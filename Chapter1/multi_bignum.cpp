#include <iostream>
#include <string>
#include <vector>

using namespace std;


string multiply(string a, string b) {
    int len1 = a.size();
    int len2 = b.size();
    
    if (a == "0" || b == "0") {
        return "0";
    }
    
    vector<int> result(len1 + len2, 0);
    for (int i =len1-1; i>= 0; --i) {
        for (int j = len2-1; j>= 0; --j) {
            int mul = (a[i] - '0') * (b[j] - '0'); 
            int sum = mul + result[i + j + 1]; 
            result[i + j + 1] = sum % 10; 
            result[i + j] += sum / 10; 
        }
    }
    
    
    string product = "";
    bool leadingZero = true; 
    for(int num : result) {
        if (leadingZero && num == 0) continue; 
        leadingZero = false; 
        product+= to_string(num);
    }
    return product;
}

int main() {
    string a, b;
    cin>>a>>b;
    cout<<multiply(a, b)<<endl;

    return 0;
}
