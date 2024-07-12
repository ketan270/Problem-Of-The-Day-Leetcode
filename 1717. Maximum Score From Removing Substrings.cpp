class Solution {
public:

   int flag=0;
    void Remove_ba(string str,int &count,int y,int x)
    {
        flag++;
        stack<char>st;
        st.push(str[0]);
        for(int i=1;i<str.size();i++)
        {
           if(str[i]=='a' && !st.empty() && st.top()=='b')
             {
                count+=y;
                st.pop();
             }
             else
             {
                st.push(str[i]);
             }
        }
        string str1="";
        while(!st.empty())
        {
            str1.push_back(st.top());
            st.pop();
        }
        reverse(str1.begin(),str1.end());
        if(flag<3)
        Remove_ab(str1,count,y,x);
    }

    void Remove_ab(string str,int &count,int y,int x)
    {
        flag++;
        stack<char>st;
        st.push(str[0]);
        for(int i=1;i<str.size();i++)
        {
            if(str[i]=='b' && !st.empty() && st.top()=='a')
            {
                count+=x;
                st.pop();
            }
            else
            {
                st.push(str[i]);
            }
        }
        string str1="";
        while(!st.empty())
        {
            str1.push_back(st.top());
            st.pop();
        }
        reverse(str1.begin(),str1.end());
        if(flag<3)
        Remove_ba(str1,count,y,x);
    }

    int maximumGain(string s, int x, int y) 
    {
        int count=0;
      if(y>x)
      {
        Remove_ba(s,count,y,x);
      }    
      else
      {
        Remove_ab(s,count,y,x);
      }
      return count;
    }
};
