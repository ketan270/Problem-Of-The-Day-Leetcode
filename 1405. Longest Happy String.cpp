class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, int>> pq;
        pq.push({a, 'a'});
        pq.push({b, 'b'});
        pq.push({c, 'c'});

        string res = "";
        while(pq.size() > 1)
        {
            char ch = pq.top().second;
            int freq = pq.top().first;
            pq.pop();

            if(res.size() && res.back() == ch)
            {
                int freq2 = pq.top().first;
                char ch2 = pq.top().second;
                pq.pop();

                if(freq2 <= 0)
                    break;

                res.push_back(ch2);
                pq.push({freq2 - 1, ch2});
            }
            if(freq <= 0)
                break;
            if(freq == 1)
                res.push_back(ch);
            else
            {
                res.push_back(ch);
                res.push_back(ch);
            }
            pq.push({freq - 2, ch});

        }
        return res;
    }
};
