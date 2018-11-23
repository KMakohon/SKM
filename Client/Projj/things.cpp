#include <QCoreApplication>
#include <iostream>
#include <QByteArray>
#include <QTcpSocket>
#include <stdlib.h>
#include <string>

#include "things.h"

using namespace std;

Things::Things()
{
}

int Things::Change1(string a)
{
    if (a.compare("a")==0) {return(97);}
    else if (a.compare("b")==0) {return(98);}
    else if (a.compare("c")==0) {return(99);}
        else {return(101);}
}

