class Solution {
public:
    int maximumSwap(int num) {
        string str=to_string(num);
        unordered_map<char,int>mp;
        int n=str.size();
        for(int i=0;i<n;i++)
        {
            mp[str[i]]=i;
        }
        string str2=str;
        int i=0,j=0;
        sort(str2.begin(),str2.end(),greater<int>());
        while(i<n && j<n && str[i]==str2[j])
        {
            i++,j++;
        }
        if(i==n && j==n)
        return num;

        while(j<n && str2[j+1]==str2[j])
        {
            j++;
        }
        char t=str[i];
        str[i]=str2[j];
        str[mp[str2[j]]]=t;
        return stoi(str);
    }
};
