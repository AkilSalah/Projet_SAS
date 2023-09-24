#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struct definitions...
typedef struct date
{
    int jour;
    int mois;
    int annee;
} deadline;

typedef struct sas
{
    int identifiant;
    char titre[20];
    char description[50];
    deadline deadline;
    char statut[50];
} tache;

static int Identifiant = 1;

// Function prototypes...
void menu();
void ajouter_tache(tache taches[], int *size);
void ajouter_plusieure_taches(tache taches[], int *size);
void affichage(tache taches[], int size);
void trie_alphabitique(tache taches[], int size);
void trie_deadline(tache taches[], int size);
void delai_trois_jours(tache taches[], int size);
void modification(tache taches[], int size);
void supprimer(tache taches[], int *size);
void recherche(tache taches[], int size);
void statistique(tache taches[], int size);

int main()
{
    printf("\n\t\t*********************** Projet SAS Gestion de Taches ToDo **************************\n\n");

    tache taches[100];
    int size = 0;
    int choix;

    while(1){
        menu();

        scanf("%d", &choix);

        printf("\n");

        switch (choix)
        {
        case 1:
            ajouter_tache(taches, &size);
            system("cls");
            affichage(taches, size);
            break;
        case 2:
            ajouter_plusieure_taches(taches, &size);
             system("cls");
            affichage(taches, size);
            break;
        case 3:{
            int affiche;
            affichage(taches,size);
            printf("\t\t >>>> MENU D'AFFICHAGE :\n");
            printf("\t\t 1 --> Trier les taches par ordre alphabetique.\n");
            printf("\t\t 2 --> Trier les taches par deadline.\n");
            printf("\t\t 3 --> Afficher les taches dont le deadline est dans 3 jours ou moins.\n\n");
            printf("Saisir votre choix : ");
            scanf("%d", &affiche);
            printf("\n");

        switch (affiche)
    {
            case 1:

                trie_alphabitique(taches, size);
                break;
            case 2:
                trie_deadline(taches, size);
                break;
            case 3:
                delai_trois_jours(taches, size);
                break;
            default:
                printf("Option invalide.\n");
            }
        }
            break;
        case 4:
            modification(taches, size);
            break;
        case 5:
            supprimer(taches, &size);
            break;
        case 6:
            recherche(taches, size);
            break;
        case 7:
            statistique(taches, size);
            break;
        case 8:
            printf("\n\t\t\t\t\t >>> AU REVOIR (: \n\n");
            return 0;
        default:
            printf("Votre choix est invalide !!\n");
        }

    }
    return 0;

}

void menu()
{
    printf("\t\t>>>> VOTRE MENU :\n");
    printf("\t\t1 --> Introduire une tache\n");
    printf("\t\t2 --> Introduire des plusieurs taches\n");
    printf("\t\t3 --> Affichage\n");
    printf("\t\t4 --> Modifier une tache\n");
    printf("\t\t5 --> Supprimer une tache\n");
    printf("\t\t6 --> Chercher une tache\n");
    printf("\t\t7 --> Statistique des taches\n");
    printf("\t\t8 --> Quitter le programme\n");
    printf("\t\t>>>> Veuillez saisir votre choix : ");
    
}

void ajouter_tache(tache taches[], int *size)
{
    int statut;
    printf("Entrer le titre de la tache  : ");
    scanf(" %[^\n]", taches[*size].titre);
    printf("Entrer la description de la tache  : ");
    scanf(" %[^\n]", taches[*size].description);
    printf("Entrer le deadline de la tache (jj mm aaaa)  : ");
    scanf("%d %d %d", &taches[*size].deadline.jour, &taches[*size].deadline.mois, &taches[*size].deadline.annee);
    printf("Entrer le statut de la tache  : \n");
    printf("Pour une tache a realiser, tapez 0\n");
    printf("Pour une tache en cours de realisation, tapez 1\n");
    printf("Pour une tache realiser, tapez 2\n");
    
    while (1) {
        printf("Taper votre choix : ");
        scanf("%d", &statut);
        
        if (statut == 0) {
            strcpy(taches[*size].statut, "A REALISER");
            break;
        } else if (statut == 1) {
            strcpy(taches[*size].statut, "EN COURS DE REALISATION");
            break;
        } else if (statut == 2) {
            strcpy(taches[*size].statut, "REALISER");
            break;
        } else {
            printf("Choix invalide, veuillez réessayer.\n");
        }
    }
    
    printf("\n");
    taches[*size].identifiant = Identifiant;
    Identifiant++;
    (*size)++;
}

