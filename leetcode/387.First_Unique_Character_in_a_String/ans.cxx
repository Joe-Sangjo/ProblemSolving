class Solution {
public:
    int firstUniqChar(string s) {
        int ret = -1;
        if(s.size() == 0) return -1;
        queue<char> q;
        q.push(s[0]);
        for(int i = 1; i < s.size(); i++) {
            char& prev = s[i-1];
            char& cur = s[i];

            
        }
    }
};