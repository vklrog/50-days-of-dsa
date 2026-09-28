//problem 1) 1614. Maximum Nesting Depth of the Parentheses
class Solution {
public:
    int maxDepth(string s) {
        int mx=INT_MIN;
        int cnt=0;
        for(auto i:s){
            if(i=='('){
                cnt++;
            }
            if(i==')'){
                cnt--;
            }
            mx=max(mx,cnt);
        }
        return mx;
    }
};
//problem 2) 24. Swap Nodes in Pairs
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        vector<pair<ListNode*, ListNode*>> v;
        ListNode* temp = head;
        while(temp){
            if(temp->next){
                v.push_back({temp->next, temp});
                temp = temp->next->next;
            }
            else{
                v.push_back({temp, nullptr});
                temp = temp->next;
            }
        }
        ListNode* start = v[0].first;
        ListNode* prev = NULL;
        for(auto [u,vv] : v){
            if(prev){
                prev->next = u;
            }
            u->next = vv;
            prev = vv ? vv : u;
        }
        prev->next = NULL;
        return start;
    }
};