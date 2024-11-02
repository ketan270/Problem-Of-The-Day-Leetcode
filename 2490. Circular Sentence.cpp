class Solution {
public:
    bool isCircularSentence(std::string sentence) 
    {
        int n = sentence.size(); // Get the size of the sentence
        
        // Check if the first and last characters of the sentence are the same
        if (sentence[0] != sentence[n - 1]) return false;

        std::istringstream iss(sentence); // Create a string stream to parse the sentence
        std::string str; // Variable to hold each word extracted from the sentence
        iss >> str; // Extract the first word
        
        // Store the last character of the first word
        char last = str[str.size() - 1];

        // Continue extracting words until the end of the sentence
        while (iss >> str) 
        {
            // Check if the last character of the previous word matches the first character of the current word
            if (last != str.front()) 
            {
                return false; // If they don't match, the sentence is not circular
            }
            // Update 'last' to be the last character of the current word for the next iteration
            last = str[str.size() - 1]; 
        }

        // Finally, check if the last character of the last word matches the first character of the sentence
        return last == sentence.front(); 
    }
};
