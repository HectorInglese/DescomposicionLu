
// Programa que descompone una matriz A en LU y da sus valores X & Y / descompone una matriz A en QR 
  
#include <string.h>
#include<conio.h>
#include<stdlib.h>
#include <iostream>
#include <iomanip>
using namespace std;


// Prototipos
void pedirDatos();
void LU(float **,float *,int,int);

// Variables Globales
float **matrizA,*matrizB,**matrizC,**matrizL,**matrizU, sum;
int nRow,nCol,i,j,k;

int main(){
	
	pedirDatos();
	LU(matrizA,matrizB,nRow,nCol);
	
	for( i=0;i<nRow;i++){
		delete[] matrizA[i];
		delete[] matrizL[i];
		delete[] matrizU[i];

	}
	delete[] matrizA;
	delete[] matrizB;
	delete[] matrizL;
	delete[] matrizU;

	
	getch();
	return 0;
}

void pedirDatos(){
	
	while (nRow <= 1)
	{
		nRow= 0;
		nCol = 0;
		cout<<"\tEl VALOR  MINIMO DEBE DE SER IGUAL O MAYOR QUE 2\n\n";	
		cout<<"Digite el orden cuadrado de la matriz = ";
		cin>>nRow;
		
		nCol=nRow;
		
		if(nRow <=1){
			cout<<"\n\n\tEl VALOR  MINIMO DEBE DE SER IGUAL O MAYOR QUE 2"<<endl;
			cout<<"\n\tPRESIONE CUALQUIER TECLA PARA VOLVER"<<endl;
			getch();
			system("cls()");		
		}
		
	}
	
	
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
	
	matrizB = new float[nCol];
	cout<<"\n\t DIGITE LOS VALORES \n"<<endl;
	for(int i = 0 ; i < nCol ; i++){
		cout<<"DIGITE LOS VALORES DE B["<<i+1<<"] = ";
		cin>>matrizB[i];
	}
	
		
}

void LU(float **,float *,int,int){
	
	std::cout << std::setprecision(2) << std::fixed;
	
		matrizL =new float*[nRow];
	for (int i=0;i<nRow;i++){
		matrizL[i] = new float[nCol];
	}	
	
		matrizU =new float*[nRow];
	for (int i=0;i<nRow;i++){
		matrizU[i] = new float[nCol];
	}	

//Poner 0 & 1 en sus respectivos lugares sin procesos matematicos
	for(int i=0; i<nRow; i++){
		for(int j=0;j<nCol; j++){
			
			if (i > j ){	
				*(*(matrizU+i)+j)	= 0 ; 	
			}
			
			if(i==j){
				*(*(matrizL+i)+j)	= 1 ;
			}
			
			if(i < j){
				*(*(matrizL+i)+j)	= 0 ;
			}
		}
	} 
// Fin	
	
//LLenando las matrices L & U con valores <> de 0  	
	for(int i=0; i<nRow; i++){
		for(j=0; j<nCol; j++){
			sum=0;
			if(i <= j){
				for(int k=0; k<nRow; k++){
					if(k != i){
						sum= sum + *(*(matrizL+i)+k) * *(*(matrizU+k)+j);
						
					}else {
                        *(*(matrizU+i)+j) = *(*(matrizA+i)+j) - sum;              
                    }
				}
			} else {
				for(int k=0; k<nRow; k++){
					if(k!=j){
						sum = sum + *(*(matrizL+i)+k) * *(*(matrizU+k)+j);
					} else {
						*(*(matrizL+i)+j) =(*(*(matrizA+i)+j) - sum ) / *(*(matrizU+j)+j);
					}
				}
			}
		}
	}
//FIN
	
//Calculo de Yn & Xn

float X[nCol]={0}, Y[nCol]={0};

    Y[0]=matrizB[0] / **matrizL;
    for(int i=1 ; i<nRow ;i++){
        sum=0;
        for(int j=0 ; j<nCol ; j++){
            sum = sum + Y[j] * *(*(matrizL+i)+j) ;
        }
        Y[i] = matrizB[i] - sum ;
    }
    

	
	X[nRow-1]=Y[nRow-1]/ matrizU[nRow-1][nCol-1];
	for (int i = nRow - 2; i>= 0 ; i--){
		sum = 0;
		for(int j = nRow-1; j > i; j--){
			sum = sum + X[j] * *(*(matrizU+i)+j) ;
		}
		X[i]=(Y[i]-sum)/ *(*(matrizU+i)+i);
	}



//FIN
	
	
// Mostrar  datos Matrices
	system("cls()");
	
	cout<<"\n  Matriz A =";
	for(int i=0; i<nRow; i++){
		for(int j=0;j<nCol; j++){	
			cout<<"  "<<*(*(matrizA+i)+j)<<"  ";	
		}
		cout<<"\n            ";
	}
	
	cout<<"\n  La matriz B = ";
	for(int i = 0 ; i < nRow ; i++){	
		cout<<matrizB[i];
		cout<<"\n                ";
	} 
	
	
	cout<<"\n  Matriz L =";
	for(int i=0; i<nRow; i++){
		for(int j=0;j<nCol; j++){	
			cout<<"  "<<*(*(matrizL+i)+j)<<"  ";	
		}
		cout<<"\n            ";
	}
	
	cout<<"\n  Matriz U =";
	for(int i=0; i<nRow; i++){
		for(int j=0;j<nCol; j++){	
			cout<<"  "<<*(*(matrizU+i)+j)<<"  ";	
		}
		cout<<"\n            ";
	}		
	
	
	printf("\n\n Y =");
    for(int i=0 ; i<nRow ; i++){
    	printf ("%10.2f",Y[i]);
        cout<<"\n    ";
    }
    
 	cout<<"\nLa solucion es : \n";
    for(int i=0 ;i<nRow ; i++){
    	printf("\n x[%d] = %.2f ",i+1,X[i]);
    	cout<<"\n";
	}
        
//Fin
}
	
	
			

	
