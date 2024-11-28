// #include <iostream>
// #include <queue>
// using namespace std;
// class Node
// {
// public:
//     int data;
//     Node *left;
//     Node *right;
//     Node(int data)
//     {                      //        (root)
//         this->data = data; //         /    \ 
//         this ->left = NULL;                 //        NULL   NULL
//         this->right = NULL;
//     }
// };
// Node *buildTree(Node *root)
// {
//     cout << "Enter data:" << endl;
//     int data; // making an integer
//     cin >> data;
//     root = new Node(data); // dynamically creating a Node type and passing a value of data integer nad assigning value to root
//     if (data == -1)
//     {
//         return NULL;
//     }
//     cout << "For Left Node of " << data << endl;
//     root->left = buildTree(root->left);

//     cout << "For right Node of " << data << endl;
//     root->right = buildTree(root->right);

//     return root;
// }
// void preOrder(Node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     cout << root->data << "  ";
//     preOrder(root->left);
//     preOrder(root->right);
// }
// void postOrder(Node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     postOrder(root->left);
//     postOrder(root->right);
//     cout << root->data << "  ";
// }
// void inOrder(Node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     inOrder(root->left);
//     cout << root->data << "  ";
//     inOrder(root->right);
// }
// void levelOrderTraversal(Node *root)
// {
//     if (root == NULL)
//     {
//         cout << "Tree is empty." << endl;
//         return;
//     }
//     queue<Node *> q;
//     q.push(root);
//     q.push(NULL);
//     while (!q.empty())
//     {
//         Node *temp = q.front();
//         q.pop();
//         if (temp == NULL)
//         {
//             cout << endl;
//             if (!q.empty())
//             {
//                 q.push(NULL);
//             }
//         }
//         else
//         {
//             cout << temp->data << " ";
//             if (temp->left)
//             {
//                 q.push(temp->left);
//             }
//             if (temp->right)
//             {
//                 q.push(temp->right);
//             }
//         }
//     }
// }
// void buildFromLevelOrderTraversal(Node *&root)
// {
//     queue<Node *> q;
//     cout << "Enter data for root: ";
//     int data;
//     cin >> data;
//     root = new Node(data);
//     q.push(root);
//     while (!q.empty())
//     {
//         Node *temp = q.front();
//         q.pop();

//         cout << "Enter data for left of " << temp->data << ": ";
//         int leftData;
//         cin >> leftData;
//         if (leftData != -1)
//         {
//             temp->left = new Node(leftData);
//             q.push(temp->left);
//         }

//         cout << "Enter data for right of " << temp->data << ": ";
//         int rightData;
//         cin >> rightData;
//         if (rightData != -1)
//         {
//             temp->right = new Node(rightData);
//             q.push(temp->right);
//         }
//     }
// }
// int main()
// {
//     Node *root = NULL; // Creating a pointer of data type Node and assigning it to NULL
//     buildFromLevelOrderTraversal(root);
//     levelOrderTraversal(root);
//     // root = buildTree(root); // Calling the function buildTree and passing value of root

//     return 0;
// }

#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root) {
    cout << "Enter data (-1 for no node):" << endl;
    int data;
    cin >> data;
    if (data == -1) {
        return NULL;
    }
    root = new Node(data);
    cout << "For Left Node of " << data << endl;
    root->left = buildTree(root->left);

    cout << "For Right Node of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void preOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << "  ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << "  ";
}

void inOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    cout << root->data << "  ";
    inOrder(root->right);
}

void levelOrderTraversal(Node *root) {
    if (root == NULL) {
        cout << "Tree is empty." << endl;
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

void buildFromLevelOrderTraversal(Node *&root) {
    queue<Node *> q;
    cout << "Enter data for root: ";
    int data;
    cin >> data;
    if (data == -1) {
        cout << "Invalid input for root." << endl;
        return;
    }
    root = new Node(data);
    q.push(root);
    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();

        cout << "Enter data for left of " << temp->data << ": ";
        int leftData;
        cin >> leftData;
        if (leftData != -1) {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout << "Enter data for right of " << temp->data << ": ";
        int rightData;
        cin >> rightData;
        if (rightData != -1) {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

void deleteTree(Node *root) {
    if (root == NULL) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Node *root = NULL;
    buildFromLevelOrderTraversal(root);
    levelOrderTraversal(root);

    cout << "Choose a traversal method: " << endl;
    cout << "1. Pre-order" << endl;
    cout << "2. In-order" << endl;
    cout << "3. Post-order" << endl;
    cout << "4. Level-order" << endl;
    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Pre-order traversal: ";
            preOrder(root);
            cout << endl;
            break;
        case 2:
            cout << "In-order traversal: ";
            inOrder(root);
            cout << endl;
            break;
        case 3:
            cout << "Post-order traversal: ";
            postOrder(root);
            cout << endl;
            break;
        case 4:
            cout << "Level-order traversal: ";
            levelOrderTraversal(root);
            cout << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
    return 0 ;
}
    // Clean up the