
#include"struct.h"
void init_background(background *bckg){


	bckg->calque_background=NULL;
	bckg->calque_background=IMG_Load("calquebackground.png");

	bckg->afficher_background=NULL;
	bckg->afficher_background=IMG_Load("background.jpg");
	bckg->pos_background.x=0;
	bckg->pos_background.y=0;


	bckg->pos_background2.x=0;
	bckg->pos_background2.y=0;
	bckg->pos_background2.h=600;
	bckg->pos_background2.w=1800;
}
void afficher_background(background bckg,SDL_Surface *screen){

	SDL_BlitSurface(bckg.afficher_background,&(bckg.pos_background2),screen,&(bckg.pos_background));
	//printf("%d %d %d %d \n", bckg->pos_background2.x,bckg->pos_background2.y,bckg->pos_background2.h,bckg->pos_background2.w);
	//SDL_Flip(screen);

}

void scrolling (perso test,background *b,int pas)
{ printf("\n POAS %d",pas);
	switch(test.direction)
	{

		case 0:

			if (b->pos_background2.x<6200&&test.position.x>=1800/2)
                		b->pos_background2.x+=pas;
									break;

		case 1:
		if (b->pos_background2.x>0)//&&test.position.x<6200-900)
                		b->pos_background2.x+=pas;
										break;

}
}
