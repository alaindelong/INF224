#include <iostream>
#include "Omultimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Groupe.h"
#include "Fabriquer.h"
#define N 4

const int PORT = 3331;
int main()
{
     //Omultimedia* m = new Omultimedia("mon nom", "mon chemin");
        //m->afficherObject(cout,m);
       // Photo *p=new Photo(10,10,"dschang.jpeg","/cal/homes/fouotsap/inf224/");

        //Omultimedia*m=p;
       // p->afficherObjet(cout);
        //p->jouerObjet(p->getObjectName(),p->getObjectPathname());
        //p->jouerObjet(cout,p->getObjectName()+p->getObjectPathname());
      // Video *v=new Video(10,"videoinf224.webm","/cal/homes/fouotsap/inf224/");
        //v->afficherObjet(cout);
        //v->jouerObjet(v->getObjectName(),v->getObjectPathname());
       // v->jouerObjet(cout,v->getObjectName()+v->getObjectPathname());
       // Groupe *g=new Groupe("g_foto");
       // Groupe *g1=new Groupe("groupe2");

       /* OmultimediaPtr p1(p), p2(v);
        g->push_back(p1);

        g->push_back(p2);

        g1->push_back(p2);

        g1->push_back(p1);

        g->afficherAttributList(cout);

        g1->afficherAttributList(cout);

        g->pop_back();
        g1->pop_front();*/
       //p->~Photo();

        //delete v;
        //delete g;


       /* int i,count=0;
        Omultimedia**vet=new Omultimedia*[2];
        vet[count++]=new Photo(10,10,"dschang.jpeg","/cal/homes/fouotsap/inf224/");
        vet[count++]=new Video(10,"videoinf224.webm","/cal/homes/fouotsap/inf224/");

        for(i=0;i<2;i++){
            vet[i]->afficherObjet(cout,vet[i]);
            vet[i]->jouerObjet(vet[i]->getObjectName(),vet[i]->getObjectPathname());
        }
       delete [] vet;*/

   /* int i,*vet,*b,*h;

    vet = new int[N];

      for(i=0;i<N;i++){
       vet[i]=i;
      }
       Film *f=new Film(vet,N,"nom film","path film");
       f->afficherDureeChapitre(cout);
       b=f->getTableauDuree();
        cout<<b[0]<<' '<<b[1]<<' '<<b[2]<<' '<<b[3]<<endl;
       for(i=0;i<N;i++){
           vet[i]=i+10;
       }
       f->setTableauDuree(vet,N);
       f->afficherDureeChapitre(cout);
       h=f->getTableauDuree();
       f->afficherObjet(cout);
       cout<<h[0]<<' '<<h[1]<<' '<<h[2]<<' '<<h[3]<<endl;
       //cout<<b[0]<<' '<<b[1]<<' '<<b[2]<<' '<<b[3]<<endl;
       for(i=0;i<N;i++){
           vet[i]=i+100;
       }
       b=f->getTableauDuree();
       cout<<b[0]<<' '<<b[1]<<' '<<b[2]<<' '<<b[3]<<endl;
       f->~Film();
       delete(f);*/
    // cree le TCPServer
    Fabriquer *f=new Fabriquer();

    shared_ptr<TCPServer> server(new TCPServer());

    // cree l'objet qui gère les données
    shared_ptr<Fabriquer> base(f);
    GroupePtr g=f->creerGroupe("mygroupe");
    GroupePtr g2=f->creerGroupe("groupe2");
    PhotoPtr p=f->creerPhoto(10,10,"dschang.jpeg","./");
    //Photo *p4=f->creerPhoto(10,10,"univ.jpeg","/cal/homes/fouotsap/inf224/Fouotsap_Foukmeniok_Alain/");
    PhotoPtr p2=f->creerPhoto(10,10,"ngui.jpeg","./");
    VideoPtr v=f->creerVideo(10,"videoinf224.webm","./");
    VideoPtr v1=f->creerVideo(10,"video2.webm","./");

    g->push_back(p);
    g->push_back(p2);
    g->push_back(v);
    g2->push_back(p);
    //g2->push_back(p5);
    g2->push_back(v1);
    // le serveur appelera cette méthode chaque fois qu'il y a une requête
    server->setCallback(*base, &Fabriquer::processRequest);

    // lance la boucle infinie du serveur
    cout << "Starting Server on port " << PORT << endl;
    int status = server->run(PORT);

    // en cas d'erreur
    if (status < 0) {
      cerr << "Could not start Server on port " << PORT << endl;
      return 1;
    }

   //f->rechercherGroupe("mygroupe");
  // cout<<"recherche groupe2"<<endl;
  // f->rechercherGroupe("groupe2");
  // p3=f->rechercherObjet("dschang.jpeg");
   //p3->afficherObjet(cout);
   //f->supprimerObjet("dschang.jpeg");

   //f->supprimerObjet("mygroupe");
   //f->rechercherGroupe("mygroupe");
    //f->jouerObjet("dschang.jpeg");
    //f->jouerObjet("videoinf224.webm");
    //f->rechercherGroupe("mygroupe");
   //f->supprimerGroupe("groupe2");
//f->rechercherGroupe("groupe2");
    //cout<< " le nom de mon groupe est "<<g->getGroupName()<<endl;
    //g->afficherAttributList(cout);
//cout<<"nothing"<<endl;
//delete(f);
    // cree le TCPServer

  return 0;
}
