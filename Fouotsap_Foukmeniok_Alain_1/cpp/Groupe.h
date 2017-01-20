#ifndef GROUPE_H
#define GROUPE_H
#include <list>
#include <string>
#include "Omultimedia.h"
#include <memory>

typedef shared_ptr <Omultimedia> OmultimediaPtr;

//class Groupe : public list <Omultimedia*>
/**
 * @brief The Groupe class sous classe de list<objet multimedia>
 */

class Groupe : public list <OmultimediaPtr>
{

private:
string groupName;
//Omultimedia* listMultimedia;

public:
    Groupe(string groupName);

    virtual string getGroupName() const;

    virtual void afficherAttributList(ostream &s) const;

    virtual ~Groupe();
};

#endif // GROUPE_H
