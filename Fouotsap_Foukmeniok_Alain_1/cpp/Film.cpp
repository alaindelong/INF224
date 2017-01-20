#include "Film.h"
#include <stdlib.h>
Film::Film(int numChapitre,string nomFilm,string pathFilm): Video(numChapitre,nomFilm,pathFilm)
{
    //ctor
    int i;
    this->numChapitre=numChapitre;

    tab = new int[numChapitre];

    for(i=0;i<numChapitre;i++){

       tab[i]=0;
    }

}

Film::Film(int *vet,int N,string nomFilm,string pathFilm):Video(N,nomFilm,pathFilm)
{

tab = new int[N];
numChapitre=N;
int i;
for(i=0;i<N;i++)

   tab[i]=vet[i];
}

Film::~Film()
{
    //dtor
    libererMemoire();

}

int Film:: getNombreChapitre()const{
return numChapitre;
}
int* Film:: getTableauDuree() const{
return tab;
}

void Film:: setNombreChapitre(int numChapitre){
    this->numChapitre=numChapitre;
}

 void Film:: setTableauDuree(const int *vet,int N){
     int i;
     delete[]tab;
     tab=new int[N];
     for(i=0;i<N;i++){
        tab[i]=vet[i];
     }
 }

void Film::afficherDureeChapitre(ostream &s)const{
int i,*vet;

for(i=0;i<getNombreChapitre();i++){
    s<< "methode afficher duree chapitre object Film "<< endl;
    vet=getTableauDuree();
    s<< vet[i]<<' '<< endl;
}
s<< endl;
}

 void Film:: libererMemoire(){
delete(getTableauDuree());

}
