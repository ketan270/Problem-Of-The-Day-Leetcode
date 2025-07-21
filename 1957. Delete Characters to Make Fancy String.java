class Solution {
    public String makeFancyString(String s) {
        StringBuilder result = new StringBuilder();
        for(int i=0;i<s.length();i++){
            
                if(i + 2 < s.length() && s.charAt(i) == s.charAt(i+1) && s.charAt(i+1) == s.charAt(i+2)){
                    continue;
                }
                else {
                    result.append(s.charAt(i));
                }
        }
        return result.toString();
    }
}
