#include "stdafx.h"
#include "BinaryTreeException.h"

//*******************************************************************
BinaryTreeException::BinaryTreeException() : Exception::Exception()
{

}
//*******************************************************************
BinaryTreeException::BinaryTreeException(const std::string &description)
	: Exception::Exception(description)
{

}
//*******************************************************************
BinaryTreeException::BinaryTreeException(Exception * const cause)
	: Exception::Exception(cause)
{

}
//*******************************************************************
BinaryTreeException::BinaryTreeException(const std::string &description,
	Exception * const cause) : Exception::Exception(description, cause)
{
	
}
//*******************************************************************
BinaryTreeException::~BinaryTreeException()
{

}
//*******************************************************************