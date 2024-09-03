#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200

int counter;
char  titre[MAX][30];
char  auteur[MAX][30];
float prix[MAX];
int quantite[MAX];

void ajouter(){

    counter++;
    printf("Entrez le titre du livre\n");
    scanf("%s", &titre[counter]);
    printf("Entrez l\'auteur du livre\n");
    scanf("%s", &auteur[counter]);
    printf("Entrez le prix du livre\n");
    scanf("%f", &prix[counter]);
    printf("Entrez le quantite du livre\n");
    scanf("%d", &quantite[counter]);
    printf("le livre a ete ajoute avec succes\n");

}

void afficher(){
    int i;
    for (i=0; i<counter; i++){
        printf("le titre : %s, l'auteur : %s, le prix : %.2f, la quantite : %d", titre[i+1], auteur[i+1], prix[i+1], quantite[i+1]);
    }
}

void rechercher(char * s){
    for(int i=0; i<counter; i++){
        if(!strcmp(s, titre[i])){
            printf("livre %s trouvé\n",s);
        }
    }
    printf("livre n'est pas dans le stock");
}

void mettreAJour(char * titre_, int quantite_){
    for (int i=0 ; i<counter; i++){
        if(!strcmp(titre_, titre[i])){
            quantite[i]=quantite_;
        }
    }
}

void afficherTotal(){
    int sum=0;
    for(int i = 0 ; i<counter; i++){
        sum+=quantite[i];
    }
    printf("le nombre total de livres en stock est %d,",sum);
}

int main(){
    int choix ;
    do{
        printf("---Menu---\n\n");
        printf("1- Ajouter un livre au stock\n");
        printf("2- Afficher tous les livres dispo\n");
        printf("3- Rechercher un livre par son titre\n");
        printf("4- Mettre a jour la quantite d un livre\n");
        printf("5- Supprimer un livre du stock\n");
        printf("6- Afficher le nombre total de livres en stock\n");
        printf("0- Quitter \n");
        printf("\n Votre choix \n\n");
        scanf("%d", &choix);
        if(choix == 1)
        {
            ajouter();
        }else if(choix == 2){
            afficher();
        }else if( choix ==3 ){
            char search[20];
            printf("entrez le titre que vous recherchez\n");
            scanf("%s", search);
            rechercher(search);
        }else if (choix == 4){
            char * titre__;
            int quantite__;
            printf("entrez le titre du livre que vous voulez mettre a jour\n");
            scanf("%s", titre__);
            printf("entrer la nouvelle quantite\n");
            scanf("%d", quantite__);
            mettreAJour(titre__, quantite__);
        } else if ( choix == 6 ){
            afficherTotal();
        }
        else if (choix == 0){ break; }


    }while(choix!=0);



}
