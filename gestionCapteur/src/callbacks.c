#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <string.h>
#include"capteur.h"
#include"dash.h"


void//retour
on_gestionCapteur_menu_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_destroy (gestionCapteur);
gtk_widget_show (menu);
}

void
on_ajouter_capteur_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *entryID;
GtkWidget *radiobutt1;
GtkWidget *radiobutt2;
GtkWidget *check1;
GtkWidget *check2;
GtkWidget *comboMarque;
GtkWidget *calendar;
int jj,mm,aa,b=1;//b utilise pour le controle
capteur c;
GtkWidget *p;


p=lookup_widget(gestionCapteur,"treeview1");


entryID=lookup_widget(gestionCapteur,"entry1");

comboMarque=lookup_widget(gestionCapteur,"combobox1");

radiobutt1=lookup_widget(gestionCapteur,"radiobutton1");
radiobutt2=lookup_widget(gestionCapteur,"radiobutton2");

check1=lookup_widget(gestionCapteur,"checkbutton1");
check2=lookup_widget(gestionCapteur,"checkbutton2");
calendar=lookup_widget(gestionCapteur,"calendar1");//CALENDR


strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(entryID)));

if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check1) )){
strcpy(c.type,"temperature");
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check2) )){
strcpy(c.type,"humidite");
}

if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(radiobutt1) )){
strcpy(c.etat,"active");
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(radiobutt2) )){
strcpy(c.etat,"non_active");
}

c.valeur=gtk_spin_button_get_value_as_float (GTK_SPIN_BUTTON (lookup_widget(gestionCapteur,"spinbutton1")));




/*controle de saisie*/
                       /*---msg controle id ---*/
if(strcmp(c.id,"")==0){
		  gtk_widget_show (lookup_widget(gestionCapteur,"label17"));
b=0;
}
else {
		  gtk_widget_hide(lookup_widget(gestionCapteur,"label17"));
}


                     /* --- msg controle combobox ---*/
        
if(gtk_combo_box_get_active (GTK_COMBO_BOX(comboMarque))==-1){
                gtk_widget_show (lookup_widget(gestionCapteur,"label18"));
b=0;
}
else{

           gtk_widget_hide (lookup_widget(gestionCapteur,"label18"));
}





if(b==1){

      /* ajouter les donne du combobox si il ya pas problem */

strcpy(c.marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboMarque)));



gtk_calendar_get_date (GTK_CALENDAR(calendar),&aa, &mm,&jj);//fct GTK pour recuperer la date

sprintf(c.dateAjout,"%d/%d/%d",jj,mm+1,aa);//convertion int => chaine(moins na9es dima 1)
                  /* controle l'ors d'ajout si id existe ou pas */

if(exist_capteur(c.id)==1)
        {

													gtk_widget_show(lookup_widget(gestionCapteur,"label16"));//show msg
        }
        else {
						  gtk_widget_hide(lookup_widget(gestionCapteur,"label16"));//hide msg
                ajouter_capteur(c);

						  gtk_widget_show(lookup_widget(gestionCapteur,"label9"));//ajoute avec succ

		/*Mise a jour treeView*/
		treeViewCapteur(p,"capteur.txt");
        }




}






}

             /*.............spp capteur.................. */
void
on_supprimer_capteur_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *entryID;
GtkWidget *p;
int b=1;
char id[30];
p=lookup_widget(gestionCapteur,"treeview1");
entryID=lookup_widget(gestionCapteur,"entry2");

strcpy(id,gtk_entry_get_text(GTK_ENTRY(entryID)));
/* controle de saisie id*/
if(strcmp(id,"")==0){
		  gtk_widget_show
(lookup_widget(gestionCapteur,"label21"));//affich msg 
b=0;
}
else {
		  gtk_widget_hide(lookup_widget(gestionCapteur,"label21"));
}
/* verf de le'existance du id dans la base de donne */
if(b==1){

	if(exist_capteur(id)==0)
        {

gtk_widget_show (lookup_widget(gestionCapteur,"label22"));//show msg err
        }
        else {
gtk_widget_hide (lookup_widget(gestionCapteur,"label22"));//hide msg et supp le capt
              supprimer_capteur(id);

gtk_widget_show (lookup_widget(gestionCapteur,"label24"));
		/*Mise a jour treeView*/

		treeViewCapteur(p,"capteur.txt");
        }

}

}

