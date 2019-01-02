//
// Operations on Binary Tree
//

#ifndef LAB9_BTREEEXERCISES_H
#define LAB9_BTREEEXERCISES_H

#include <iostream>
#include <queue>
#include "BtreeNode.h"

template<class T>
int treeHeight(BtreeNode<T> *root){
	if(root->get_left() == NULL && root->get_right() == NULL)
		return 0;
	else{
		if(root->get_left() != NULL && root->get_right() == NULL)
			return treeHeight(root->get_left()) + 1;
		else if(root->get_right() != NULL && root->get_left() == NULL)
			return treeHeight(root->get_right()) + 1;
		else if(root->get_left() != NULL && root->get_right() != NULL){
			return std::max(treeHeight(root->get_left()), treeHeight(root->get_right())) + 1;
		}
	}
}

template<class T>
int countNodes(BtreeNode<T> *root){
	if(root->get_left() == NULL && root->get_right() == NULL){
		return 1;
	}
	else{
		if(root->get_left() != NULL && root->get_right() == NULL){
			return countNodes(root->get_left()) + 1;
		}
		else if(root->get_right() != NULL && root->get_left() == NULL){
			return countNodes(root->get_right()) + 1;
		}
		else if(root->get_right() != NULL && root->get_left() != NULL){
			return countNodes(root->get_left()) + countNodes(root->get_right()) + 1;
		}
	}
}

template<class T>
BtreeNode<T> *mirror(BtreeNode<T> *root){
	if(root == NULL){
		return NULL;
	}
	return new BtreeNode<T>(root->get_data(), mirror(root->get_right()), mirror(root->get_left()));
}

template<class T>
bool isComplete(BtreeNode<T> *root){
	if((root->get_left() != NULL && root->get_right() != NULL) || root->get_left() != NULL)
		return true;
	return (isComplete(root->get_left()) && isComplete(root->get_right()));
}

#endif //LAB9_BTREEEXERCISES_H
