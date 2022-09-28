#include "struct.h"

void generer (enigme* e, char *nomficher1,char *nomficher2,char *nomficher3)
{

         FILE* qt=fopen(nomficher1,"r");
         if (qt==NULL)
         {
             printf("\n ERREUR FICHIER");
         }
         FILE* rp=fopen(nomficher2,"r");
         if (rp==NULL)
         {
             printf("\n ERREUR FICHIER");
         }
         FILE* rpp=fopen(nomficher3,"r");
         if (rpp==NULL)
         {
             printf("\n ERREUR FICHIER");
         }

         //charger la question
          int question; // nombre de la question a afficher

        srand(time(NULL));
        question=(rand()%3)+1; //changer 3 avec le numbero des questions


         int i=1;
        while((fgets((*e).question,60,qt)!=NULL)&&(question!=i))
         {


             i++;
         }




         //charger les reponses
         i=1;

          while((fscanf(rp,"%s %s %s",(*e).rep1,(*e).rep2,(*e).rep3)!=EOF)&&(question!=i))
         {
             i++;
         }

         //charger la reponse correcte

         i=1;

         while((fscanf(rpp,"%s",(*e).rep)!=EOF)&&(question!=i))
         {
             i++;
         }





         //SDL SURFACE



    (*e).police=TTF_OpenFont("Roman.ttf",30);
	(*e).Noir.r=255;
	(*e).Noir.g=255;
	(*e).Noir.b=255;

    // question
    (*e).q= TTF_RenderText_Blended((*e).police,(*e).question,(*e).Noir);


	(*e).posQ.x=0;
	(*e).posQ.y=0;

	//rep1
    (*e).r1= TTF_RenderText_Blended((*e).police,(*e).rep1,(*e).Noir);

	(*e).posR1.x=0;
	(*e).posR1.y=250;




    	//rep2
   (*e).r2= TTF_RenderText_Blended((*e).police,(*e).rep2,(*e).Noir);

	(*e).posR2.x=250;
	(*e).posR2.y=250;

		//rep3
    (*e).r3= TTF_RenderText_Blended((*e).police,(*e).rep3,(*e).Noir);

	(*e).posR3.x=500;
	(*e).posR3.y=250;




	//background

	(*e).taswira=IMG_Load("background.jpg");
	//position de l'image
	(*e).pos_taswira.x=0;
    	(*e).pos_taswira.y=0;




fclose(qt);
fclose(rpp);
fclose(rp);


}
void afficherEnigme(enigme e, SDL_Surface * screen)
{
    /*SDL_BlitSurface(e.taswira,NULL,screen,&e.pos_taswira);

    SDL_BlitSurface(e.q,NULL,screen,&e.posQ);

    SDL_BlitSurface(e.r1,NULL,screen,&e.posR1);
    SDL_BlitSurface(e.r2,NULL,screen,&e.posR2);
    SDL_BlitSurface(e.r3,NULL,screen,&e.posR3); */



    //partie mise a jour


        //partie affichage
    SDL_BlitSurface(e.taswira,NULL,screen,&e.pos_taswira);
    SDL_BlitSurface(e.q,NULL,screen,&e.posQ);
    SDL_BlitSurface(e.r1,NULL,screen,&e.posR1);
    SDL_BlitSurface(e.r2,NULL,screen,&e.posR2);
    SDL_BlitSurface(e.r3,NULL,screen,&e.posR3);













}
void sauvegarder (perso p,  char * nomfichier) //; int charger ( personne * p, background *b , char * nomfichier)
{

    FILE* sauv=fopen(nomfichier,"w");
    if (sauv==NULL)
    {
        printf("\n erreur fichier");
    }

    fprintf(sauv,"%d %d",p.position.x,p.position.y); //TETBADEL

}

int charger ( perso * p, char * nomfichier)
{
    FILE* sauv=fopen(nomfichier,"r");
    if (sauv==NULL)
    {
        printf("\n erreur fichier");
    }
    /*
SDL_Rect pos;
pos.x=p->position.x;

    fscanf(sauv,"%d %d ",(*p).position.x,(*p).position.y);
if (pos.x==p->position.x) return 1
else return 0; */
  fscanf(sauv,"%hd %hd ",&p->position.x,&p->position.y);

}