/***********************************/
void/* bouton gestion capt*/ 
on_menu_gestionCapteur_activate       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *p;
gestionCapteur = create_gestionCapteur ();
p=lookup_widget(gestionCapteur,"treeview1");
i=0;//indise creation entete une seule fois  
/*creation treeView*/
treeViewCapteur(p,"capteur.txt");//remplir trev

gtk_widget_show (gestionCapteur);
gtk_widget_hide (menu);
}

/*************************************************************/
void
on_menu_CapteurAlarmante_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
capteurAlarmante = create_capteurAlarmante ();
gtk_widget_show (capteurAlarmante);
gtk_widget_hide (menu);
}

/*********************************/
void
on_modifier_capteur_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *labelID;
GtkWidget *radiobutt1;
GtkWidget *radiobutt2;
GtkWidget *check1;
GtkWidget *check2;
GtkWidget *comboMarque;
int jj,mm,aa,x1;
capteur c;
GtkWidget *p;
p=lookup_widget(gestionCapteur,"treeview1");

labelID=lookup_widget(gestionCapteur,"label38");

comboMarque=lookup_widget(gestionCapteur,"combobox2");

radiobutt1=lookup_widget(gestionCapteur,"radiobutton3");
radiobutt2=lookup_widget(gestionCapteur,"radiobutton4");

check1=lookup_widget(gestionCapteur,"checkbutton3");
check2=lookup_widget(gestionCapteur,"checkbutton4");





strcpy(c.id, gtk_label_get_text(GTK_LABEL(labelID)) );



if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check1) )){
strcpy(c.type,"temperature");
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check2) )){
strcpy(c.type,"humidite");
}

if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(radiobutt1) )){
strcpy(c.etat,"active");
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(radiobutt2) )){
strcpy(c.etat,"non_active");
}

c.valeur=gtk_spin_button_get_value_as_float (GTK_SPIN_BUTTON (lookup_widget(gestionCapteur,"spinbutton2")));

jj=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestionCapteur,"spinbutton3")));
mm=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestionCapteur,"spinbutton4")));
aa=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestionCapteur,"spinbutton5")));

strcpy(c.marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboMarque)));


sprintf(c.dateAjout,"%d/%d/%d",jj,mm,aa);



modifier_capteur(c);

gtk_widget_show (lookup_widget(gestionCapteur,"label39"));
/*Mise a jour treeView*/

		treeViewCapteur(p,"capteur.txt");

}


void/******* remplir ******/
on_remplir_capteur_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *labelID;
GtkWidget *radiobutt1;
GtkWidget *radiobutt2;
GtkWidget *check1;
GtkWidget *check2;
GtkWidget *comboMarque;
int jj,mm,aa,x1;

GtkTreeSelection *selection;
        GtkTreeModel *model;
        GtkTreeIter iter;
        GtkWidget* p;
        GtkWidget *label;
        gchar* id;
 capteur c;
//associer les objet avec les variables
        label=lookup_widget(gestionCapteur,"label37");
        p=lookup_widget(gestionCapteur,"treeview1");


labelID=lookup_widget(gestionCapteur,"label38");

comboMarque=lookup_widget(gestionCapteur,"combobox2");

radiobutt1=lookup_widget(gestionCapteur,"radiobutton3");
radiobutt2=lookup_widget(gestionCapteur,"radiobutton4");

check1=lookup_widget(gestionCapteur,"checkbutton3");
check2=lookup_widget(gestionCapteur,"checkbutton4");




        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));

        if (gtk_tree_selection_get_selected(selection, &model, &iter)) //verifier la selection du tableau
        {  gtk_tree_model_get (model,&iter,0,&id,-1);//recuperer id de la ligne selectionnée

gtk_widget_hide (lookup_widget(gestionCapteur,"label39"));//hide label modifié !

	c = trouver_capteur(id);
	//conversion chaine => int	
	/**/sscanf(c.dateAjout,"%d/%d/%d",&jj,&mm,&aa); 
	gtk_label_set_text(GTK_LABEL( labelID ),c.id);
	gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestionCapteur,"spinbutton2")),c.valeur);  
	gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestionCapteur,"spinbutton3")),jj);  
	gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestionCapteur,"spinbutton4")),mm);  
	gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestionCapteur,"spinbutton5")),aa);/*n3abou fe les valeur */  
