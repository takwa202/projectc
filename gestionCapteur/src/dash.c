#include<stdio.h>
#include<stdlib.h>
#include "callbacks.h"
#include<string.h>




int exist_cap(tabCapteurs*e,int n,int id){
int i=0;
for(i=0;i<n;i++){
    if(e[i].id_cap==id)return 1;
}
return 0;
}



int remplire_numero(tabCapteurs*e,int aa,char*fich){
FILE*f=NULL;
int i=-1,id;
temperature t;
f=fopen(fich,"r");
while(fscanf(f,"%s %d %d %d %f\n",t.idCapteur,&t.jj,&t.mm,&t.aa,&t.valeur)!=EOF){
        if(t.aa ==aa){
sscanf(t.idCapteur,"%d",&id);
if(exist_cap(e,i+1,id)==0){
i++;
e[i].id_cap=id;
}
}

}

fclose(f);
return i+1;
}

float calculer_max(int id,int aa,char*fich){
FILE*f=NULL;
int id1;
float max=-500;
temperature t;
f=fopen(fich,"r");
while(fscanf(f,"%s %d %d %d %f\n",t.idCapteur,&t.jj,&t.mm,&t.aa,&t.valeur)!=EOF){
sscanf(t.idCapteur,"%d",&id1);
if(aa==t.aa && id==id1){

if(t.valeur>max){
    max=t.valeur;
}

}

}
fclose(f);
return max;
}
float calculer_min(int id,int aa,char*fich){
FILE*f=NULL;
int id1;
float min=1000;
temperature t;
f=fopen(fich,"r");
while(fscanf(f,"%s %d %d %d %f\n",t.idCapteur,&t.jj,&t.mm,&t.aa,&t.valeur)!=EOF){
sscanf(t.idCapteur,"%d",&id1);
if(aa==t.aa && id==id1){

if(t.valeur<min){
    min=t.valeur;
}

}
}
fclose(f);
return min;
}

int remplire_id_capt(char*fich,int aa,float seuil_minA,float seuil_minB,float seuil_maxA,float seuil_maxB,int*capt){
int n,j=-1,i;
tabCapteurs e[50];
// remplissage les ids des capteurs dans le fichier humidite ou temperature.txt ==> e[i].id_cap
n = remplire_numero(e,aa,fich);

for (i=0;i<n;i++){
    printf("id = %d \t",e[i].id_cap);
    e[i].max_cap = calculer_max(e[i].id_cap,aa,fich);
    e[i].min_cap = calculer_min(e[i].id_cap,aa,fich);
    printf("max_cap=%f\t",e[i].max_cap);
    printf("min_cap = %f\n",e[i].min_cap);

    if((e[i].min_cap>=seuil_minA && e[i].min_cap<=seuil_minB) ||  (e[i].max_cap>=seuil_maxA && e[i].max_cap<=seuil_maxB)    ){

        j++;
        capt[j]=e[i].id_cap;
        printf("ce capteur dans l'intervalle [-4,-2] ou [50,69] : %d\n",capt[j]);

    }
}

return j+1;
}
