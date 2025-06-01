class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        if(tickets.size() == 0) return 0;

        // <num, index>
        queue<std::pair<int, int> > q;
        for(int i = 0; i < tickets.size(); i++){
            q.push(std::make_pair(tickets[i], i));
        }

        int time = 0;
        while(!q.empty()) {
            auto& index = q.front().second;
            auto& num = q.front().first;

            time++;
            num--;            
            if(num == 0 && index == k) return time;

            q.pop();
            if(num != 0) {
                q.push(std::make_pair(num, index));
            }
        }
        return time;
    }
};