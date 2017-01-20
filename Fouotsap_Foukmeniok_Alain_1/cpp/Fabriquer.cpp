#include "Fabriquer.h"

#include <sstream>


Fabriquer::Fabriquer()
{
}
PhotoPtr Fabriquer ::creerPhoto(int lat,int lon,string nomPhoto,string pathPhoto){
    PhotoPtr photoPtr(new Photo(lat,lon,nomPhoto,pathPhoto));
    //OmultimediaPtr photoPtr(p);
    tabObjet[nomPhoto]=photoPtr;
    return photoPtr;
}

VideoPtr Fabriquer ::creerVideo(int duree, string nomvideo, string pathVideo){
    VideoPtr videoPtr(new Video(duree,nomvideo,pathVideo));
    //OmultimediaPtr videoPtr(v);
    tabObjet[nomvideo]=videoPtr;
    return videoPtr;
}

FilmPtr Fabriquer ::creerFilm(int numchap,string nomfilm,string pathFilm){
    FilmPtr filmPtr(new Film(numchap,nomfilm,pathFilm));

    //OmultimediaPtr filmPtr(f);

    tabObjet[nomfilm]=filmPtr;

    return filmPtr;
}

GroupePtr Fabriquer ::creerGroupe(string nomgroupe){

    GroupePtr groupPtr(new Groupe(nomgroupe));

   // GroupePtr groupPtr(g);

    tabGroupe[nomgroupe]=groupPtr;

    return groupPtr;
}

void Fabriquer ::supprimerObjet(string nomObjet){
    auto it=tabObjet.find(nomObjet);
    if(it!=tabObjet.end()){
        //it->second->afficherObjet(cout);      
        for(auto itg=tabGroupe.begin(); itg != tabGroupe.end(); ++itg){
            for(auto  et=itg->second->begin();et!=itg->second->end();){
                  auto k2 =et;
               ++k2;
                if((*et)==it->second){
                    itg->second->erase(et);
                    //cout<<"terminer avec succes111111************"<<endl;
                et=k2;
                }else
                    ++et;
            }
        }
       // tabObjet.erase(it);
        //cout<<"terminer avec succes************"<<endl;

    }else{
        auto it=tabGroupe.find(nomObjet);
        if(it!=tabGroupe.end())
            //it->second->afficherAttributList(cout);
            tabGroupe.erase(it);
        else cout<< "objet ou groupe non existent"<<endl;
    }

}

void Fabriquer :: supprimerGroupe(string nomGroupe){
    auto it=tabGroupe.find(nomGroupe);
    if(it!=tabGroupe.end())
    {
        it->second->afficherAttributList(cout);
        tabGroupe.erase(it);
    }else{
        cout<<"groupe non existent"<<endl;
    }
}

OmultimediaPtr Fabriquer ::rechercherObjet(string nomObjet)const{
    auto it=tabObjet.find(nomObjet);
    if(it!=tabObjet.end()){
        it->second->afficherObjet(cout);
        return it->second;
    }
    else{
        cout<<"objet non existent"<<endl;
        return NULL;}
}
GroupePtr Fabriquer ::rechercherGroupe(string nomGroupe)const{
    auto it=tabGroupe.find(nomGroupe);
    if(it!=tabGroupe.end()){
        it->second->afficherAttributList(cout);
        return it->second;
    }
    else{

        cout<<"groupe non existent"<<endl;
    return nullptr;}
}
void Fabriquer::jouerObjet(string nomObjet) const{
    auto it=tabObjet.find(nomObjet);
    if(it!=tabObjet.end())
        it->second->jouerObjet(it->second->getObjectName(),it->second->getObjectPathname());
}

/**
 * @brief Fabriquer::processRequest
 * @param cnx
 * @param request un exemple de requête "rechercher objet dschang.jpeg" ou bien "jouer objet videoinf224.webm" ou "rechercher groupe mygroupe"
 * @param response
 * @return
 */
bool Fabriquer::processRequest(TCPConnection& cnx, const string& request, string& response)
{
  cerr << "\nRequest: '" << request << "'" << endl;

  // 1) pour decouper la requête:
  // on peut par exemple utiliser stringstream et getline()
 OmultimediaPtr obj;
 GroupePtr gpr;
  stringstream ss(request);
  stringstream s;
  string s1,s2,s3;
  string  a;
  ss>>s1>>s2>>s3;

  // 2) faire le traitement:
  // - si le traitement modifie les donnees inclure: TCPLock lock(cnx, true);
  // - sinon juste: TCPLock lock(cnx);
if (s1.compare("rechercher")==0){

    if(s2.compare("objet")==0){
        obj=rechercherObjet(s3);
        if(obj!=nullptr)
        response="attribut objet-->> nom objet "+s3+" path objet "+obj->getObjectPathname();
        else
            response="objet non existent";
    }else{
        if(s2.compare("groupe")==0){
            gpr=rechercherGroupe(s3);
            if(gpr!=nullptr){
            gpr->afficherAttributList(s);
            response="attribut element groupe rechercher ";
            while(getline(s,a)!=NULL)
           response.append(a);
              } else
            response="groupe non existent";
        }
        else{
            response="recherche non valide";
        }
    }
}
  else{
    if(s1.compare("jouer")==0){
        jouerObjet(s3);
    }else{
        response="rechercher non valide aucune option";
    }
}
s.str("");
  // 3) retourner la reponse au client:
  // - pour l'instant ca retourne juste OK suivi de la requête
  // - pour retourner quelque chose de plus utile on peut appeler la methode print()
  //   des objets ou des groupes en lui passant en argument un stringstream
  // - attention, la requête NE DOIT PAS contenir les caractères \n ou \r car
  //   ils servent à délimiter les messages entre le serveur et le client

  //response = "OK: "+s1 + s2;
  //cerr << "response: " << response << endl;

  // renvoyer false si on veut clore la connexion avec le client
  return true;
}
