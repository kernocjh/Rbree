#include <iostream>
#include <cstdio>
#include <cstdlib> 
using namespace std;

typedef char ElemType;

enum Color { red, black };
typedef struct RBtreeNode{
	ElemType data;
	int key;
	RBtreeNode *left;
	RBtreeNode *right;
	RBtreeNode *parent;
	Color color;
	RBtreeNode(int _key) : key(_key), left(NULL), right(NULL), parent(NULL), color(red){
	}
}RBtreeNode;

typedef struct rbtree{
	RBtreeNode *root;
	RBtreeNode *NIL;
}RBtree;

RBtreeNode *NIL;

void initNILnode(RBtreeNode *&node){
	node = new RBtreeNode(0);
	NIL->left = NIL;
	NIL->right = NIL;
	NIL->parent = NIL;
	NIL->color = black;
}

void initRBtreeNode(RBtreeNode *node);

void leftRotate(RBtree *T, RBtreeNode *x);
void rightRotate(RBtree *T, RBtreeNode *y);
void rbtreeInsert(RBtree *T, RBtreeNode *node);
void rbtreeInsertFixup(RBtree *T, RBtreeNode *node);

void rbtreeTransplant(RBtree *T, RBtreeNode *u, RBtreeNode *v);
RBtreeNode* treeMinimum(RBtreeNode *node);
void rbtreeDelete(RBtree *T, RBtreeNode *node);
void rbtreeDeleteFixup(RBtree *T, RBtreeNode *node);

void travelor(RBtreeNode *root, int counter){
	if (root == NIL){
		cout << "(" << counter << ")";
		return;
	}
	if (root->color == black)
		++counter;
	printf("%d ", root->key);
	travelor(root->left, counter);
	travelor(root->right, counter);
}
int main(){

	initNILnode(NIL);
	RBtree root;

	root.NIL = NIL;
	root.root = NIL;
	RBtreeNode rb1(7), rb2(14), rb3(1), rb4(6),
		rb5(5), rb6(27), rb7(18), rb8(10), rb9(9), rb10(15),rb(7);

	initRBtreeNode(&rb1);
	initRBtreeNode(&rb);
	initRBtreeNode(&rb2);
	initRBtreeNode(&rb3);
	initRBtreeNode(&rb4);
	initRBtreeNode(&rb5);
	initRBtreeNode(&rb6);
	initRBtreeNode(&rb7);
	initRBtreeNode(&rb8);
	initRBtreeNode(&rb9);
	initRBtreeNode(&rb10);

	rbtreeInsert(&root, &rb1);
	rbtreeInsert(&root, &rb5);
	rbtreeInsert(&root, &rb4);
	rbtreeInsert(&root, &rb3);
	rbtreeInsert(&root, &rb2);

	rbtreeInsert(&root, &rb6);
	rbtreeInsert(&root, &rb7);
	rbtreeInsert(&root, &rb8);
	rbtreeInsert(&root, &rb9);
	rbtreeInsert(&root, &rb10);
	travelor(root.root, 0);
	cout << endl;
	rbtreeDelete(&root, &rb1);
	rbtreeDelete(&root, &rb5);
	rbtreeDelete(&root, &rb4);
	rbtreeDelete(&root, &rb3);
	rbtreeDelete(&root, &rb2);

	rbtreeDelete(&root, &rb6);
	rbtreeDelete(&root, &rb7);
	rbtreeDelete(&root, &rb8);
	rbtreeDelete(&root, &rb9);
	rbtreeDelete(&root, &rb10);
	travelor(root.root, 0);
	cout << endl;
	rbtreeInsert(&root, &rb1);
	rbtreeInsert(&root, &rb5);
	rbtreeInsert(&root, &rb4);
	rbtreeInsert(&root, &rb3);
	rbtreeInsert(&root, &rb2);

	rbtreeInsert(&root, &rb6);
	rbtreeInsert(&root, &rb7);
	rbtreeInsert(&root, &rb8);
	rbtreeInsert(&root, &rb9);
	rbtreeInsert(&root, &rb10);
	travelor(root.root, 0);
	cout << endl;
	rbtreeDelete(&root, &rb1);
	rbtreeDelete(&root, &rb5);
	rbtreeDelete(&root, &rb4);
	rbtreeDelete(&root, &rb3);
	rbtreeDelete(&root, &rb2);

	rbtreeDelete(&root, &rb6);
	rbtreeDelete(&root, &rb7);
	rbtreeDelete(&root, &rb8);
	rbtreeDelete(&root, &rb9);
	rbtreeDelete(&root, &rb10);
	travelor(root.root, 0);
	cout << endl;
	rbtreeInsert(&root, &rb1);
	rbtreeInsert(&root, &rb);
	/*rbtreeInsert(&root, &rb5);
	rbtreeInsert(&root, &rb5);*/
	/*
	rbtreeInsert(&root, &rb4);
	rbtreeInsert(&root, &rb3);
	rbtreeInsert(&root, &rb2);

	rbtreeInsert(&root, &rb6);
	rbtreeInsert(&root, &rb7);
	rbtreeInsert(&root, &rb8);
	rbtreeInsert(&root, &rb9);
	rbtreeInsert(&root, &rb10);

	rbtreeInsert(&root, &rb1);
	rbtreeInsert(&root, &rb5);
	rbtreeInsert(&root, &rb4);
	rbtreeInsert(&root, &rb3);
	rbtreeInsert(&root, &rb2);

	rbtreeInsert(&root, &rb6);
	rbtreeInsert(&root, &rb7);
	rbtreeInsert(&root, &rb8);
	rbtreeInsert(&root, &rb9);
	rbtreeInsert(&root, &rb10);*/
	travelor(root.root, 0);
	cout << endl;
	return 0;
}