void ajouter_plusieure_taches(tache taches[], int *size)
{
    int nbrT, i;
    printf("Combien de taches tu veux saisir : ");
    scanf("%d", &nbrT);
    for (i = 0; i < nbrT; i++)
    {
        ajouter_tache(taches, size);
    }
}

void affichage(tache taches[], int size)
{
    printf("\n------------------------\n");
    printf(" >>Listes des taches : \n");
    printf("------------------------\n");
    for (int i = 0; i < size; i++)
    {
        printf("Identifiant : %d\nTitre : %s\nDescription : %s\nDeadline : %d/%d/%d\nStatut : %s\n",
               taches[i].identifiant, taches[i].titre, taches[i].description,
               taches[i].deadline.jour, taches[i].deadline.mois, taches[i].deadline.annee,
               taches[i].statut);
        printf("\n");
    }
}

void trie_alphabitique(tache taches[], int size)
{
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
          system("cls");
        affichage(taches,size);
}

void trie_deadline(tache taches[], int size)
{
    tache tmp;
    for (int i = 0; i < size-1; i++) {
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
          system("cls");
           affichage(taches,size);

}

void delai_trois_jours(tache taches[], int size)
{
    printf("Taches avec un delai de 3 jours ou moins :\n");
    time_t seconds = time(NULL);
    struct tm *current_time = localtime(&seconds);
    int currentYear = (current_time->tm_year + 1900);
    int currentMonth = (current_time->tm_mon + 1);
    int currentDay = current_time->tm_mday;

    for (int i = 0; i < size; i++) {

        int jours = taches[i].deadline.annee * 365 + taches[i].deadline.mois * 30 + taches[i].deadline.jour;
        int delai_jour = jours - (currentYear * 365 + currentMonth * 30 + currentDay);

        system("cls");
        if (delai_jour <= 3 && delai_jour >= 0) {
            printf("Identifiant : %d\nTitre : %s\nDescription : %s\nDeadline : %d/%d/%d\nStatut : %s\n\n",
                   taches[i].identifiant, taches[i].titre, taches[i].description,
                   taches[i].deadline.jour, taches[i].deadline.mois, taches[i].deadline.annee,
                   taches[i].statut);
        }
    }
}

void modification(tache taches[], int size) {
    int id, found = 0;
    printf("Entrer l'identifiant de la tache à modifier : ");
    scanf("%d", &id);

    for (int i = 0; i < size; i++) {
        if (taches[i].identifiant == id) {
            found = 1;
            int choix;
            printf("\n");
            printf("\t\t >>>> Que voulez-vous modifier ?\n");
            printf("\t\t 1--> Description\n");
            printf("\t\t 2-->  Statut\n");
            printf("\t\t 3-->  Deadline\n");
            printf("Veuillez saisie votre choix :");
            scanf("%d", &choix);

            switch (choix) {
                case 1:
                    printf("Nouvelle description : ");
                    scanf(" %49s", taches[i].description);
                    break;
                case 2:
                    printf("Nouveau statut : ");
                    scanf(" %49s", taches[i].statut);
                    break;
                case 3:
                    printf("Nouvelle deadline (jj mm aaaa) : ");
                    scanf("%d %d %d", &taches[i].deadline.jour, &taches[i].deadline.mois, &taches[i].deadline.annee);
                    break;
                default:
                    printf("Option invalide.\n");
            }

            printf("La tache a ete modifiee avec succes.\n");
            break;
        }
    }

    if (!found) {
        printf("Tache non trouvee.\n");
    }
}

void supprimer(tache taches[], int *size)
{
    int id;
    int tr = 0;
    printf("Entrer l'identifiant de la tache que vous voulez supprimer : ");
    scanf("%d", &id);

    for (int i = 0; i < *size; i++) {
        if (taches[i].identifiant == id) {
            tr = 1;
            printf("La tache a ete trouvee !!\n");
            // Déplacer les tâches suivantes d'un cran vers le haut pour remplir l'emplacement supprimé
            for (int j = i; j < *size - 1; j++) {
                taches[j] = taches[j + 1];
            }

            (*size)--;
            printf("Tache supprimee avec succes.\n");
            break; // Vous pouvez sortir de la boucle dès que la tâche est trouvée et supprimée
        }
    }

    if (tr == 0) {
        printf("Tache introuvable.\n");
    }
}

void recherche(tache taches[], int size) {
    int choix;
    printf("\t\t >>>>MENU DE RECHERCHE :\n");
    printf("\t\t 1-->Recherche par ID\n");
    printf("\t\t 2-->Recherche par titre\n");
    printf("Taper votre choix : ");
    scanf("%d", &choix);

    switch (choix) {
        case 1: {
            int id;
            printf("Entrez l'ID de la tâche que vous recherchez : ");
            scanf("%d", &id);
            int found = 0;

            for (int i = 0; i < size; i++) {
                if (taches[i].identifiant == id) {
                    found = 1;
                      system("cls");
                    printf("La tache que vous cherchez existe :\n");
                    printf("Identifiant : %d\nTitre : %s\nDescription : %s\nDeadline : %d/%d/%d\nStatut : %s\n\n",
                           taches[i].identifiant, taches[i].titre, taches[i].description,
                           taches[i].deadline.jour, taches[i].deadline.mois, taches[i].deadline.annee,
                           taches[i].statut);
                    break;
                }
            }

            if (!found) {
                  system("cls");
                printf("La tache que vous cherchez n'existe pas.\n");
            }
            break;
        }

        case 2: {
            char titre[20];
            printf("Entrez le titre de la tache que vous recherchez : ");
            scanf(" %19s", titre);
            int found = 0;

            for (int i = 0; i < size; i++) {
                if (strcmp(taches[i].titre, titre) == 0) {
                    found = 1;
                      system("cls");
                    printf("La tache que vous cherchez existe :\n");
                    printf("Identifiant : %d\nTitre : %s\nDescription : %s\nDeadline : %d/%d/%d\nStatut : %s\n\n",
                           taches[i].identifiant, taches[i].titre, taches[i].description,
                           taches[i].deadline.jour, taches[i].deadline.mois, taches[i].deadline.annee,
                           taches[i].statut);
                }
            }

            if (!found) {
                  system("cls");
                printf("La tache que vous cherchez n'existe pas.\n");
            }
            break;
        }

        default:
            printf("Option invalide.\n");
    }
}

void statistique(tache taches[], int size){
    printf("\n");
 
            int complet = 0;
            int incomplet = 0;

            for (int i = 0; i < size; i++) {
                if (strcmp(taches[i].statut, "REALISER") == 0) {
                    complet++;
                } else {
                    incomplet++;
                }
            }
              system("cls");
            printf("\n------------------------\n");
            printf(" >> Statistiques des taches :   \n");
            printf("--------------------------\n");
            printf("Nombre total de taches : %d\n\n", size);
            printf("Nombre des taches completes : %d\n\n", complet);
            printf("Nombre des taches incompletes : %d\n\n", incomplet);
            printf("Taches avec le dalai des jours restants :\n\n");
            time_t seconds = time(NULL);
            struct tm *current_time = localtime(&seconds);
            int currentYear = (current_time->tm_year + 1900);
            int currentMonth = (current_time->tm_mon + 1);
            int currentDay = current_time->tm_mday;

            for (int i = 0; i < size; i++) {
                // Calculer le nombre de jours restants jusqu'à la deadline de la tâche
                int jours = taches[i].deadline.annee * 365 + taches[i].deadline.mois * 30 + taches[i].deadline.jour;
                int delai_jour = jours - (currentYear * 365 + currentMonth * 30 + currentDay);

                printf("Identifiant : %d\nTitre : %s\nDescription : %s\nDeadline : %d/%d/%d\nStatut : %s\nNombre de jours restants : %d\n\n",
                    taches[i].identifiant, taches[i].titre, taches[i].description,
                    taches[i].deadline.jour, taches[i].deadline.mois, taches[i].deadline.annee,
                    taches[i].statut, delai_jour);
            }
    
}
