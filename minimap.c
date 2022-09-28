#include <stdio.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include "struct.h"

void initminimap(minimap *m)
{
	m->mini = IMG_Load("mini.png");
	m->joueur = IMG_Load("minijoueur.png");
  m->pos_mini.x=300;
   m->pos_mini.y=0;
    m->pos_joueur.x=300;
    m->pos_joueur.y=5;
}



 /*void MAJMinimap(SDL_Rect posJoueur,  minimap * m, SDL_Rect camera, int redimensionnement)
 {
SDL_Rect posJoueurABS;
 posJoueurABS.x = posJoueur.x + camera.x;
posJoueurABS.y = posJoueur.y + camera.y;
 posbonhomme.x=posJoueurABS.x * redimensionnement/100;
 posbonhomme.y=posJoueurABS.y * redimensionnement/100;
 }*/
void affichermini (minimap m, SDL_Surface * screen)
{

 SDL_BlitSurface( m.mini, NULL, screen, &m.pos_mini );
  SDL_BlitSurface( m.joueur, NULL, screen, &m.pos_joueur );


}


void Initemps(temps *t)
{
	t->textColor;
	t->textColor.r = 255;
    t->textColor.g = 255;
    t->textColor.b = 255;
	t->start=SDL_GetTicks();
	t->font=TTF_OpenFont("lazy.ttf", 30);
	t->pos_temps.x=0;
	t->pos_temps.y=0;
}


temps affichertemps(temps t,SDL_Surface* screen)
{
sprintf(t.timeshown,"%d",(SDL_GetTicks() - t.start)/60);
t.seconds=TTF_RenderText_Solid( t.font, t.timeshown, t.textColor );
SDL_BlitSurface( t.seconds, NULL, screen, &t.pos_temps );

	return t;
}



SDL_Color GetPixel(SDL_Surface* pSurface ,int x,int y)
{
SDL_Color color;
Uint32 col=0;
//Determine position
char* pPosition=(char* ) pSurface->pixels;
pPosition+= (pSurface->pitch * y);
pPosition+= (pSurface->format->BytesPerPixel *x);
memcpy(&col ,pPosition ,pSurface->format->BytesPerPixel);
//convertir color
SDL_GetRGB(col,pSurface->format, &color.r, &color.g, &color.b);
return (color);
}


int collisionPP( SDL_Rect person, SDL_Surface * Masque)

{

  SDL_Color col;
	col=GetPixel(Masque,person.x+person.w,person.y+person.h);
printf("%d %d %d\n",col.r,col.b,col.g);


if ((col.r==0)&&(col.b==0)&&(col.g==255))
{

  return 1;//obstacle1
}
else
{
	return 0;
}
 }
