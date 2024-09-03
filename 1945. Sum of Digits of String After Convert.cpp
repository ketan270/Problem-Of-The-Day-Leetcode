class Solution {
public:
    int getLucky(string s, int k) {
        int res = 0;
        string temp = "";
        for(int i =0 ; i < s.size() ; i++)
        {
            temp+=to_string(s[i]-'a'+1);
        }
        while(k)
        {  int ans = 0;
            for(int i = 0 ; i < temp.size();i++)
            {
                ans+=(temp[i]-'0');
            
            }
            temp = to_string(ans);
            res = ans;
            k--;
        }
        return res;
    }
};
