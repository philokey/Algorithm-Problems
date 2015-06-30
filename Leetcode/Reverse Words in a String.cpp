class Solution {
public:
    stack<string> sta;
    string str;
    void reverseWords(string &s) {
        str.clear();
        for(int i = 0; s[i]; i++) {
            if(s[i]==' ') {
                sta.push(str);
                str.clear();
            }
            else str+=s[i];
        }
        sta.push(str);
        bool flag = 0;
        s.clear();
        while(!sta.empty()) {
            str = sta.top();
            sta.pop();
            if(str.length()==0) continue;
            if(flag) s+=" ";
            flag = 1;
            s+=str;
        }
    }
};
