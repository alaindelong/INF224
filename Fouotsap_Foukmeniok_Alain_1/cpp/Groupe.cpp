#include "Groupe.h"
#include <iostream>
#include <list>


Groupe::Groupe(string groupName)
{

    this->groupName = groupName;
}

 string Groupe:: getGroupName() const{
     return groupName;
 }
 void Groupe:: afficherAttributList(ostream &s) const{
     s<<"éléments groupe: "<<getGroupName()<<endl;
   /*for(list<Omultimedia*>::const_iterator it=this->cbegin();it!=this->cend();++it){

      (*it)->afficherObjet(s);
   }*/
     for(list<OmultimediaPtr>::const_iterator it=this->cbegin();it!=this->cend();++it){

           (*it)->afficherObjet(s);
     }
 }

Groupe:: ~Groupe(){

}
