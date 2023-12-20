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
public:
   string guessPWD(int pwdLength);

};



int main() {
    myClient c;
    c.guessPWD(5);
	/*srand(time(NULL));
	TCPclient c;
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
			msg = string("client wants this");
		}
		cout << "client sends:" << msg << endl;
		c.sendData(msg);
		msg = c.receive(32);
		cout << "got response:" << msg << endl;
		sleep(1);

	}*/
}


string myClient::guessPWD(int pwdLength){              //ich will hier ein Pasworrt such algorithum Implementieren
    int j = 1,i = 0, b = 0;
    bool found;
    string tempPWD;
    for(int k=0; k<pwdLength;k++){                    //länge von dem Password wird eingetragen
        char len[pwdLength];
        len[k]= 'A';
        tempPWD=len;
    }
    while(found==false){
        i = 0;
        for(i;i<SYMBOLS.length();i++){                    //testet jede möglichkeit
            tempPWD[j]=SYMBOLS[i];
            cout<<tempPWD<<endl;
            }
            tempPWD[j]=SYMBOLS[i];
            j++;
            if(j == pwdLength){
                j=1;
            }
            if(j ==27){                         //abbruchsbedingung
            found =true;
            }
            else{
                versuche++;
            }
    }
}
