#include <iostream>
#include <conio.h>
#include <stdlib.h>//new y delete
#include <stdio.h>
#include <chrono>
#include <vector>

using namespace std;

void pedirDatos();
void multiplicar_mostrar_m(vector<int>,vector<int>,int);
void mostrarMatrices(vector<int>,vector<int>,int);

vector<int> p_matriz1,p_matriz2;
int n;

   
int main(){
	
    pedirDatos();
    
    auto begin = std::chrono::high_resolution_clock::now();
    
    mostrarMatrices(p_matriz1,p_matriz2,n);
    multiplicar_mostrar_m(p_matriz1,p_matriz2,n);


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
    for(int i=0;i<n*n;i++){
    	int random = rand() % 10;
        p_matriz1.push_back(random);
    }
    
    for(int i=0;i<n*n;i++){
    	int random = rand() % 10;
        p_matriz2.push_back(random);
    }



}

void multiplicar_mostrar_m(vector<int> p_matriz1,vector<int> p_matriz2,int n){
	int z=0;
    for(int i=0;i<n*n;i++){
            p_matriz1[i] *= p_matriz2[i];
            z++;
    }    
    
    cout<<"\nLa multiplicacion de las 2 matrices es: \n";
    int x=0;
	for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<p_matriz1[x]<<" "; //p_matriz[i][j]
            x++;
        }
        cout<<"\n";
    } 


}

void mostrarMatrices(vector<int> p_matriz1,vector<int> p_matriz2,int n){
    cout<<"\nLa matriz 1 es: \n";
    int x=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<p_matriz1[x]<<" "; //p_matriz[i][j]
            x++;
        }
        cout<<"\n";
    }   
    
    cout<<"\nLa matriz 2 es: \n";
    int y=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<p_matriz2[y]<<" "; //p_matriz[i][j]
            y++;
        }
        cout<<"\n";
    }   
     

}


