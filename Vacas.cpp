/******************************************************************************
Programa de la granja
Autor: Luis Miguel Arcila Guzmán
Fecha: Septiembre 17/2021

*******************************************************************************/

#include <iostream>  //libreria estandar de c++
#include <fstream>   //libreria necesaria para leer archivos
#include <string>   //libreria necesaria para trabajar con los objetos tipo string

#include <sstream>   //para convertir string a int por medio de stringstream 
using namespace std;  //uso el espacio de nombres std nos ahorramo tener que escribir std:: en algunas instrucciones ej: cout


void lectura(string vec[],string vec2[],string vec3[]);   //función para leer los 3 archivos y almacenarlos como tipo string en los vectores argumentos
void cambio_tipo_dato(string vec[],string vec2[],float vec3[],int vec4[]);  //conversion de tipo de dato para vectores con la información de los litros y el tipo de vaca
float precio(float litros,int tipo);                    //función para calcular el precio de venta de la leche producida
void ordenar(string vec[],float vec2[],int vec3[],float vec4[]);  //función para ordenar los vectores en función del precio de venta de leche de cada vaca
void buscar_Mireya(string vec[],float vec2[],float vec3[]);         //función que busca la vaca Mirella e imprime en pantalla los litros que esta produce y su precio de venta

int main()
{
    
    //creación de los vectores y de variable indicador del número de vacas 
    int longitud=30;   
    string nombres[30];
    string litros[30];
    string tipo[30];
    float litrosfloat[30];
    int tipoint[30];
    float precio_f[30];
    
    
    lectura(nombres,litros,tipo);  //lee los 3 archivos y los  almacena como tipo string en los vectores nombres,litros y tipo
    cambio_tipo_dato(litros,tipo,litrosfloat,tipoint); //conversión tipo de dato 
    
    for(int i=0;i<longitud;i++){         //crea un nuevo vector con el precio de venta de la leche producida
        precio_f[i]=precio(litrosfloat[i],tipoint[i]);
        
    }
    
    ordenar(nombres,litrosfloat,tipoint,precio_f);    //ordena los datos de los vectores argumentos de la funcion ordenar()
    
    
    cout<<"Impresion por precio en orden ascendente:"<<endl;
    for(int i=0;i<longitud;i++){
        cout <<" Nombre: "<< nombres[i]<<" litros: "<< litrosfloat[i] <<" Precio: "<< precio_f[i]<< endl;
    }
    
    buscar_Mireya(nombres,litrosfloat,precio_f);
    
    //cout << typeid(nombres).name() << endl;
   
  
    return 0;
}


void lectura(string vec[],string vec2[],string vec3[]){
    ifstream archivo1;  //costrucción de un objeto ifstream 
    string texto;   //creación de una variable auxiliar texto
    int i=0;
    archivo1.open("Nombres.txt",ios::in);   //ios::in es abrir el archivo en modo lectura
    
    if(archivo1.fail()){     //en caso de que no se pueda abrir el archivo imprime el mensaje
        cout<<"no se pudo abrir";
        exit(1);
        }
    
    while(!archivo1.eof()){   //recorre todo el archivo mientras no sea el final de este
        
        getline(archivo1,texto); //copia cada fila lo del archivo en la variable string texto
        vec[i]=texto;   //el valor de todas las filas es puesto en un vector
       
        i++;
    }
    
    archivo1.close();  //cierra el archivo
    
    ifstream archivo2;  //costrucción de un objeto ifstream
    
    i=0;
    archivo2.open("Litros.txt",ios::in);   //ios::in es abrir el archivo en modo lectura
    
    if(archivo2.fail()){    //en caso de que no se pueda abrir el archivo imprime el mensaje
        cout<<"no se pudo abrir";
        exit(1);
        }
    
    while(!archivo2.eof()){   //recorre todo el archivo mientras no sea el final de este
        
        getline(archivo2,texto); //copia cada fila lo del archivo en la variable string texto
        vec2[i]=texto;      //el valor de todas las filas es puesto en un vector
       
        i++;
    }
    
    archivo2.close();   //cierra el archivo
    
    
    ifstream archivo3;      //costrucción de un objeto ifstream
    
    i=0;
    archivo3.open("Tipo.txt",ios::in);   //ios::in es abrir el archivo en modo lectura
    
    if(archivo3.fail()){    //en caso de que no se pueda abrir el archivo imprime el mensaje
        cout<<"no se pudo abrir";
        exit(1);
        }
    
    while(!archivo3.eof()){   //recorre todo el archivo mientras no sea el final de este
        
        getline(archivo3,texto); //copia cada fila lo del archivo en la variable string texto
        vec3[i]=texto;      //el valor de todas las filas es puesto en un vector
       
        i++;
    }
    archivo3.close();   //cierra el archivo
    
    
}



void cambio_tipo_dato(string vec[],string vec2[],float vec3[],int vec4[]){
    
    for(int i=0;i<30;i++){
    stringstream floatlitros(vec[i]);   //stringstream es una clase para operar sobre variables string, crea un objeto copia de vec[i] que viene siendo el vector con la información de los Litros
    floatlitros >> vec3[i];             //el objeto clase stringstream es copiado dentro del vector de tipo flotante
	stringstream inttipo(vec2[i]);      // crea un objeto copia de vec2[i], el cual es el vector con información del tipo de vaca
	inttipo >> vec4[i];                 //el objeto clase stringstream es copiado dentro del vector de tipo entero
}
    }

void ordenar(string vec[],float vec2[],int vec3[],float vec4[]){
    float aux4;
    int aux3;
    float aux2;
    string aux;
    
     for(int i=0;i<30;i++){       //dos ciclos for anidados para ordenar el vector
        for(int j=0;j<29;j++){
            if(vec4[j] > vec4[j+1]){
                
                aux4=vec4[j];
                vec4[j]=vec4[j+1];
                vec4[j+1]=aux4;
                
                aux3=vec3[j];
                vec3[j]=vec3[j+1];
                vec3[j+1]=aux3;
                
                aux2=vec2[j];
                vec2[j]=vec2[j+1];
                vec2[j+1]=aux2;
                
                aux=vec[j];
                vec[j]=vec[j+1];
                vec[j+1]=aux;
            }
        }
     }
    
    cout<<endl<<"La vaca cuya produccion tuvo el mayor precio fue: "<< vec[29]<< "de tipo" <<vec3[29]<<endl<<endl;
    
}


float precio(float litros,int tipo){ 
    float Precio_F;
    if(tipo==1 && litros<50){
        Precio_F=litros*1500+500;
        return Precio_F;
    }
    else if(tipo==1 && litros>=50){
        Precio_F=litros*1500+550;
        return Precio_F;
    }
    else if(tipo==2 && litros<50){
        Precio_F=litros*1500+1000;
        return Precio_F;
    }
    else if(tipo==2 && litros>=50){
        Precio_F=litros*1500+1100;
        return Precio_F;
    }
    return Precio_F;
}

void buscar_Mireya(string vec[],float vec2[],float vec3[]){
    int i=0;
    string m;
    char band= 'F';
    
    while((band=='F') && (i<30)){  //ciclo para comparar todos los nombres de las vacas con el nombre Mireya
        m=vec[i];
        m.resize(6);   //este resize es para eliminar la última letra de los datos del vector nombre
        if(m=="Mireya"){
            band='V';
            cout<<endl<<"La vaca Mireya tuvo una produccion de: "<<vec2[i]<<" litros y una venta total de: "<<vec3[i]<<endl;
        }
        i++;
    }
    if(band=='F'){
        cout<<"La vaca Mireya no se encuentra"<<endl;
    }
   
    
}