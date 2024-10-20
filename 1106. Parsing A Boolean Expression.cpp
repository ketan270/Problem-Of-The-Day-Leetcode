class Solution {
public:
    bool parseBoolExpr(string s) {
        stack<char>st;
        for(auto i : s){
            if(i == ')' ){
                if(!st.empty()){
                    int t = 0;
                    int f = 0;
                    while(!st.empty() && st.top() != '('){
                        char c = st.top();
                        st.pop();
                        if(c == 't')
                        t++;
                        else if(c == 'f')
                        f++;
                    }
                    st.pop();
                    char operation = st.top();
                    if(operation == '&'){
                        if(f)
                        st.push('f');
                        else
                        st.push('t');
                    }else if(operation == '|'){
                        if(t)
                        st.push('t');
                        else
                        st.push('f');
                    }else{
                        if(f)
                        st.push('t');
                        else
                        st.push('f');
                    }
                }
            }else
                st.push(i);
        }
        return (st.top() == 't') ? true : false;
    }
};
