#include "struct.h"






void initPerso(perso *p)
{
  (*p).sheet=IMG_Load("sheet.png");
 (*p).photo_vie=IMG_Load("heart.png");

  (*p).posSprite.x=0;
  (*p).posSprite.y=0;
  (*p).posSprite.w=1440/8; 	//CHANGE
  (*p).posSprite.h=306/2;   //CHANGE




  (*p).position.x=0;
  (*p).position.y=400;

(*p).position_vie.x=900;
(*p).position_vie.y=0;

(*p).direction=-1;
(*p).vie=3;
(*p).score=0;


(*p).police=TTF_OpenFont("Roman.ttf",60);
	(*p).Noir.r=255;
	(*p).Noir.g=255;
	(*p).Noir.b=255;

(*p).position_score.x=1600;
(*p).position_score.y=0;

(*p).vitesse=400;
(*p).acceleration=0;

(*p).saut=0;



}


void afficherPerso(perso p, SDL_Surface * screen)
{


  SDL_BlitSurface(p.sheet,&p.posSprite,screen,&p.position);



if (p.vie==1)
SDL_BlitSurface(p.photo_vie,NULL,screen,&p.position_vie);
else if (p.vie==2)
{
SDL_BlitSurface(p.photo_vie,NULL,screen,&p.position_vie);

(p).position_vie.x=1050;
(p).position_vie.y=0;
	 SDL_BlitSurface(p.photo_vie,NULL,screen,&p.position_vie);

}
else if (p.vie==3)
{
SDL_BlitSurface(p.photo_vie,NULL,screen,&p.position_vie);

(p).position_vie.x=1050;
(p).position_vie.y=0;
	 SDL_BlitSurface(p.photo_vie,NULL,screen,&p.position_vie);

(p).position_vie.x=1200;
(p).position_vie.y=0;
	 SDL_BlitSurface(p.photo_vie,NULL,screen,&p.position_vie);
}


// SCORE


char str[10];


  sprintf(str, "%d", p.score);

	p.photo_score= TTF_RenderText_Blended(p.police,str,p.Noir);

			SDL_BlitSurface(p.photo_score,NULL,screen,&p.position_score);



}
/*void animerPerso( perso * p)
{

(*p).posSprite.y=(*p).direction*(*p).posSprite.h;



    if ((*p).posSprite.x==SPRITEWIDTH -(*p).posSprite.w)
        (*p).posSprite.x=0;
    else
        (*p).posSprite.x = (*p).posSprite.x + (*p).posSprite.w;

}
*/




void animerPerso( perso * p)
{
if (((*p).saut==2)|| ((*p).saut==1))
    (*p).posSprite.y=180;

else if ((*p).direction==0)
    (*p).posSprite.y=0;


if ((*p).direction!=-1) 	//pas de -1 car il n'y a pas d'animation pour l'état de repos
{

    if ((*p).posSprite.x==1440 -(*p).posSprite.w)
        (*p).posSprite.x=0;
    else
        (*p).posSprite.x = (*p).posSprite.x + (*p).posSprite.w;
}

}



void deplacer( perso *p,Uint32 dt)
{

    double x;
    x=(0.5*((*p).acceleration)*(0.001*(double)(dt*dt)))+(((*p).vitesse)*(0.001*(double)dt));
		if (x<0)
	{
		(*p).direction=-1;
		(*p).acceleration=0;
	}

  if ((*p).direction==0)
    (*p).position.x+=x;
  else if ((*p).direction==1)
    (*p).position.x-=x;
}





void sauter( perso *p,Uint32 dt,int fond)
{

    int seuil= fond-130;
    double y=(0.5*((*p).acceleration)*(0.001*(double)(dt*dt)))+(((*p).vitesse)*(0.001*(double)dt));

    //SAUT 1 UP
    //SAUT 2 DOWN

   if ((*p).saut==1) //montant
   {
       if ((*p).position.y>seuil)
	{
		(*p).acceleration+=0.25;
		(*p).position.y-=y;

	}
        else
            (*p).saut=2;
   }



   else if ((*p).saut==2) //descendant
   {
       if ((*p).position.y<fond)
	{
	 (*p).acceleration+=0.5;
        (*p).position.y+=y;

	}
       else if ((*p).position.y>=fond)
	{
	    (*p).saut=0;
	    (*p).acceleration=0;
	    (*p).position.y=fond;
	}
   }

}



















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
