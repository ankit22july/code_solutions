// BinarySearchTreeImplementation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

typedef struct BinarySearchTreeNode
{
	int key;
	BinarySearchTreeNode* leftChild;
	BinarySearchTreeNode* rightChild;
} NODE;

//using NODE = BinarySearchTreeNode;

NODE* createNode(int key)
{
	NODE* node = (NODE *)malloc(sizeof(NODE));
	if (node != nullptr)
	{
		cout << "Node creation passed\n";
		node->key = key;
		node->leftChild = nullptr;
		node->rightChild = nullptr;
	}
	else
	{
		cout << "Node creation failed\n";
	}
	return node;
}

NODE * insert(NODE * node, int key)
{	
	if (node == nullptr) 
		return createNode(key);

	//if tree is not empty find the proper place to insert new node
	if (key > node->key)
		node->rightChild = insert(node->rightChild, key);
	else
		node->leftChild = insert(node->leftChild, key);

	//return the node pointer
	return node;
}

NODE* ReplaceWithInorderSuccessor(NODE* node) {
	NODE* current = node;
	NODE* parent = nullptr;

	// Find the leftmost leaf
	while (current && current->leftChild != NULL)
	{
		parent = current;
		current = current->leftChild;
	}

	if (current != node)
	{
		node->key = current->key;
		parent->leftChild = nullptr;
		free(current);
	}

	return node;
}

NODE* deleteNode(int key, NODE * root)
{
	NODE* temp = nullptr;
	NODE* parent = nullptr;

	if (root == nullptr)
	{
		return nullptr;
	}

	if (key == root->key)
	{
		cout << "Found Key : " << key << endl;
		if (root->leftChild == nullptr && root->rightChild == nullptr)
		{
			free(root);
			root = nullptr;
		}
		else if (root->leftChild == nullptr || root->rightChild == nullptr)
		{
			if (root->leftChild)
			{
				NODE * temp = root->leftChild;
				free(root);
				root = temp;
			}
			else
			{
				NODE* temp = root->rightChild;
				free(root);
				root = temp;
			}
		}
		else
		{
			root = ReplaceWithInorderSuccessor(root);
		}
		
		return root;
	}

	if (key < root->key)
		temp = root->leftChild;
	else
		temp = root->rightChild;

	parent = root;

	while (temp != NULL)
	{
		if (key == temp->key)
		{
			cout << "Found Node with Key : " << key << endl;

			if (temp->leftChild == nullptr && temp->rightChild == nullptr)
			{
				if (parent->leftChild == temp)
					parent->leftChild = nullptr;
				else
					parent->rightChild = nullptr;

				free(temp);
				temp = nullptr;
				return root;
			}
			else if (temp->leftChild == nullptr || temp->rightChild == nullptr)
			{
				if (temp->leftChild)
				{
					if (parent->leftChild == temp)
						parent->leftChild = temp->leftChild;
					else
						parent->rightChild = temp->leftChild;
				}
				else
				{
					if (parent->leftChild == temp)
						parent->leftChild = temp->rightChild;
					else
						parent->rightChild = temp->rightChild;
				}

				free(temp);
				temp = nullptr;
				return root;
			}
			else
			{
				temp = ReplaceWithInorderSuccessor(temp);
				return root;
			}
		}

		parent = temp;

		if (key < temp->key)
			temp = temp->leftChild;
		else
			temp = temp->rightChild;
	}
	
	return nullptr;
}


void inorderTraversal (NODE* root) 
{
	if (root != nullptr) 
	{
		inorderTraversal(root->leftChild);
		cout << root->key << " ";
		inorderTraversal(root->rightChild);
	}
}

void preorderTraversal(NODE* root)
{
	if (root != nullptr)
	{
		cout << root->key << " ";
		inorderTraversal(root->leftChild);
		inorderTraversal(root->rightChild);
	}
}

void postorderTraversal(NODE* root)
{
	if (root != nullptr)
	{
		inorderTraversal(root->leftChild);
		inorderTraversal(root->rightChild);
		cout << root->key << " ";
	}
}

int main()
{
	NODE* root = nullptr;
	root = insert(root, 5);
	root = insert(root, 3);
	root = insert(root, 7);
	root = insert(root, 10);
	root = insert(root, 6);

	cout << "Before : ";
	inorderTraversal(root);
	cout << endl;

	root = deleteNode(5, root);

	cout << "After : ";
	inorderTraversal(root);
	cout << endl;

	return 0;
}