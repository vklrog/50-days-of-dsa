// problem 1) 3789. Minimum Cost to Acquire Required Items
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long tk1=max(need1,need2);
        long long mi=LLONG_MAX;
        if(tk1==need1){
            long long cst=min(1ll*cost1*need1+1ll*cost2*need2,1ll*costBoth*need1);
            mi=min(mi,cst);
            mi=min(mi,1ll*need2*costBoth+1ll*(need1-need2)*cost1);
        }
        if(tk1==need2){
            long long cst=min(1ll*cost1*need1+1ll*cost2*need2,1ll*costBoth*need2);
            mi=min(mi,cst);
            mi=min(mi,1ll*need1*costBoth+1ll*(need2-need1)*cost2);
        }
        return mi;
    }
};