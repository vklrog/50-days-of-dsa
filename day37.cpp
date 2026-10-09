//problem 1) 1541. Minimum Insertions to Balance a Parentheses String
class Solution {
public:
    int minInsertions(string s) {
        int count=0;
        int result=0;
        for(int i=0;i<s.size();){
            if(count>0){
                if(s[i]==')'){
                    count-=1;
                    if(i+1<s.size() && s[i+1]==')'){
                        i+=2;
                    }else{
                        result+=1;
                        i+=1;
                    }
                }else if(s[i]=='('){
                    count++;
                    i+=1;
                }
            }else{
                if(s[i]==')'){
                    if(i+1<s.size() && s[i+1]==')'){
                        result+=1;
                        i+=2;
                    }else{
                        result+=2;
                        i+=1;
                    }
                }else if(s[i]=='('){
                    count++;
                    i+=1;
                }
            }
        }
        result+=(count*2);
        return result;
    }
};