//problem 1) 836. Rectangle Overlap
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        using ll=long long;
        ll x1 = rec1[0], y1 = rec1[1];
        ll x2 = rec1[2], y2 = rec1[3];
        ll x3 = rec2[0], y3 = rec2[1];
        ll x4 = rec2[2], y4 = rec2[3];
        if(x1==x3 && y1==y3 && x2==x4 && y2==y4){
            return true;
        }
        if((x1<=x3 && x3<x2)|| (x3<=x1 && x1<x4) ||(x1==x3 && x2==x4)){
            if((y1<=y3 && y3<y2)|| (y3<=y1 && y1<y4) || (y2==y4 && y1==y3)){
                return true;
            }
        }
        return false;
    }
};
// problem2) 2253B - Hypercarp and the Control Panel
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<pair<int, int>> groups;

    for (int x : a) {
        if (groups.empty() || groups.back().first != x)
            groups.push_back({x, 1});
        else
            groups.back().second++;
    }

    int m = groups.size();

    for (int i = 0; i + 1 < m; i++) {
        if (groups[i].second > 1 &&
            groups[i + 1].second > 1) {
            cout << m + 2 << '\n';
            return;
        }
    }

    for (int i = 0; i < m; i++) {

        if (i < m - 1 &&
            groups[i].second > 1 &&
            (i + 2 >= m ||
             groups[i + 2].first != groups[i].first)) {

            cout << m + 1 << '\n';
            return;
        }
        if (i > 0 && groups[i].second > 1 && (i - 2 < 0 || groups[i - 2].first != groups[i].first)) {
            cout << m + 1 << '\n';
            return;
        }
    }

    cout << m << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
        solve();
}