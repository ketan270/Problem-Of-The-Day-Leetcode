class Solution {
public:
    string reversePrefix(string v, char ch) {
        if(find(v.begin(), v.end(), ch)!=v.end())
        {
            int it = find(v.begin(), v.end(), ch)-v.begin();
            it++;
            reverse(v.begin(),v.begin()+it);
            return v;
        }
        
        return v;
    }
};
