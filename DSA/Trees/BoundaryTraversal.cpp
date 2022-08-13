void leftBoundary(Node* root,vector<int>&res){
    if(!root) return;
    if(root->left){
        res.push_back(root->data);
        leftBoundary(root->left,res);
    }
    else if(root->right){
        res.push_back(root->data);
        leftBoundary(root->right,res);
    }
}

void bottomBoundary(Node* root,vector<int>&res){
     if(!root) return;
     bottomBoundary(root->left,res);
     if(!root->left && !root->right) res.push_back(root->data);
     bottomBoundary(root->right,res);
}

void rightBoundary(Node* root,vector<int>&res){
    if(!root) return;
    if(root->right){
        rightBoundary(root->right,res);
        res.push_back(root->data);
    }
    else if(root->left){
        rightBoundary(root->left,res);
        res.push_back(root->data);
    }        
}

vector <int> printBoundary(Node *root){
    vector<int>res;
    if(!root) return res;
    res.push_back(root->data);
    leftBoundary(root->left,res);
    bottomBoundary(root,res);
    rightBoundary(root->right,res);
    return res;
}