/*remlir chek button et spin button*/	
if(strcmp(c.type,"temperature")==0){
gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(check1),TRUE );
}
if(strcmp(c.type,"humidite")==0){
gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(check2),TRUE );
}

if(strcmp(c.etat,"active")==0){
gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(radiobutt1),TRUE );
}
if(strcmp(c.etat,"non_active")==0){
gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(radiobutt2),TRUE );
}    


if(strcmp(c.marque,"M1")==0)x1=0;		
if(strcmp(c.marque,"M2")==0)x1=1;                
if(strcmp(c.marque,"M3")==0)x1=2 ;  
/*prmier choix combobox x=0,desieme x=1...et pas de choix =-1 */

gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(gestionCapteur,"combobox2")),x1);
       




 	   gtk_widget_show (lookup_widget(gestionCapteur,"button9"));//bouton modifier
           gtk_widget_hide (label);
	}else{
                gtk_widget_show (label);//msg err selectionee 
        }





}


void
on_affciher_seul_capteur_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* p;
GtkWidget *entryID;
char id[30];
int b=1;
capteur c;
p=lookup_widget(gestionCapteur,"treeview1");
entryID=lookup_widget(gestionCapteur,"entry3");

strcpy(id,gtk_entry_get_text(GTK_ENTRY(entryID)));

/*controle de saisie*/
if(strcmp(id,"")==0){
		  gtk_widget_show (lookup_widget(gestionCapteur,"label40"));
b=0;
}
else {
		  gtk_widget_hide(lookup_widget(gestionCapteur,"label40"));
}

if(b==1){

c = trouver_capteur(id);

if(strcmp(c.id,"null")==0){

		  gtk_widget_show (lookup_widget(gestionCapteur,"label35"));
}else{
		  gtk_widget_hide (lookup_widget(gestionCapteur,"label35"));

afficher_single_capteur(p,c);


}


}





}


void/***reset***/
on_affciher_reset_capteur_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *p;
p=lookup_widget(gestionCapteur,"treeview1");
treeViewCapteur(p,"capteur.txt");//fonction eli tjib tt les cap w t7othom fe tr
}


void
on_alarmante_capteur_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
int aa,m,i;
float seuil_minA=-3,seuil_minB=-1,seuil_maxA=50,seuil_maxB=69;

char fich[30];
char chId[30];
int capt[50];
char nombre[30];
char ch[200]="";
capteur c;
GtkWidget *radiobutt1;
GtkWidget *radiobutt2;

radiobutt1=lookup_widget(capteurAlarmante,"radiobutton5");
radiobutt2=lookup_widget(capteurAlarmante,"radiobutton6");

aa=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(capteurAlarmante,"spinbutton6")));

if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(radiobutt1) )){
strcpy(fich,"temperature.txt");
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(radiobutt2) )){
strcpy(fich,"humidite.txt");
}


m =remplire_id_capt(fich,aa,seuil_minA,seuil_minB,seuil_maxA,seuil_maxB,capt);

if(m!=0){

for(i=0;i<m;i++){
sprintf(chId,"%d",capt[i]);
c= trouver_capteur(chId);
strcat(ch,c.id);
strcat(ch,"\n");
}

gtk_widget_show (lookup_widget(capteurAlarmante,"label45") );

}else{
gtk_widget_hide (lookup_widget(capteurAlarmante,"label45") );
strcpy(ch,"aucun capteur ayant une valeur alarmante ! ");
}

gtk_label_set_text(GTK_LABEL( lookup_widget(capteurAlarmante,"label46") ),ch);








}


void
on_capteurAlarmante_menu_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (menu);
gtk_widget_destroy (capteurAlarmante);
}

