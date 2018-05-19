#ifndef LISC_H
#define LISC_H


class lisc
{
    public:
        lisc();
        virtual ~lisc();
        int wys_liscia;
        int szer_liscia;
        int typ_liscia;

        void losuj_wys_liscia();
        void losuj_szer_liscia();
        void losuj_typ_liscia();
        void ustaw_teksture();
        int losuj (int mini, int maxi);
};

#endif // LISC_H
