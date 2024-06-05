class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        // Create an array 'alpha' to keep track of the minimum frequency of each character in all words.
        // Initialize it with a large value (10000) as a placeholder.
        vector<int> alpha(26, 10000);

        // Loop through each word in the 'words' vector.
        for (string word : words) {
            // Create a temporary array 'tempAlpha' to store the frequency of characters in the current word.
            // Initialize it with a large value (1000) as a placeholder.
            vector<int> tempAlpha(26, 1000); 

            // Count the frequency of each character in the current word.
            for (char c : word) {
                tempAlpha[c - 'a']++; 
            }

            // Update the 'alpha' array with the minimum frequency of each character seen so far.
            for (int i = 0; i < 26; i++) {
                alpha[i] = min(tempAlpha[i], alpha[i]); 
            }
        }

        // Create a vector 'res' to store the common characters found in all words.
        vector<string> res;

        // Loop through the 'alpha' array to extract the common characters and their frequencies.
        for (int i = 0; i < 26; i++) {
            // The frequency of a character is represented by the value in 'alpha' at index 'i'.
            // Since we initialized the 'alpha' array with a value of 10000, any value greater than 1000 indicates
            // that the character is present in all words. We extract this character and its frequency accordingly.
            while (alpha[i]-- > 1000) { 
                // Create a string containing the common character.
                string commonChar(1, 'a' + i); 
                // Add the common character to the 'res' vector.
                res.push_back(commonChar);
            }
        }

        // Return the vector containing common characters found in all words.
        return res;
    }
};
