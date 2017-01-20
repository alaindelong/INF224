#include "Photo.h"

Photo::Photo(unsigned int latitude, unsigned int longitude, string nomPhoto,string pathPhoto): Omultimedia(nomPhoto,pathPhoto)
{
    //ctor
    this->latitude = latitude;
    this->longitude = longitude;
}

Photo::~Photo()
{
    //dtor
cout<<"destructeur photo"<<endl;

}

unsigned int Photo::getLatitudePhoto() const{
return latitude;
}
unsigned int Photo::getLongitudePhoto() const{
    return longitude;
}
void Photo::setLatitudePhoto(unsigned int latitude){
    this->latitude=latitude;
}
void Photo::setLongitudePhoto(unsigned int longitude){
    this->longitude=longitude;
}
void Photo:: afficherObjet(ostream &s) const{
    s <<"nom photo: "<<getObjectName()<<" path Photo: "<< getObjectPathname()<< endl;


}
 void Photo:: jouerObjet(string nomObjet,string path)const{
 string cmd = "imagej "+path+nomObjet+" &";
 system(cmd.c_str());
}
