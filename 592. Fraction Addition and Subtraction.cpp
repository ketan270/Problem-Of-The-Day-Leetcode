class Solution {
public:
    string fractionAddition(string exp) {
        int x=0;
        string s1="";
        if(exp[0]=='-')
        x=1;
        int y=0;
        int a=0;
        if(x==0)
         a=exp[x]-'0';
        else
         a=-(exp[x]-'0');
        if(exp[x+1]>='0' && exp[x+1]<='9') //to check if a is 10 or -10  in the first numerator 
        {
          if(x==0)
          a=10;
          else
          a=-10;
          y++;
        }
        int b=exp[x+2+y]-'0';
        if(exp[x+3+y]>='0' && exp[x+3+y]<='9') ////to check if a is 10 or -10  in the first dinomerator
        {
          b=10;
          y++;
        }                         
        stack<string>st;
        string s=exp.substr(x+3+y,exp.size()); // pushing into stack like taking example -1/10+1/2; for we r pushing from +1/2
        reverse(s.begin(),s.end());
        for(int i=0;i<s.size();i++)
        {
            string str="";
            str+=s[i];
            st.push(str);
        }
        int c=0;
        int d=0;
        int i=0;
        int nume=0,dino=0; //for checking if not 10
        bool flag=false;   //to store "+" or "-"
        bool check=false; //helps in calculating d if c has already been calculated 
        while(!st.empty())
        {
         if(st.top()=="-")
           flag=true;
            
         if(st.top()>="0" && st.top()<="9" && check==false)
         {
           if(flag)
           c=-(stoi(st.top()));
           else
           c=stoi(st.top());
           if(nume==1)
           {
               if(flag)
               c=-10;
               else
               c=10;
           }
           nume++;
         }
         if(st.top()>="0" && st.top()<="9" && check==true)
         {
           d=stoi(st.top());
           if(dino==1)
           {
               d=10;
           }
           dino++;
         }
         if(st.top()=="/")
         check=true;
         st.pop();
         if((st.size()==0 || st.top()=="+" ||st.top()=="-") && check)
         {
             cout<<a<<"/"<<b<<endl;
             cout<<c<<"/"<<d<<endl;
             a=a*d+c*b;
             b=b*d;
             int gcd=__gcd(abs(a),b);
             a=a/gcd;
             b=b/gcd;
             i=0;
             flag=false;
             check=false;
             c=0;
             d=0;
             nume=0;
             dino=0;
         }
         
         
        }
        return to_string(a)+"/"+to_string(b);
    }
};
