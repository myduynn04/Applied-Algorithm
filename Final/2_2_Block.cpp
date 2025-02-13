/*
Trong thời đại chiến quốc, bạn là một kiến trúc sư danh tiếng của Vương quốc An Lạc, được giao nhiệm vụ
xây dựng một pháo đài vững chãi để chống lại kẻ địch đang tiến gần. Pháo đài này không chỉ cần mạnh mẽ
mà còn phải phản ánh vẻ đẹp của nghệ thuật và kiến trúc An Lạc. Để thực hiện điều này, bạn cần tập hợp
các khối đá với kích thước L1xW1xH1, L2xW2xH2, ..., LNxWNxHN, đây là nền móng cho các tòa tháp và bức tường
của pháo đài. Vừa qua, quân đoàn thợ mỏ của bạn đã phát hiện một khối đá lớn dạng hình hộp chữ nhật,
nguyên liệu lý tưởng cho kế hoạch của bạn. Khối đá (hoặc bất kỳ khối nhỏ nào được cắt từ nó) chỉ có thể
được cắt theo ba chiều không gian (dài, rộng, cao) thành hai khối nhỏ hơn với các kích thước nguyên.
Mỗi lần cắt đá là phải xuyên suốt qua khối đó (cắt đứt đôi hoàn toàn khối đá theo chiều đã chọn).
Đây là cách duy nhất để cắt khối đá, và các khối sau khi cắt không thể được ghép lại với nhau thành khối
to hơn được. Lưu ý, các khối đá này có thể được xoay theo nhiều hướng khác nhau để phù hợp với từng vị trí
cụ thể trong lúc xây dựng pháo đài: một khối với kích thước AxBxC có thể được sử dụng giống như khối BxAxC,
BxCxA, CxAxB, hoặc CxBxA. Bạn có thể tạo ra không hoặc nhiều khối với mỗi kích thước mong muốn. Một khối đá
bị lãng phí nếu nó không phải là một trong những kích thước mong muốn sau tất cả các lần cắt. Nhiệm vụ của
bạn là làm thế nào để cắt khối đá ban đầu sao cho tổng thể tích các khối đá bị lãng phí là ít nhất.

Đầu vào:

Dòng thứ nhất chứa một số nguyên dương T là số lượng test case (1 ≤ T ≤ 10). Mỗi bộ test case có khuôn dạng
như sau:
· Dòng đầu tiên chứa ba số nguyên thể hiệnkích thước L, W, H (1 ≤ L, W, H ≤ 100) của khối đá ban đầu.

· Dòng thứ hai chứa một số nguyên N (0 < N ≤ 50): số lượng các khối có kích thước mong muốn.

· N dòng tiếp theo chứa kích thước các khối mong muốn. Mỗi dòng chứa ba số nguyên: chiều dài Li,
chiều rộng Wi, và chiều cao Hi của kích thước khối mong muốn đó (1 ≤ i ≤ N). Dữ liệu đảm bảo
1 ≤ Li ≤ L, 1 ≤ Wi ≤ W, và 1 ≤ Hi ≤ H.

Kết quả:

Viết mỗi test case ghi ra trên một dòng một số nguyên duy nhất là tổng thể tích tối thiểu của lượng đá
bị lãng phí từ việc cắt khối đá cẩm thạch ban đầu.

Ví dụ:
Dữ liệu vào
2
5 10 3
3
3 9 3
2 4 3
2 2 2
5 5 2
2
3 2 3
1 3 2
Kết quả
13
8

Giải thích
Với test case đầu, bạn có thể cắt thành 1 khối 3x9x3,   hai khối 2x4x3 và 1 khối 2x2x2. Lãng phí một khối 1x3x3 và 1 khối 2x2x1 có tổng   thể tích là 13
Với test case thứ hai, bạn có thể cắt thành 1 khối   3x2x3 và 4 khối 1x3x2. Lãng phí một khối 2x2x2 có thể tích là 8
*/


#include <bits/stdc++.h>
using namespace std;
#define MAXN 10000000
int T;
int block[3][55]; //mang luu cac block mong muon
int mem[102][102][102];
int main(){
   cin>>T;
   int res[T];
   for (int u = 1; u<=T; u++){
        int l,h,w,n;
        cin>>l>>h>>w;
        cin>>n;

        for (int i=1; i<=n; i++){
          cin>>block[0][i]>> block[1][i] >>block[2][i];
        }

        for (int i =1; i<=l; i++){
            for (int j=1; j<=h; j++ ){
                for (int k=1; k<=w; k++){
                        mem[i][j][k]=MAXN;}}}

        for (int i =1; i<=l; i++){
            for (int j=1; j<=h; j++ ){
                mem[i][j][0]=0;}}
        for (int i =1; i<=h; i++){
            for (int j=1; j<=w; j++ ){
                mem[0][i][j]=0;}}
        for (int i =1; i<=w; i++){
            for (int j=1; j<=l; j++ ){
                mem[j][0][i]=0;}}

        for (int i=1; i<=n; i++){
            mem[block[0][i]][block[1][i]][block[2][i]] =0;
            mem[block[0][i]][block[2][i]][block[1][i]] =0;
            mem[block[1][i]][block[0][i]][block[2][i]] =0;
            mem[block[1][i]][block[2][i]][block[0][i]] =0;
            mem[block[2][i]][block[1][i]][block[0][i]] =0;
            mem[block[2][i]][block[0][i]][block[1][i]] =0;}

        for (int i =1; i<=l; i++){
            for (int j=1; j<=h; j++ ){
                for (int k=1; k<=w; k++){
                    mem [i][j][k]= min(mem[i][j][k],
                                        min(mem[i-1][j][k] +j*k,
                                            min(mem[i][j-1][k] +i*k, mem[i][j][k-1] +j*i ) ) );
                    //Cut along l
                    for (int x=1; x<=i; x++) mem[i][j][k] = min ( mem[i][j][k],mem[i-x][j][k] +mem[x][j][k] );
                    //Cut along h
                    for (int x=1; x<=j; x++) mem[i][j][k] = min ( mem[i][j][k],mem[i][j-x][k] +mem[i][x][k] );
                    //Cut along w
                    for (int x=1; x<=k; x++) mem[i][j][k] = min ( mem[i][j][k],mem[i][j][k-x] +mem[i][j][x] );

                }}}
      res[u]=mem[l][h][w];}
    for (int u=1; u<=T; u++) cout<<res[u]<<endl;
    return 0;
}




