#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
typedef struct date
{   int jour;
    int mois;
    int annee;
}deadline;

typedef struct sas
{
int  identifiant;
char titre[20];
char description[50];
deadline deadline;
char statut[50];
}tache;
    static int Identifiant = 1;

int main() {
		printf("\t *****************Projet SAS Gestion de Taches ToDo*****************\n");

	int choix;
	tache taches[50];
	int size = 0 ;
    menu:
	printf(" 1--> Introduire une tache \n");
	printf(" 2--> Introduire des plusieurs taches \n");
	printf(" 3--> Affichage \n");
	printf(" 4--> Modifier une tache\n");
	printf(" 5--> Supprimer une tache \n");
    printf(" 6--> Chercher une tache \n");
    printf(" 7--> Statistique des tache \n");
    printf("veuillez saisir votre choix : ");
	scanf("%d",&choix);
    switch (choix)
    {
    case 1:{

			printf("enterer le titre du taches  : ");
			scanf(" %99[^\n]", &taches[size].titre);
			printf("entrer la description du taches : ");
			scanf(" %99[^\n]", &taches[size].description);
			printf("enterer le deadline de taches : ");
			scanf("%d", &taches[size].deadline.jour);
            scanf("%d", &taches[size].deadline.mois);
            scanf("%d", &taches[size].deadline.annee);
            printf("entrer le statut du taches : ");
			scanf(" %99[^\n]", &taches[size].statut);
            printf("\n \n");
            taches[size].identifiant = Identifiant;
			printf("Identifiant : %d\nTitre : %s\nDescription : %s\nDeadline : %d/%d/%d\nStatut : %s\n",
                           Identifiant, taches[size].titre, taches[size].description,
                           taches[size].deadline.jour, taches[size].deadline.mois, taches[size].deadline.annee,
                           taches[size].statut);
			size++;
			Identifiant++;
			goto menu ;
        break;
    }
     case 2:{
        int nbrT,i;
        printf("Combien des tachess tu veux le saisie : ");
        scanf("%d",&nbrT);
        for ( i = 0; i < nbrT; i++)
        {

			printf("enterer le titre du taches  : ");
			scanf(" %99[^\n]", &taches[size].titre);
			printf("entrer la description du taches : ");
			scanf(" %99[^\n]", &taches[size].description);
			printf("enterer le deadline de taches : ");
			scanf("%d", &taches[size].deadline.jour);
            scanf("%d", &taches[size].deadline.mois);
            scanf("%d", &taches[size].deadline.annee);
            printf("entrer le statut du taches : ");
			scanf(" %99[^\n]", &taches[size].statut);
			taches[size].identifiant = Identifiant;
			printf("Identifiant : %d\nTitre : %s\nDescription : %s\nDeadline : %d/%d/%d\nStatut : %s\n \n",
                           Identifiant, taches[size].titre, taches[size].description,
                           taches[size].deadline.jour, taches[size].deadline.mois, taches[size].deadline.annee,
                           taches[size].statut);
			size++;
			Identifiant++;

        }
			goto menu ;
        break;
    }
    case 3 :{
        int affiche;
        printf("\n");
        printf("1-->Trier les taches par ordre alphabetique. \n");
        printf("2-->Trier les taches par deadline. \n");
        printf("3-->Afficher les taches dont le deadline est dans 3 jours ou moins \n");
        printf("\n");
        printf("saisir votre choix : ");
        scanf("%d",&affiche);
        if (affiche == 1) {
        int i, j;
        tache tmp;
         for (i = 0; i < size - 1; i++) {
         for (j = i + 1; j < size; j++) {
            if (strcmp(taches[i].titre, taches[j].titre) > 0) {
                tmp = taches[i];
                taches[i] = taches[j];
                taches[j] = tmp;
            }
        }
    }
        for ( i=0 ; i<size ; i++) {
            printf("Identifiant : %d\nTitre : %s\nDescription : %s\nDeadline : %d/%d/%d\nStatut : %s\n \n",
                           taches[i].identifiant, taches[i].titre, taches[i].description,
                           taches[i].deadline.jour, taches[i].deadline.mois, taches[i].deadline.annee,
                           taches[i].statut);
        }
        goto menu;
}
      if (affiche == 2) {
    tache tmp;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (taches[i].deadline.annee > taches[j].deadline.annee) {
                tmp = taches[i];
                taches[i] = taches[j];
                taches[j] = tmp;
            } else if (taches[i].deadline.annee == taches[j].deadline.annee) {
                if (taches[i].deadline.mois > taches[j].deadline.mois) {
                    tmp = taches[i];
                    taches[i] = taches[j];
                    taches[j] = tmp;
                } else if (taches[i].deadline.mois == taches[j].deadline.mois) {
                    if (taches[i].deadline.jour > taches[j].deadline.jour) {
                        tmp = taches[i];
                        taches[i] = taches[j];
                        taches[j] = tmp;
                    }
                }
            }
        }
    }

    for (int i = 0; i < size; i++) {
        printf("Identifiant : %d\nTitre : %s\nDescription : %s\nDeadline : %d/%d/%d\nStatut : %s\n\n",
            taches[i].identifiant, taches[i].titre, taches[i].description,
            taches[i].deadline.jour, taches[i].deadline.mois, taches[i].deadline.annee,
            taches[i].statut);
    }
     }
    if (affiche == 3) {
    printf("Tâches avec un délai de 3 jours ou moins :\n");
    for (int i = 0; i < size; i++) {
        // Calculer le nombre de jours restants jusqu'au délai de la tâche
        int jours = taches[i].deadline.annee * 365 + taches[i].deadline.mois * 30 + taches[i].deadline.jour;
        time_t seconds = time(NULL);
        struct tm *current_time = localtime(&seconds);
        int currentYear = (current_time->tm_year + 1900);
        int currentMonth = (current_time->tm_mon + 1);
        int currentDay = current_time->tm_mday;
        int delai_jour = jours - (currentYear * 365 + currentMonth * 30 + currentDay);

        // Vérifier si le délai est de 3 jours ou moins
        if (delai_jour <= 3 && delai_jour >= 0) {
            printf("Identifiant : %d\nTitre : %s\nDescription : %s\nDeadline : %d/%d/%d\nStatut : %s\n\n",
                taches[i].identifiant, taches[i].titre, taches[i].description,
                taches[i].deadline.jour, taches[i].deadline.mois, taches[i].deadline.annee,
                taches[i].statut);
        }
    }
    goto menu;
    break;
}

    }

