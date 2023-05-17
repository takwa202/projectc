#include <gtk/gtk.h>
typedef struct capteur capteur;
struct capteur{
char id[30];
char marque[30];
char type[30];
float valeur;
char dateAjout[30];
char etat[30];
};

typedef struct temperature temperature;
struct temperature{
char idCapteur[20];
int jj;
int mm;
int aa;
float valeur;
};

typedef struct tabCapteurs tabCapteurs;
struct tabCapteurs{
int id_cap;
float max_cap;
float min_cap;
};



int i;


GtkWidget *gestionCapteur;
GtkWidget *capteurAlarmante;
  GtkWidget *menu;
void
on_gestionCapteur_menu_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajouter_capteur_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_supprimer_capteur_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_menu_gestionCapteur_activate        (GtkButton       *button,
                                        gpointer         user_data);

void
on_menu_CapteurAlarmante_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifier_capteur_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_remplir_capteur_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_affciher_seul_capteur_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_affciher_reset_capteur_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_alarmante_capteur_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_capteurAlarmante_menu_clicked       (GtkButton       *button,
                                        gpointer         user_data);
