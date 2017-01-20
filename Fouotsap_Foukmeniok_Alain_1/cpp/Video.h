#ifndef VIDEO_H
#define VIDEO_H
#include "Omultimedia.h"

/**
 * @brief The Video class sous classe d'objet multimedia
 */
class Video: public Omultimedia
{
    private:
    unsigned int duree;
    public:
        Video(unsigned int duree,string nomVideo,string nomPathVideo);

        virtual ~Video();

       unsigned int getDuree() const;

       void setDuree(unsigned int duree);
       /**
         * @brief afficherObjet affiche les attributs d'un objet video(nom de l'objet et le chemin d'accès)
         * @param s
         */
        void afficherObjet(ostream &s) const override;

        void jouerObjet(string nomObjet, string path) const override;

};

#endif // VIDEO_H
