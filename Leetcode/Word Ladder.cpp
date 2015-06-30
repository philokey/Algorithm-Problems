class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<pair<string,int> > q;
        q.push(make_pair(start,1));
        pair<string,int> fr;
        int n;
        while (!q.empty()) {
            fr = q.front();
            q.pop();
            if (fr.first == end) {
                return fr.second;
            }
            n = fr.first.length();
            for (int i = 0; i < n; ++i) {
                string tmp = fr.first;
                for (int j = 0; j < 26; ++j) {
                    if (fr.first[i] != j + 'a') {
                        tmp[i] = j + 'a';
                        unordered_set<string>::iterator pos = dict.find(tmp);
                        if (pos != dict.end()) {
                            dict.erase(pos);
                            q.push(make_pair(tmp,fr.second + 1));
                        }
                    }
                }
            }
        }
        return 0;
    }
};

