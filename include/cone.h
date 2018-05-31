#ifndef CONE_H
#define CONE_H


class cone
{

    public:
        cone();
        float *vertices;
        float *texCoords;
        void zrob_tablice();
        void drawCone();



        virtual ~cone();

    protected:

    private:
};

namespace coneNamespace {
            extern float vertices[];
            extern float texCoords[];
        };

#endif // CONE_H
