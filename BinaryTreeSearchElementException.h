#ifndef BINARYTREESEARCHELEMENTEXCEPTION_H
#define BINARYTREESEARCHELEMENTEXCEPTION_H

#include "BinaryTreeException.h"

//***************************************************************************
class BinaryTreeSearchElementException : public BinaryTreeException
{
public:
	BinaryTreeSearchElementException();
	BinaryTreeSearchElementException(const std::string &description);
	BinaryTreeSearchElementException(Exception * const cause);
	BinaryTreeSearchElementException(const std::string &description,
		Exception * const cause);
public:
	virtual ~BinaryTreeSearchElementException() override;
};
//***************************************************************************

#endif BINARYTREESEARCHELEMENTEXCEPTION_H