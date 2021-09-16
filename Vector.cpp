/******************************************************************************
Vector 7
Autor: Luis Miguel Arcila Guzmán
Fecha: Septiembre 17/2021
*******************************************************************************/

#include <iostream>

#include <vector>  //esta clase tiene el metodo resize para la redimension de vectores
using namespace std;

int main()
{
    int n;
    int band=1;
    
    while(band==1){         //el ciclo se repetira hasta que el usuario ingrese un número <20 y menor o igual a 100
    cout<<"ingrese el número de elementos del vector"<<endl; 
    cin>>n;
    if(n>20&&n<=100){
        band=0;         //si se ingresa el número correcto band se pone en 0 y se sale del ciclo while
        }
        else{band=1;}   
    }
    vector<int> vec(n);   //declaración del vector
    
    
    for(int i=0;i<n;i++){
        vec[i]=1+rand()% 100;    //crea el vector de numero aleatorios entre el 1 y 100
        
    }
    cout<<"El vector es:"<<endl;
  
    for(int i=0;i<n;i++){       //impresion elementos del vector desordenados
        cout<<vec[i]<<endl;
    }
    
    
    int aux;
  for(int i=0;i<n;i++){       //dos ciclos for anidados para ordenar el vector
        for(int j=0;j<n-1;j++){
            if(vec[j] > vec[j+1]){
                
                aux=vec[j];
                vec[j]=vec[j+1];
                vec[j+1]=aux;
                
            }}}

cout<<"Y el vector ordenado es:"<<endl;
  for(int i=0;i<n;i++){             //impresion del vector ordenado
        cout<<vec[i]<<endl;
    }
    
    int num;
    cout<<"inserte un número cualquier"<<endl;   
    cin>>num;
    vec.resize(n+1);        //redimensionado del vector
    vec[n]=num;              //insersion del nuevo número
    
cout<<"Y el vector ordenado con el nuevo número es:"<<endl;
    int aux2;
     for(int i=0;i<n+1;i++){       //dos ciclos for anidados para ordenar el vector con el nuevo número
        for(int j=0;j<n;j++){
            if(vec[j] > vec[j+1]){
                
                aux2=vec[j];
                vec[j]=vec[j+1];
                vec[j+1]=aux2;
                
            }}}
            
    for(int i=0;i<n+1;i++){     //impresion del vector ordenado
        cout<<vec[i]<<endl;
    }
            
    return 0;
}