#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Album{
public:
  void CompraSobre(int n_en_sobre);
  void Status(void);
  Album(int n);
  bool esta_lleno(void);
  int Comprados(void);
  bool Esta_l(int lamina);
  
private:
  int n_total;
  int n_repetidas;
  int n_en_album;
  int n_sobres_comprados;
  
  int *album;
  int *repetidas;
};

void Album::Status(void){
  cout << n_en_album << " "<<n_repetidas << endl;
}

bool Album::esta_lleno(void){
  if(n_total == n_en_album){
    return true;
  }
  else{
    return false;
  }

}

void Album::CompraSobre(int n_en_sobre){
  int lamina;
  for(int i=0;i<n_en_sobre;i++){
    lamina = rand()%n_total;
    if(album[lamina]==0){
      album[lamina] = 1;
      n_en_album++;
    }else{
      repetidas[lamina] +=1;
      n_repetidas++;
    }
  }
  n_sobres_comprados++;
}

int Album::Comprados(void){
  return n_sobres_comprados;
}

Album::Album(int n){
  album = new int[n];
  repetidas = new int[n];
  n_total = n;
  n_repetidas = 0;
  n_en_album = 0 ;
  n_sobres_comprados = 0;
  for (int i=0;i<n_total;i++){
    album[i] = 0;
    repetidas[i] = 0;
  }
}



bool Album::Esta_l(int lamina){
  if(album[lamina]==0){
    return false;
  }
  else{
    return true;
  }
}



int main(){
  srand(time(0));
  Album A(669);
  while(!A.esta_lleno()){
    A.CompraSobre(5);  
  }
  cout << A.Comprados() << endl;
  
}
