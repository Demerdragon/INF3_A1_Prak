//============================================================================
// Name        : INF3_Prak.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <string>
#include <iostream>

#include <cstdio>      /* printf, NULL */
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */

#include <unistd.h>

#include "SHA256.H"
#include "TASK1.H"
using namespace std;


int main(){
	srand(time(nullptr));
	TASK1::demoTASK1_01();
	TASK1::demoTASK1_00();
	TASK1::BlackBoxUnsafe g(4,4);
	g.guessPWD();
    return 0;
}





