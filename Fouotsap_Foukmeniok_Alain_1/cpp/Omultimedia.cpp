#include "Omultimedia.h"
#include <string>
#include <iostream>


Omultimedia::Omultimedia(){
    this->object_name=nullptr;
    this->object_pathname=nullptr;
}


Omultimedia::Omultimedia(string object_name,string object_pathname){
    this->object_name=object_name;
    this->object_pathname=object_pathname;
}

 void Omultimedia::setObjectName(string object_name){
    this->object_name=object_name;
}

 void Omultimedia::setObjectPathname(string object_pathname){
    this->object_pathname=object_pathname;
}

 string Omultimedia::getObjectName() const{
    return object_name;
}

 string Omultimedia::getObjectPathname()const{
    return object_pathname;
}
 Omultimedia::~Omultimedia(){

 }
 /**
  * @brief Omultimedia::afficherObjet
  * @param s flux de sortie(file,console,buffer de texte)
  */
 void Omultimedia::afficherObjet(ostream &s) const
 {
   s << this->getObjectName()<<"  "<< this->getObjectPathname() << endl;
 }

   /*void Omultimedia:: jouerObjet(string str1,string str2) const {
       cout<<str1+str2<<endl;
   }*/
