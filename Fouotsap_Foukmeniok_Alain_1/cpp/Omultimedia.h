#ifndef OMULTIMEDIA_H
#define OMULTIMEDIA_H

#include <iostream>
#include <string>
using namespace std;
/**
 * @brief The Omultimedia class classe d'objet multimedia
 */
class Omultimedia
{
private:
    string object_name;
    string object_pathname;
public:
    Omultimedia();

    Omultimedia(string object_name,string object_pathname);

    virtual void setObjectName(string object_name);

    virtual void setObjectPathname(string object_pathname);

    virtual string getObjectName() const;

    virtual string getObjectPathname() const;

    virtual ~Omultimedia();

    virtual void afficherObjet(ostream &s) const = 0;
   // virtual void afficherObjetMultimedia(string object_pathname) const=0;
    /**
     * @brief jouerObjet joue un objet multimedia à partir de son nom et son path
     * @param nomObjet
     * @param path
     * c'est une méthode abstraite qui sera redéfinie dans chacune des sous classes
     */
    virtual void jouerObjet(string nomObjet, string path) const =0;
};

#endif // OMULTIMEDIA_H
