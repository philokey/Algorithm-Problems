class Solution {
public:
    int getnum(string num) {
        int ret = 0;
        int beg = 0,op=1;
        if(num[0]=='+') beg = 1,op = 1;
        else if(num[0]=='-') beg = 1,op = -1;
        for(int i = beg; num[i]; i++)
            ret = ret*10+num[i]-'0';
        return ret*op;
    }
    bool judge(string num) {
        if(num.length()==1) {
            if(num[0]>='0'&&num[0]<='9') return 1;
            else return 0;
        }
        return 1;
    }
    int evalRPN(vector<string> &tokens) {
        stack<int> sta;
        int n = tokens.size();
        for(int i = 0; i < n; i++){
            if(judge(tokens[i])){
                sta.push(getnum(tokens[i]));
            }
            else{
                int a,b;
                a = sta.top(),sta.pop();
                b = sta.top(),sta.pop();
                if(tokens[i][0]=='+') b+=a;
                else if(tokens[i][0]=='-') b-=a;
                else if(tokens[i][0]=='*') b*=a;
                else b/=a;
                sta.push(b);
            }
        }
        return sta.top();
    }
};
