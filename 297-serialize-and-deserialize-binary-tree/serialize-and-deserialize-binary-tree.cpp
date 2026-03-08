/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    
    string serialize(TreeNode* root) {
        string result;
        serializeHelper(root, result);
        return result;
    }

   
    TreeNode* deserialize(string data) {
        vector<string> nodes = split(data, ',');
        int index = 0;
        return deserializeHelper(nodes, index);
    }

private:
    
    void serializeHelper(TreeNode* node, string& result) {
        if (!node) {
            result += "null,";
            return;
        }
        result += to_string(node->val) + ",";
        serializeHelper(node->left, result);
        serializeHelper(node->right, result);
    }

    // Helper for deserialization
    TreeNode* deserializeHelper(vector<string>& nodes, int& index) {
        if (index >= nodes.size() || nodes[index] == "null") {
            index++;
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(nodes[index++]));
        node->left = deserializeHelper(nodes, index);
        node->right = deserializeHelper(nodes, index);
        return node;
    }

    // Split function
    vector<string> split(const string& s, char delim) {
        vector<string> tokens;
        string token;
        stringstream ss(s);
        while (getline(ss, token, delim)) {
            tokens.push_back(token);
        }
        return tokens;
    }
};
