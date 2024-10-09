class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();

        int ans = 0;
        int count  = 0;

        if(n == 0)
        {
            return 0;
        }

        for(int i=0; i<n; i++)
        {
            if(s[i] == '(')
            {
                ans++;
            }
            else if(s[i] == ')')
            {
                ans--;
            }

            if(ans < 0)
            {
                count++;
                ans = 0;

            }
        }

        return count + ans;
    }
};
