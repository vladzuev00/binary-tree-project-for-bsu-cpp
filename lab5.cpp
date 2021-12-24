// lab5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "ElementsGenerator.h"
#include "BinaryTree.h"

using namespace std;

int main()
{
	const int minimalBorderOfGeneration = -10000;
	const int maximalBorderOfGeneration = 10000;
	const ElementsGenerator<double> *elementsGenerator = new ElementsGenerator<double>(
		minimalBorderOfGeneration, maximalBorderOfGeneration);

	const int amountOfInsertedNodes = 10000;
	const double * const valuesOfInsertedNodes = elementsGenerator         //delete
		->generateElements(amountOfInsertedNodes);
	delete elementsGenerator;

	BinaryTree<double> * const binaryTree = new BinaryTree<double>();

	for (int i = 0; i < amountOfInsertedNodes; i++)
	{
		binaryTree->insertNode(*(valuesOfInsertedNodes + i));
	}

	std::cout << binaryTree->findDescriptionInInreasingOrder() << "\n";

	delete binaryTree;

	system("pause");
	return EXIT_SUCCESS;
}


