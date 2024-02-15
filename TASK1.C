/*
 * TASK1.C
 *
 *  Created on: 10.09.2019
 *      Author: aml
 */

#include <cstdlib>
#include <cstring>
#include <iostream>

#include "TASK1.H"
#include "SHA256.H"

namespace TASK1{

string BlackBoxUnsafe::getSymbols(){
	return string(charSymbArray_);
};

BlackBoxUnsafe::BlackBoxUnsafe(int pwdLength, int symbSetSize){
	if((symbSetSize < 1) || (symbSetSize > SYMBOLS.length()) ){
		lengthSymbArray_ = SYMBOLS.length();
	}else{
		lengthSymbArray_ = symbSetSize;
	}
	// extract and save the subset of valid symbols
	charSymbArray_ = new char [lengthSymbArray_ + 1];
	strncpy(charSymbArray_, SYMBOLS.c_str(), lengthSymbArray_);
	// create and save random password
	pwd_ = this->randomPwd(pwdLength);
	return;
}

string BlackBoxUnsafe::input(string strPwd){
	if(strPwd.compare(pwd_) == 0){
		return string("ACCESS ACCEPTED");
	}
	return string("ACCESS DENIED");
}

string BlackBoxUnsafe::randomPwd(int l){
	int symbolIdx;
	if(l < MINIMAL_PWD_LENGTH){ l = MINIMAL_PWD_LENGTH;};
	pwd_ = string("");
	for(int i=0; i < l; i++){
		symbolIdx = rand() % lengthSymbArray_;
		pwd_ += charSymbArray_[symbolIdx];
	}
	return pwd_;
}

BlackBoxSafe::BlackBoxSafe(int pwdLength, int symbSetSize) : BlackBoxUnsafe(pwdLength, symbSetSize){
    pwd_ = sha256(pwd_); //store as hash value
}

string BlackBoxSafe::input(string strPwd){
    if(sha256(strPwd).compare(pwd_) == 0) { //comparing hash values
        return string("ACCESS ACCEPTED");
    }
    return string ("ACCESS DENIED");
}

void demoTASK1_00(){
    cout << "demoTASK1-00:" << endl;
	string pwd("meinpassword");
	cout << "pwd   : " << pwd << endl;
	cout << "SHA256: " << sha256(pwd) << endl;
	pwd = ("einpassword");
	cout << "pwd   : " << pwd << endl;
	cout << "SHA256: " << sha256(pwd) << endl << endl;
	return;
}

void demoTASK1_01(){
    cout << "demoTASK1-01:" << endl;
	TASK1::BlackBoxUnsafe unsave(3,5);
	cout << unsave.pwd_ << endl;
	cout << unsave.input("hallo") << endl << endl;
	return;
}

void demoTASK1_02(){
    cout << "demoTASK1-02:" << endl;
    TASK1::BlackBoxSafe save(3,5);
    cout << save.pwd_ << endl;
    cout << save.input("hallo") << endl << endl;
}
}
