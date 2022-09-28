#include "struct.h"


image image_initialize(char* destination,int posX,int posY)
{
	image I;

	I.nom=IMG_Load(destination);
	I.position.x=posX;
	I.position.y=posY;


		return I;

}








void bouton_initialize(int menu,bouton B[][50],int taille[3],char* location0,char* location1,int posX,int posY,char* texte,int posXTexte,int posYTexte,char* locationFont,int tailleText,int color1,int color2,int color3,char* music)
{


//image
	B[menu][(taille[menu])].nom[0]=IMG_Load(location0);
	B[menu][(taille[menu])].nom[1]=IMG_Load(location1);
	B[menu][(taille[menu])].position.x=posX;
	B[menu][(taille[menu])].position.y=posY;
//son
	B[menu][(taille[menu])].sf[0]=Mix_LoadWAV("");
	B[menu][(taille[menu])].sf[1]=Mix_LoadWAV(music);
//texte

	B[menu][(taille[menu])].police=TTF_OpenFont(locationFont,tailleText);
	B[menu][(taille[menu])].color.r= color1;
	B[menu][(taille[menu])].color.g=color2;
	B[menu][(taille[menu])].color.b=color3;

	B[menu][(taille[menu])].positionTexte.x=posXTexte;
	B[menu][(taille[menu])].positionTexte.y=posYTexte;
	B[menu][(taille[menu])].texte=TTF_RenderText_Blended((B[menu][(taille[menu])].police),texte,(B[menu][(taille[menu])].color));


	B[menu][(taille[menu])].etat=0;
	B[menu][(taille[menu])].etatSon=0;



	taille[menu]++;







}



