//problem 1) 109A - Lucky Sum of Digits
#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve() {
    int n;
    cin >> n;
    for (int b = n / 7; b >= 0; b--) {
        int rem = n - (b * 7);
        if (rem % 4 == 0) {
            int a = rem / 4;
            string s(a, '4');
            s.append(b, '7');
            
            cout << s << "\n";
            return;
        }
    }
    
    cout << -1 << "\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}

//problem 2) 2094. Finding 3-Digit Even Numbers
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> d(10);
        vector<int> arr;
        for(auto i:digits){
            d[i]++;
        }
        for(int k=100;k<=998;k+=2){
            int i=k;
            int t1=i%10;
            i/=10;
            int t2=i%10;
            i/=10;
            int t3=i%10;
            d[t1]--;
            d[t2]--;
            d[t3]--;
            if(d[t1]>=0 && d[t2]>=0 && d[t3]>=0){
                arr.push_back(k);
            }
            d[t1]++;
            d[t2]++;
            d[t3]++;
        }
        return arr;
    }
};
//problem 3) 1295. Find Numbers with Even Number of Digits
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt=0;
        for(auto i:nums){
            if((i<100 && i>9)||(i>=1000 && i<=9999)||(i==100000)){
                cnt++;
            }
        }
        return cnt;
    }
};
//problem 4) 206. Reverse Linked List
class Solution {
public:
    ListNode* root;
    ListNode* solve(ListNode* head){
        if(head->next==nullptr){
            root=head;
            return head;
        }
        solve(head->next)->next=head;
        return head;
    }
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr) return nullptr;
        ListNode* temp=solve(head);
        temp->next=nullptr;
        return root;
    }
};
//problem 5) 50. Pow(x, n)
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1.0 / x;
            N = -N;
        }
        double res = 1.0;
        while (N) {
            if (N & 1){
                res *= x;
            }
            x *= x;
            N >>= 1;
        }
        return res;
    }
};