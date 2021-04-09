
// Programa que descompone una matriz A en LU y da sus valores X & Y / descompone una matriz A en QR 
  
#include <string.h>
#include<conio.h>
#include<stdlib.h>
#include <iostream>
#include <iomanip>
using namespace std;


// Prototipos
void pedirDatos();
void mostrarDatos(float **,int,int);
void LU(float **,int,int);
void DEL();

// Variables Globales
float **matrizA,*matrizB ,**matrizL, **matrizU, **matrizQ, **matrizR;
int nRow, nCol;
float matB[100],sum;

//Programa principal
int main(){

	
	pedirDatos();
	LU(matrizA,nRow,nCol);
	
	getch();
	return 0;
}

// Funciones

//Funcion pedir Matriz A & B
void pedirDatos(){
	
	cout<<"Digite el numero de filas: ";
	cin>>nRow;
	cout<<"Digite el numero de columnas: ";
	cin>>nCol;
	
	matrizA =new float*[nRow];
	for (int i=0;i<nRow;i++){
		matrizA[i] = new float[nCol];
	}
	
	cout<<"\n\t DIGITE LOS VALORES \n"<<endl;
	for(int i=0;i<nRow;i++){
		for(int j=0;j<nCol;j++){
			cout<<"DIGITE LOS VALORES DE A["<<i+1<<"]["<<j+1<<"] = ";
			cin>>*(*(matrizA+i)+j);	
		}
	}
	DEL();
}

//Funcion prueba
void mostrarDatos(float **matrizA,float *matrizB,int nRow,int nCol){
	
	
	
	
	system("cls()");
	cout<<"\n \n Matriz A =";
	for(int i=0; i<nRow; i++){
		cout<<"|";
		for(int j=0;j<nCol; j++){	
			cout<<" "<<*(*(matrizA+i)+j)<<" ";	
		}
		cout<<"|";
		cout<<"\n           ";
	}	
	cout<<"\n \n Matriz B =";
	for(int i=0; i<nRow; i++){	
		cout<<"|";
		cout<<" "<<*matrizB;
		cout<<" |";
		cout<<"\n           ";

	}	
}

//Funcion Matriz LU
void LU(float **,int,int){
	
	DEL();
	
	float sum=0;
	
	matrizL =new float*[nRow];
	for (int i=0;i<nRow;i++){
		matrizL[i] = new float[nCol];
	}
	
	matrizU =new float*[nRow];
	for (int i=0;i<nRow;i++){
		matrizU[i] = new float[nCol];
	}
	
	  //Llenado de ceros y unos en posiciones conocidas
    for(int i=0;i<nRow;i++){
        for(int j=0;j<nCol;j++)
            if(i>j){
              *(*(matrizU+i)+j)	= 0;    //Ceros debajo de la diagonal para la matriz U
            }
            else if(i==j){
              *(*(matrizL+i)+j)	=1;    //Unos en la diagonal de L
            } else{
              *(*(matrizL+i)+j)=0;    //Ceros encima de la diagonal para la matriz L
            }
    }
    
    for(int i=0;i<nRow;i++){
        for(int j=0;j<nCol;j++){
             sum=0;
            if(i<=j){               //Es decir, solo se llenan los elementos de la diagonal y encima de ella para U
                for(int k=0;k<nRow;k++){
                    if(k!=i){
                        sum= sum +  *(*(matrizL+i)+k)  *   *(*(matrizU+k)+j);
                    }else {
                        *(*(matrizU+i)+j) = *(*(matrizA+i)+j)- sum ;               //Llenado de elementos restantes de U
                    }
                }
            } else{                 //Es decir, solo se llenan los elementos debajo de la diagonal para L
                for(int k=0;k<nRow;k++){
                    if(k!=j){
                        sum = sum + *(*(matrizU+i)+k) * *(*(matrizU+k)+j);
                    }else {
                       *(*(matrizL+i)+j) = (*(*(matrizA+i)+j) - sum ) / *(*(matrizU+j)+j);      //Llenado de elementos restantes de L
                    }
                }
            }
        }
    }
    
    cout<<"\n \n Matriz L =";
	for(int i=0; i<nRow; i++){
		cout<<"|";
		for(int j=0;j<nCol; j++){	
			cout<<" "<<*(*(matrizL+i)+j)<<" ";	
		}
		cout<<"|";
		cout<<"\n           ";
}

	cout<<"\n \n Matriz U =";
	for(int i=0; i<nRow; i++){
		cout<<"|";
		for(int j=0;j<nCol; j++){	
			cout<<" "<<*(*(matrizU+i)+j)<<" ";	
		}
		cout<<"|";
		cout<<"\n           ";
}	
    
    getch();
}
	
void DEL(){
	
	fflush(stdin);
	//Liberar Memoria
	for(int i=0;i<nRow;i++){
		delete[] matrizA[i];
		delete[] matrizB;
		delete[] matrizL[i];
		delete[] matrizU[i];
		delete[] matrizQ[i];
		delete[] matrizR[i];
	}
	delete[] matrizA;
	delete[] matrizB;
	delete[] matrizL;
	delete[] matrizU;
	delete[] matrizQ;
	delete[] matrizR;
	//
}	
	
