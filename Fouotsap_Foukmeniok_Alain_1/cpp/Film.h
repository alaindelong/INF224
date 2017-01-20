#ifndef FILM_H
#define FILM_H
#include <string>
#include "Video.h"
using namespace std;
/**
 * @brief The Film class sous classe de Video
 */
class Film : public Video
{
   private:
       // int* tab;
        int numChapitre;
        int *tab;

    public:
        Film(int numChapitre,string nomFilm,string pathFilm);

        Film(int *vet,int N,string nomFilm,string pathFilm);

        virtual ~Film();

        virtual int getNombreChapitre()const;

        virtual int* getTableauDuree() const;

        virtual void setNombreChapitre(int numChapitre);

        virtual void setTableauDuree(const int *vet,int N);

        virtual void afficherDureeChapitre(ostream &s)const;

        virtual void libererMemoire();


};
#endif // FILM_H
