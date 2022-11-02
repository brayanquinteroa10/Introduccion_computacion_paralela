#include <iostream>
#include <conio.h>
#include <stdlib.h>//new y delete
#include <stdio.h>
#include <chrono>

using namespace std;

void pedirDatos();
void multiplicar_m(int **,int **,int);
void mostrarMatrices(int **,int **,int);
void mostrarResultado(int **,int);

int **p_matriz1,**p_matriz2,n;
    
int main(){
	
    pedirDatos();
    
    auto begin = std::chrono::high_resolution_clock::now();
    
    mostrarMatrices(p_matriz1,p_matriz2,n);
    multiplicar_m(p_matriz1,p_matriz2,n);
    mostrarResultado(p_matriz1,n);
    
  //Liberar la memoria utilizada en matriz 1
    
    for(int i=0;i<n;i++){
    	delete[] p_matriz1[i];        

    }
    delete[] p_matriz1;
        
    
    //Liberar la memoria utilizada en matriz 2
    
    for(int i=0;i<n;i++){
    	delete[] p_matriz2[i];        

    }
    delete[] p_matriz2;
        
    
    
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    
    printf("\n Tiempo empleado: %.3f segundos.\n", elapsed.count() * 1e-9);

    getch();
    
    return 0;
}

void pedirDatos(){
 cout<<"Digite el valor de N: ";
    cin>>n;

    //Reservando memoria
    p_matriz1= new int*[n];
    for(int i=0;i<n;i++){
        p_matriz1[i] = new int[n];
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int random = rand() % 10;
            *(*(p_matriz1+i)+j)= random;//p_matriz[i][j]

        }
    }

    p_matriz2= new int*[n];
    for(int i=0;i<n;i++){
        p_matriz2[i] = new int[n];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int random = rand() % 10;
            *(*(p_matriz2+i)+j)= random;//p_matriz[i][j]

        }
    }
}

void multiplicar_m(int **p_matriz1,int **p_matriz2,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            *(*(p_matriz1+i)+j) *= *(*(p_matriz2+i)+j);
        }
    }    

}

void mostrarMatrices(int **p_matriz1,int **p_matriz2,int n){
    cout<<"\nLa matriz 1 es: \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<*(*(p_matriz1+i)+j)<<" "; //p_matriz[i][j]
        }
        cout<<"\n";
    }   
    
    cout<<"\nLa matriz 2 es: \n";

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<*(*(p_matriz2+i)+j)<<" "; //p_matriz[i][j]
        }
        cout<<"\n";
    }   

}

void mostrarResultado(int **p_matriz1,int n){
    cout<<"\nLa multiplicacion de las 2 matrices es: \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<*(*(p_matriz1+i)+j)<<" "; //p_matriz[i][j]
        }
        cout<<"\n";
    }

}
