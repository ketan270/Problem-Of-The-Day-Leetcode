struct Node {
	Node *links[10];
	bool flag = false;

	bool containKey(int dig) {
		return (links[dig] != NULL);
	}

	void put(int dig, Node *node) {
		links[dig] = node;
	}

	Node *get(int dig) {
		return links[dig];
	}

	void setEnd() {
		flag = true;
	}

	bool isEnd() {
		return flag;
	}
};

class Trie {
private:
	Node* root;
public:
	Trie() {

		root = new Node();
	}

	void insert(int num) {

		Node *node = root;
        vector<int> arr;
        
        while(num!=0)
        {
            int curr = num%10;
            arr.push_back(curr);
            num = num/10;
        }
        
        reverse(arr.begin(), arr.end());
        
		for(int i=0; i<arr.size(); ++i)
        {          
            int dig = arr[i];
			if (!node->containKey(dig))
				node->put(dig, new Node());

			node = node->get(dig);
		}
        
		node->setEnd();
	}
    

	int check(int num) 
    {
        
		Node* node = root;

        vector<int> arr;
        
        while(num!=0)
        {
            int curr = num%10;
            arr.push_back(curr);
            num = num/10;
        }
        
        reverse(arr.begin(), arr.end());
        int res = 0;
            
		for (int i = 0; i < arr.size(); i++) 
        {
            int dig = arr[i];
            
			if (!node->containKey(dig)) 
				return res;

            ++res;
			node = node->get(dig);
		}
        
		return res;
    }
};


class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        Trie* tr = new Trie;
        
        for(int i=0; i<arr1.size(); ++i)
            tr->insert(arr1[i]);
        
        int res = -1;
        
        for(int i=0; i<arr2.size(); ++i)
        {
            int len = tr->check(arr2[i]);
            res = max(res, len);
        }
        
        return res;
        
    }
};
