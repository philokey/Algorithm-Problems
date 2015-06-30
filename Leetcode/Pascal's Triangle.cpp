class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ret;  
        if(numRows == 0)  return ret;  
        for(int i = 0; i < numRows; ++i) {  
            vector<int> onelevel;  
            onelevel.clear();  
            onelevel.push_back(1);  
            for(int j = 1; j <= i; ++j)  
            {  
                onelevel.push_back(ret[i-1][j-1] + (j < i ? ret[i-1][j] : 0));  
            }  
            ret.push_back(onelevel);  
        }  
        return ret;  
    }
};
