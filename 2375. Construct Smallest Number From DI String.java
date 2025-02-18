class Solution {
    public String smallestNumber(String pattern) {
        Stack<Integer> st = new Stack<>();
        String result = "";
        for(int i=0;i<=pattern.length();i++){
            st.push(i+1);
    
                if(i== pattern.length() || pattern.charAt(i)== 'I'){
                    while(!st.isEmpty()){
                    result += st.pop();
                }
            }
        }
        return result;
    }

}
