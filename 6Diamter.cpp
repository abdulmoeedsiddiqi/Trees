// Given a binary tree, the diameter (also known as the width) is defined
// as the number of edges on the longest path between two leaf nodes in the tree.
//  This path may or may not pass through the root. 
// Your task is to find the diameter of the tree.


int   diameter( Node* root){
    if( root == NULL) return 0 ;

    int opt1 = diameter(root -> left ) ; 
    int opt2 = diameter( root -> right ) ; 
    int opt3 = height(root -> left ) + 1 + height(root -> right ) ; 

    return max ( opt3 , max( opt1 , opt 2)) ;

}