#include <unordered_map>
#include <string>
#include <map>
#include <set>

using namespace std;

class AllOne {
public:
    AllOne() {}

    void inc(const string& key) {
        // Increment the count of the key
        int count = ++countMap[key];

        // Add the key to the corresponding count set
        countKeys[count].insert(key);

        // If this is not the first occurrence, remove it from the old count set
        if (count > 1) {
            countKeys[count - 1].erase(key);
            if (countKeys[count - 1].empty()) {
                countKeys.erase(count - 1);
            }
        }
    }

    void dec(const string& key) {
        // Decrement the count of the key
        int count = countMap[key];

        // Remove the key from the current count set
        countKeys[count].erase(key);
        if (countKeys[count].empty()) {
            countKeys.erase(count);
        }

        // If the count is greater than 1, we need to update
        if (count > 1) {
            countMap[key]--;
            countKeys[count - 1].insert(key);
        } else {
            countMap.erase(key); // Remove the key completely if count becomes 0
        }
    }

    string getMaxKey() {
        if (countKeys.empty()) return "";
        return *countKeys.rbegin()->second.begin(); // Return any key with max count
    }

    string getMinKey() {
        if (countKeys.empty()) return "";
        return *countKeys.begin()->second.begin(); // Return any key with min count
    }

private:
    unordered_map<string, int> countMap; // Maps keys to their counts
    map<int, set<string>> countKeys; // Maps counts to a set of keys (ordered)
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
