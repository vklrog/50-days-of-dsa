//problem1) 3871. Count Commas in Range II
class Solution {
public:
    long long countCommas(long long n) {
        using ll = long long;
        ll ans = 0;
        map<int, pair<ll, ll>> m = {
            {1, {1000LL, 999999LL}},
            {2, {1000000LL, 999999999LL}},
            {3, {1000000000LL, 999999999999LL}},
            {4, {1000000000000LL, 999999999999999LL}},
            {5, {1000000000000000LL, 999999999999999999LL}}
        };
        ll sub = 0;
        if (n < 1000) {
            return 0;
        }
        while (n >= 1000) {
            int ad;
            for (const auto& el : m) {
                if (n <= el.second.second) {
                    sub = el.second.first;
                    ad = el.first;
                    ans += (n - sub + 1) * ad;
                    break;
                }
            }
            n = sub - 1;
        }
        return ans;
    }
};
//problem2) 445. Add Two Numbers II

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp=l1;
        vector<int> l;
        while(temp){
            int val=temp->val;
            l.push_back(val);
            temp=temp->next;
        }
        ListNode* temp2=l2;
        vector<int> r;
        while(temp2){
            int val=temp2->val;
            r.push_back(val);
            temp2=temp2->next;
        }
        ListNode* next=nullptr;
        ListNode* head=nullptr;;
        ListNode* curr=head;
        int rem=0;
        int i=0,j=0;
        reverse(begin(l),end(l));
        reverse(begin(r),end(r));
        while(i<l.size() && j<r.size()){
            int  sum=l[i]+r[j]+rem;
            if(sum>=10){
                rem=1;
                sum=sum%10;
            }else{
                rem=0;
            }
            ListNode* temp=new ListNode(sum);
            curr=temp;
            curr->next=next;
            next=curr;
            i++;
            j++;

        }
        while(i<l.size()){
            int val=l[i]+rem;
            if(val>=10){
                rem=1;
                val=val%10;
            }else{
                rem=0;
            }
            ListNode* temp=new ListNode(val);
            curr=temp;
            curr->next=next;
            next=curr;
            i++;
        }
        while(j<r.size()){
            int val=r[j]+rem;
            if(val>=10){
                rem=1;
                val=val%10;
            }else{
                rem=0;
            }
            ListNode* temp=new ListNode(val);
            curr=temp;
            curr->next=next;
            next=curr;
            j++;
        }
        if(rem!=0){
            ListNode* temp=new ListNode(rem);
            curr=temp;
            curr->next=next;
            next=curr;
        }
        return next;
    }
};

//problem3) 442. Find All Duplicates in an Array
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> s;
        vector<int> arr;
        for(auto n:nums){
            if(s.count(n)){
                arr.push_back(n);
            }else{
                s.insert(n);
            }

        }
        return arr;
    }
};