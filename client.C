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
#include <sstream>

using namespace std;
using namespace TASK1;

class myClient : public TCPclient{
private:
    int versuche;
    int ablauf;
    string tempPWD;
public:
   string guessPWD(int pwdLength);
   string randPWD(int pwdLength,int SymbolLen);
};



int main() {
	srand(time(NULL));
	myClient c;
	string host = "localhost";
	string msg;

	//connect to host
	c.conn(host , 2023);

	int i=0;
	int a = 1;
	int len = 4;
    int Slen = 5;
    unsigned int count,hacked;
	bool goOn=1;
	//cout<<"PWDLength length: ";cin >> len;
	//cout<<"Symbol length: ";cin >> Slen;
	cout<<"alphlng,pwlng,tries"<<endl;
	while(goOn){ // send and receive data
        while(a == 1){
            std::ostringstream oss;
            oss <<"NEWPWD["<<len<<","<<Slen<<"]";
            msg = oss.str();
            //cout << "client sends:" << msg << endl;
            c.sendData(msg);
            msg = c.receive(32);
            //cout << "got response:" << msg << endl;
            a = 0;
        }
        msg = c.randPWD(len,Slen);
		//cout << "client sends:" << msg << endl;
		c.sendData(msg);
		msg = c.receive(32);
		//cout << "got response:" << msg << endl;
		if(msg.compare(0,15,"ACCESS ACCEPTED")== 0){            // wenn Passwort geknackt ist
            a=1;
            cout<<Slen<<","<<len<<","<<count<<endl;
            count = 0;
            hacked++;
            if(hacked >= 100){                  //wie Oft der Versuch durch geführt werden muss;
                cout<<",,=STABW(C2:C"<<hacked+1<<")"<<",stabw"<<endl;
                cout<<",,=MITTELWERT(C2:C"<<hacked+1<<")"<<",mittelwert"<<endl;
                hacked = 0;
                goOn = false;
                a = 0;
            }
		}
		else{
            count++;
		}
		sleep(0);

	}
}


string myClient::randPWD(int pwdLength,int SymbolLen){
    string tempPWD = SYMBOLS.substr(0,pwdLength+5);
    tempPWD[0]= 'P';
    tempPWD[1]= 'W';
    tempPWD[2]= 'D';
    tempPWD[3]= '[';
    int randIdx;
    for(int i = 4;i<=pwdLength+4;i++){
        randIdx = rand()% SymbolLen;
        tempPWD[i] = SYMBOLS[randIdx];
    }
    tempPWD[pwdLength+4]= ']';

	return tempPWD;
}
