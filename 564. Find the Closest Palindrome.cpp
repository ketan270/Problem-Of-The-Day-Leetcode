
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <climits>

class Solution {
public:
    string nearestPalindromic(string s) {
        int len = s.length();
        if (s == "1") return "0";

        vector<string> candidates;

        string firstHalf = s.substr(0, (len + 1) / 2);
        string candidate = createPalindrome(firstHalf, len % 2 == 0);
        candidates.push_back(candidate);

        string decrementedFirstHalf = to_string(stoll(firstHalf) - 1);
        if (!decrementedFirstHalf.empty()) {
            candidate = createPalindrome(decrementedFirstHalf, len % 2 == 0);
            candidates.push_back(candidate);
        }

        string incrementedFirstHalf = to_string(stoll(firstHalf) + 1);
        if (!incrementedFirstHalf.empty()) {
            candidate = createPalindrome(incrementedFirstHalf, len % 2 == 0);
            candidates.push_back(candidate);
        }

        candidates.push_back("1" + string(len - 1, '0') + "1");
        candidates.push_back(string(len - 1, '9'));

        string closest = "";
        long long minDiff = LLONG_MAX;
        long long originalNumber = stoll(s);

        for (const string& candidate : candidates) {
            if (candidate == s) continue; 
            try {
                long long candidateNumber = stoll(candidate);
                long long diff = abs(candidateNumber - originalNumber);
                if (diff < minDiff || (diff == minDiff && candidateNumber < stoll(closest))) {
                    minDiff = diff;
                    closest = candidate;
                }
            } catch (const invalid_argument&) {
                continue;
            } catch (const out_of_range&) {

                continue;
            }
        }

        return closest;
    }

private:
    string createPalindrome(string half, bool evenLength) {
        string palindrome = half;
        if (!evenLength) half.pop_back();  
        reverse(half.begin(), half.end());
        palindrome += half;
        return palindrome;
    }
};
