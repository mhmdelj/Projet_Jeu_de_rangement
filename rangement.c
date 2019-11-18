#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "rangement.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

liste *inserer(liste *li, FILE *ff, int nb)
{
    liste *no = (liste*) malloc(sizeof(liste));
    int i;
    
    for (i=0;i<nb;i++)
	{
		fscanf(ff, "%s",no->str);
	}
	
    no->suivant = li;
    li=no;
    /* On retourne la nouvelle liste, i.e. le pointeur sur le premier élément */     
	
    return li;
} 

void afficher(liste *li){
     liste *encours;
     encours = li;   
     int i = 0;
     while(encours)
     {
         printf("%s\n",encours->str);            
         encours = encours->suivant;
     }                    
}

/*int my_rand (void)
{
   static int tab[100];
   static int first = 0;
   int index;
   int rn;
	
   if (first == 0)
   {
      int i;

      
      for (i = 0; i < 100; i++)
         tab[i] = rand()%100+1;
      first = 1;
   }
   index = (int)(rand() / RAND_MAX * (100 - 1));
   rn = tab[index];
   tab[index] = rand();
   return (rn);
}*/

liste* scan(liste* ll){
	int i;
	liste *no = (liste*) malloc(sizeof(liste));
	liste *encours;
	
	encours = ll;
	scanf("%s",no->str);
	no->suivant = NULL;
	if(ll != NULL) {
		while(encours->suivant != NULL){
			encours = encours->suivant;
		}
		encours->suivant = no;
	}
	else
		ll = no;
	return ll;
}

void Tri_Selection(liste *tete)
		{
			liste *p, *q, *min;
			char *aide;
			for(p=tete ; p->suivant!=NULL ; p=p->suivant)
				{
					min=p;
					for(q=p->suivant ; q!=NULL ; q=q->suivant)
						{
							if(strcmp(q->str,min->str) < 0)
								{
									min=q;
								}
						}
					strcpy(aide, p->str);
					strcpy(p->str, min->str);
					strcpy(min->str, aide);
				}
		}

void comparer(liste *l, liste *ll){

     liste *encours, *enc;
     int ordonne = 1, i=1;
     char* s, *ss;
     encours = l;  
	 enc = ll; 
     for(i = 0; i < 4; i++)
     {
     	s = encours->str;
     	ss = enc->str;
         if(strcmp(s,ss) != 0)
			{
				ordonne = 0;
				break;
			}
			encours = encours->suivant;
         	enc = enc->suivant;
     }
	 
	 if(ordonne == 1){
	 	printf("\nBravo!\n");
	 	m = 1;
	 }
		
	 else
		printf("\nOpss! Pas Grave, tu peux relancer le jeu :) ");    
}

liste* supprimer_liste(liste *li, int n){
	liste *encours;
	int i;
	
	for(i = 0; i < n; i++){
		encours = li;
		li = encours->suivant;
		free(encours);
	}
	return li;
}

void sauvegarder_jeu(Info_joueur *infos)
{ 
     FILE *flot; 
     //ouverture fichier en mode ecriture binaire
     flot =fopen("score.txt", "a"); 
     if(flot != NULL)
     {
        // enregistrer les infos du joueur dans le fichier
        fprintf(flot, "%s %d %d %d", infos->nom, infos->score,infos->niveau,infos->nb_mots);       
        fclose (flot);
     } 
}

Info_joueur* charger_jeu(Info_joueur *j, char nom[])
{     
  FILE	*flot;  
  Info_joueur *infos = (Info_joueur*) malloc(sizeof(Info_joueur));
  int score, niveau, nb_mots;
  int i;
  char nom_j[15];
  //printf("\n--------");
  srand (time(NULL));
  flot = fopen("score.txt", "rb");   
  if(flot != NULL)	
  {
      // chargement des informations du joueurs dans la structure infos
      
      while(fscanf(flot, "%s %d %d %d", &nom_j, &score, &niveau, &nb_mots) != EOF)
      {	
	  	if(strcmp(nom, nom_j) == 0){
		  trouve = 1;
        // affichage sur console
        strcpy(infos->nom, &nom_j);
        
        infos->score = score;
		infos->niveau = niveau;
		infos->nb_mots = nb_mots;
		j = infos;
		printf("------------------------------------------\n");
        printf("Bienvenue %s tu es au stage %d \n", j->nom, j->score);
        printf("le niveau choisi est : %d et le nombre de mots %d", j->niveau, j->nb_mots);
        printf("\nEnjoy!\n");
        printf("------------------------------------------\n");
      }  
  	}
  }
  // fermeture fichier
  fclose (flot);
  return infos;		
}

