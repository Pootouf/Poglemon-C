#ifndef POGLEMON_H_INCLUDED
#define POGLEMON_H_INCLUDED

#include <SDL.h>
#include <string>
#include <SDL_ttf.h>

class Poglemon
{

    private:

    int IDPog;
    int hp;
    int hpTotal;
    int atk;
    int speatk;
    int def;
    int spedef;
    int vitesse;
    int niveau;
    int xpNiveau;
    int xpactuel;
    int type1;
    int type2;
    int numeroPog;
    int progressionXP;
    bool isInit;
    int attaqueid[4];
    int attaquepprestant[4];

    SDL_Texture* texturePog;


    public:

    std::string name;

    Poglemon(SDL_Renderer* pRenderer, int ID_pog, std::string namePog, int niveauPog, bool newPog);
    //Renvoie la variable isInit
    bool exist();
    //Initialise un pokemon qui n'existe pas encore en lui donnant ses statistiques ainsi que sa texture
    void Init(SDL_Renderer* pRenderer, int ID_pog, std::string namePog, int niveauPog);
    //D�finit les stats et les attaques d'un poglemon en fonction de son niveau, qu'il soit nouveau ou pas.
    void MonteeNiveau(int niveauPog);
    //permet d'afficher les informations d'un poglemon dans un rectangle de la taille de celui du menu Equipe
    void AffichePogEquipe(int numPog, int resolutionecranx, int resolutionecrany, SDL_Renderer* pRenderer);
    //Reinitialise la texture d'un poglemon
    void Reset(SDL_Renderer* pRenderer);
    //Appelle la fonction affichepoglemonstats puis ferme le menu si une touche est press�e
    void PoglemonStats(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany);
    //Affiche le menu poglemon stats
    void AffichePoglemonStats(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany);
    //Detruit le poglemon si celui ci existe
    void destructeurPoglemon();
    //Sauvegarde le poglemon dans un fichier
    void save(FILE* fichier);
    //Charge le poglemon dans fichier
    void chargement(SDL_Renderer* pRenderer, FILE* fichier);
    //Change le nom du poglemon
    void changementNom(char newName[]);
    //Afiche la texture du poglemon si elle existe
    void AffichePoglePC(SDL_Renderer* pRenderer, int positionx, int positiony, int resolutionecranx, int resolutionecrany);
    //Affiche la texture du poglemon dans un combat
    void AffichePogCombat(bool joueur, int resolutionecranx, int resolutionecrany, SDL_Renderer* pRenderer);
    //Affiche les diff�rentes attaques du poglemon en combat
    void AfficheAttaqueCombat(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany);
    //Affiche le nom, le niv et la vie du poglemon � des endroits diff�rents en fonction de la variable joueur. Si elle est v�rifi�e, une barre d'xp sera rajout� egalement
    void AfficheNomCombat(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, bool joueur);
    //Renvoie la vitesse
    int vitesseCombat();
    //Calcule le nombre de degat subit et enleve la valeur obtenu au hp. Si celle ci est inf�rieur � 0, hp est remis � 0
    void degat(int attaqueE, int puissance, int niveauE, bool physique);
    //Renvoie l'attaque
    int attaqueCombat();
    //Renvoie l'attaque spe
    int attaquespeCombat();
    //Renvoie le niveau
    int niveauCombat();
    //Renvoie la puissance de l'attaque
    int puissanceAttaque(int attaqueNum);
    //Renvoie la pr�cision de l'attaque
    int precisionAttaque(int attaqueNum);
    //Enleve des pp
    void enlevepp(int attaqueNum);
    //Rajoute des pp
    void rajoutepp(int attaqueNum);
    //Renvoie les pp
    int renvoiepp(int attaquenum);
    //Renvoie l'id de l'attaque
    int renvoieid(int attaquenum);
    //Renvoie true si l'attaque est physique, false sinon
    bool estphysique(int attaquenum);
    //Renvoie true si le poglemon est ko, false sinon
    bool estko();
    //Ajoute de l'xp au poglemon et permet de monter de niveau
    void gainXp(int basexpE, int niveauE, int resolutionecranx, int resolutionecrany, SDL_Renderer* pRenderer, int divPog);
    //Renvoie la basexp du poglemon
    int renvoiebasexp();
    //Renvoie le nom du poglemon
    std::string renvoienompog();
    //Renvoie le nom de l'attaque
    std::string renvoienomattaque(int attaquenum);
    //Soigne le poglemon
    void soin();

};

//Permet de cr�er un nouveau poglemon dans l'equipe. Essaye de le cr�er � la premiere position si celle ci est libre, sinon essaye � la suivante jusqu'� la sixieme position.
void newPoglemon(Poglemon* poglemon1, Poglemon* poglemon2, Poglemon* poglemon3, Poglemon* poglemon4, Poglemon* poglemon5, Poglemon* poglemon6, Poglemon *pc[960], SDL_Renderer* pRenderer, int IDPog, std::string name, int niv);

//Permet d'afficher un texte � une position donn�e avec la police d'�criture donn�e en parametre
void affichageTexte(TTF_Font* font, std::string texture, SDL_Renderer* pRenderer, int positionx, int positiony);

//Permet d'afficher une barre de vie ou d'xp
void affichageBarre(std::string nomBarreVide, std::string nomBarrePleine, SDL_Renderer* pRenderer, int positionx, int positiony, int valeurMax, int valeurActuelle, int resolutionecranx, int resolutionecrany);

#endif // POGLEMON_H_INCLUDED
