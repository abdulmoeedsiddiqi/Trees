// For Height of Tree
 int height(Node* root){
    if(root == NULL) return -1 ;  // EDGE BASED HEIGHT
    if(root == NULL) return 0 ;  // Node BASED HEIGHT
    int leftHeight = height ( root -> left ) ; 
    int rightHeight = height ( root -> right ) ;

    return 1 + max(leftHeight , rightHeight) ; 
}