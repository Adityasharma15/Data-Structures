// 449. Serialize and Deserialize BST

class Codec {

    int findNodeValue(string &data, int & pos){
        pos = data.find(",");
        int value = stoi(data.substr(0,pos));
        return value;
    }


    int i = 0;
    TreeNode * constructTree(string &data, int bound){

        int pos = 0;

        if(data.size() == 0)
            return NULL;

        int value = findNodeValue(data, pos);
        if(value>bound) return NULL;

        // UPDATE ONLY WHEN IN RANGE

        data = data.substr(pos+1);
        TreeNode * node = new TreeNode(value);
        node->left = constructTree(data, value);
        node ->right = constructTree(data, bound);
        return node;
    }


public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        // saving preorder traversal
        if(!root)
            return "";

        string ser = to_string(root->val) + ",";
        ser += serialize(root->left);
        ser += serialize(root->right);
        return ser;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        // left with bst from preorder but from a string with
        // , separated node values
        return constructTree(data, INT_MAX);
    }
};
