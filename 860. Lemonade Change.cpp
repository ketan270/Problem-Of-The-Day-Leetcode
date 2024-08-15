class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        // Note
        // Each lemonade costs only 5$
        // Each customer gets only one lemonade
        // Each customer gives either 5$, 10$ or 20$ notes
        // We need to provide change to each and every customer.
        // 5 5 5 10 20
        // First served
        // Second served
        // Third served
        // (3 5$ coins) 10 -> 5$ (2 5$, 1 10$)
        // Fourth custoemr --> (1 10$ and 1 5$) --> Served --> (1 5$, 1 20$) with us that will add up to 25$
        // Give them either 3 5$ as a change
        // Give them 1 5$ and 1 10$ as a change

        int count5 = 0;
        int count10 = 0;
        int count20 = 0;
        for(auto &ele : bills){
            if(ele == 5){ count5 += 1; }
            else if(ele == 10) {
                if(count5 >= 1){
                    count10 += 1;
                    count5  -= 1;
                } 
                else return false;
            }
            else{
                if(count5 >= 1 and count10 >= 1){
                    count5  -= 1;
                    count10 -= 1;
                    count20 += 1;
                }
                else if(count5 >= 3){
                    count5 -= 3;
                    count20 += 1;
                }
                else return false;
            }
        }
        return true;
    }
};