case 4: {
    int affiche;
    printf("\n");
    printf("1--> Modifier la description d'une tache\n");
    printf("2--> Modifier le statut d'une tâche\n");
    printf("3--> Modifier le deadline d'une tâche\n");
    printf("Veuillez saisir votre choix : ");
    printf("\n");
    scanf("%d", &affiche);

    int tr = 0; // Variable pour suivre si la tâche a été trouvée

    if (affiche == 1) {
        int id;
        printf("Entrer l'identifiant du tache pour modifier sa description : ");
        scanf("%d", &id);
        for (int i = 0; i < size; i++) {
            if (taches[i].identifiant == id) {
                tr = 1; // Marquer la tâche comme trouvée
                printf("La tache est trouvee.\n");
                printf("Identifiant : %d\nTitre : %s\nDescription : %s\nDeadline : %d/%d/%d\nStatut : %s\n\n",
                    taches[i].identifiant, taches[i].titre, taches[i].description,
                    taches[i].deadline.jour, taches[i].deadline.mois, taches[i].deadline.annee,
                    taches[i].statut);
                printf("Nouvelle description : ");
                scanf("%s", taches[i].description);
                printf("La modification a bien ete enregistre !!!\n");
            }
        }
    }

    if (affiche == 2) {
        int id;
        printf("Entrer l'identifiant du tache pour modifier le statut : ");
        scanf("%d", &id);
        for (int i = 0; i < size; i++) {
            if (taches[i].identifiant == id) {
                tr = 1; // Marquer la tâche comme trouvée
                printf("La tache est trouvee.\n");
                printf("Identifiant : %d\nTitre : %s\nDescription : %s\nDeadline : %d/%d/%d\nStatut : %s\n\n",
                    taches[i].identifiant, taches[i].titre, taches[i].description,
                    taches[i].deadline.jour, taches[i].deadline.mois, taches[i].deadline.annee,
                    taches[i].statut);
                printf("Nouveau statut : ");
                scanf("%s", taches[i].statut);
                printf("La modification a bien ete enregistre !!!\n");
            }
        }
    }
    if (affiche == 3) {
        int id;
        printf("Entrer l'identifiant du tache pour modifier le Deadline : ");
        scanf("%d", &id);
        for (int i = 0; i < size; i++) {
            if (taches[i].identifiant == id) {
                tr = 1; // Marquer la tâche comme trouvée
                printf("La tache est trouvee.\n");
                printf("Identifiant : %d\nTitre : %s\nDescription : %s\nDeadline : %d/%d/%d\nStatut : %s\n\n",
                    taches[i].identifiant, taches[i].titre, taches[i].description,
                    taches[i].deadline.jour, taches[i].deadline.mois, taches[i].deadline.annee,
                    taches[i].statut);
                printf("Nouveau deadline : ");
                scanf("%d %d %d", &taches[i].deadline.jour, &taches[i].deadline.mois, &taches[i].deadline.annee);
                printf("La modification a bien ete enregistre !!!\n");
            }
        }
    }

    if (tr == 0) {
        printf("Tache introuvable.\n");
    }
    goto menu;
    break;

}
    case 5 :{
        int id;
        int tr=0;
    printf("entrer id de la tache que tu veux le supprimer : ");
    scanf("%d",&id);
    for(int i =0;i<size;i++){
        if(taches[i].identifiant==id){
            printf("la tache est trouver !!\n");
            tr=1;
            for (int j=i;j<size-1;j++){
                taches[j+1]=taches[j];

            }size--;
                printf("Tache supprimee avec succes\n");
                    break;
        }

    }
              if (tr == 0) {
                printf("Tache introuvable.\n");
            }
            goto menu;
            break;
    }
    case 6 :{
        int affiche;
    printf("1-->Rechercher une tache par son Identifiant \n");
    printf("2-->Rechercher une tache par son Titre \n");
    printf("veuillez choisir votre votre choix :");
    scanf("%d",&affiche);
    if(affiche==1){
        int id;
        printf("entrer id de la tache que tu cherche : ");
        scanf("%d",&id);
        for(int i =0;i<size;i++){
            if(taches[i].identifiant==id){
                printf("la tache que tu cherche est exist !!\n");
                printf("\n");
                printf("Identifiant : %d\nTitre : %s\nDescription : %s\nDeadline : %d/%d/%d\nStatut : %s\n\n",
                    taches[i].identifiant, taches[i].titre, taches[i].description,
                    taches[i].deadline.jour, taches[i].deadline.mois, taches[i].deadline.annee,
                    taches[i].statut);
                printf("\n");

            }
            if(i==size){
            printf("la tache n'exist pas ");
        }
        }goto menu;
    }
         if(affiche==2){
        char titre[20];
        printf("entrer le titre de la tache que tu cherche : ");
        scanf("%s",&titre);
        for(int i =0;i<size;i++){
            if(strcmp(taches[i].titre,titre)==0){

                printf("la tache que tu cherche est exist !!\n");
                printf("\n");
                printf("Identifiant : %d\nTitre : %s\nDescription : %s\nDeadline : %d/%d/%d\nStatut : %s\n\n",
                    taches[i].identifiant, taches[i].titre, taches[i].description,
                    taches[i].deadline.jour, taches[i].deadline.mois, taches[i].deadline.annee,
                    taches[i].statut);
                    printf("\n");

            }
            if(i==size){
            printf("la tache n'exist pas ");
        }
        }goto menu;
    }
}
    case 7:{
        int affiche;
    printf("1-->Afficher le nombre total des taches.\n");
    printf("2-->Afficher le nombre des tâches complètes et incomplètes.\n");
    printf("3-->Afficher le nombre des jours restants jusqu'au délai de chaque tâche.\n");
    printf("saisir votre choix : ");
    scanf("%d",&affiche);
    if(affiche==1){
        printf("le nombre total des taches est  :%d \n",size);
        goto menu;
    }
    if(affiche ==2){
        int tcomlet=0;
        int tincomplet=0;
        for(int i =0;i<size;i++){
           if(strcmp(taches[i].statut, "a realiser") == 0 || strcmp(taches[i].statut, "en cours de realisation") == 0){
        tincomplet++;
        }
        else if (strcmp(taches[i].statut, "finalise") == 0) {
        tcomlet++;
        }
        }
         printf("les taches complet : %d taches \n",tcomlet);
            printf("les taches incomplet : %d taches \n",tincomplet);
            goto menu;
    }

 if (affiche==3) {
    printf("Tâches avec le délai des jours restants :\n");
    time_t seconds = time(NULL);
    struct tm *current_time = localtime(&seconds);
    int currentYear = (current_time->tm_year + 1900);
    int currentMonth = (current_time->tm_mon + 1);
    int currentDay = current_time->tm_mday;

    for (int i = 0; i < size; i++) {
        // Calculer le nombre de jours restants jusqu'au délai de la tâche
        int jours = taches[i].deadline.annee * 365 + taches[i].deadline.mois * 30 + taches[i].deadline.jour;
        int delai_jour = jours - (currentYear * 365 + currentMonth * 30 + currentDay);

            printf("Identifiant : %d\nTitre : %s\nDescription : %s\nDeadline : %d/%d/%d\nStatut : %s\nNombre de jours restants : %d\n\n",
                taches[i].identifiant, taches[i].titre, taches[i].description,
                taches[i].deadline.jour, taches[i].deadline.mois, taches[i].deadline.annee,
                taches[i].statut, delai_jour);

    }

    goto menu;
}


    }

    }
return 0;
}
