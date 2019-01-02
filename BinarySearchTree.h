// Binary Search Tree Class
//

#ifndef LAB9_BINARYSEARCHTREE_H
#define LAB9_BINARYSEARCHTREE_H

#include <iostream>
#include <iomanip>

template<typename T1, typename T2>
class BinarySearchTree {
private:
    class BinaryNode;

public:
    BinarySearchTree() : root(NULL) {

    }

    // (Deep) Copy constructor
    BinarySearchTree(const BinarySearchTree &src) : root(src.clone(src.root)) {}

    ~BinarySearchTree() {
        makeEmpty();
    };

    bool isEmpty() const {
        return !root;
    }

    bool contains(const T1 &x, const T2 &y) const {
        return contains(x, y, root);
    }

    void printMin() const;

    void printTree() const {
        printTree(root, 0);
    };

    void makeEmpty() {
        makeEmpty(root);
    }

    void insert(const T1 &x, const T2 &y) {
        insert(x, y, root);
    }

private:
    class BinaryNode {
    public:
        T1 x;
        T2 y;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode() :
                left(NULL), right(NULL) {}

        BinaryNode(const T1 &x, const T2 &y, BinaryNode *lt = NULL, BinaryNode *rt = NULL)
                : x(x), y(y), left(lt), right(rt) {}

    };

    BinaryNode *root;

    void insert(const T1 &x, const T2 &y, BinaryNode *&t);

    bool contains(const T1 &x, const T2 &y, BinaryNode *t) const;

    void makeEmpty(BinaryNode *t);

    void printTree(BinaryNode *t, int depth) const;

    BinaryNode *clone(BinaryNode *t) const {
        return !t ? NULL :
               new BinaryNode(t->x, t->y, clone(t->left), clone(t->right));
    };
};

// Print the BST out, the output is rotated -90 degrees.
template<typename T1, typename T2>
void BinarySearchTree<T1, T2>::printTree(typename BinarySearchTree<T1, T2>::BinaryNode *t, int depth) const {
    if (t == NULL)
        return;
    const int offset = 6;
    printTree(t->right, depth + 1);
    std::cout << std::setw(depth * offset);
    std::cout << "(" << t->x << "," << t->y << ")" << std::endl;
    printTree(t->left, depth + 1);
}

template<typename T1, typename T2>
void BinarySearchTree<T1, T2>::insert(const T1 &x, const T2 &y, BinarySearchTree<T1, T2>::BinaryNode *&t){
	BinaryNode* temp = new BinaryNode(x, y, NULL, NULL);
	if(t == NULL){
		t = temp;
		return;
	}
	if(x < t->x){
		insert(x, y, t->left);
	}
	else if(x > t->x){
		insert(x, y, t->right);
	}
	else if(y < t->y){
		insert(x, y, t->left);
	}
	else if(y > t->y ){
		insert(x, y, t->right);
	}
	else{
		return;
	}
}

//  Check if the BST contains the value (x,y).
template<typename T1, typename T2>
bool BinarySearchTree<T1, T2>::contains(const T1 &x, const T2 &y, BinarySearchTree<T1, T2>::BinaryNode *t) const{
	if(t == NULL)
		return false;
	if(x < t->x){
		contains(x, y, t->left);
	}
	else if(x > t->x){
		contains(x, y, t->right);
	}
	else if(y < t->y){
		contains(x, y, t->left);
	}
	else if(y > t->y){
		contains(x, y, t->right);
	}
	else{
		return true;
	}
}


// Make Empty
template<typename T1, typename T2>
void BinarySearchTree<T1, T2>::makeEmpty(BinarySearchTree<T1, T2>::BinaryNode *t){
	if(t->left == NULL && t->right == NULL){
		delete t;
		return;
	}
	delete (t->left);
	delete (t->right);
}

// Print minimum key
// If the tree is empty, you should print "Empty tree"
template<typename T1, typename T2>
void BinarySearchTree<T1, T2>::printMin() const{
	if(isEmpty()){
		std::cout << "Empty Tree." << std::endl;
		return;
	}
	BinarySearchTree bTree;
	bTree.root = root;
	if(bTree.root->left == NULL && bTree.root->right == NULL){
		std::cout << "The minimum key is (" << bTree.root->x << "," << bTree.root->y << ")" << std::endl;
		return;
	}
	if(bTree.root->left == NULL && bTree.root->right != NULL){
		bTree.root = bTree.root->right;
		bTree.printMin();

	}
	else if((bTree.root->left != NULL && bTree.root->right == NULL) || (bTree.root->left != NULL && bTree.root->right != NULL)){
		bTree.root = bTree.root->left;
		bTree.printMin();

	}
}

#endif //LAB9_BINARYSEARCHTREE_H
