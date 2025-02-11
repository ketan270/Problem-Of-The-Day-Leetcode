class Solution {
    public String removeOccurrences(String s, String part) {
        StringBuilder result = new StringBuilder();
        int n = part.length();
        for(char ch : s.toCharArray()){
            result.append(ch);
            if(result.length()>=n && result.substring(result.length() - n).equals(part)){
                result.delete(result.length() - n,result.length());
            }
        }
        return result.toString();

    }
}
