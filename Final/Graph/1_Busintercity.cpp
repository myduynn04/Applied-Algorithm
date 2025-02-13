#include <bits/stdc++.h>
using namespace std;

#define MAX_INT 1000000

int n, m;
int C[10001], D[10001];
int visited[10001] = {0};
map<int, set<int> > sto;


auto compare = [] (pair<int, int> p1, pair<int, int> p2) {
    return p1.second > p2.second;
};

int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> C[i] >> D[i];
    }
    for (int i=0; i<m; i++) {
        int s, e; cin >> s >> e;
        sto[s].insert(e);
        sto[e].insert(s);
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(compare)> Q(compare);
    Q.push(make_pair(1, 0)); //thanh pho dang dung, chi phi bo ra
    while (!Q.empty()) {
        auto top = Q.top(); Q.pop();
        visited[top.first] = 1;
        if (top.first == n) {
            cout << top.second;
            return 0;
        }
        int d = 1; //kha nang di ~ do sau
        set<int> st; //luu tru cac tp da duoc tham
        set<int> city;
        city.insert(top.first);
        while (d <= D[top.first]) {
            set<int> new_city;
            for (auto v : city) {
                for (auto g : sto[v]) {
                    if (!visited[g] && st.find(g) == st.end()) {

                        new_city.insert(g);
                        st.insert(g);
                        Q.push(make_pair(g, C[top.first] + top.second));
                    }
                }
            }
            city = new_city;
            d++;
        }
    }
}
