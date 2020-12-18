#ifndef CUERPO_H
#define CUERPO_H
#include <math.h>
#include <cmath>

class cuerpo
{
private:
    float PX;
    float PY;
    float VX;
    float VY;
    float radio;//DISTANCIA ENTRE DOS PLANETAS
    float masa;
    float AX;
    float AY;
    float G;
    float R; //(RADIO DEL PLANETA)

public:
    cuerpo(float px_, float py_, float vx_, float vy_,float masa_, float R_);

    float getPX() const;
    float getPY() const;
    float getMasa() const;
    float getR() const;

    void acelerar(float px2_, float py2_, float masa2);
    void actualizar(float dt);
};

#endif // CUERPO_H
