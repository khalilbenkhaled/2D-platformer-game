/**
* @file ES.c
* @brief source file de l'ES.
* @author Khalil Ben Khaled
* @version 0.01
* @date Apr 01, 2021
*
* fonctions pour l'entite secondaire *
*/

#include "struct.h"


/**
* @brief pour initialiser l'ennmi e.
* @param e l'ennmi
* @return Nothing
*/

void initEnnemi(ES*e)
{
  (*e).sheet=IMG_Load("ennemi_spr.png");

  (*e).posSprite.x=0;
  (*e).posSprite.y=0;
  (*e).posSprite.w=400/4;
  (*e).posSprite.h=400/4;



  (*e).position.x=POS_INITIALE_X; //POSITION INITIALE
  (*e).position.y=POS_INITIALE_Y;	//INITIALE


  (*e).etat=WAITING;
}
/**
* @brief pour afficher l'ennmi e .
* @param scren le "screen"
* @param e l'ennemi
* @return Nothing
*/

void afficherEnnemi(ES e, SDL_Surface * screen)
{
  SDL_BlitSurface(e.sheet,&e.posSprite,screen,&e.position);

}
/**
* @brief pour animer l'ennmi e .
* @param e l'ennemi
* @return Nothing
*/

void animerEnnemi( ES * e)
{
  if (e->etat==FOLLOWING)
  {
    if ((*e).direction==RIGHT)
    (*e).posSprite.y=0;
    else if ((*e).direction==LEFT)
    (*e).posSprite.y=100;
  }
  else if (e->etat==ATTACKING){
    if ((*e).direction==RIGHT)
    (*e).posSprite.y=200;
    else if ((*e).direction==LEFT)
    (*e).posSprite.y=300;
  }
  else if (e->etat==WAITING){
    (*e).posSprite.y=0;
  }



    if ((*e).posSprite.x==400-(*e).posSprite.w)
      (*e).posSprite.x=0;
    else
      (*e).posSprite.x = (*e).posSprite.x + (*e).posSprite.w;

}

/**
* @brief pour deplacer l'ennmi e .
* @param e l'ennemi
* @return Nothing
*/

void deplacerES( ES * e)
{

  if ((*e).direction==RIGHT)
    (*e).position.x++;
  else if ((*e).direction==LEFT)
    (*e).position.x--;
}


/**
* @brief pour detecter la collision entre l'ennemi et l'hero du jeu .
* @param e l'ennemi
* @param p l'hero
* @return 0 s'il n'y a pas de collision 1 s'il y as
*/


int collisionBB( perso p, ES e)
{


  if ((p.position.x + p.posSprite.w< e.position.x) || (p.position.x> e.position.x + e. posSprite.w) || (p.position.y + p.posSprite.h< e. position.y) || (p.position.y> e. position.y + e. posSprite.h ))
    return 0;
  else
    return 1;



}


/**
* @brief IA qui change les conditions du deplacement de l'ennemi
* @param e l'ennemi
* @param posPerso la position l'hero
* @return nothing
*/

void deplacerIA(ES *e,SDL_Rect posPerso)
{
    int d=e->position.x-posPerso.x;
int s1=400; //A CHANGER ///////////////////////////////
int s2=200; // A CHANGER /////////////////////////////////////
switch(e->etat){
    case WAITING:
        if (d>s1) e->etat=WAITING;
        else if (d>s2&&d<=s1) e->etat=FOLLOWING;

        else if (d<=0&&d>=-s1) e->etat=FOLLOWING;
            break;
    case FOLLOWING:
        if (s2<d&&d<=s1) e->etat=FOLLOWING;
        else if (d>0&&d<=s2) e->etat=ATTACKING;
        else if (d>s1) e->etat=WAITING;
        else if (d<0 &&d<-s1) e->etat=WAITING;
        else if (d<=0&&d>=-s2) e->etat=ATTACKING;
            break;
    case ATTACKING:
        if (d>0&&d<=s2 || d<=0&&d>=-s2) e->etat=ATTACKING;
        else if (d>=0&&d>s2) e->etat=FOLLOWING;
        else if (d<=0&&d>=-s1) e->etat=FOLLOWING; // ou ATTACKING
            break;
    }
    if (e->etat!=WAITING){
    if (d>=0) e->direction=LEFT;
    else if (d<0) e->direction=RIGHT;
        deplacerES(e);
}
else e->direction=-1;
}







/*
SDL_Surface * SDL_initialize(  int largeur, int hauteur)
{

SDL_Init(SDL_INIT_VIDEO |SDL_INIT_AUDIO);	// video/audio initialisation

    if (SDL_Init(SDL_INIT_VIDEO)!=0)		//check for video error
    {
        printf("\n erreur init du video: %s",SDL_GetError());
        SDL_Quit();
        EXIT_FAILURE;
    }
    else if (SDL_Init(SDL_INIT_AUDIO)!=0)	//check for sound error 1
    {
	printf("SDL sound erreur: %s\n", SDL_GetError());
        SDL_Quit();
        EXIT_FAILURE;
    }


Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );	//more sound initialisation


     if(Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 )!=0) 	// //check for sound error 2
 	{
        printf("SDL Sound erreur: %s\n", Mix_GetError());
        Mix_CloseAudio();
        SDL_Quit();
        EXIT_FAILURE;
    	}

TTF_Init();	//text initialisation
	if (TTF_Init()!=0)	//checking for text error
	{
        printf("SDL Sound erreur: %s\n", Mix_GetError());
        Mix_CloseAudio();
        SDL_Quit();
        EXIT_FAILURE;
    	}

    SDL_Surface *screen=NULL; 	// window initialisation
    screen= SDL_SetVideoMode(largeur,hauteur,0,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
    if (screen==NULL)	//checking for window errors
    {
        printf("\n erreur init du screen: %s",SDL_GetError());
        EXIT_FAILURE;
    }



}
*/
