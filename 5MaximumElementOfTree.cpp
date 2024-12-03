int maxElementOfTree(Node* root){
    if( root == NULL) return INT_MIN;
    int leftMax = maxElementOfTree ( root -> left ) ; 
    int rightMax = maxElementOfTree ( root -> right ) ; 
    return max( root -> data , max ( leftMax , rightMax ) ) ; 
}