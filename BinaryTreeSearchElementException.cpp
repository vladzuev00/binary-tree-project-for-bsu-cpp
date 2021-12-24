#include "stdafx.h"
#include "BinaryTreeSearchElementException.h"

//***************************************************************************
BinaryTreeSearchElementException::BinaryTreeSearchElementException() 
	: BinaryTreeException::BinaryTreeException()
{

}
//***************************************************************************
BinaryTreeSearchElementException::BinaryTreeSearchElementException(
	const std::string &description)
	: BinaryTreeException::BinaryTreeException(description)
{

}
//***************************************************************************
BinaryTreeSearchElementException::BinaryTreeSearchElementException(
	Exception * const cause)
	: BinaryTreeException::BinaryTreeException(cause)
{

}
//***************************************************************************
BinaryTreeSearchElementException::BinaryTreeSearchElementException(
	const std::string &description, Exception * const cause)
	: BinaryTreeException::BinaryTreeException(description, cause)
{

}
//***************************************************************************
BinaryTreeSearchElementException::~BinaryTreeSearchElementException()
{

}
//***************************************************************************