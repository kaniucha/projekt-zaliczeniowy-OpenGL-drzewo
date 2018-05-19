#include "galaz.h"
#include <cstdlib>
#include <time.h>
#include "constants.h"
#include <stdio.h>

int min_dl_galezi=40;
int max_dl_galezi=100; // przez 10
int min_gr_galezi=1;
int max_gr_galezi=10; //przez 10


int galaz::losuj(int mini, int maxi)
    {
    int range = maxi-mini + 1;
	return rand()%range + mini;
    };


void galaz:: losuj_dlugosc_galezi()
    {
    int r=losuj(min_dl_galezi,max_dl_galezi);
    dlugosc_galezi=float(r)/10;
    };


void galaz:: losuj_grubosc_galezi()
   {
    int r=losuj(min_gr_galezi,max_gr_galezi);
    grubosc_galezi=float(r)/10;
    };

void galaz:: losuj_wys_galezi_na_matce()
    {
    int r=losuj(1,10);
    float temp=float(r)/10;
    wys_galezi_na_matce=temp;
    };



void galaz:: losuj_kat_na_matce()
    {
    int r=losuj(0,200);
    kat_na_matce=float(r*PI/100);
    };

//od 15 do 60
void galaz:: losuj_kat_do_pionu()
    {
    int r=losuj(1,10);
     kat_do_pionu=float(PI/r);
    };

galaz::galaz()
{
    losuj_dlugosc_galezi();
    losuj_grubosc_galezi();
    losuj_wys_galezi_na_matce();
    losuj_kat_na_matce();
    losuj_kat_do_pionu();
}

galaz::~galaz()
{
    //dtor
}