void afficher(SDL_Surface* screen,bouton B[][50],int taille[3],int menu)
{



	for(int i=0;i<(taille[menu]);i++)
	{
		SDL_BlitSurface(B[menu][i].nom[(B[menu][i].etat)],NULL,screen,&B[menu][i].position);

		Mix_PlayChannel(-1,B[menu][i].sf[(B[menu][i].etatSon)],0);

		SDL_BlitSurface(B[menu][i].texte,NULL,screen,&B[menu][i].positionTexte);

                    if ((B[(menu)][i].etat==1)&&(B[(menu)][i].etatSon==1))
                    {
                        B[(menu)][i].etatSon=0;
                    }

	}



}
void Events_Handler(int *menu,bouton B[][50],int taille[3],int* check,int* loop,SDL_Surface* screen,int* move,int* volume_lvl, int* btn,int* init)
{


	SDL_Event event;
if ((*menu)==0)
{
if (SDL_PollEvent(&event)!=0)
{


	switch (event.type)
	{

		case (SDL_QUIT):

			(*loop)=0;
			break;

		case (SDL_MOUSEMOTION):



		for(int i=0;i<taille[(*menu)];i++)
	{

			(*check)=CheckMousePosition((*check),event.motion.x,event.motion.y,B[(*menu)][i].position.x,B[(*menu)][i].position.y,(B[(*menu)][i].position.x+245),(B[(*menu)][i].position.y+49));



			if (((*check)==0)&&(B[(*menu)][i].etat==1))
			{
			B[(*menu)][i].etatSon=0;


			}
			else if (((*check)==0)&&(B[(*menu)][i].etat==0))
			{
			B[(*menu)][i].etat=1;
			B[(*menu)][i].etatSon=1;
			}
			else if ((*check)==-1)
			{
			B[(*menu)][i].etatSon=0;
			B[(*menu)][i].etat=0;
			}




	}


			break;
		case(SDL_MOUSEBUTTONDOWN):
			for(int i=0;i<taille[(*menu)];i++)
	{
		(*check)=CheckMousePosition((*check),event.button.x,event.button.y,B[(*menu)][i].position.x,B[(*menu)][i].position.y,(B[(*menu)][i].position.x+245),(B[(*menu)][i].position.y+49));
		if ((*check)==0)
		{
      if (i==0)
      (*menu)=3;
			if (i==1)   //clic option
       (*menu)=1;

			else if (i==2) //clic exit
			(*loop)=0;


		}



	}
	break;
       case (SDL_KEYDOWN ):

            if (event.key.keysym.sym==SDLK_DOWN)




            {
                //automatisation FOR LATER
                /*for(int i=0;i<taille[(*menu)];i++)
                {
                    if ((B[(*menu)][i].etat==1)&&(i!=(taille[(*menu)]-1)))
                    {
                        B[(*menu)][i].etat=0;
                        B[(*menu)][i].etatSon=0;
                        B[(*menu)][i+1].etat=1;
                        B[(*menu)][i+1].etatSon=1;
                        (*btn)=1;
                    }
                    else if ((i==(taille[(*menu)]-1))&&((B[(*menu)][i].etat==1)))
                    {
                        B[(*menu)][i].etat=0;
                        B[(*menu)][i].etatSon=0;
                        B[(*menu)][0].etat=1;
                        B[(*menu)][0].etatSon=1;
                        (*btn)=1;
                    }
                    else if ((i==(taille[(*menu)]-1))&&(btn==0))
                    {
                        B[(*menu)][0].etat=1;
                        B[(*menu)][0].etatSon=1;
                    }
                } //////////////////////
                */

                //
                if ((B[(*menu)][0].etat==0)&&(B[(*menu)][1].etat==0)&&(B[(*menu)][2].etat==0))
                {
                    B[(*menu)][0].etat=1;
                    B[(*menu)][0].etatSon=1;

                }
                else if ((B[(*menu)][0].etat==1)&&(B[(*menu)][1].etat==0)&&(B[(*menu)][2].etat==0))
                {
                    B[(*menu)][0].etat=0;
                    B[(*menu)][0].etatSon=0;
                    B[(*menu)][1].etat=1;
                    B[(*menu)][1].etatSon=1;
                }
                else if ((B[(*menu)][0].etat==0)&&(B[(*menu)][1].etat==1)&&(B[(*menu)][2].etat==0))
                {

                    B[(*menu)][1].etat=0;
                   B[(*menu)][1].etatSon=0;
                    B[(*menu)][2].etat=1;
                   B[(*menu)][2].etatSon=1;
                }
                else if ((B[(*menu)][0].etat==0)&&(B[(*menu)][1].etat==0)&&(B[(*menu)][2].etat==1))
                {
                    B[(*menu)][2].etat=0;
                    B[(*menu)][2].etatSon=0;
                    B[(*menu)][0].etat=1;
                    B[(*menu)][0].etatSon=1;

                }



            }
             else if (event.key.keysym.sym==SDLK_UP)
            {
                if ((B[(*menu)][0].etat==0)&&(B[(*menu)][1].etat==0)&&(B[(*menu)][2].etat==0))
                {
                    B[(*menu)][2].etat=1;
                    B[(*menu)][2].etatSon=1;

                }
                else if ((B[(*menu)][0].etat==1)&&(B[(*menu)][1].etat==0)&&(B[(*menu)][2].etat==0))
                {
                    B[(*menu)][0].etat=0;
                    B[(*menu)][0].etatSon=0;
                    B[(*menu)][2].etat=1;
                    B[(*menu)][2].etatSon=1;
                }
                else if ((B[(*menu)][0].etat==0)&&(B[(*menu)][1].etat==1)&&(B[(*menu)][2].etat==0))
                {

                    B[(*menu)][1].etat=0;
                   B[(*menu)][1].etatSon=0;
                    B[(*menu)][0].etat=1;
                   B[(*menu)][0].etatSon=1;
                }
                else if ((B[(*menu)][0].etat==0)&&(B[(*menu)][1].etat==0)&&(B[(*menu)][2].etat==1))
                {
                    B[(*menu)][2].etat=0;
                    B[(*menu)][2].etatSon=0;
                    B[(*menu)][1].etat=1;
                    B[(*menu)][1].etatSon=1;

                }



            }
             else if (event.key.keysym.sym==SDLK_SPACE)
             {
                    if (B[(*menu)][0].etat==1)
                        (*menu)=3;

                     else if (B[(*menu)][1].etat==1)
                      (*menu)=1;



                     else if (B[(*menu)][2].etat==1)
                      (*loop)=0;

             }





            break;
         /*   case (SDL_KEYUP ):
                if (event.key.keysym.sym==SDLK_DOWN)
                {
                     for(int i=0;i<taille[(*menu)];i++)
                {
                    if  ((B[(*menu)][i].etat==1)&&(B[(*menu)][i].etatSon==0))
                    {
                        B[(*menu)][i].etatSon=1;

                    }
                    else if ((B[(*menu)][i].etat==1)&&(B[(*menu)][i].etatSon==1))
                    {
                        B[(*menu)][i].etatSon=0;
                    }
                }
                }

                break; */




	}//end switch event typee





}//end SDL_PollEvent if
}
else if ((*menu)==2)
{
if (SDL_PollEvent(&event)!=0)
{


	switch (event.type)
	{

		case (SDL_QUIT):

			(*loop)=0;
			break;

		case (SDL_MOUSEMOTION):



		for(int i=0;i<taille[(*menu)];i++)
	{

			(*check)=CheckMousePosition((*check),event.motion.x,event.motion.y,B[(*menu)][i].position.x,B[(*menu)][i].position.y,(B[(*menu)][i].position.x+245),(B[(*menu)][i].position.y+49));



			if (((*check)==0)&&(B[(*menu)][i].etat==1))
			{
			B[(*menu)][i].etatSon=0;


			}
			else if (((*check)==0)&&(B[(*menu)][i].etat==0))
			{
			B[(*menu)][i].etat=1;
			B[(*menu)][i].etatSon=1;
			}
			else if ((*check)==-1)
			{
			B[(*menu)][i].etatSon=0;
			B[(*menu)][i].etat=0;
			}




	}


			break;
		case(SDL_MOUSEBUTTONDOWN):
			for(int i=0;i<taille[(*menu)];i++)
	{
		(*check)=CheckMousePosition((*check),event.button.x,event.button.y,B[(*menu)][i].position.x,B[(*menu)][i].position.y,(B[(*menu)][i].position.x+245),(B[(*menu)][i].position.y+49));
		if ((*check)==0)
		{
      if (i==0)
      (*menu)=3;
			if (i==1){
			//	initPerso(&p);
				//init_background(&bckg);
        (*init)=1;
				(*menu)=5;
			}
			if (i==2) //clic option
			(*menu)=1;
			else if (i==3) //clic exit
			(*loop)=0;


		}



	}
	break;
       case (SDL_KEYDOWN ):

            if (event.key.keysym.sym==SDLK_DOWN)




            {
                //automatisation FOR LATER
                /*for(int i=0;i<taille[(*menu)];i++)
                {
                    if ((B[(*menu)][i].etat==1)&&(i!=(taille[(*menu)]-1)))
                    {
                        B[(*menu)][i].etat=0;
                        B[(*menu)][i].etatSon=0;
                        B[(*menu)][i+1].etat=1;
                        B[(*menu)][i+1].etatSon=1;
                        (*btn)=1;
                    }
                    else if ((i==(taille[(*menu)]-1))&&((B[(*menu)][i].etat==1)))
                    {
                        B[(*menu)][i].etat=0;
                        B[(*menu)][i].etatSon=0;
                        B[(*menu)][0].etat=1;
                        B[(*menu)][0].etatSon=1;
                        (*btn)=1;
                    }
                    else if ((i==(taille[(*menu)]-1))&&(btn==0))
                    {
                        B[(*menu)][0].etat=1;
                        B[(*menu)][0].etatSon=1;
                    }
                } //////////////////////
                */

                //
                if ((B[(*menu)][0].etat==0)&&(B[(*menu)][1].etat==0)&&(B[(*menu)][2].etat==0))
                {
                    B[(*menu)][0].etat=1;
                    B[(*menu)][0].etatSon=1;

                }
                else if ((B[(*menu)][0].etat==1)&&(B[(*menu)][1].etat==0)&&(B[(*menu)][2].etat==0))
                {
                    B[(*menu)][0].etat=0;
                    B[(*menu)][0].etatSon=0;
                    B[(*menu)][1].etat=1;
                    B[(*menu)][1].etatSon=1;
                }
                else if ((B[(*menu)][0].etat==0)&&(B[(*menu)][1].etat==1)&&(B[(*menu)][2].etat==0))
                {

                    B[(*menu)][1].etat=0;
                   B[(*menu)][1].etatSon=0;
                    B[(*menu)][2].etat=1;
                   B[(*menu)][2].etatSon=1;
                }
                else if ((B[(*menu)][0].etat==0)&&(B[(*menu)][1].etat==0)&&(B[(*menu)][2].etat==1))
                {
                    B[(*menu)][2].etat=0;
                    B[(*menu)][2].etatSon=0;
                    B[(*menu)][0].etat=1;
                    B[(*menu)][0].etatSon=1;

                }



            }
             else if (event.key.keysym.sym==SDLK_UP)
            {
                if ((B[(*menu)][0].etat==0)&&(B[(*menu)][1].etat==0)&&(B[(*menu)][2].etat==0))
                {
                    B[(*menu)][2].etat=1;
                    B[(*menu)][2].etatSon=1;

                }
                else if ((B[(*menu)][0].etat==1)&&(B[(*menu)][1].etat==0)&&(B[(*menu)][2].etat==0))
                {
                    B[(*menu)][0].etat=0;
                    B[(*menu)][0].etatSon=0;
                    B[(*menu)][2].etat=1;
                    B[(*menu)][2].etatSon=1;
                }
                else if ((B[(*menu)][0].etat==0)&&(B[(*menu)][1].etat==1)&&(B[(*menu)][2].etat==0))
                {

                    B[(*menu)][1].etat=0;
                   B[(*menu)][1].etatSon=0;
                    B[(*menu)][0].etat=1;
                   B[(*menu)][0].etatSon=1;
                }
                else if ((B[(*menu)][0].etat==0)&&(B[(*menu)][1].etat==0)&&(B[(*menu)][2].etat==1))
                {
                    B[(*menu)][2].etat=0;
                    B[(*menu)][2].etatSon=0;
                    B[(*menu)][1].etat=1;
                    B[(*menu)][1].etatSon=1;

                }



            }
             else if (event.key.keysym.sym==SDLK_SPACE)
             {
                    if (B[(*menu)][0].etat==1)
                        (*menu)=3;
										if (B[(*menu)][1].etat==1){
										//	initPerso(&p);
											//init_background(&bckg);
                      (*init)=1;
											(*menu)=3;
										}


                     else if (B[(*menu)][2].etat==1)
                     (*menu)=4;


                     else if (B[(*menu)][3].etat==1)
                      (*loop)=0;

             }





            break;
         /*   case (SDL_KEYUP ):
                if (event.key.keysym.sym==SDLK_DOWN)
                {
                     for(int i=0;i<taille[(*menu)];i++)
                {
                    if  ((B[(*menu)][i].etat==1)&&(B[(*menu)][i].etatSon==0))
                    {
                        B[(*menu)][i].etatSon=1;

                    }
                    else if ((B[(*menu)][i].etat==1)&&(B[(*menu)][i].etatSon==1))
                    {
                        B[(*menu)][i].etatSon=0;
                    }
                }
                }

                break; */




	}//end switch event typee





}//end SDL_PollEvent if
}
else if ((*menu)==1)
{
if (SDL_PollEvent(&event)!=0)
{


	switch (event.type)
	{

		case (SDL_QUIT):

			(*loop)=0;
			break;


		case(SDL_MOUSEBUTTONDOWN):
		if (event.button.button==SDL_BUTTON_LEFT)
		{
			for(int i=0;i<taille[(*menu)];i++)
	{
		(*check)=CheckMousePosition((*check),event.button.x,event.button.y,B[(*menu)][i].position.x,B[(*menu)][i].position.y,(B[(*menu)][i].position.x+245),(B[(*menu)][i].position.y+49));
		if ((*check)==0)
		{
			if (i==0) //clic fullscreen // *****************************************edit the FULLSCREEN title ******************************************************
			SDL_WM_ToggleFullScreen(screen);
			if(i==1)
			(*menu)=0;
			if(i==2)
			{
			(*move)=1;
			B[(*menu)][i+1].position.x=event.button.x;
			(*volume_lvl)=(((B[(*menu)][i+1].position.x-730)*100)/245);
			}

		}



	}
		}
			break;
		case(SDL_MOUSEBUTTONUP):
		if ((event.button.button==SDL_BUTTON_LEFT)&&((*move)==1))
		{
		(*move)=0;
		}
			break;

		case (SDL_MOUSEMOTION):
		(*check)=CheckMousePosition((*check),event.motion.x,event.motion.y,B[(*menu)][2].position.x,B[(*menu)][2].position.y,(B[(*menu)][2].position.x+245),(B[(*menu)][2].position.y+49));
		if (((*check)==0)&&((*move)==1))
		{
		B[(*menu)][3].position.x=event.button.x;
		(*volume_lvl)=(((B[(*menu)][3].position.x-730)*100)/245);
		}

		//motion bouton return
		(*check)=CheckMousePosition((*check),event.motion.x,event.motion.y,B[(*menu)][1].position.x,B[(*menu)][1].position.y,(B[(*menu)][1].position.x+245),(B[(*menu)][1].position.y+49));
		if (((*check)==0)&&(B[(*menu)][1].etat==1))
			{
			B[(*menu)][1].etatSon=0;


			}
			else if (((*check)==0)&&(B[(*menu)][1].etat==0))
			{
			B[(*menu)][1].etat=1;
			B[(*menu)][1].etatSon=1;
			}
			else if ((*check)==-1)
			{
			B[(*menu)][1].etatSon=0;
			B[(*menu)][1].etat=0;
			}
			//motion bouton fullscreen
		(*check)=CheckMousePosition((*check),event.motion.x,event.motion.y,B[(*menu)][0].position.x,B[(*menu)][0].position.y,(B[(*menu)][0].position.x+245),(B[(*menu)][0].position.y+49));
		if (((*check)==0)&&(B[(*menu)][0].etat==1))
			{
			B[(*menu)][0].etatSon=0;


			}
			else if (((*check)==0)&&(B[(*menu)][0].etat==0))
			{
			B[(*menu)][0].etat=1;
			B[(*menu)][0].etatSon=1;
			}
			else if ((*check)==-1)
			{
			B[(*menu)][0].etatSon=0;
			B[(*menu)][0].etat=0;
			}
		break;
		case (SDL_KEYDOWN ):

            if (event.key.keysym.sym==SDLK_BACKSPACE)
            {
                (*menu)=0;
            }

            else if (event.key.keysym.sym==SDLK_m)
            {
                if ((*volume_lvl)==0)
                {
                    (*volume_lvl)=50;
                }
                else
                    (*volume_lvl)=0;
            }
            //ARROW KEYS
            if (event.key.keysym.sym==SDLK_DOWN)




            {
                //automatisation FOR LATER
                /*for(int i=0;i<taille[(*menu)];i++)
                {
                    if ((B[(*menu)][i].etat==1)&&(i!=(taille[(*menu)]-1)))
                    {
                        B[(*menu)][i].etat=0;
                        B[(*menu)][i].etatSon=0;
                        B[(*menu)][i+1].etat=1;
                        B[(*menu)][i+1].etatSon=1;
                        (*btn)=1;
                    }
                    else if ((i==(taille[(*menu)]-1))&&((B[(*menu)][i].etat==1)))
                    {
                        B[(*menu)][i].etat=0;
                        B[(*menu)][i].etatSon=0;
                        B[(*menu)][0].etat=1;
                        B[(*menu)][0].etatSon=1;
                        (*btn)=1;
                    }
                    else if ((i==(taille[(*menu)]-1))&&(btn==0))
                    {
                        B[(*menu)][0].etat=1;
                        B[(*menu)][0].etatSon=1;
                    }
                } //////////////////////
                */

                //
                if ((B[(*menu)][1].etat==0)&&(B[(*menu)][3].etat==0)&&(B[(*menu)][0].etat==0))
                {
                    B[(*menu)][1].etat=1;
                    B[(*menu)][1].etatSon=1;

                }
                else if ((B[(*menu)][1].etat==1)&&(B[(*menu)][3].etat==0)&&(B[(*menu)][0].etat==0))
                {
                    B[(*menu)][1].etat=0;
                    B[(*menu)][1].etatSon=0;
                    B[(*menu)][3].etat=1;
                    B[(*menu)][3].etatSon=1;
                }
                else if ((B[(*menu)][1].etat==0)&&(B[(*menu)][3].etat==1)&&(B[(*menu)][0].etat==0))
                {

                    B[(*menu)][3].etat=0;
                   B[(*menu)][3].etatSon=0;
                    B[(*menu)][0].etat=1;
                   B[(*menu)][0].etatSon=1;
                }
                else if ((B[(*menu)][1].etat==0)&&(B[(*menu)][3].etat==0)&&(B[(*menu)][0].etat==1))
                {
                    B[(*menu)][0].etat=0;
                    B[(*menu)][0].etatSon=0;
                    B[(*menu)][1].etat=1;
                    B[(*menu)][1].etatSon=1;

                }



            }
             else if (event.key.keysym.sym==SDLK_UP)
            {
                if ((B[(*menu)][1].etat==0)&&(B[(*menu)][3].etat==0)&&(B[(*menu)][0].etat==0))
                {
                    B[(*menu)][0].etat=1;
                    B[(*menu)][0].etatSon=1;

                }
                else if ((B[(*menu)][1].etat==1)&&(B[(*menu)][3].etat==0)&&(B[(*menu)][0].etat==0))
                {
                    B[(*menu)][1].etat=0;
                    B[(*menu)][1].etatSon=0;
                    B[(*menu)][0].etat=1;
                    B[(*menu)][0].etatSon=1;
                }
                else if ((B[(*menu)][1].etat==0)&&(B[(*menu)][3].etat==1)&&(B[(*menu)][0].etat==0))
                {

                    B[(*menu)][3].etat=0;
                   B[(*menu)][3].etatSon=0;
                    B[(*menu)][1].etat=1;
                   B[(*menu)][1].etatSon=1;
                }
                else if ((B[(*menu)][1].etat==0)&&(B[(*menu)][3].etat==0)&&(B[(*menu)][0].etat==1))
                {
                    B[(*menu)][0].etat=0;
                    B[(*menu)][0].etatSon=0;
                    B[(*menu)][3].etat=1;
                    B[(*menu)][3].etatSon=1;

                }



            }


	}//end switch event typee





}//end SDL_PollEvent if
} //END OPTION IF
else if ((*menu)==4)
{
if (SDL_PollEvent(&event)!=0)
{


	switch (event.type)
	{

		case (SDL_QUIT):

			(*loop)=0;
			break;


		case(SDL_MOUSEBUTTONDOWN):
		if (event.button.button==SDL_BUTTON_LEFT)
		{
			for(int i=0;i<taille[(*menu)];i++)
	{
		(*check)=CheckMousePosition((*check),event.button.x,event.button.y,B[(*menu)][i].position.x,B[(*menu)][i].position.y,(B[(*menu)][i].position.x+245),(B[(*menu)][i].position.y+49));
		if ((*check)==0)
		{
			if (i==0) //clic fullscreen // *****************************************edit the FULLSCREEN title ******************************************************
			SDL_WM_ToggleFullScreen(screen);
			if(i==1)
			(*menu)=2;
			if(i==2)
			{
			(*move)=1;
			B[(*menu)][i+1].position.x=event.button.x;
			(*volume_lvl)=(((B[(*menu)][i+1].position.x-730)*100)/245);
			}

		}



	}
		}
			break;
		case(SDL_MOUSEBUTTONUP):
		if ((event.button.button==SDL_BUTTON_LEFT)&&((*move)==1))
		{
		(*move)=0;
		}
			break;

		case (SDL_MOUSEMOTION):
		(*check)=CheckMousePosition((*check),event.motion.x,event.motion.y,B[(*menu)][2].position.x,B[(*menu)][2].position.y,(B[(*menu)][2].position.x+245),(B[(*menu)][2].position.y+49));
		if (((*check)==0)&&((*move)==1))
		{
		B[(*menu)][3].position.x=event.button.x;
		(*volume_lvl)=(((B[(*menu)][3].position.x-730)*100)/245);
		}

		//motion bouton return
		(*check)=CheckMousePosition((*check),event.motion.x,event.motion.y,B[(*menu)][1].position.x,B[(*menu)][1].position.y,(B[(*menu)][1].position.x+245),(B[(*menu)][1].position.y+49));
		if (((*check)==0)&&(B[(*menu)][1].etat==1))
			{
			B[(*menu)][1].etatSon=0;


			}
			else if (((*check)==0)&&(B[(*menu)][1].etat==0))
			{
			B[(*menu)][1].etat=1;
			B[(*menu)][1].etatSon=1;
			}
			else if ((*check)==-1)
			{
			B[(*menu)][1].etatSon=0;
			B[(*menu)][1].etat=0;
			}
			//motion bouton fullscreen
		(*check)=CheckMousePosition((*check),event.motion.x,event.motion.y,B[(*menu)][0].position.x,B[(*menu)][0].position.y,(B[(*menu)][0].position.x+245),(B[(*menu)][0].position.y+49));
		if (((*check)==0)&&(B[(*menu)][0].etat==1))
			{
			B[(*menu)][0].etatSon=0;


			}
			else if (((*check)==0)&&(B[(*menu)][0].etat==0))
			{
			B[(*menu)][0].etat=1;
			B[(*menu)][0].etatSon=1;
			}
			else if ((*check)==-1)
			{
			B[(*menu)][0].etatSon=0;
			B[(*menu)][0].etat=0;
			}
		break;
		case (SDL_KEYDOWN ):

            if (event.key.keysym.sym==SDLK_BACKSPACE)
            {
                (*menu)=2;
            }

            else if (event.key.keysym.sym==SDLK_m)
            {
                if ((*volume_lvl)==0)
                {
                    (*volume_lvl)=50;
                }
                else
                    (*volume_lvl)=0;
            }
            //ARROW KEYS
            if (event.key.keysym.sym==SDLK_DOWN)




            {
                //automatisation FOR LATER
                /*for(int i=0;i<taille[(*menu)];i++)
                {
                    if ((B[(*menu)][i].etat==1)&&(i!=(taille[(*menu)]-1)))
                    {
                        B[(*menu)][i].etat=0;
                        B[(*menu)][i].etatSon=0;
                        B[(*menu)][i+1].etat=1;
                        B[(*menu)][i+1].etatSon=1;
                        (*btn)=1;
                    }
                    else if ((i==(taille[(*menu)]-1))&&((B[(*menu)][i].etat==1)))
                    {
                        B[(*menu)][i].etat=0;
                        B[(*menu)][i].etatSon=0;
                        B[(*menu)][0].etat=1;
                        B[(*menu)][0].etatSon=1;
                        (*btn)=1;
                    }
                    else if ((i==(taille[(*menu)]-1))&&(btn==0))
                    {
                        B[(*menu)][0].etat=1;
                        B[(*menu)][0].etatSon=1;
                    }
                } //////////////////////
                */

                //
                if ((B[(*menu)][1].etat==0)&&(B[(*menu)][3].etat==0)&&(B[(*menu)][0].etat==0))
                {
                    B[(*menu)][1].etat=1;
                    B[(*menu)][1].etatSon=1;

                }
                else if ((B[(*menu)][1].etat==1)&&(B[(*menu)][3].etat==0)&&(B[(*menu)][0].etat==0))
                {
                    B[(*menu)][1].etat=0;
                    B[(*menu)][1].etatSon=0;
                    B[(*menu)][3].etat=1;
                    B[(*menu)][3].etatSon=1;
                }
                else if ((B[(*menu)][1].etat==0)&&(B[(*menu)][3].etat==1)&&(B[(*menu)][0].etat==0))
                {

                    B[(*menu)][3].etat=0;
                   B[(*menu)][3].etatSon=0;
                    B[(*menu)][0].etat=1;
                   B[(*menu)][0].etatSon=1;
                }
                else if ((B[(*menu)][1].etat==0)&&(B[(*menu)][3].etat==0)&&(B[(*menu)][0].etat==1))
                {
                    B[(*menu)][0].etat=0;
                    B[(*menu)][0].etatSon=0;
                    B[(*menu)][1].etat=1;
                    B[(*menu)][1].etatSon=1;

                }



            }
             else if (event.key.keysym.sym==SDLK_UP)
            {
                if ((B[(*menu)][1].etat==0)&&(B[(*menu)][3].etat==0)&&(B[(*menu)][0].etat==0))
                {
                    B[(*menu)][0].etat=1;
                    B[(*menu)][0].etatSon=1;

                }
                else if ((B[(*menu)][1].etat==1)&&(B[(*menu)][3].etat==0)&&(B[(*menu)][0].etat==0))
                {
                    B[(*menu)][1].etat=0;
                    B[(*menu)][1].etatSon=0;
                    B[(*menu)][0].etat=1;
                    B[(*menu)][0].etatSon=1;
                }
                else if ((B[(*menu)][1].etat==0)&&(B[(*menu)][3].etat==1)&&(B[(*menu)][0].etat==0))
                {

                    B[(*menu)][3].etat=0;
                   B[(*menu)][3].etatSon=0;
                    B[(*menu)][1].etat=1;
                   B[(*menu)][1].etatSon=1;
                }
                else if ((B[(*menu)][1].etat==0)&&(B[(*menu)][3].etat==0)&&(B[(*menu)][0].etat==1))
                {
                    B[(*menu)][0].etat=0;
                    B[(*menu)][0].etatSon=0;
                    B[(*menu)][3].etat=1;
                    B[(*menu)][3].etatSon=1;

                }



            }


	}//end switch event typee





}//end SDL_PollEvent if
}
}

int CheckMousePosition(int check,int MouseX,int MouseY,int StartX,int StartY,int EndX,int EndY)
{

	if((MouseX>=StartX)&&(MouseY>=StartY)&&(MouseX<=EndX)&&(MouseY<=EndY))
		{
		(check)=0;

		}

	else
		(check)=-1;


	return(check);

}
