class Solution {
    public String compressedString(String word) {
        StringBuilder comp = new StringBuilder();
        int n = word.length();
        int i = 0;
        
        while (i < n) {
            char currentChar = word.charAt(i);
            int count = 0;
            
            // Count the consecutive characters
            while (i < n && word.charAt(i) == currentChar && count < 9) {
                count++;
                i++;
            }
            
            // Append the count and the character to the result
            comp.append(count).append(currentChar);
            
            // Continue to count characters if we exceeded the count of 9
            while (i < n && word.charAt(i) == currentChar) {
                count = 0;
                while (i < n && word.charAt(i) == currentChar && count < 9) {
                    count++;
                    i++;
                }
                comp.append(count).append(currentChar);
            }
        }
        
        return comp.toString();
    }
}
