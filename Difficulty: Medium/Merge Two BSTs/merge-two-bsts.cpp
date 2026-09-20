/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  public:
    void inorder(Node* root,vector<int> &arr){
        if(root == NULL){
            return;
        }
        inorder(root->left,arr);
        arr.push_back(root->data);
        inorder(root->right,arr);
    }
    vector<int> merge(Node *r1, Node *r2) {
        // code here
        vector<int> arr1,arr2;
        inorder(r1,arr1);
        inorder(r2,arr2);
        
        vector<int> temp;
        int i = 0, j = 0;
        while(i<arr1.size() && j < arr2.size()){
            if(arr1[i]<arr2[j]){
                temp.push_back(arr1[i++]);
            } else{
                temp.push_back(arr2[j++]);
            }
        }
        while(i<arr1.size()){
            temp.push_back(arr1[i++]);
        }
        while(j<arr2.size()){
            temp.push_back(arr2[j++]);
        }
        return temp;
    }
};