void initRBtreeNode(RBtreeNode *node)
{
	if (NIL == node || node == NULL){
		return;
	}
	node->left = NIL;
	node->right = NIL;
	node->parent = NIL;
}
void leftRotate(RBtree *T, RBtreeNode *x)
{  /**
   * left totate
   */
	RBtreeNode *y;
	y = x->right;

	/**
	* jugde y left child is NIl?
	*/
	x->right = y->left;  // Node x right child is Node y's left 
	if (y->left != T->NIL){
		x->right->parent = x; 	// µÈÐ§ÓÚ y->left->parent = x;
	}
	/**
	* link x parents' node as y parents' node
	*/
	y->parent = x->parent;


	/**
	* judge x's parent is NIL?
	*/
	if (x->parent == T->NIL){
		T->root = y;
	}
	else if (x == x->parent->left){
			/**
			* judge x is x parents' left child or right child
			*/
			x->parent->left = y;
	}
	else{
		x->parent->right = y;
	}
	
	/**
	* link x as y left child
	*/

	y->left = x;
	/**
	* link y as x parent
	*/

	x->parent = y;

}
void rightRotate(RBtree *T, RBtreeNode *y)
{
	/**
	* right totate
	*/
	RBtreeNode *x = y->left;
	y->left = x->right;

	/**
	* jugde x right child is NIl?
	*/
	if (x->right != T->NIL){
		x->right->parent = y;	//y->left->parent = y;
	}

	/**
	* link y parents' node as x parents' node
	*/
	x->parent = y->parent;
	if (y->parent == T->NIL){
		T->root = x;
	}
	else if (y->parent->left == y){
			/**
			* judge y is y parents' left child or right child
			*/
			y->parent->left = x;
	}
	else{
		y->parent->right = x;
	}
	/**
	* link y as x right child
	*/
	x->right = y;

	/**
	* link x as y parent
	*/
	y->parent = x;
}

void rbtreeInsert(RBtree *T, RBtreeNode *node)
{

	RBtreeNode *x, *y;
	y = T->NIL;
	x = T->root;
	while (x != T->NIL){
		y = x;
		if (node->key < x->key){
			x = x->left;
		}
		else {
			x = x->right;
		}
	}

	node->parent = y;
	if (y == T->NIL){  //  This is root Node. 
		T->root = node;
		/*node->color = black;
		return;*/
	}
	else if (node->key >= y->key){
		y->right = node;
	}
	else{
		y->left = node;
	}

	node->left = T->NIL;
	node->right = T->NIL;
	node->color = red;
	rbtreeInsertFixup(T, node);
}

