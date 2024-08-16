class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        
        int n = arrays.size();
        int ans = 0;
        int minIndex = 0;
        int mini = 1e9;
        int cntMini = 0;

        for(int i=0; i<n; i++)
        {
            vector<int>a = arrays[i];
            int val1 = a[0];

            if(val1 < mini)
            {
                mini = val1;
                minIndex = i;
            }
        }

        for(int i=0; i<n; i++)
        {
            vector<int>a = arrays[i];
            int val1 = a[0];

            if(val1 == mini)
            cntMini++;
        }

        if(cntMini == 1)
        {
            for(int i=0; i<n; i++)
            {
                vector<int>a = arrays[i];
                int val = a[a.size()-1];

                if(minIndex != i)
                ans = max(ans, abs(val- mini));       
            }
            
            vector<int>a =arrays[minIndex];
            int maxi = a[a.size() - 1];

            for(int i=0; i<n; i++)
            {
                vector<int>b = arrays[i];
                int val = b[0];

                if(minIndex != i)
                ans = max(ans, abs(maxi - val));
            }
        }
        else
        {
            for(int i=0; i<n; i++)
            {
                vector<int>a = arrays[i];
                int maxi = a[a.size()-1];

                ans = max(ans, abs(maxi - mini));
            }
        }
        return ans;
    }
};
