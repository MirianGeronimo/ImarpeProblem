#include "stdio.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/*definimos la función captura*/
float C(float t){
    return 10;
}
/*definimos la función abundancia de la poblacion en el tiempo t*/
/*que tiene como parámetros el tiempot, población inicial N0*/
/*la tasa r y la capacidad de K*/
float   N(int t, int N0,float r,float K){
    float my_vector2[t+1];
    int tiempos[t+1];
    my_vector2[0]=N0;
    tiempos[0]=0;
    
    float N;

    for(int i = 0; i<= t-1; i=i+1)
    {
        N=N0+r*N0*(1-N0/K)-C(i);
        N0=N;
        my_vector2[i+1]=N;
        tiempos[i+1]=i+1;
        cout << "La población en tiempo t=" << i+1 << " es N(t)=" << N << endl;
        

    }
    /*for(int i = 0; i < t+1; i++){
    cout<<my_vector2[i]<<" ";
    }*/
    ofstream fout("Myfile.txt");
    if(fout.is_open())
	{
        fout << "tiempos" ;
        fout << " Poblacion " ;
        fout << endl;
		for(int i = 0; i<=t; i++)
		{
      fout << tiempos[i] << " " ;
      fout << my_vector2[i] << " " ;
      fout << endl; 
		}
    cout << "Success!" << endl;
	}
	else 
	{
		cout << "File could not be opened." << endl;
	}
    
    return my_vector2[t+1]; 
}

int main()
{
float N0,r,K;
int t;
/*Damos ciertos valores de entrada*/
N0=7;
r=2.4;
K=100;
t=20;
/*imprimimos los resultados*/
printf("La población en el tiempo t=0 es N(t)=%.5f",N0);
printf("\n");
N(t,N0,r,K);
printf("\n");
}