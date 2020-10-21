// 297. Serialize and Deserialize Binary Tree

class Codec {

// $ is used to represent NULL node

    int findvalue(string &data){
        // because there can be values of greater than 1 length
        // like 123, 5555, so find next , and all the elements
        // before that;
        int pos = data.find(",");

        // all the value before next ',' is to be used
        int value = stoi(data.substr(0, pos));

        // change the string, remove this value we have taken
        // and also the ',';
        data = data.substr(pos+1);
        return value;
    }


    TreeNode * Deserialise(string & data){

        if(data[0] == '$'){

            // if we are a leaf node, remove this NULL and
            // the ',' after it.
            if(data.size() > 1)
                data = data.substr(2);

            return NULL;
        }

        // create this node.
        TreeNode * node = new TreeNode(findvalue(data));
        node->left = Deserialise(data);
        node->right = Deserialise(data);
        return node;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        if(!root){
           return "$";
        }

        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return Deserialise(data);
    }
};
