#ifndef H_RANGEMENT
#define H_RANGEMENT


	int m;
	int trouve = 0;
	
	typedef struct liste {
		char str[15];
		struct liste *suivant;
	}liste;
	
	typedef struct Info_joueur
	{
	        char nom[15];
	        int score;
	        int niveau;
	        int nb_mots;
	}Info_joueur;
	
	liste *inserer(liste*, FILE*, int);
	void afficher(liste*);
	liste* scan(liste*);
	void Tri_Selection(liste*);
	void comparer(liste*, liste*);
	liste* supprimer_liste(liste*, int);
	void sauvegarder_jeu(Info_joueur*);
	Info_joueur* charger_jeu(Info_joueur*, char nom[]);
	int nombreAleatoire(int);

#endif	
