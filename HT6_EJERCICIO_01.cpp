/*Hoja de Trabajo # 6.1
En una librería se venden 4 modelos diferentes de cuadernos.*/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <regex>
using namespace std;

struct reg		{
	string		DIAi;
	string	 	MOD;
	int		 	CANT;
	float	 	CASH;		
				};
	

void	ingresar()	;
void	modificar()	;
void 	eliminar();
void	reporte();

int main(){
int	operacion=0;
	do{
	cout<<"--------------------------------------------"<<endl;	
	cout<<"Bienvenido, que accion desea realizar ?"<<endl<<endl;
	cout<<"1. Ingreso de datos"<<endl<<"2. Modificacion de Datos"<<endl<<"3. Borrado de Datos"<<endl<<"4. Reportes"<<endl<<"0. Salir"<<endl;
	cout<<"--------------------------------------------"<<endl;	
	cin>>operacion;
 	if (operacion==1){
 		system("CLS");
		ingresar();	};
 	if (operacion==2){
 		system("CLS");
		modificar();	};
 	if (operacion==3){
 		system("CLS");
		eliminar();	};
 	if (operacion==4){
 		system("CLS");
		reporte();	};
 } 	while (operacion!=0);
 	return (0);				}	
 
 void ingresar(){
	string		zDIAi;
	int		 	zMOD;
	int		 	zCANT;
	float	 	zCASH;
 	cout<<"ingrese el dia de la venta |1 <-> 30 dias|:	";cin>>zDIAi;
 	cout<<"ingrese el Modelo |1| |2| |3| |4|:	";cin>>zMOD;
 	cout<<"ingrese Cantidad adquirida:	";cin>>zCANT;
 	zCASH=zCANT*25;
 	if (zMOD<=3){
 		zCASH=zCANT*18.50;
 		if (zMOD<=2){
 			zCASH=zCANT*15;
 			if (zMOD==1){
 				zCASH=zCANT*10;
 			}
 		}
 	}
 
 //	GUARDANDO
 ofstream grabararchivo;
	try {
		grabararchivo.open("HT6_EJERCICIO_01.txt",ios::app);
		grabararchivo<<zDIAi<<"\t"<<zMOD<<"\t"<<zCANT<<"\t"<<zCASH<<endl;
		grabararchivo.close();		
		}
	catch(exception X){
		cout<<"Error en el manejo del archivo"<<endl;	
		}
}
 
 void modificar(){
	int		 	zMOD;
	int		 	zCANT;
	float	 	zCASH;
 	int	modDIAi;
 	int	modMOD;
 	int modCANT;
 	int zDIAi;
 	int	salida;
 	int	flag;
 	ifstream data_a; //archivo original
	ofstream data_temp; //archivo temporal
	
	remove("Temp.txt");
	data_a.open("HT6_EJERCICIO_01.txt",ios::in);
	data_temp.open("Temp.txt",ios::app);
	
	//Solicitud de DATOS
	cout<<"Ingrese el DIA del renglon a modificar:	"<<endl;	cin>>modDIAi;
	cout<<"Ingrese el MODELO:	"<<endl;	cin>>modMOD;
	
	do {
		cout<<"Ingrese NUEVA cantidad de Unidades: "<<endl;	cin>>modCANT;
		cout<<"\nDesea Modificar algo MAS? Si= 1/No= 2: "<<endl; cin>>salida;
	} while (salida!=2);
	
	//leer archivo anterior
	while (data_a>>zDIAi>>zMOD>>zCANT>>zCASH){
		if(modDIAi==zDIAi){
			data_temp<<zDIAi<<"\t"<<zMOD<<"\t"<<modCANT<<"\t"<<zCASH<<endl;
			cout<<"Archivo Actualizado...."<<endl;
			flag=1;
		}			
		else if(modDIAi!=zDIAi)
			data_temp<<zDIAi<<"\t"<<zMOD<<"\t"<<zCANT<<"\t"<<zCASH<<endl;					
	}
	data_a.close();
	data_temp.close();
	
	if (flag==1){
		remove("HT6_EJERCICIO_01.txt");
		rename("Temp.txt","HT6_EJERCICIO_01.txt");
	}	
 }
 
 void eliminar(){
    int 		zDIAi;
	int		 	zCANT;
	float	 	zCASH;
	int			zMOD;
 	int	modDIAi;
 	int	resp;
 //	int modCANT;
 	int	salida;
 	int	flag;
 	ifstream data_a; //archivo original
	ofstream data_temp; //archivo temporal
	
	remove("Temp.txt");
	data_a.open("HT6_EJERCICIO_01.txt",ios::in);
	data_temp.open("Temp.txt",ios::app);
	
	//Solicitud de DATOS
	
	
	do {
	   	cout<<"Ingrese el DIA que desea eliminar:	"<<endl;	cin>>modDIAi;
		cout<<"Esta seguro que desea eliminar estos DATOS?  Si= 1/No= 2:  "<<endl;	cin>>resp;

	} while (resp!=1);
	
	//leer archivo anterior
	while (data_a>>zDIAi>>zMOD>>zCANT>>zCASH){
		if(modDIAi==zDIAi){
			cout<<"Datos Eliminados...."<<endl;
			flag=1;
		}			
		else if(modDIAi!=zDIAi)
			data_temp<<zDIAi<<"\t"<<zMOD<<"\t"<<zCANT<<"\t"<<zCASH<<endl;					
	}
	data_a.close();
	data_temp.close();
	
	if (flag==1){
		remove("HT6_EJERCICIO_01.txt");
		rename("Temp.txt","HT6_EJERCICIO_01.txt");
	}	
	if (flag==0){
		 cout<<"Error al Eliminar datos, Asegurese que estos daatos existan o no hallan sido borrados antes";
	}	
 }
 void reporte(){
 	//?Calcular el total recaudado por modelo en los 30 días.
	// ?Calcular cuál fue el modelo que se vendió mas en los 30 días
	/*------------ LECTURA Y CARGA --------------------*/
	float	SUMAmod4=0,SUMAmod3=0,SUMAmod2=0,SUMAmod1=0;
	float	SUMAcant4=0,SUMAcant3=0,SUMAcant2=0,SUMAcant1=0;
	ifstream archivo;	fflush(stdin);
	archivo.open("HT6_EJERCICIO_01.txt",ios::in); //append
	if(archivo.fail()){
		cout<<" No se pudo abrir el archivo";
		exit(1);	}
	int lineas;
	string s;
	string	data_a="HT6_EJERCICIO_01.txt";
	while (getline(archivo, s))
        lineas++;
    archivo.close();
    reg recordset[lineas];
    
 	archivo.open(data_a.c_str(),ios::in);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1);	}	
	
	for (int i = 0; i < lineas; i++) {
        if (!archivo) {                                               
            cerr << "No se puede abrir el archivo " << endl;
            system("PAUSE");
            break; }
        archivo>>recordset[i].DIAi>>recordset[i].MOD>>recordset[i].CANT>>recordset[i].CASH;
 }
 	/*------------FIN --------------------*/
 	/*----------TRABAJO CON DATOS GUARDADOS---------*/
	for (int i = 0; i < lineas; i++) {
	 if(recordset[i].MOD=="4"){
	 	SUMAcant4=(recordset[i].CANT+SUMAmod4); // Suma las cantidades
		SUMAmod4=(SUMAcant4*25); }// suma el CASH
	 if(recordset[i].MOD=="3"){
	 	SUMAcant3=(recordset[i].CANT+SUMAmod3); // Suma las cantidades
		SUMAmod3=(SUMAcant3*18.50); }// suma el CASH
	 if(recordset[i].MOD=="2"){
	 	SUMAcant2=(recordset[i].CANT+SUMAmod2); // Suma las cantidades
		SUMAmod2=(SUMAcant2*15); }// suma el CASH
	 if(recordset[i].MOD=="1"){
	 	SUMAcant1=(recordset[i].CANT+SUMAmod1); // Suma las cantidades
		SUMAmod1=(SUMAcant1*10); }// suma el CASH	
	 }
	 /*----en pantalla----*/
	 cout<<"------------------------------------"<<endl;
	 cout<<"Modelo #4: Q."<<SUMAmod4<<endl<<"Modelo #3: Q."<<SUMAmod3<<endl<<"Modelo #2: Q."<<SUMAmod2<<endl<<"Modelo #1: Q."<<SUMAmod1<<endl;
	 cout<<"------------------------------------"<<endl;
	 if (SUMAmod4>SUMAmod3 && SUMAmod4>SUMAmod2 && SUMAmod4>SUMAmod1){cout<<"El modelo mas vendido es: MODELO#4";	 }
	 if (SUMAmod1>SUMAmod3 && SUMAmod1>SUMAmod2 && SUMAmod1>SUMAmod4){cout<<"El modelo mas vendido es: MODELO#1";	 }	 
	 if (SUMAmod2>SUMAmod3 && SUMAmod2>SUMAmod4 && SUMAmod2>SUMAmod3){cout<<"El modelo mas vendido es: MODELO#2";	 }
	 if (SUMAmod3>SUMAmod4 && SUMAmod3>SUMAmod2 && SUMAmod3>SUMAmod1){cout<<"El modelo mas vendido es: MODELO#3";	 }	 
	 cout<<endl<<"------------------------------------";
	 }
