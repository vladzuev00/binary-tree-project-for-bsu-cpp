#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <string>

//*********************************************************************
template<class ElementType>
class Node;
//*********************************************************************
template<class ElementType>
class BinaryTree
{
private:
	Node<ElementType> *root;
private:
	static const std::string DELIMITER_OF_ELEMENTS_IN_DESCRIPTION;
	static const std::string START_OF_DESCRIPTION_OF_BINARY_TREE;
	static const std::string END_OF_DESCRIPTION_OF_BINARY_TREE;
private:
	void deleteRootNode();
private:
	static void findDecriptionByInOrderTreeWalk(std::string &holderOfDescription, 
		Node<ElementType> * const rootOfTree);  
	static const Node<ElementType>& findNodeByItsValue(const ElementType &valueOfFoundNode,
		Node<ElementType> * const rootOfSubTree);
	static const Node<ElementType>& findNodeWithMinValueInSubTree(const Node<ElementType> &rootOfSubTree);
	static const Node<ElementType>& findNodeWithMaxValueInSubTree(const Node<ElementType> &rootOfSubTree);
	static void deleteLeafNode(const Node<ElementType> &deletedLeafNode);
	static void deleteNodeWithOnlyLeftChild(Node<ElementType> &deletedNode);
	static void deleteNodeWithOnlyRightChild(Node<ElementType> &deletedNode);
	static void deleteNodeWithTwoChild(Node<ElementType> &deletedNode);
	static void deleteLeafRoot(Node<ElementType> **deletedRoot);
	static void deleteRootWithOnlyRightChild(Node<ElementType> **deletedRoot);
	static void deleteRootWithOnlyLeftChild(Node<ElementType> **deletedRoot);
	static void deleteRootWithTwoChild(Node<ElementType> **deletedRoot);
public:
	BinaryTree();
	BinaryTree(const ElementType &rootValue);
	//BinaryTree(const BinaryTree<ElementType> &other);
public:
	std::string findDescriptionInInreasingOrder() const;   
	const Node<ElementType>& findNodeByItsValue(const ElementType &valueOfFoundNode) const;
	const Node<ElementType>& findNodeWithMinValue() const;
	const Node<ElementType>& findNodeWithMaxValue() const;
	const Node<ElementType>& findNodeWithNextBiggerValue(const Node<ElementType> &node) const;  
	const Node<ElementType>& findNodeWithPreviousSmallerValue(const Node<ElementType> &node) const;
	void insertNode(const ElementType &valueOfInsertedNode);
	bool isEmpty() const;
	void deleteNode(Node<ElementType> &deletedNode);
public:
	//bool operator!=(const BinaryTree<ElementType> &other) const;
	//bool operator==(const BinaryTree<ElementType> &other) const;
	//const BinaryTree<ElementType>& operator=(const BinaryTree<ElementType> &other);
public:
	~BinaryTree();
};
//*********************************************************************
template<class ElementType>
class Node
{
private:
	Node<ElementType> *leftChild;
	Node<ElementType> *rightChild;
	Node<ElementType> *parent;
	ElementType value;
private:
	static const ElementType DEFAULT_VALUE_OF_NODE;
public:
	Node();
	Node(Node<ElementType> * const leftChild, Node<ElementType> * const rightChild,
		 Node<ElementType> * const parent, const ElementType &value);
	Node(const Node &other);
public:
	void setLeftChild(Node<ElementType> * const leftChild);
	Node<ElementType>* getLeftChild() const;
	void setRightChild(Node<ElementType> * const rightChild);
	Node<ElementType>* getRightChild() const;
	void setParent(Node<ElementType> * const parent);
	Node<ElementType>* getParent() const;
	void setValue(const ElementType &value);
	const ElementType& getValue() const;
	bool isLeaf() const;
	bool isWithOnlyLeftChild() const;
	bool isWithOnlyRightChild() const;
	bool isWithOnlyOneChild() const;
public:
	const Node<ElementType>& operator=(const Node<ElementType> &other);
public:
	~Node();
};
//*********************************************************************
#endif BINARYTREE_H

