class Solution {
    int _shelfWidth;
    int helper(vector<vector<int>>& books, int idx, vector<int>& dpTable)
    {
        if (idx >= books.size())
        {
            return 0;
        }
        if (dpTable[idx] != -1)
        {
            return dpTable[idx];
        }
        int totalHeight = INT_MAX;
        int currentThickness = books[idx][0];
        int currentHeight =  books[idx][1];
        totalHeight = min(totalHeight, currentHeight + helper(books, idx + 1, dpTable));

        for (int i = idx + 1; i < books.size(); i++)
        {
            // I have the option to add more books if the shelfWidth allows
            if (currentThickness + books[i][0] <= _shelfWidth)
            {
                currentThickness += books[i][0];
                currentHeight = max(currentHeight,books[i][1]);
                totalHeight = min(totalHeight, currentHeight + helper(books, i + 1, dpTable));
            }
            else
            {
                totalHeight = min(totalHeight, currentHeight + helper(books, i, dpTable));
            // in order placement of book is only allowed. That's why break here
                break;
            }
        }
        dpTable[idx] = totalHeight;
        return totalHeight;
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        _shelfWidth = shelfWidth;
        vector<int> dpTable(books.size(), -1);
        return helper(books, 0, dpTable);
    }
};
