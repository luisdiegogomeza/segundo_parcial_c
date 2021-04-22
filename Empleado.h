#pragma once
#include "Persona.h"
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
using namespace std;
class Empleado:Persona {
private: string nit;
	   // constructor
public:
	Empleado() {
	}
	Empleado(string nom, string ape, string dir, int tel, string fn, string n) : Persona(nom, ape, dir, tel, fn) {
		nit = n;
	}

	// METODOS
	//set (modificar)
	void setNit(string n) { nit = n; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	void setFecha_Nacimiento(int fn) { fecha_nacimiento = fn; }
	//get (mostrar)
	string getNit() { return nit; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	string getFecha_Nacimiento() { return fecha_nacimiento; }

	// metodo
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string t = to_string(telefono);
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO Empleado(nit,nombres,apellidos,direccion,telefono,fecha_nacimiento) VALUES ('" + nit + "','" + nombres + "','" + apellidos + "','" + direccion + "'," + t + ",'" + fecha_nacimiento + "')";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			cout << "------------ Datos de Empleado ------------" << endl;
			string consulta = "select * from empleaod";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << endl;
				}

			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void modificar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idempleado, nit, nombres, apellidos, direccion, telefono, fecha_nacimiento;
			char s;
			cout << "------------------------------------------------" << endl;
			cout << "Ingrese el id del Empleado que desea modificar: ";
			cin >> idempleado;
			string consulta = "select * from empleado where id_cliente=" + idempleado+ "";
			const char* i = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {

				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					cout << "IdEmpleado: " << fila[0] << endl;
					cout << ("Nit: ") << fila[1] << endl;
					cout << ("Nombres: ") << fila[2] << endl;
					cout << ("Apellidos: ") << fila[3] << endl;
					cout << ("Direccion: ") << fila[4] << endl;
					cout << ("Telefono: ") << fila[5] << endl;
					cout << ("Fecha de nacimiento: ") << fila[6] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cout << "\nIngrese el nuevo nit de empleado: ";
						cin >> nit;
						string modificar = "update Empleado set nit = '" + nit + "' where id_empleado =" + idempleado + "";
						cin.ignore();
						cout << "\nIngrese el nombre de empleado: ";
						getline(cin, nombres);
						string modificar = "update Empleado set nombres = '" + nombres + "' where id_empleado =" + idcliente + "";
						cout << "\nIngrese los apellidos de cliente: ";
						getline(cin, apellidos);
						string modificar = "update Empleado set apellidos = '" + apellidos + "' where id_empleado =" + idcliente + "";
						cout << "\nIngrese la nueva direccion de cliente: ";
						getline(cin, direccion);
						string modificar = "update Empleado set direccion = '" + direccion + "' where id_empleado =" + idcliente + "";
						cout << "\nIngrese el nuevo telefono de cliente: ";
						getline(cin, telefono);
						string modificar = "update Empleado set telefono = '" + telefono + "' where id_empleado =" + idcliente + "";
						cout << "\nIngrese la fecha de nacimiento de empleado: ";
						getline(cin, fecha_nacimiento);
						string modificar = "update Empleado set fecha_nacimiento = '" + fecha_nacimiento + "' where id_empleado =" + idcliente + "";
						cin >> fecha_nacimiento;
						const char* m = modificar.c_str();
						q_estado = mysql_query(cn.getConectar(), i);
					}
					else {
						cout << ("Modificacion exitosa") << endl;
					}
				}
			}
			else {
				cout << "Error al modificar\n";
			}
		}
		else {
			cout << "Error en la conexion\n";
		}
		cn.cerrar_conexion();
	}

	void eliminar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idempleado;
			cout << "------------------------------------------------" << endl;
			cout << "Ingrese el id del registro que desea eliminar\n";
			cin >> idempleado;
			string eliminar = "delete from Empleado where id_cliente = (" + idempleado + ")";
			const char* i = eliminar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Eliminacion Exitosa ..." << endl;
			}
			else {
				cout << " xxx Error al eliminar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
};

