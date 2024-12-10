class Solution {
public:
    int maximumLength(string s) {
        vector<int> charCount(26, 0);
        int left = 0, right = 0, uniqueChar = 0, maxLen = -1;

        while (right < s.size()) {
            // Add the current character to the window
            if (++charCount[s[right] - 'a'] == 1) {
                uniqueChar++;
            }
            right++;

            // Shrink the window if there are multiple unique characters
            while (uniqueChar > 1) {
                if (--charCount[s[left] - 'a'] == 0) {
                    uniqueChar--;
                }
                left++;
            }

            // Check if the current window forms a larger substring
            if (right - left > maxLen) {
                int substrCount = 0;
                int findPos = left;
                string target = s.substr(findPos, right - left);

                // Count occurrences of the substring in the string
                while ((findPos = s.find(target, findPos)) != string::npos) {
                    if (++substrCount >= 3) {
                        maxLen = right - left;
                        break;
                    }
                    findPos++;
                }
            }
        }
        return maxLen;
    }
};
