#include <iostream>
#include <conio.h>
#include <stdlib.h>//new y delete
#include <stdio.h>
#include <chrono>
#include <vector>

using namespace std;


void multiplicar_mostrar_m(vector<vector<int>> ,vector<vector<int>> ,int);
void mostrarMatrices(vector<vector<int>> ,vector<vector<int>> ,int);

   
int main(){
	
	int n;
    
    cout<<"Digite el valor de N: ";
    cin>>n;
    
    vector<vector<int>> p_matriz1(n , vector<int> (n));
    vector<vector<int>> p_matriz2(n , vector<int> (n));

    //Reservando memoria
	for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        	int random = rand() % 10;
            p_matriz1[i][j] = random;
        }
    } 

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        	int random = rand() % 10;
            p_matriz2[i][j]= random;
        }
    } 
    
    auto begin = std::chrono::high_resolution_clock::now();
    
    mostrarMatrices(p_matriz1,p_matriz2,n);
    multiplicar_mostrar_m(p_matriz1,p_matriz2,n);


    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    
    printf("\n Tiempo empleado: %.3f segundos.\n", elapsed.count() * 1e-9);

    getch();
    
    return 0;
}


 

void multiplicar_mostrar_m(vector<vector<int>> p_matriz1,vector<vector<int>> p_matriz2,int n){

   for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            p_matriz1[i][j] *= p_matriz2[i][j];
        }
    }
    cout<<"\nLa multiplicacion de las 2 matrices es: \n";

	for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<p_matriz1[i][j]<<" "; //p_matriz[i][j]
        }
        cout<<"\n";
    } 


}

void mostrarMatrices(vector<vector<int>> p_matriz1,vector<vector<int>> p_matriz2,int n){
    cout<<"\nLa matriz 1 es: \n";

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<p_matriz1[i][j]<<" "; //p_matriz[i][j]
        }
        cout<<"\n";
    }   
    
    cout<<"\nLa matriz 2 es: \n";

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<p_matriz2[i][j]<<" "; //p_matriz[i][j]

        }
        cout<<"\n";
    }   
     

}


