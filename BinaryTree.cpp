#include "stdafx.h"
#include "BinaryTree.h"
#include "BinaryTreeSearchElementException.h"

//*********************************************************************
template class Node<double>;
//*********************************************************************
template<class ElementType>
Node<ElementType>::Node() 
	: leftChild(NULL), rightChild(NULL), parent(NULL), value(Node<ElementType>::DEFAULT_VALUE_OF_NODE)
{
	
}
//*********************************************************************
template<class ElementType>
Node<ElementType>::Node(Node<ElementType> * const leftChild, Node<ElementType> * const rightChild,
						Node<ElementType> * const parent, const ElementType &value)
	: leftChild(leftChild), rightChild(rightChild), parent(parent), value(value)
{

}
//*********************************************************************
template<class ElementType>
Node<ElementType>::Node(const Node<ElementType> &other)
	: leftChild(NULL), rightChild(NULL), parent(NULL), value(other.value)
{

}
//*********************************************************************
template<class ElementType>
const ElementType Node<ElementType>::DEFAULT_VALUE_OF_NODE = 0;
//*********************************************************************
template<class ElementType>
void Node<ElementType>::setLeftChild(Node<ElementType> * const leftChild)
{
	this->leftChild = leftChild;
}
//*********************************************************************
template<class ElementType>
Node<ElementType>* Node<ElementType>::getLeftChild() const
{
	return this->leftChild;
}
//*********************************************************************
template<class ElementType>
void Node<ElementType>::setRightChild(Node<ElementType> * const rightChild) 
{
	this->rightChild = rightChild;
}
//*********************************************************************
template<class ElementType>
Node<ElementType>* Node<ElementType>::getRightChild() const 
{
	return this->rightChild;
}
//*********************************************************************
template<class ElementType>
void Node<ElementType>::setParent(Node<ElementType> * const parent) 
{
	this->parent = parent;
}
//*********************************************************************
template<class ElementType>
Node<ElementType>* Node<ElementType>::getParent() const 
{
	return this->parent;
}
//*********************************************************************
template<class ElementType>
void Node<ElementType>::setValue(const ElementType &value)
{
	this->value = value;
}
//*********************************************************************
template<class ElementType>
const ElementType& Node<ElementType>::getValue() const
{
	return this->value;
}
//*********************************************************************
template<class ElementType>
const Node<ElementType>& Node<ElementType>::operator=(const Node<ElementType> &other)
{
	if (this == &other) 
	{
		return *this;
	}
	this->value = other.value;
	return *this;
}
//*********************************************************************
template<class ElementType>
bool Node<ElementType>::isLeaf() const 
{
	return this->leftChild == NULL && this->rightChild == NULL
		&& this->parent != NULL;
}
//*********************************************************************
template<class ElementType>
bool Node<ElementType>::isWithOnlyLeftChild() const 
{
	return (this->leftChild != NULL && this->rightChild == NULL);
}
//*********************************************************************
template<class ElementType>
bool Node<ElementType>::isWithOnlyRightChild() const
{
	return (this->rightChild != NULL && this->leftChild == NULL);
}
//*********************************************************************
template<class ElementType>
bool Node<ElementType>::isWithOnlyOneChild() const 
{
	return this->isWithOnlyLeftChild() || this->isWithOnlyRightChild();
}
//*********************************************************************
template<class ElementType>
Node<ElementType>::~Node()
{
	delete this->leftChild;
	delete this->rightChild;

	if (this->parent != NULL && this == this->parent->leftChild) 
	{
		this->parent->leftChild = NULL;
	}
	else if (this->parent != NULL && this == this->parent->rightChild)
	{
		this->parent->rightChild = NULL;
	}
}
//*********************************************************************
template class BinaryTree<double>;
//*********************************************************************
template<class ElementType>
BinaryTree<ElementType>::BinaryTree() : root(NULL)
{
	
}
//*********************************************************************
template<class ElementType>
BinaryTree<ElementType>::BinaryTree(const ElementType &rootValue) 
	: root(new Node<ElementType>(NULL, NULL, NULL, rootValue))
{
	
}
//*********************************************************************
template<class ElementType>
std::string BinaryTree<ElementType>::findDescriptionInInreasingOrder() const
{
	std::string holderOfDescription = BinaryTree<ElementType>::START_OF_DESCRIPTION_OF_BINARY_TREE;
	BinaryTree<ElementType>::findDecriptionByInOrderTreeWalk(holderOfDescription, this->root);
	holderOfDescription.append(BinaryTree<ElementType>::END_OF_DESCRIPTION_OF_BINARY_TREE);
	return holderOfDescription;
}
//*********************************************************************
template<class ElementType>
const std::string BinaryTree<ElementType>::START_OF_DESCRIPTION_OF_BINARY_TREE = "[";
//*********************************************************************
template<class ElementType>
const std::string BinaryTree<ElementType>::END_OF_DESCRIPTION_OF_BINARY_TREE = "]";
//*********************************************************************
template<class ElementType>
void BinaryTree<ElementType>::findDecriptionByInOrderTreeWalk(std::string &holderOfDescription, 
	Node<ElementType> * const currentNode)
{
	if (currentNode == NULL)
	{
		return;
	}
	BinaryTree<ElementType>::findDecriptionByInOrderTreeWalk(holderOfDescription, currentNode->getLeftChild());
	holderOfDescription.append(std::to_string(currentNode->getValue()));
	holderOfDescription.append(BinaryTree<ElementType>::DELIMITER_OF_ELEMENTS_IN_DESCRIPTION);
	BinaryTree<ElementType>::findDecriptionByInOrderTreeWalk(holderOfDescription, currentNode->getRightChild());
}
//*********************************************************************
template<class ElementType>
const std::string BinaryTree<ElementType>::DELIMITER_OF_ELEMENTS_IN_DESCRIPTION = ", ";
//*********************************************************************
template<class ElementType>
const Node<ElementType>& BinaryTree<ElementType>::findNodeByItsValue(const ElementType &valueOfFoundNode) const 
{
	if (this->root == NULL)
	{
		throw new BinaryTreeSearchElementException("Impossible to find node in empty binary tree");
	}
	return BinaryTree<ElementType>::findNodeByItsValue(valueOfFoundNode, this->root);
}
//*********************************************************************
template<class ElementType>
const Node<ElementType>& BinaryTree<ElementType>::findNodeByItsValue(const ElementType &valueOfFoundNode,
	Node<ElementType> * const rootOfSubTree)
{
	if (rootOfSubTree == NULL)
	{
		throw new BinaryTreeSearchElementException("Impossible to find node with given value. "
			"Given value: " + std::to_string(valueOfFoundNode));
	}
	else if (rootOfSubTree->getValue() == valueOfFoundNode)
	{
		return *rootOfSubTree;
	}
	else if (rootOfSubTree->getValue() < valueOfFoundNode)
	{
		return BinaryTree<ElementType>::findNodeByItsValue(valueOfFoundNode, rootOfSubTree->getRightChild());
	}
	else 
	{
		return BinaryTree<ElementType>::findNodeByItsValue(valueOfFoundNode, rootOfSubTree->getLeftChild());
	}
}
//*********************************************************************
template<class ElementType>
const Node<ElementType>& BinaryTree<ElementType>::findNodeWithMinValue() const   
{
	return BinaryTree<ElementType>::findNodeWithMinValueInSubTree(*this->root);
}
//*********************************************************************
template<class ElementType>
const Node<ElementType>& BinaryTree<ElementType>::findNodeWithMinValueInSubTree(
	const Node<ElementType> &rootOfSubTree)
{
	const Node<ElementType> *runnerNode = &rootOfSubTree;
	while (runnerNode->getLeftChild() != NULL)
	{
		runnerNode = runnerNode->getLeftChild();
	}
	return *runnerNode;
}
//*********************************************************************
template<class ElementType>
const Node<ElementType>& BinaryTree<ElementType>::findNodeWithMaxValue() const
{
	return BinaryTree<ElementType>::findNodeWithMaxValueInSubTree(*this->root);
}
//*********************************************************************
template<class ElementType>
const Node<ElementType>& BinaryTree<ElementType>::findNodeWithMaxValueInSubTree(
	const Node<ElementType> &rootOfSubTree)
{
	const Node<ElementType> *runnerNode = &rootOfSubTree;
	while (runnerNode->getRightChild() != NULL)
	{
		runnerNode = runnerNode->getRightChild();
	}
	return *runnerNode;
}
//*********************************************************************
template<class ElementType>           
const Node<ElementType>& BinaryTree<ElementType>::findNodeWithNextBiggerValue(      
	const Node<ElementType> &node) const
{
	if (node.getRightChild() != NULL) 
	{
		return BinaryTree<ElementType>::findNodeWithMinValueInSubTree(*(node.getRightChild()));
	}
	const Node<ElementType> *runnerNode = &node;
	const Node<ElementType> *parentOfRunnerNode = runnerNode->getParent();
	while (parentOfRunnerNode != NULL && runnerNode == parentOfRunnerNode->getRightChild())
	{
		runnerNode = parentOfRunnerNode;
		parentOfRunnerNode = parentOfRunnerNode->getParent();
	}
	if (parentOfRunnerNode == NULL)    
	{
		throw new BinaryTreeSearchElementException("Given node is node with max value");
	}
	return *parentOfRunnerNode;
}
//*********************************************************************
template<class ElementType>
const Node<ElementType>& BinaryTree<ElementType>::findNodeWithPreviousSmallerValue(
	const Node<ElementType> &node) const
{
	if (node.getLeftChild() != NULL) 
	{
		return BinaryTree<ElementType>::findNodeWithMaxValueInSubTree(*(node.getLeftChild()));
	}
	const Node<ElementType> *runnerNode = &node;
	const Node<ElementType> *parentOfRunnerNode = runnerNode->getParent();
	while (parentOfRunnerNode != NULL && runnerNode == parentOfRunnerNode->getLeftChild()) 
	{
		runnerNode = parentOfRunnerNode;
		parentOfRunnerNode = parentOfRunnerNode->getParent();
	}
	if (parentOfRunnerNode == NULL)   
	{
		throw new BinaryTreeSearchElementException("Given node is node with min value");
	}
	return *parentOfRunnerNode;
}
//*********************************************************************
template<class ElementType>
void BinaryTree<ElementType>::insertNode(const ElementType &valueOfInsertedNode) 
{
	if (this->isEmpty()) 
	{
		this->root = new Node<ElementType>(NULL, NULL, NULL, valueOfInsertedNode);
		return;
	}
	Node<ElementType> *insertedNode = new Node<ElementType>(
		NULL, NULL, NULL, valueOfInsertedNode);
	Node<ElementType> *parentOfInsertedNode = NULL;
	Node<ElementType> *runnerNode = this->root;        
	while (runnerNode != NULL) 
	{
		parentOfInsertedNode = runnerNode;
		if (valueOfInsertedNode < runnerNode->getValue())
		{
			runnerNode = runnerNode->getLeftChild();
		}
		else 
		{
			runnerNode = runnerNode->getRightChild();
		}
	}
	insertedNode->setParent(parentOfInsertedNode);
	if (valueOfInsertedNode < parentOfInsertedNode->getValue())
	{
		parentOfInsertedNode->setLeftChild(insertedNode);
	}
	else 
	{
		parentOfInsertedNode->setRightChild(insertedNode);
	}
}
//*********************************************************************
template<class ElementType>
bool BinaryTree<ElementType>::isEmpty() const 
{
	return this->root == NULL;
}
//*********************************************************************
template<class ElementType>
void BinaryTree<ElementType>::deleteNode(Node<ElementType> &deletedNode)
{
	if (&deletedNode == this->root)
	{
		this->deleteRootNode();
	}
	else if(deletedNode.isLeaf()) 
	{
		BinaryTree<ElementType>::deleteLeafNode(deletedNode);
	}
	else if(deletedNode.isWithOnlyLeftChild())
	{
		BinaryTree<ElementType>::deleteNodeWithOnlyLeftChild(deletedNode);
	}
	else if(deletedNode.isWithOnlyRightChild())
	{
		BinaryTree<ElementType>::deleteNodeWithOnlyRightChild(deletedNode);
	}
	else 
	{
		BinaryTree<ElementType>::deleteNodeWithTwoChild(deletedNode);
	}
}
//*********************************************************************
template<class ElementType>
void BinaryTree<ElementType>::deleteRootNode() 
{
	if (this->root->isLeaf())
	{
		BinaryTree<ElementType>::deleteLeafRoot(&this->root);
	}
	else if (this->root->isWithOnlyRightChild())
	{
		BinaryTree<ElementType>::deleteRootWithOnlyRightChild(&this->root);
	}
	else if (this->root->isWithOnlyLeftChild())
	{
		BinaryTree<ElementType>::deleteRootWithOnlyLeftChild(&this->root);
	}
	else 
	{
		BinaryTree<ElementType>::deleteRootWithTwoChild(&this->root);
	}
}
//*********************************************************************
template<class ElementType>
void BinaryTree<ElementType>::deleteLeafRoot(Node<ElementType> **deletedRoot)
{
	delete *deletedRoot;
	*deletedRoot = NULL;
}
//*********************************************************************
template<class ElementType>
void BinaryTree<ElementType>::deleteRootWithOnlyRightChild(Node<ElementType> **deletedRoot) 
{
	Node<ElementType> *rightChildOfDeletedRoot = (*deletedRoot)->getRightChild();
	rightChildOfDeletedRoot->setParent(NULL);
	(*deletedRoot)->setRightChild(NULL);
	delete *deletedRoot;
	*deletedRoot = rightChildOfDeletedRoot;
}
//*********************************************************************
template<class ElementType>
void BinaryTree<ElementType>::deleteRootWithOnlyLeftChild(Node<ElementType> **deletedRoot)
{
	Node<ElementType> *leftChildOfDeletedRoot = (*deletedRoot)->getLeftChild();
	leftChildOfDeletedRoot->setParent(NULL);
	(*deletedRoot)->setLeftChild(NULL);
	delete *deletedRoot;
	*deletedRoot = leftChildOfDeletedRoot;
}
//*********************************************************************
template<class ElementType>
void BinaryTree<ElementType>::deleteRootWithTwoChild(Node<ElementType> **deletedRoot)
{
	Node<ElementType> *leftChildOfDeletedRoot = (*deletedRoot)->getLeftChild();
	Node<ElementType> *rightChildOfDeletedRoot = (*deletedRoot)->getRightChild();
	Node<ElementType> *nodeWithMinimalValueFromRightChildOfDeletedRoot = (Node<ElementType>*)
		&BinaryTree<ElementType>::findNodeWithMinValueInSubTree(*rightChildOfDeletedRoot);

	nodeWithMinimalValueFromRightChildOfDeletedRoot->setLeftChild(leftChildOfDeletedRoot);
	leftChildOfDeletedRoot->setParent(nodeWithMinimalValueFromRightChildOfDeletedRoot);
	rightChildOfDeletedRoot->setParent(NULL);

	(*deletedRoot)->setLeftChild(NULL);
	(*deletedRoot)->setRightChild(NULL);
	delete *deletedRoot;

	*deletedRoot = rightChildOfDeletedRoot;
}
//*********************************************************************
template<class ElementType>
void BinaryTree<ElementType>::deleteLeafNode(const Node<ElementType> &deletedLeafNode)
{
	Node<ElementType> *parentOfDeletedNode = deletedLeafNode.getParent();
	if (parentOfDeletedNode->getLeftChild() == &deletedLeafNode)
	{
		delete parentOfDeletedNode->getLeftChild();
	}
	else if (parentOfDeletedNode->getRightChild() == &deletedLeafNode)
	{
		parentOfDeletedNode->setRightChild(NULL);
		delete parentOfDeletedNode->getRightChild();
	}
}
//*********************************************************************
template<class ElementType>
void BinaryTree<ElementType>::deleteNodeWithOnlyLeftChild(Node<ElementType> &deletedNode)
{
	Node<ElementType> *parentOfDeletedNode = deletedNode.getParent();
	if (parentOfDeletedNode->getLeftChild() == &deletedNode)
	{
		parentOfDeletedNode->setLeftChild(deletedNode.getLeftChild());
	}
	else if (parentOfDeletedNode->getRightChild() == &deletedNode)
	{
		parentOfDeletedNode->setRightChild(deletedNode.getLeftChild());
	}
	deletedNode.getLeftChild()->setParent(parentOfDeletedNode);
	deletedNode.setLeftChild(NULL);
	delete &deletedNode;
}
//*********************************************************************
template<class ElementType>
void BinaryTree<ElementType>::deleteNodeWithOnlyRightChild(Node<ElementType> &deletedNode)
{
	Node<ElementType> *parentOfDeletedNode = deletedNode.getParent();
	if (parentOfDeletedNode->getLeftChild() == &deletedNode) 
	{
		parentOfDeletedNode->setLeftChild(deletedNode.getRightChild());
	}
	else if (parentOfDeletedNode->getRightChild() == &deletedNode) 
	{
		parentOfDeletedNode->setRightChild(deletedNode.getRightChild());
	}
	deletedNode.getRightChild()->setParent(parentOfDeletedNode);
	deletedNode.setRightChild(NULL);
	delete &deletedNode;
}
//*********************************************************************
template<class ElementType>
void BinaryTree<ElementType>::deleteNodeWithTwoChild(Node<ElementType> &deletedNode)
{
	Node<ElementType> *nodeReplacingDeletedNode = deletedNode.getRightChild();
	Node<ElementType> *parentOfDeletedNode = deletedNode.getParent();
	if (&deletedNode == parentOfDeletedNode->getLeftChild()) 
	{
		parentOfDeletedNode->setLeftChild(nodeReplacingDeletedNode);
	}
	else if (&deletedNode == parentOfDeletedNode->getRightChild()) 
	{
		parentOfDeletedNode->setRightChild(nodeReplacingDeletedNode);
	}
	nodeReplacingDeletedNode->setParent(parentOfDeletedNode);
	nodeReplacingDeletedNode->setLeftChild(deletedNode.getLeftChild());

	deletedNode.setParent(NULL);
	deletedNode.setLeftChild(NULL);
	deletedNode.setRightChild(NULL);
	delete &deletedNode;
}
//*********************************************************************
template<class ElementType>
BinaryTree<ElementType>::~BinaryTree()
{
	delete this->root;
}
//*********************************************************************

