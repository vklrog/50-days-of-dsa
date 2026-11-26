// problem 1) 3360. Stone Removal Game
class Solution {
public:
    bool canAliceWin(int n) {
        int al=true;
        int in=10;
        while(n>=0){
            if(al){
                n-=in;
                al=false;
            }else{
                n-=in;
                al=true;
            }
            in--;
        }
        if(!al){ //alice
            if(n<0){
                return false;
            }{
                return true;
            }
        }else{ // bob
            if(n<0){
                return true;
            }else{
                return false;
            }
        }

    }
};