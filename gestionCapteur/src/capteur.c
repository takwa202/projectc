#include<stdio.h>
#include<stdlib.h>
#include "callbacks.h"
#include<string.h>
#include <gtk/gtk.h>
#include "interface.h"








/*
char id[30];
char marque[30];
char type[30];
float valeur;
char dateAjout[30];
char etat[30];
*/
/***********f1*************/
void ajouter_capteur(capteur cap){
FILE*f=NULL;
f=fopen("capteur.txt","a+");//(+) creation du fichier sil nexsite pas
fprintf(f,"%s %s %s %f %s %s\n",cap.id,cap.marque,cap.type,cap.valeur,cap.dateAjout,cap.etat);
fclose(f);
}

/*********f2*************/

int exist_capteur(char*id){
FILE*f=NULL;
capteur cap;
f=fopen("capteur.txt","r");
while(fscanf(f,"%s %s %s %f %s %s\n",cap.id,cap.marque,cap.type,&cap.valeur,cap.dateAjout,cap.etat)!=EOF){
if(strcmp(cap.id,id)==0)return 1;
}
fclose(f);
return 0;
}

/***********f3***********/
void supprimer_capteur(char*id){

FILE*f=NULL;
FILE*f1=NULL;
capteur cap ;
f=fopen("capteur.txt","r");
f1=fopen("ancien.txt","w+");
while(fscanf(f,"%s %s %s %f %s %s\n",cap.id,cap.marque,cap.type,&cap.valeur,cap.dateAjout,cap.etat)!=EOF){
if(strcmp(id,cap.id)!=0)fprintf(f1,"%s %s %s %.3f %s %s\n",cap.id,cap.marque,cap.type,cap.valeur,cap.dateAjout,cap.etat);
}
fclose(f);
fclose(f1);
remove("capteur.txt");
rename("ancien.txt","capteur.txt");

}
/****************************f4**********/

capteur trouver_capteur(char*id){

FILE*f=NULL;
capteur cap ;
capteur cap1 ;
int b=0;
f=fopen("capteur.txt","r");
while(fscanf(f,"%s %s %s %f %s %s\n",cap.id,cap.marque,cap.type,&cap.valeur,cap.dateAjout,cap.etat)!=EOF){
if (strcmp(cap.id,id)==0)
{
cap1=cap;
b=1;
}

}
fclose(f);
if(b==0){
strcpy(cap1.id,"null");
}

return  cap1;

}

/**********f5***********/
void modifier_capteur(capteur c){

FILE*f=NULL;
FILE*f1=NULL;
capteur cap ;
f=fopen("capteur.txt","r");

f1=fopen("ancien.txt","w+");
while(fscanf(f,"%s %s %s %f %s %s\n",cap.id,cap.marque,cap.type,&cap.valeur,cap.dateAjout,cap.etat)!=EOF){
if(strcmp(c.id,cap.id)!=0){fprintf(f1,"%s %s %s %.3f %s %s\n",cap.id,cap.marque,cap.type,cap.valeur,cap.dateAjout,cap.etat);
}else{
fprintf(f1,"%s %s %s %.3f %s %s\n",c.id,c.marque,c.type,c.valeur,c.dateAjout,c.etat);
}
}
fclose(f);
fclose(f1);
remove("capteur.txt");
rename("ancien.txt","capteur.txt");




}
        /******************f7*******************/ 

afficher_single_capteur(GtkWidget* treeview1,capteur cap){


GtkListStore *adstore;/*creation du modele de type liste*/
GtkTreeViewColumn *adcolumn;/*visualisation des colonnes*/
GtkCellRenderer *cellad;/*afficheur de cellule(text,image..)*/
GtkTreeIter Iter;



        /* Creation du modele */
        adstore=gtk_list_store_new(6,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_FLOAT,
G_TYPE_STRING,G_TYPE_STRING);
          /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &Iter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &Iter,0,cap.id,1,cap.marque,2,cap.type,
3,cap.valeur,4,cap.dateAjout,5,cap.etat,-1);
          
            /* Creation de la 1ere colonne */
 if(i==0)// i = 0 seulement pour la premierre fois
	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ID",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("MARQUE",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("TYPE",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("VALEUR",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("DATE AJOUT",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

               /* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ETAT",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	i++;// i diff a 0 
       }


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );



}


void treeViewCapteur(GtkWidget* treeview1,char*l){

GtkListStore *adstore;/*creation du modele de type liste*/
GtkTreeViewColumn *adcolumn;/*visualisation des colonnes*/
GtkCellRenderer *cellad;/*afficheur de cellule(text,image..)*/
FILE *f;
GtkTreeIter Iter;
capteur cap;

        /* Creation du modele */
adstore = gtk_list_store_new(6,G_TYPE_STRING,G_TYPE_STRING,
G_TYPE_STRING,G_TYPE_FLOAT,G_TYPE_STRING,G_TYPE_STRING);
        /* Insertion des elements */
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %f %s %s\n",cap.id,cap.marque,cap.type,&cap.valeur,cap.dateAjout,cap.etat)!=EOF)
        {
         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &Iter);
         /* Mise a jour des donnees */
 gtk_list_store_set(adstore, &Iter,0,cap.id,1,cap.marque,2,cap.type,3,cap.valeur,4,cap.dateAjout,5,cap.etat,-1);}
  fclose(f);
/*********************************************************/
	/* Creation de la 1ere colonne */

//creation des Entetes s'execute une seule fois 
if(i==0)
	{ cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ID",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("MARQUE",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("TYPE",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("VALEUR",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("DATE AJOUT",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ETAT",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	i++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );

}
