/*Hoja de Trabajo # 6.1
Realice un programa que, dado el peso, la altura, la edad y el género (M/F) 
de un grupo de N personas que pertenecen a un departamento de la república,.*/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
using namespace std;
struct reg		{
	int			EDAD;
	float 		ALTU;
	float	 	PESO;
	string	 	GENE;		
				};


void	ingresar()	;
void 	reporte()	;
void 	MENU()		;
void 	ordenar()	;

int main(){
//	ordenar();
	MENU()	;
	return (0);
	}
 void ingresar(){
	int			zEDAD;
	float	 	zALTU;
	float	 	zPESO;
	char	 	zGENE[1];
 	cout<<"ingrese la EDAD| :"			;cin>>zEDAD;
 	cout<<"ingrese la ALTURA :"			;cin>>zALTU;
 	cout<<"ingrese el PESO :"	 		;cin>>zPESO;
 	cout<<"ingrese el GENERO |M| o |F|:";cin>>zGENE; 	strupr(zGENE)	;
 	
 //	GUARDANDO
 ofstream grabararchivo;
	try {
		grabararchivo.open("HT6_EJERCICIO_02.txt",ios::app);
		grabararchivo<<zEDAD<<"\t"<<zALTU<<"\t"<<zPESO<<"\t"<<zGENE<<endl;
		grabararchivo.close();		
		}
	catch(exception X){
		cout<<"Error en el manejo del archivo"<<endl;	
		}
ordenar();
}

 void reporte(){
 	  /*Obtenga un promedio de peso, altura y edad de esta población. */
	/*------------ LECTURA Y CARGA --------------------*/
int 		lineas;
string 		auxiliar;	// variable auxiliar para lectura de lineas	
float		sumaEDAD,sumaALTU,sumaPESO;
	
	ifstream archivo;	fflush(stdin);

	try{
		archivo.open("HT6_EJERCICIO_02.txt",ios::in);
	         while (getline(archivo, auxiliar))
	 	     lineas++;
	    archivo.close();
			}
	catch(exception X){
		cout<<"Error en el manejo del archivo"<<endl;		
			}
		reg recordset[lineas];
	try{
		archivo.open("HT6_EJERCICIO_02.txt",ios::in);
		for (int i = 0; i < lineas; i++) {
        archivo>>recordset[i].EDAD>>recordset[i].ALTU>>recordset[i].PESO>>recordset[i].GENE;
	
			}
			archivo.close();	//En caso de que falle REVISAR AQUI
			}
	catch(exception X){
		cout<<"Error en el manejo del archivo"<<endl;		
			}	
 	/*------------FIN --------------------*/
 	/*----------TRABAJO CON DATOS GUARDADOS-----promedios----*/
 	for (int i = 0; i < lineas; i++) {
 		sumaEDAD=(sumaEDAD+recordset[i].EDAD);
	 	sumaALTU=(sumaALTU+recordset[i].ALTU);
	 	sumaPESO=(sumaPESO+recordset[i].PESO);
 	 }

 	sumaEDAD=(sumaEDAD/lineas);cout<<"El promedio de EDAD 		es de: "	<<sumaEDAD<<endl;
 	sumaALTU=(sumaALTU/lineas);cout<<"El promedio de ALTURA		es de: "	<<sumaALTU<<endl;
	sumaPESO=(sumaPESO/lineas);cout<<"El promedio de PESO 		es de: "	<<sumaPESO<<endl;
	 }
 
void MENU(){
int	operacion=0;
	do{
	cout<<"--------------------------------------------"<<endl;	
	cout<<"Bienvenido, que accion desea realizar ?"<<endl<<endl;
	cout<<"1. Ingreso de datos"<<endl<<"2. Reportes"<<endl<<"0. Salir"<<endl;
	cout<<"--------------------------------------------"<<endl;	
	cin>>operacion;
 	if (operacion==1){
 		system("CLS");
		ingresar();	};
 	if (operacion==2){
 		system("CLS");
		reporte();	};
 } 	while (operacion!=0);
 				}	
void ordenar(){
		//------------ LECTURA Y CARGA --------------------
int 		lineas;
string 		auxiliar;	// variable auxiliar para lectura de lineas	
	
ifstream archivo;	fflush(stdin);

	try{
		archivo.open("HT6_EJERCICIO_02.txt",ios::in);
	         while (getline(archivo, auxiliar))
	 	     lineas++;
	    archivo.close();
			}
	catch(exception X){
		cout<<"Error en el manejo del archivo"<<endl;		
			}
reg recordset[lineas];	
cout<<"se detalla el archivo PREVIO al ordenamiento"<<endl;
	try{
		archivo.open("HT6_EJERCICIO_02.txt",ios::in);
		for (int i = 0; i < lineas; i++) {
        archivo>>recordset[i].EDAD>>recordset[i].ALTU>>recordset[i].PESO>>recordset[i].GENE;
        cout<<recordset[i].EDAD<<"\t"<<recordset[i].ALTU<<"\t"<<recordset[i].PESO<<"\t"<<recordset[i].GENE<<"\t"<<endl;	
			}
			archivo.close();	
			}
	catch(exception X){
		cout<<"Error en el manejo del archivo"<<endl;		
			}	
 	//*------------FIN --------------------
 	 	//*-------- (BUBBLESORT)------- 	 	
 int 	i,j,temp;
 	int		tempEDAD;
	float	tempALTU;
	float	tempPESO;
	string	tempGENE;	 	
		 		 	
	 for (i=1; i<lineas; i++){	//cicla 8 veces
	        for (j=0 ; j<lineas-i; j++){	// civla 9 veces
			          		 if (recordset[j].EDAD > recordset[j+1].EDAD){
			          		 	tempEDAD=recordset[j].EDAD;
			          		 	tempALTU=recordset[j].ALTU;
			          		 	tempPESO=recordset[j].PESO;
			          		 	tempGENE=recordset[j].GENE;
    		 							   recordset[j].EDAD=recordset[j+1].EDAD;
    		 							   recordset[j].ALTU=recordset[j+1].ALTU;
    		 							   recordset[j].PESO=recordset[j+1].PESO;
    		 							   recordset[j].GENE=recordset[j+1].GENE;
			          		 	recordset[j+1].EDAD = tempEDAD;
			          		 	recordset[j+1].ALTU = tempALTU;
			          		 	recordset[j+1].PESO = tempPESO;
			          		 	recordset[j+1].GENE = tempGENE;
									}
		    }
	}
//	GUARDANDO
remove("Temp.txt");
 ofstream grabararchivo;
	try {
		grabararchivo.open("Temp.txt",ios::app);
			 for (i=0; i<lineas; i++){
		 	 grabararchivo<<recordset[i].EDAD<<"\t"<<recordset[i].ALTU<<"\t"<<recordset[i].PESO<<"\t"<<recordset[i].GENE<<endl;
			  }
		grabararchivo.close();		
		}
	catch(exception X){
		cout<<"Error en el manejo del archivo"<<endl;	
		}		 

		remove("HT6_EJERCICIO_02.txt");
		rename("Temp.txt","HT6_EJERCICIO_02.txt");
	}

