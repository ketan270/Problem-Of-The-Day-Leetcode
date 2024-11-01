class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        if (n < 3) return s;  // If the string has fewer than 3 characters, it's already fancy.

        string result = s.substr(0, 2);  // Initialize the result string with the first two characters.
        
        // Traverse the string starting from the third character.
        for (int i = 2; i < n; ++i) {
            // Check if the current character does not form three consecutive identical characters.
            if (s[i] != s[i - 1] || s[i] != s[i - 2]) {
                result += s[i];  // Append the current character to the result.
            }
        }
        
        return result;
    }
};
