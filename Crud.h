
#include<mysql.h>
#include "Empleado.h"
#include <iostream>
using namespace  std;

int main()
{
	string DPI, nombres, apellidos, direccion, fecha_nacimiento, fecha_inicio_laboral,fecha_ingrso;
	int telefono,genero,idpuesto;
	cout << "Ingrese Nit:";
	getline(cin, nit);
	cout << "Ingrese Nombres:";
	getline(cin, nombres);
	cout << "Ingrese Apellidos:";
	getline(cin, apellidos);
	cout << "Ingrese Direccion:";
	getline(cin, direccion);
	cout << "Ingrese Telefono:";
	cin >> telefono;
	cin.ignore();
	cout << "Fecha Nacimiento:";
	cin >> fecha_nacimiento;
	cout << "fecha_inicio_laboral:";
	cin >> fecha_inicio_laboral;
	cout << "fecha_ingrso:";
	cin >> fecha_ingrso;

	Empleado c = Empleado(nombres, apellidos, direccion, telefono, genero, idpuesto, telefono, fecha_nacimiento, fecha_inicio_laboral, fecha_ingrso, nit);

	c.crear();
	c.leer();
	c.modificar();
	c.eliminar();

	system("pause");
	return 0;
}

