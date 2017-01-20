#ifndef PHOTO_H
#define PHOTO_H
#include <string>
#include "Omultimedia.h"
using namespace std;

/**
 * @brief The Photo class sous classe d'objet multimedia
 */
class Photo : public Omultimedia
{


    private:
        unsigned int latitude;
        unsigned int longitude;
    public:
        Photo(unsigned int latitude,unsigned int longitude,string nomPhoto,string pathPhoto);
        virtual ~Photo();

        unsigned int getLatitudePhoto() const;

        unsigned int getLongitudePhoto() const;

        void setLatitudePhoto(unsigned int latitude);

        void setLongitudePhoto(unsigned int longitude);

        void afficherObjet(ostream &s) const override;

        void jouerObjet(string nomObjet,string path) const override;

};
#endif // PHOTO_H
