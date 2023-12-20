/*
 * client.C
 *
 *  Created on: 11.09.2019
 *      Author: aml
 */

#include <string>
#include <iostream>
#include <unistd.h> //contains various constants
#include "TASK1.H"
#include "SIMPLESOCKET.H"

using namespace std;
using namespace TASK1;

class myClient : public TCPclient{
private:
    int versuche;
    int ablauf;
    string tempPWD;
public:
   string guessPWD(int pwdLength);
};



int main() {
	srand(time(NULL));
	myClient c;
	string host = "localhost";
	string msg;

	//connect to host
	c.conn(host , 2023);
	int i=0;
	bool goOn=1;
	while(goOn){ // send and receive data
		if((rand() % 20) < i++){
			msg = string("BYEBYE");
			goOn = 0;
		}else{
            myClient c;
			msg = c.guessPWD(5);
		}
        c.guessPWD(5);
		cout << "client sends:" << msg << endl;
		c.sendData(msg);

		c.sendData(c.guessPWD(5));
		msg = c.receive(32);
		cout << "got response:" << msg << endl;
		sleep(1);

	}
}


string myClient::guessPWD(int pwdLength){              //ich will hier ein Pasworrt such algorithum Implementieren
    myClient c;
    bool found;
    for(int k=0; k<pwdLength;k++){                    //länge von dem Password wird eingetragen
        char len[pwdLength];
        len[k]= 'A';
        tempPWD=len;
        }
        while(found == false){
            for(int i=0;i<SYMBOLS.length();i++){                    //geht das Alphabet durch
                tempPWD[0]=SYMBOLS[i];
                for(int j=0;i<SYMBOLS.length();i++){                //geht das Alphabet durch
                    tempPWD[1]=SYMBOLS[i];
                    for(int l=0;i<SYMBOLS.length();i++){            //geht das Alphabet durch
                        tempPWD[2]=SYMBOLS[i];
                        for(int m=0;i<SYMBOLS.length();i++){        //geht das Alphabet durch
                            tempPWD[3]=SYMBOLS[i];
                            for(int n=ablauf;i<SYMBOLS.length();i++){    //geht das Alphabet durch
                                tempPWD[4]=SYMBOLS[i];
                                cout << "client sends:" << tempPWD << endl;
                                c.sendData(tempPWD);
                                versuche++;
                                return tempPWD;
                            }
                        }
                    }
                }
            }

        }
}

