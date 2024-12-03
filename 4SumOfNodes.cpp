int sumOfNode(Node* root){
    if(root == NULL ) return 0 ;

    return root -> data + sumOfNode( root -> left) + sumOfNode ( root -> right ) ;
}