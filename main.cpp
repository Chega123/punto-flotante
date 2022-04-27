#include <iostream>
using namespace std;
int* convertir_bit_float(int bin[],float num,int largo_cad){
  int convertir=num;
  for(int i=largo_cad-1; i>=0;i--){
    bin[i]=convertir%2;
    convertir=convertir/2;
  }
  return bin;
}


int* convertir_bit_decimales_float(int bin[], float num,int largo_cad){
  int numero_int=num;
  float resta_float =numero_int;
  resta_float=num-resta_float;
  for(int i=0; i<largo_cad;i++){
    resta_float*=2;
    if(resta_float>=1.00){resta_float-=1.0;bin[i]=1;}
    else if(resta_float<1.00){bin[i]=0;}
  }
  return bin;
}


int* convertir_bit_double(int bin[],double num,int largo_cad){
  int convertir=num;
  for(int i=largo_cad-1; i>=0;i--){
    bin[i]=convertir%2;
    convertir=convertir/2;
  }
  return bin;
}


int* convertir_bit_decimales_double(int bin[], double num,int largo_cad){
  int numero_int=num;
  float resta_float =numero_int;
  resta_float=num-resta_float;
  for(int i=0; i<largo_cad;i++){
    resta_float*=2;
    if(resta_float>=1.00){resta_float-=1.0;bin[i]=1;}
    else if(resta_float<1.00){bin[i]=0;}
  }
  return bin;
}


void punto_flotante_float(float num) { 
  int  signo;
  int* exponente,significando;
  int expo_2=1,exp=2;
  bool bucle=true;
  //parte signo
  if (num>=0){signo=0;}
  if (num<0){signo=1;}
  //Parte exponente
  while (bucle == true){
    if(num>=exp){exp*=2; expo_2+=1;}
    if(num<exp){bucle=false;}
  }
  int num_binario[expo_2];
  int almacen_decimales[23];
  int* entero =convertir_bit_float(num_binario, num,expo_2);
  int* decimales=convertir_bit_decimales_float(almacen_decimales,num,23);
  expo_2-=1;
  float numero_exp=127+expo_2;
  int exponente_almacen[8];
  exponente=convertir_bit_float( exponente_almacen, numero_exp,8);
  // Parte significando
  int almacen_significando[23];
  for (int k=0;k<24;k++){
    almacen_significando[k]=0;}
  int count=0;
  for(int j=0;j<expo_2;j++){
    almacen_significando[j]=entero[j+1]; 
        count+=1;
    }
  for(int l=count,l_2=0;l<24;l++,l_2++){
    almacen_significando[l]= decimales[l_2];}
  cout<<"signo(float): "<<signo<<endl;
  cout<<"exponente(float): ";
  for (int i=0;i<8;i++){cout<< exponente[i];}

  cout<<endl<<"significando(float): ";
   for (int i=0;i<24;i++){cout<<almacen_significando[i];}
  cout<<endl;
}



void punto_flotante_double(double num) { 
  int  signo;
  int* exponente,significando;
  int expo_2=1,exp=2;
  bool bucle=true;
  //parte signo
  if (num>=0){signo=0;}
  if (num<0){signo=1;}
  //Parte exponente
  while (bucle == true){
    if(num>=exp){exp*=2; expo_2+=1;}
    if(num<exp){bucle=false;}
  }
  int num_binario[expo_2];
  int almacen_decimales[52];
  int* entero =convertir_bit_double(num_binario, num,expo_2);
  int* decimales=convertir_bit_decimales_double(almacen_decimales,num,52);
  expo_2-=1;
  double numero_exp=1023+expo_2;
  int exponente_almacen[11];
  exponente=convertir_bit_double(exponente_almacen, numero_exp,11);
  // Parte significando
  int almacen_significando[52];
  for (int k=0;k<53;k++){
    almacen_significando[k]=0;}
  int count=0;
  for(int j=0;j<expo_2;j++){
    almacen_significando[j]=entero[j+1]; 
        count+=1;
    }
  for(int l=count,l_2=0;l<53;l++,l_2++){
    almacen_significando[l]= decimales[l_2];}
  cout<<"signo(double): "<<signo<<endl;
  cout<<"exponente(double): ";
  for (int i=0;i<11;i++){cout<< exponente[i];}
  cout<<endl<<"significando(double): ";
   for (int i=0;i<53;i++){cout<<almacen_significando[i];}
  cout<<endl;  
}



int main() {
    float numero; 
    cout << "inserte un numero float"<<endl;
    cin >>numero;
    double numero_2; 
    cout << "inserte un numero double"<<endl;
    cin >>numero_2;
    cout<<endl<<"float"<<endl;
    punto_flotante_float(numero);
    cout<<endl<<"double"<<endl;
    punto_flotante_double(numero_2);
    cout<<endl<<"float to double"<<endl;
    punto_flotante_double(numero);
}
