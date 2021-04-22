// examen_parcial2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <mysql.h>
#include <iostream>
using namespace std;
int q_estado;
int main()
{
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "urs_comercial", "comercial@123", "db_comercial", 3306, NULL, 0);
    if (conectar) {
        cout << "Coneccion exitosa..." << endl;

    }
    else {
        cout << "Error en la coneccion..." << endl;

    }
   

    system("pause");
    return 0;
}


