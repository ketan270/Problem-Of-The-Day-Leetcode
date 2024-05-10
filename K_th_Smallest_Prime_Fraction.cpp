class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        vector<float> fraction;
        vector<int> ans;
        
        for(int i = 0; i < arr.size()-1; i++)
        {
            for(int j = i+1; j < arr.size(); j++)
            {
                fraction.push_back((float)arr[i]/arr[j]);
            }
        }
        
        sort(fraction.begin(), fraction.end());
        
        float d = fraction[k-1];
        
        for(int i = 0; i < arr.size()-1; i++)
        {
            for(int j = i+1; j < arr.size(); j++)
            {
                if(d == (float)arr[i]/arr[j])
                {
                    ans.push_back(arr[i]);
                    ans.push_back(arr[j]);
                    break;
                }
            }
        }
        
        return ans;
        
    }
};
