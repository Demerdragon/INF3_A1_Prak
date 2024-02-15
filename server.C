/*
 * server.C
 *
 *  Created on: 11.09.2019
 *      Author: aml
 */
#include <cstdio> // standard input and output library
#include <cstdlib> // this includes functions regarding memory allocation
#include <cstring> // contains string functions
#include <cerrno> //It defines macros for reporting and retrieving error conditions through error codes
#include <ctime> //contains various functions for manipulating date and time
#include <iostream>
#include <string>
#include <unistd.h> //contains various constants
#include <sys/types.h> //contains a number of basic derived types that should be used whenever appropriate
#include <arpa/inet.h> // defines in_addr structure
#include <sys/socket.h> // for socket creation
#include <netinet/in.h> //contains constants and structures needed for internet domain addresses

#include "SIMPLESOCKET.H"
#include "TASK1.H"

/**
 *
 *  \class myServer
 *
 *  \brief Implements a server that can generate random passwords
 *          and check if the sent password is correct.
 *
 *
 */
class myServer : public TCPserver{
protected:
    TASK1::BlackBoxSafe *b;
public:

/**
 *
 * \brief Constructor for the password-server
 *  \param port declares the port which the client connects to
 *  \param maxDataSize Defines the maximum size for data packets
 *         that can be sent to the server
 *
 */
    myServer(int port, int maxDataSize) : TCPserver(port,maxDataSize){
        b = new TASK1::BlackBoxSafe(4,10);
    };
/**
 *
 * \brief myResponse detects and executes sent commands and
 *          returns messages based on the commands
 *  \param input data sent from the client
 *
 *
 */
    string myResponse(string input);
};

int main(){
	srand(time(nullptr));
	myServer srv(2023,25);
	srv.run();
}



string myServer::myResponse(string input){
    int pwdlength, abclength;

    if(input.compare(0,7,"NEWPWD[")== 0){       //Suche nach Kommando für das Erstellen eines neuen Passworts
        sscanf(input.c_str(), "NEWPWD[%i,%i]", &pwdlength, &abclength);
        if (pwdlength < 4 || pwdlength > 12){   //Das Passwort soll zwischen 4 und 12 Zeichen lang sein.
            return string("Please choose password length between 4 - 12.");
        }
        if (abclength < 2 || abclength > 62){
            return string("Please choose symbolset size between 2 - 62.");
            //Symbole sind in TASK1.H unter der Variable SYMBOLS gespeichert. Bei einem neuen Passwort kann die Auswahl an Zeichen dadurch  beschränkt werden,
            //dass man die Länge abclength angibt. Dann nimmt er nur die ersten Zeichen aus dem string.
        }
        delete b;
        b = new TASK1::BlackBoxSafe(pwdlength, abclength);
        return b->pwd_;
    }

    if(input.compare(0,4,"PWD[") == 0){     //Suche nach Kommando für Raten eines Passworts.
        string pwd_try;

        std::size_t ende = input.find("]");
        size_t length = ende - 4;
        if (length < 4 || length > 12) return string("Password must be between 4 - 12 characters.");
        pwd_try = input.substr(4, length);      //Aus dem input-string wird alles zwischen [ und ] extrahiert.
        return b->input(pwd_try);
    }



    return string("Unknown command./n");        //Falls keiner der oben genannten Kommandos eingegeben wurde
}
