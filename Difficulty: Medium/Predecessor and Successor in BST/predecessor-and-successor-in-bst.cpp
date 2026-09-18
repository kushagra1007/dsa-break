/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  public:
    Node* rightMostInLeftSubtree(Node* root){
        Node* ans;
    
        while(root != NULL) {
            ans = root;
            root = root->right;
        }
        return ans;
    }
    Node* leftMostInRightSubtree(Node* root){
        Node* ans;
    
        while(root != NULL) {
            ans = root;
            root = root->left;
        }
        return ans;
    }
    vector<Node*> findPreSuc(Node* root, int key) {
       Node* curr = root;
       Node* pred = NULL;
       Node* succ = NULL;
       
       while(curr != NULL){
           if(key < curr->data){
               succ = curr;
               curr = curr->left;
           }
           else if(key > curr->data){
               pred = curr;
               curr = curr->right;
           } else{
               if(curr->left != NULL){
                   pred = rightMostInLeftSubtree(curr->left);
               }
               if(curr->right != NULL){
                   succ = leftMostInRightSubtree(curr->right);
               }
               break;
           }
       }
       return {pred,succ};
    }
};