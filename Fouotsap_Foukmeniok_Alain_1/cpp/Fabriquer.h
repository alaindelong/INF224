#ifndef FABRIQUER_H
#define FABRIQUER_H
#include "Groupe.h"
#include "Omultimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include <map>
#include <memory>
#include "tcpserver.h"

using namespace cppu;

//const int PORT = 3331;

typedef shared_ptr <Groupe> GroupePtr;
typedef shared_ptr<Photo>PhotoPtr;
typedef shared_ptr<Video>VideoPtr;
typedef shared_ptr<Film>FilmPtr;

/**
 * @brief The Fabriquer class c'est la classe principale de notre serveur,elle permet de créer des objets multimedia,de créer des groupes d'objets, de les supprimer, de les jouer, de les afficher
 * et de les jouer
 */
class Fabriquer
{
private:
    map <string,GroupePtr> tabGroupe;
    map <string,OmultimediaPtr> tabObjet;

public:
    Fabriquer();

    /**
     * @brief creerPhoto cree un objet photo
     * @param lat hauteur de l'objet
     * @param lon largeur de l'objet
     * @param nomPhoto nom de la photo dans le repertoire
     * @param pathPhoto chemin du repertoire contenant la photo
     * @return retourne un pointeur vers l'objet crée
     */
    PhotoPtr creerPhoto(int lat,int lon,string nomPhoto,string pathPhoto);
    /**
     * @brief creerVideo cree un objet video
     * @param duree duree de l'objet
     * @param nomvideo nom de la video dans le repertoire
     * @param pathVideo chemin du repertoire contenant la video
     * @return retourne un pointeur vers l'objet crée
     */

    VideoPtr creerVideo(int duree,string nomvideo,string pathVideo);
    /**
     * @brief creerFilm cree un objet film
     * @param numchap définit le nombre de chapitres
     * @param nomfilm nom de l'objet film crée
     * @param pathFilm chemin du repertoire contenant le film
     * @return retourne un pointeur vers l'objet crée
     */

    FilmPtr creerFilm(int numchap,string nomfilm,string pathFilm);
    /**
     * @brief creerGroupe cree un objet groupe
     * @param nomgroupe nom de l'objet groupe
     * @return retourne un pointeur vers le premier élément de la liste(groupe)
     */

    GroupePtr creerGroupe(string nomgroupe);
    /**
     * @brief supprimerObjet supprime un objet de la table d'objet et de tous les groupes qui le contiennent
     * @param nomObjet nom de l'objet à supprimer
     */

    void supprimerObjet(string nomObjet);
    /**
     * @brief supprimerGroupe supprime un groupe de la table contenant les groupes
     * @param nomGroupe nom du groupe à supprimer
     */

    void supprimerGroupe(string nomGroupe);
    /**
     * @brief rechercherObjet recherche un objet dans la table d'objets et affiche ses attributs(nom de l'objet et le path du repertoire)
     * @param nomObjet nom de l'objet à rechercher
     * @return retourne un pointeur vers l'objet s'il existe sinon retourne nullptr
     */

    OmultimediaPtr rechercherObjet(string nomObjet)const;
    /**
     * @brief rechercherGroupe recherche un groupe dans la table des groupes et affiche tous les éléments du groupe
     * @param nomGroupe nom du groupe
     * @return retourne un pointeur vers le premier élément du groupe(la tête de la liste)
     */

    GroupePtr rechercherGroupe(string nomGroupe)const;
    /**
     * @brief jouerObjet joue un objet multimedia
     * @param nomObjet nomde l'objet multimedia à jouer (photo ou video)
     */

    void jouerObjet(string nomObjet) const;
    /**
     * @brief processRequest fonction qui gère la connexion chaque fois qu'un client se connecte: peut rechercher un objet multimedia ou un groupe d'objets à partir du nom, peut aussi jouer un objet
     * @param cnx
     * @param request est la requête du client
     * @param response est la réponse du serveur suite à la requête du client
     * @return true dans le cas où le client se connecte correctement et false dans le cas contraire
     */

    bool processRequest(TCPConnection& cnx, const string& request, string& response);


};

#endif // FABRIQUER_H
