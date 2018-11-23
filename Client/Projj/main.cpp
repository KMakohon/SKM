#include <QCoreApplication>
#include <iostream>
#include <QByteArray>
#include <QTcpSocket>
#include <stdlib.h>
#include <string>
#include <fstream>

#include "socc.h"

using namespace std;

int Change1(string a)
{
    if (a.compare("a")==0) {return(97);}
    else if (a.compare("b")==0) {return(98);}
    else if (a.compare("c")==0) {return(99);}
        else {return(101);}
}

void readFILE(string filename)
{
    string line;
    ifstream myfile(filename);
    if (myfile.is_open())
    {
      while ( getline (myfile,line) )
      {
        cout << line << '\n';
      }
      myfile.close();
    }

    else cout << "Unable to open file\n";
}

int main()
{
    socc cTest;
    string input;
    int input_int;

    cout << "Witaj co chcesz zrobić." <<endl;
    cout << "Podaj litere: ";
    cin >> input;
    input_int = Change1(input);

    switch (input_int) {
    case 97:
        cout << "Wyświetlam: a" <<endl;
        cTest.Test();
        break;

    case 98:
        cout << "Wyświetlam: b" <<endl;
        readFILE("/home/students/s434672/Desktop/cos2.txt");
        break;

    case 99:
        cout << "Wyświetlam: c" <<endl;
        break;
    default:
        cout << "Nie ma takiej opcji. Wpisz jeszcze raz."<< endl;
        break;
    }

    //cTest.Test();

}
