/*
 * TASK1.H
 *
 *  Created on: 10.09.2019
 *      Author: aml
 */

/**
 *
 * \file TASK1.H
 *
 * \brief Contains namespace TASK1. Namespace TASK1 contains the implementation
 * of check sum calculation.
 *
 */

#ifndef TASK1_H_
#define TASK1_H_

#include <string>

using namespace std;

/**
 *
 * \namespace TASK1
 *
 * \brief Contains the implementation
 * of check sum calculation.
 *
 */
namespace TASK1{

/**
 *
 * \var const string SYMBOLS
 *
 *	\brief This contains all possible characters a password can contain
 *
 */
const string SYMBOLS = "ABCDEFGHIJKLMNOPQRTSTUVWXYZabcdefghijklmopqrstuvwxyz0123456789";

/**
 *
 * \var const unsigned int MINIMAL_PWD_LENGTH
 *
 * \brief Defines the minimal length of a password
 *
 */
const unsigned int MINIMAL_PWD_LENGTH = 4;

/**
 *
 * \class IBlackBox
 *
 *	\brief Interface class for password check classes.
 *
 */
class IBlackBox{
public:

/**
 *
 * \brief Comparing the input password to the stored password
 *
 */
	virtual string input(string strPwd) = 0;

/**
 *
 * \brief Returning the used alphabet
 *
 */
	virtual string getSymbols() = 0;
};

/**
 *
 * \class BlackBoxUnsafe
 *
 * \brief Implements a unsafe password checker where the
 * password is stored as plan text.
 *
 */
class BlackBoxUnsafe : public IBlackBox{
public:

/**
 *
 * \brief Constructor, creates a password
 *  \param pwdLength Length of the to be created password
 *  \param symbSetSize Max number of different characters used in the password
 *         Index for const string SYMBOLS
 *
 */
				   BlackBoxUnsafe(int pwdLength, int symbSetSize);

/**
 *
 * \brief Gets a password and compares it to the stored plain text
 *        Returns "ACCESS ACCEPTED" or "ACCESS DENIED"
 *
 */
	virtual string input(string strPwd);

/**
 *
 * \brief Returns the used set of Symbols stored in char *charSymbArray_
 *
 */
			string getSymbols();

/**
 *
 * \brief Algorythm to brute force passwords
 *
 */
			string guessPWD();

/**
 *
 * \brief Variable to store the correct password
 *
 */
			string pwd_;

protected:

/**
 *
 * \brief Function to create a random password
 *  \param pwdLength Length of the password to be created
 *
 */
	string randomPwd(int pwdLength);

/**
 *
 * \brief Used set of characters for the password
 *
 */
	char * charSymbArray_;

/**
 *
 * \brief Stores the number of different Symbols used
 *        delivers the highes index used of const string SYMBOLS
 *
 */
	int    lengthSymbArray_;
};

/**
 *
 * \class BlackBoxSafe
 *
 * \brief Implements a more safe password checker where only the
 * password's checksum is stored.
 *
 * Removed definition of constructor, moved to TASK1.C
 *
 *
 */
class BlackBoxSafe : public BlackBoxUnsafe{
public:

/**
 *
 * \brief Constructor, creates a random password
 *  \param pwdLength length of the to be created password
 *  \param symbSetSize number of the max different available characters
 *
 */
                   BlackBoxSafe(int pwdLength, int symbSetSize);

/**
 *
 * \brief Overrighting the comparison from BlackBoxUnsave's plain text comparison with hash comparison
 *
 */
    virtual string input(string strPwd);
};

/**
 *
 * \brief Simple demonstration of calculating
 * the check sum for a given string.
 *
 */
void demoTASK1_00();

/**
 *
 * \brief Simple demonstration of using the password checker unsave.
 *
 */
void demoTASK1_01();

/**
 *
 * \brief Simple demonstration of using the password checker save.
 *
 */
void demoTASK1_02();

} // end namespace TASK1

#endif /* TASK1_H_ */
