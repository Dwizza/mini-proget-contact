#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct contacts{
    char nom[50];
    char n_telephone[50];
    char e_mail[50];
};
struct contacts contact[100];
int count=0;

void menu(){
    printf("---------------menu------------------\n");
    printf("1. Ajouter un Contact.\n");
    printf("2. Modifier un Contact\n");
    printf("3. Supprimer un Contact\n");
    printf("4. Afficher Tous les Contacts\n");
    printf("5. Rechercher un Contact\n");
    printf("6. Quitter.\n");
}
void add(){
    int n,i;
    printf("------------------\n");
    printf("Combien de contact tu veux entrer :");
    scanf("%d",&n);
    for ( i =0;i<n;i++){
    printf("------------------\n");
    printf("Entrez votre nom et prenom :");
    scanf(" %[^\n]s",contact[i].nom);
    printf("Entrez votre numero de telephone :");
    scanf(" %[^\n]s",contact[i].n_telephone);
    printf("Entrez votre email :");
    scanf(" %[^\n]",contact[i].e_mail);
    count++;
}
}
void modifier(){
    char nom_modif[20];
    char tel_modif[20];
    char mail_modif[20];
    int choix,cmp;
    if(count==0){
        printf("------------------\n");
        printf("Il n'y a aucun contact !\n");
        printf("------------------\n");
        }
    else {
    printf("Entrez le nom de contact qui tu veux modifier :");
    scanf(" %[^\n]s",&nom_modif);
    for(int i=0;i<=count;i++){
        cmp=strcmp(contact[i].nom,nom_modif);
    if (cmp==0){
            printf("------------------\n");
            printf("1. Modifer le numero de telephone.\n");
            printf("2. Modifier l'email.\n");
            printf("3. Modifier le numero de telephone et l'email.\n");
            printf("Entrez votre choix :");
            scanf("%d",&choix);
        switch(choix){
        case 1:
            printf("Entrez le nouveau numero de telephone :");
            scanf(" %[^\n]s",&tel_modif);
            strcpy(contact[i].n_telephone,tel_modif);
            printf("Votre modification est bien effectuer.\n");
            break;
        case 2:
            printf("Entrez le nouveau Email :");
            scanf(" %[^\n]s",&mail_modif);
            strcpy(contact[i].e_mail,mail_modif);
            printf("Votre modification est bien effectuer.\n");
            break;
        case 3:
            printf("Entrez le nouveau numero de telephone :");
            scanf(" %[^\n]s",&tel_modif);
            strcpy(contact[i].n_telephone,tel_modif);
            printf("Entrez le nouveau Email :");
            scanf(" %[^\n]s",&mail_modif);
            strcpy(contact[i].e_mail,mail_modif);
            printf("Votre modification est bien effectuer.\n");
            break;
        }
      }
    }
  }
}
void supprimer(){
    char nom_sup[20];
    if (count==0){
        printf("------------------\n");
        printf("il n'y a aucun contact.\n");

    }
    else{
    printf("Entrez le nom du contact que tu veux supprimer :");
    scanf(" %[^\n]s",&nom_sup);
    for (int i=0;i<count;i++){
        if (strcmp(contact[i].nom,nom_sup)==0){
                for (int j=i;j<count;j++){
            contact[j]=contact[j+1];}
            count--;
     }
    }
  }
}
void affichage(){
    if (count==0){
        printf("------------------\n");
        printf("aucun contact a afficher !\n");
    }
    int a,b;
    char temp[20];
    for(int i=0;i<count;i++){
    if(count>0){

        printf("le nom :%s\n",contact[i].nom);
        printf("n.telephone : %s\n",contact[i].n_telephone);
        printf("E-mail : %s\n",contact[i].e_mail);
        }
    }
}
void recherche(){
    char nom_recherche[20];
    if (count==0){
        printf("------------------\n");
        printf("aucun contact a afficher !\n");
    }
    else{
    printf("Entrez le nom que tu veux chercher :");
    scanf(" %[^\n]s",&nom_recherche);


    for(int i=0;i<count;i++){
        if(strcmp(contact[i].nom,nom_recherche)==0){
            printf("le nom : %s\n",contact[i].nom);
            printf("n_telephone : %s\n",contact[i].n_telephone);
            printf("E-mail : %s\n",contact[i].e_mail);

        }

    }
}
}

int main(){
    int choix;
    do{
            menu();
            printf("Entrez votre choix :");
            scanf("%d",&choix);
        switch(choix){
        case 1 :
            add();
            break;
        case 2 :
            modifier();
            break;
        case 3 :
            supprimer();
            break;
        case 4 :
            affichage();
            break;
        case 5:
            recherche();
            break;
        case 6:
            exit(0);

        }


    }while(choix<100);

    return 0;
}

