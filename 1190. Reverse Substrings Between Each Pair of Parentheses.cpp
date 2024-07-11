class Solution {
public:
    // TC: O(N^2)
    // SC: O(N)
    // string reverseParentheses(string s) {
    //     stack<int> st;
    //     string res = ""; // The final ans

    //     // Consider the following example
    //     // (ll(abcd)) and res = "" initially
    //     // First we encounter '('. Now the open bracket means that all the letters (till another closing bracket) that are added to 'res' after encountering this bracket must be reversed
    //     // We push the length of 'res' into a stack.
    //     // The stack now contains 0
    //     // res = ll
    //     // We encounter another '('. Now all letters encountered after this must be reversed
    //     // Or all the letters added to 'res' after 'll' should be reversed
    //     // Thus 'll' should be skipped (or not reveresed)
    //     // We push the length of 'res' into stack which gives us how many letters in 'res' to skip
    //     // res = llabcd
    //     // We then encounter ')'
    //     // Stack contains : [0, 2 ..
    //     // Now we reverse 'res' skipping first two letters 'll'
    //     // res = lldcba
    //     // Stack : [0 ..
    //     // We encounter another ')'
    //     // We reverse 'res' skipping '0' letters
    //     // Thus, res = abcdll --> Answer
    //     for(auto ch: s)
    //     {
    //         if(ch == '(')
    //             st.push(res.size());
    //         else if(ch == ')')
    //         {
    //             int j = st.top();
    //             st.pop();
    //             reverse(res.begin() + j, res.end());
    //         }
    //         else // We add anything other than the bracket to the 'res' string
    //             res += ch;
    //     }
    //     return res;
    // }

    // Consider the following string: (u(love)i)
    // Now first we store index of open brackets and corresponding closed brackets and vice versa
    // Whenever we encounter any bracket, we move to its corresponding open (or close) bracket and reverse the direction of moving
    // For example, we encounter the bracket at index = 0
    // We move to its close bracket at some index = i
    // Now we move from right to left and continue adding letters to 'res' string
    // res = i
    // We now encounter ')'
    // Go to its corresponding bracket and reverse the direction
    // We now move from left to right and continue adding letters to 'res' string
    // Thus, res = ilove
    // We encounter another ')'. Do this until iterator 'i' gets out of bounds

    // TC: O(N)
    // SC: O(N)

    string reverseParentheses(string s)
    {
        stack<int> openBrackets;
        vector<int> mpp(s.size()); // {index of open bracket, corresponding close bracket} and {close bracket, open bracket}

        // Storing the indexes
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '(')
                openBrackets.push(i);
            else if(s[i] == ')')
            {
                int j = openBrackets.top();
                openBrackets.pop();

                mpp[i] = j; // {open bracket, close bracket}
                mpp[j] = i; // {close bracket, open bracket}
            }
        }

        // Flag denotes the direction of moving
        // 1 --> move from left to right
        // -1 --> move from right to left
        int flag = 1;
        string res = "";
        for(int i=0; i<s.size(); i += flag)
        {
            if(s[i] == '(' || s[i] == ')')
            {
                i = mpp[i];
                flag = -flag;
            }
            else
                res += s[i];
        }

        return res;
    }
};
