#include "struct.h"


int  main()
{
	SDL_Surface* screen;


screen=SDL_initialize(1800,600);

//	SDL_Surface *background=IMG_Load("background.jpg");
	SDL_Rect position_background;
SDL_Surface *backgroundcalque=IMG_Load("calquebackground.png");
position_background.x=0;
position_background.y=0;
//P
perso p;
initPerso(&p);
//ES
ES e;
initEnnemi(&e);

//enigme
enigme en;

generer (&en,"qt.txt","rp.txt","rpp.txt");
int correcte=0;
int sauvgarde=0;


//background
background bckg;
init_background(&bckg);


int continuer=1;
Uint32 dt,t_prev=0;
int seuil,fond;
int collisionBBox;








int x;
temps t;
Initemps(&t);
minimap m;
initminimap(&m);

/////////////////////////////// hetha tebaaa lmenu ////////////////////





int pas=0;
int an=0;

////////////////////// PARTIE MENU ///////////////////////:
bouton B[3][50];
int taille[3];
//initialisation de nombre de bouton a 0
for(int i=0;i<3;i++)
taille[i]=0;

image background_menu;
background_menu=image_initialize("background.jpg",0,0);
//button initialisation
//main menu without continer  buttons
bouton_initialize(0,B,taille,"images/main_menu/button1.png","images/main_menu/button2.png",730,300,"NEW GAME",810,310,"fonts/police.ttf",40,0,0,0,"music/button.wav");
bouton_initialize(0,B,taille,"images/main_menu/button1.png","images/main_menu/button2.png",730,400,"OPTIONS",775,410,"fonts/police.ttf",40,0,0,0,"music/button.wav");
bouton_initialize(0,B,taille,"images/main_menu/button1.png","images/main_menu/button2.png",730,500,"EXIT",810,510,"fonts/police.ttf",40,0,0,0,"music/button.wav");
//main menu with  continuer buttons
bouton_initialize(2,B,taille,"images/main_menu/button1.png","images/main_menu/button2.png",730,200,"RESUME",790,210,"fonts/police.ttf",40,0,0,0,"music/button.wav");
bouton_initialize(2,B,taille,"images/main_menu/button1.png","images/main_menu/button2.png",730,300,"NEW GAME",810,310,"fonts/police.ttf",40,0,0,0,"music/button.wav");
bouton_initialize(2,B,taille,"images/main_menu/button1.png","images/main_menu/button2.png",730,400,"OPTIONS",775,410,"fonts/police.ttf",40,0,0,0,"music/button.wav");
bouton_initialize(2,B,taille,"images/main_menu/button1.png","images/main_menu/button2.png",730,500,"EXIT",810,510,"fonts/police.ttf",40,0,0,0,"music/button.wav");
//options menu buttons from main menu
bouton_initialize(1,B,taille,"images/options_menu/fullscreen1.png","images/options_menu/fullscreen2.png",400,500,"FULLSCREEN",410,520,"fonts/police.ttf",40,0,0,0,"music/button.wav"); //fullscreeen button
bouton_initialize(1,B,taille,"images/options_menu/fullscreen1.png","images/options_menu/fullscreen2.png",0,0,"RETOUR",10,20,"fonts/police.ttf",40,0,0,0,"music/button.wav"); //return button
bouton_initialize(1,B,taille,"images/options_menu/bar.png","images/options_menu/bar.png",730,300,"",0,0,"fonts/police.ttf",40,0,0,0,"music/button.wav"); //sound bar
bouton_initialize(1,B,taille,"images/options_menu/changer.png","images/options_menu/changer.png",852,300,"",0,0,"fonts/police.ttf",40,0,0,0,"music/button.wav"); //sound changer button
//options menu buttons from men with resume
bouton_initialize(4,B,taille,"images/options_menu/fullscreen1.png","images/options_menu/fullscreen2.png",400,500,"FULLSCREEN",410,520,"fonts/police.ttf",40,0,0,0,"music/button.wav"); //fullscreeen button
bouton_initialize(4,B,taille,"images/options_menu/fullscreen1.png","images/options_menu/fullscreen2.png",0,0,"RETOUR",10,20,"fonts/police.ttf",40,0,0,0,"music/button.wav"); //return button
bouton_initialize(4,B,taille,"images/options_menu/bar.png","images/options_menu/bar.png",730,300,"",0,0,"fonts/police.ttf",40,0,0,0,"music/button.wav"); //sound bar
bouton_initialize(4,B,taille,"images/options_menu/changer.png","images/options_menu/changer.png",852,300,"",0,0,"fonts/police.ttf",40,0,0,0,"music/button.wav"); //sound changer button

//background music
Mix_Music *background_music;
background_music=Mix_LoadMUS("music/TownTheme.mp3");
int volume_lvl=50;
Mix_PlayMusic(background_music,-1);
Mix_VolumeMusic(volume_lvl);
//launching background music



int check=-1;
int move=0;
int btn=0;
int init=0;


int menu;

FILE* s=fopen("sauv.txt","r");
if(fscanf(s,"%hd %hd ",&p.position.x,&p.position.y)==EOF)
menu=0;
else{
menu=2;        ////// ly fyh loption
 charger (  &p,  "sauv.txt");

}

int s_position=-1; 			//tebaa khalil
while(continuer) //game loop
{

	if (menu!=3){
		printf("\n MENUUUUUUUUU %d \n",menu);
		Mix_VolumeMusic(volume_lvl);



		SDL_BlitSurface(background_menu.nom,NULL,screen,&background_menu.position);
		afficher(screen,B,taille,menu);

		Events_Handler(&menu,B,taille,&check,&continuer,screen,&move,&volume_lvl,&btn,&init);
	SDL_Flip(screen);

	}

else
{
	t_prev=SDL_GetTicks();
	an=p.position.x;
	 if (p.position.x>320) correcte=1;
if (p.position.x>s_position) s_position=p.position.x; //	tebaa khalil
		deplacer(&p,dt);
    sauter(&p,dt,fond);
    animerPerso(&p);

		deplacerIA(&e,p.position);
    animerEnnemi(&e);


		scrolling (p,&bckg,pas);



		afficher_background(bckg,screen);
    afficherPerso(p,bckg.afficher_background);




    afficherEnnemi(e,bckg.afficher_background);


collisionBBox =collisionBB(p,e);

// update vie
//if (collisionBBox==1) p.vie=2; 				//////////////////  A CHANGER
if (p.score<0) p.vie--;
printf("`\n P.VIE %d",p.vie);
if (p.vie==0) {
	init=1;
	menu=0;
} /////////////////////////////////// update later with a proper game over screen
//update score



if (s_position<p.position.x) p.score++;




//enigme
if (p.position.x>=300&&correcte==0)
  {
		if (p.position.x==300) sauvegarder ( p,"sauv.txt");
  afficherEnigme(en, screen);
  p.direction=-1;
  }



affichermini (m,screen);
affichertemps(t,screen);
x=collisionPP( p.position, backgroundcalque);



m.pos_joueur.x= (300+(p.position.x)*0.05);

SDL_Event event;

if (SDL_PollEvent(&event)!=0)
{
	if (event.type==SDL_KEYDOWN)
	{

		if (event.key.keysym.sym==SDLK_d)
		{
			p.direction=0;


			}
		if (event.key.keysym.sym==SDLK_q)
		{
			p.direction=1;


			 }

        if (event.key.keysym.sym==SDLK_SPACE) //saut event
        {
            if (p.saut==0)
            {
                fond= p.position.y;
                p.saut=1;
            }
        }


  if (event.key.keysym.sym==SDLK_ESCAPE)
 {
	 	sauvegarder ( p,"sauv.txt");
  	menu=2;

  }




        if (event.key.keysym.sym==SDLK_a)
		{
			if(strcmp(en.rep1,en.rep)==0)
      {
        correcte=1;

 charger (  &p,  "sauv.txt");
      }
      else
      {printf("\n WRONG1");
      p.score=p.score-20;}
		}
    else if (event.key.keysym.sym==SDLK_b)
		{
			if(strcmp(en.rep2,en.rep)==0)
      {
        correcte=1;
 charger (  &p,  "sauv.txt");
              //UPDATE LATER
      }
      else
      {printf("\n WRONG2");
      p.score=p.score-20;}
		}
    else if (event.key.keysym.sym==SDLK_c)
		{
			if(strcmp(en.rep3,en.rep)==0)
      {
        correcte=1;
 charger (  &p,  "sauv.txt");
           //UPDATE LATER
      }
      else
      {printf("\n WRONG3");
      p.score=p.score-20;}
	}



	}
	if (event.type==SDL_KEYUP)
	{
		if (event.key.keysym.sym==SDLK_d)

			p.acceleration=-75;

		else if (event.key.keysym.sym==SDLK_q)

			p.acceleration=-75;


	}


}

if (init==1){
	init_background(&bckg);
	initPerso(&p);

		init=0;
}


  SDL_Flip(screen);
	pas=p.position.x-an;

  dt=SDL_GetTicks()-t_prev;
} // END ELSE MENU!=3
}//END WHILE






}
