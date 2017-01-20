#include "Video.h"

Video::Video(unsigned int duree,string nomVideo, string nomPathVideo): Omultimedia(nomVideo,nomPathVideo)
{
    //ctor
    this->duree=duree;
}

Video::~Video()
{
    //dtor
cout<<"destructeur video"<<endl;

}

unsigned int Video:: getDuree() const{
return duree;
}
void Video::setDuree (unsigned int duree){
this->duree=duree;
}
/**
  * @brief Video::afficherObjet
  * @param s
  */
 void Video::afficherObjet(ostream &s) const{
    s<< "nom Video:"<<' '<< getObjectName()<<" path Video: "<< getObjectPathname()<< endl;
}

 /**
 * @brief Video::jouerObjet
 * @param nomObjet : Nom de l'objet à jouer. Nom photo ou nom de la video
 * @param path emplacement de l'objet
 */
void Video:: jouerObjet(string nomObjet, string path)const{
  string cmd = "mpv "+ path + nomObjet + " &";
  system(cmd.c_str());
}
