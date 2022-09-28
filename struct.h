#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
//////////// MENU ////////////:

typedef struct //+-zeyda
{
	SDL_Surface * nom;
	SDL_Rect position;
}image;

typedef struct
{
//image

SDL_Surface* nom[2];
SDL_Rect position;
//son
Mix_Chunk* sf[2];
//text
TTF_Font* police;
SDL_Surface* texte;
SDL_Color color;
SDL_Rect positionTexte;

int etat;
int etatSon;

}bouton;


void bouton_initialize(int menu,bouton B[][50],int taille[3],char* location0,char* location1,int posX,int posY,char* texte,int posXTexte,int posYTexte,char* locationFont,int tailleText,int color1,int color2,int color3,char* music);
void afficher(SDL_Surface* screen,bouton B[][50],int taille[3],int menu);

image image_initialize(char* destination,int posX,int posY);
void Events_Handler(int *menu,bouton B[][50],int taille[3],int* check,int* loop,SDL_Surface* screen,int* move,int* volume_lvl, int* btn,int* init);

int CheckMousePosition(int check,int MouseX,int MouseY,int StartX,int StartY,int EndX,int EndY);


//////////////////////////////////////////////////MENU


typedef struct
{
	SDL_Surface * sheet,*photo_vie,*photo_score;
	SDL_Rect position;
    SDL_Color Noir;
    TTF_Font *police;

  SDL_Rect posSprite,position_vie,position_score;
  int direction; // 0 RIGHT 1 LEFT
  int score,vie;
  double vitesse,acceleration;

  int saut; //1 montant 2 desc

}perso;



void initPerso(perso *p);
void afficherPerso(perso p, SDL_Surface * screen);
void animerPerso( perso * p);
void deplacer( perso *p,Uint32 dt);
void sauter( perso *p,Uint32 dt,int fond);



SDL_Surface * SDL_initialize( int largeur, int hauteur);

//ES///////////////////////////////////////////////////////////////////////

#define WAITING 0
#define FOLLOWING 1
#define ATTACKING 2


#define RIGHT 0
#define LEFT 1

#define POSMAX 5830
#define POSMIN 3630

#define POS_INITIALE_X 600
#define POS_INITIALE_Y 450
/*
#define POSMAX 500
#define POSMIN 0

#define POS_INITIALE_X 500
#define POS_INITIALE_Y 400*/


typedef struct
{
	SDL_Surface * sheet;
	SDL_Rect position;
  SDL_Rect posSprite;
  int direction; // 0 RIGHT 1 LEFT
  int etat;
}ES;






void initEnnemi(ES *e);
void afficherEnnemi(ES e, SDL_Surface * screen);
void animerEnnemi( ES * e);
void deplacerIA(ES *e,SDL_Rect posPerso);
void deplacerES( ES * e);
int collisionBB( perso p, ES e);

/////////////////////////ENIGME/////////////////////////////:

typedef struct
{
    char question[50],rep1[50],rep2[50],rep3[50],rep[50];
    SDL_Surface* q, *r1, *r2, *r3;
    SDL_Rect posQ,posR1,posR2,posR3;
    TTF_Font* police;
    SDL_Color Noir;

    SDL_Surface* taswira;
    SDL_Rect pos_taswira;

}enigme;



void generer (enigme* e, char *nomficher1,char *nomficher2,char *nomficher3);
void afficherEnigme(enigme e, SDL_Surface * screen);
int charger ( perso * p, char * nomfichier);
void sauvegarder (perso p, char * nomficher);



///////////////////////////minimap////////////////////////////////////////////////

typedef struct
{
	SDL_Surface* mini;
	SDL_Rect pos_mini;
	SDL_Surface* joueur ;
	SDL_Rect pos_joueur;

}minimap;

typedef struct
{
	Uint32 start;
	TTF_Font *font;
	SDL_Surface *seconds;
	SDL_Color textColor;
	char timeshown[100];
	SDL_Rect pos_temps;

}temps;

void initminimap(minimap *m);
// void MAJMinimap(SDL_Rect posJoueur,  minimap * m, SDL_Rect camera, int redimensionnement);
void affichermini (minimap m, SDL_Surface * screen);
void Initemps(temps *t);
temps affichertemps(temps t,SDL_Surface* screen);
SDL_Color GetPixel(SDL_Surface* pSurface ,int x,int y);
int collisionPP( SDL_Rect person, SDL_Surface * Masque);


/////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////// TACHE BACKGROUND /////////////////////////:
typedef struct background{

	SDL_Surface *afficher_background;
	SDL_Rect pos_background;
	SDL_Rect pos_background2;
	SDL_Surface *calque_background;
}background;

void init_background(background *bckg);
void afficher_background(background bckg,SDL_Surface *screen);
void scrolling (perso test,background *b,int pas);