int nombreAleatoire(int nombreMax){

    //srand(time(NULL));

    return (rand() % nombreMax);
   }

int main(int argc, char *argv[]) {
	//system("color 27");
	FILE *f_mots, *f_score;
	liste *l = NULL, *ll = NULL, *lll = NULL;
	int ligneVoulu;
	int i, n, ordonne, score = 1, niveau;
	Info_joueur *joueur;
	Info_joueur *joueur_charge;
	char nom[15];
	//textcolor(3);
	system("color 74");
	printf("Votre nom : \n");
	//system("color 70");
	scanf("%s", &nom);
	//printf("------------");
	//strcpy(joueur->nom, nom);
	joueur_charge = charger_jeu(joueur_charge, nom);
	//printf("\nmmmmmmm---");
	//printf("\n %s %d", joueur_charge->nom, joueur_charge->score);
	//printf("%d", trouve);
	if(trouve == 1){
		//printf("\n------------");
		joueur = joueur_charge;
	}
	else if(trouve == 0){
		joueur = (Info_joueur*) malloc(sizeof(Info_joueur));
		strcpy(joueur->nom, &nom);
		printf("------------------------------------------\n");
		printf("Choix du niveau : \n 0 - Facile \t 1 - Defficille\n");
		//system("color 27");
		scanf("%d",&joueur->niveau);
		printf("------------------------------------------\n");
		printf("Entrer le nombre des mots (MAX : 16) \t");
		scanf("%d",&joueur->nb_mots);
		joueur->score = 1;
		
	}
		if(joueur->niveau == 0)
			f_mots = fopen("mots_F.txt", "rt");
		else if(joueur->niveau == 1)
			f_mots = fopen("mots_D.txt", "rt");
	//printf("\n----tttttt--------");
	srand(time(NULL));
	ligneVoulu = nombreAleatoire(6);
	//printf("\nttttttttttttt\n");
	for(i = 0; i < joueur->nb_mots; i++){
		
		l = inserer(l, f_mots, ligneVoulu);
	}
	//printf("\nrrrrrrrrrr\n");
	printf("------------------------------------------\n");
	afficher(l);
	// Ordonnanncement des mots
	printf("------------------------------------------\n");
	printf("\nOrdonner les mots \n");
	for(i = 0; i < joueur->nb_mots; i++){ 
		ll = scan(ll);
	}
	// affichage des mots entrées
	printf("------------------------------------------\n");
	printf("Votre reponse donc est : \n");
	afficher(ll); 
	
	printf("\n--------");
	Tri_Selection(l);
	//afficher(l);

	comparer(l, ll);
	l = supprimer_liste(l, joueur->nb_mots);
	ll = supprimer_liste(ll, joueur->nb_mots);
	
	while((m == 1) && (joueur->score < 10)){
		joueur->score = joueur->score + 1;
		printf("------------------------------------------\n");
		printf("\n %d eme stage ouvert :D \n", joueur->score);
		ligneVoulu = nombreAleatoire(12);
		m = 0; 
		
		for(i = 0; i < joueur->nb_mots; i++){
			l = inserer(l, f_mots, ligneVoulu);
		}
		
		printf("------------------------------------------\n");
		afficher(l);
		// Ordonnanncement des mots
		printf("------------------------------------------\n");
		printf("\nOrdonner les mots \n");
		for(i = 0; i < joueur->nb_mots; i++){ 
			ll = scan(ll);
		}
		// affichage des mots entrées
		printf("------------------------------------------\n");
		printf("Votre reponse donc est : \n");
		afficher(ll); 
		
		printf("\n--------");
		Tri_Selection(l);
		//afficher(l);
	
		comparer(l, ll);
		l = supprimer_liste(l, joueur->nb_mots);
		ll = supprimer_liste(ll, joueur->nb_mots);
	}
	if(joueur->score == 10){
		printf("\nTu gagne le Champions, Felecitations! :D :D :D");
		printf("\nTu peux relancer le jeu a nouveau :)");
	}
	
	fclose(f_mots);

	sauvegarder_jeu(joueur);
	
	//system("PAUSE");
	return 0;
}