void rbtreeInsertFixup(RBtree *T, RBtreeNode *node)
{
	RBtreeNode *y;
	while (node->parent->color == red){  // all solution that parents' node is red

		/**
		* if the parents node is the grandparents left node, it decided to execute the rightRotate at last.
		*/
		if (node->parent == node->parent->parent->left){// Its parent is  the grandparents left node
			y = node->parent->parent->right;
			if (y->color == red){ //case 1: Its uncle's node is red
				node->parent->color = black;
				y->color = black;
				node->parent->parent->color = red;
				node = node->parent->parent;
				continue;
			}

			/**
			* The following solution is that uncle's node is black
			*/
			if (node == node->parent->right){ // case 2:Its uncle's node is black, it is the its parents right node
				node = node->parent;
				leftRotate(T, node);
			}
			// case 3:Its uncle's node is black,  it is the parents left node
			node->parent->color = black;
			node->parent->parent->color = red;
			rightRotate(T, node->parent->parent);
		}

		/**
		* if the parents node is the grandparents right node, it decided to execute the leftRotate at last.
		*/
		else{ // same as then clause with "right" and "left" exchanged.
			y = node->parent->parent->left;
			if (y != T->NIL && y->color == red){ // //case 1: Its uncle's node is red, 
				node->parent->color = black;
				y->color = black;
				node->parent->parent->color = red;
				node = node->parent->parent;
				continue;
			}

			if (node == node->parent->left){ //case 2:Its uncle's node is black, it is the its parents left node
				node = node->parent;
				rightRotate(T, node);
			}
			// case 3:Its uncle's node is black,  it is the parents right node
			node->parent->color = black;
			node->parent->parent->color = red;
			leftRotate(T, node->parent->parent);
		}
	}
	T->root->color = black;
}



void rbtreeTransplant(RBtree *T, RBtreeNode *u, RBtreeNode *v)
{
	/**
	This function link u's parent to v, but, u's left child and right child don't link to v
	*/
	if (u->parent == T->NIL){
		T->root = v;
	}
	else if (u == u->parent->left){
		u->parent->left = v;
	}
	else{
		u->parent->right = v;
	}
	v->parent = u->parent;// This will be executed in no condition, but node v may be node NIL
}

RBtreeNode* treeMinimum(RBtreeNode *node)
{
	while (node->left != NIL)
		node = node->left;

	return node;
}

void rbtreeDelete(RBtree *T, RBtreeNode *node)
{
	RBtreeNode *y = node, *x;
	Color yOriginalColor = y->color;
	if (node->left == T->NIL){ //case 1:Its left child is NIL
		x = node->right;
		rbtreeTransplant(T, node, node->right);
	}
	else if (node->right == T->NIL){ // case 2:Its right child is NIL
		x = node->left;
		rbtreeTransplant(T, node, node->left);
	}
	else{ // case 3:It has two child.
		y = treeMinimum(node->right); // y's left child must is NIL
		yOriginalColor = y->color;
		x = y->right;
		if (y->parent == node)  // case 3-1: It's next node is its right child
			x->parent = y;
		else{   //case 3-2: It's next node isn't its right child
			// y's right child moves up.
			rbtreeTransplant(T, y, y->right);
			// y node represents the node which is deleted.
			y->right = node->right;
			y->right->parent = y;
		}
		// y node move up
		rbtreeTransplant(T, node, y);

		// update the its left child. 
		y->left = node->left;
		y->left->parent = y;
		y->color = node->color;
	}

	if (yOriginalColor == black){
		rbtreeDeleteFixup(T, x);
	}
}

void rbtreeDeleteFixup(RBtree *T, RBtreeNode *node)
{
	RBtreeNode *w;
	while (node != T->root && node->color == black){
		if (node == node->parent->left){

			w = node->parent->right;   //  w is brothers' node
			if (w->color == red){  // case 1 its brother's node is red
				w->color = black;
				node->parent->color = red;
				leftRotate(T, node->parent);
				w = node->parent->right;
			}

			if (w->left->color == black && w->right->color == black){ //case 2: brothers' node is black and brothers' left right node is black
				w->color = red;
				node = node->parent;
			}
			else{  
				if (w->right->color == black){//  case 3: brothers' node is black, its right child is black, its left child is red.
					w->left->color = black;
					w->color = red;
					rightRotate(T, w);
					w = node->parent->right;
				}
				w->color = node->parent->color; //   case 4:  brothers' node is black, and its right is red
				node->parent->color = black;
				w->right->color = black;
				leftRotate(T, node->parent);
				node = T->root;
			}
		}
		else{
			w = node->parent->left;   //  w is brothers' node
			if (w->color == red){  // case 1 its brother's node is red
				w->color = black;
				node->parent->color = red;
				rightRotate(T, node->parent);
				w = node->parent->left;
			}

			if (w->right->color == black && w->left->color == black){ //case 2: brothers' node is black and brothers' left right node is black
				w->color = red;
				node = node->parent;
			}
			else{
				if (w->left->color == black){//  case 3: brothers' node is black, its right child is black, its left child is red.
					w->right->color = black;
					w->color = red;
					leftRotate(T, w);
					w = node->parent->left;
				}
				w->color = node->parent->color; //   case 4:  brothers' node is black, and its right is red
				node->parent->color = black;
				w->left->color = black;
				rightRotate(T, node->parent);
				node = T->root;
			}
		}
	}
	node->color = black;
}
