#include "bst.h"
#include <stdlib.h>

Node* traverse(Node *node,void *data,Compare compare){
                                                                                                                         if(compare(data,node->data) == 0)
                return NULL;
        if(NULL == node->left && NULL == node->right)
                return node;
        if(compare(data,node->data) < 0)
                return traverse(node->left, data, compare);
        else return traverse(node->right, data, compare);
}

BST* createBST(Compare compare){
        BST* tree = calloc(1, sizeof(BST));
        tree->root = NULL;
        tree->compare = compare;
        return tree;
}
Node* createBSTNode(void *data){
        Node *node = calloc(1,sizeof(Node));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        return node;
} 
int insertInBST(BST *tree, void *data){
        Node *node,*parentNode;
        if(NULL == tree->root){
                tree->root = createBSTNode(data);
                return 1;
        }
        parentNode = traverse(tree->root,data,tree->compare);
        if(parentNode){
                if(tree->compare(data,parentNode->data) > 0)
                parentNode->right = createBSTNode(data);
                else parentNode->left = createBSTNode(data);
        }
        else return 0;
        return 1;
}

int searchInBST(BST *tree, void *data){
        Node *parentNode,*rootNode;
        rootNode = tree->root;
        if(NULL == rootNode) return 0;
        if(NULL == traverse(rootNode, data, tree->compare))
        return 1;
        return 0;
}
int deleteFromBST(BST* tree, void *value){
        Node* node = tree->root;
        if (node->left == NULL && node->right == NULL)
                tree->root = NULL;
        return 1;
};
