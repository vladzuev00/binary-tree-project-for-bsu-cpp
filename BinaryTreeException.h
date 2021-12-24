#ifndef BINARYTREEEXCEPTION_H
#define BINARYTREEEXCEPTION_H

#include "Exception.h";

//*******************************************************************
class BinaryTreeException : public Exception
{
public:
	BinaryTreeException();
	BinaryTreeException(const std::string &description);
	BinaryTreeException(Exception * const cause);
	BinaryTreeException(const std::string &description, Exception * const cause);
public:
	virtual ~BinaryTreeException() override;
};
//*******************************************************************

#endif BINARYTREEEXCEPTION_H