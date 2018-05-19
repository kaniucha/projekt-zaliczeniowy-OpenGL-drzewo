#ifndef GALAZ_H
#define GALAZ_H


class galaz
{
    public:
        galaz();
        virtual ~galaz();
        int losuj(int mini, int maxi);
        void losuj_dlugosc_galezi();
        void losuj_grubosc_galezi();
        void losuj_wys_galezi_na_matce();
        void losuj_kat_na_matce();
        void losuj_kat_do_pionu();
        float kat_do_pionu;
        float dlugosc_galezi;
        float wys_galezi_na_matce;
        float kat_na_matce;
        float grubosc_galezi;

    private:
};

#endif // GALAZ_H
