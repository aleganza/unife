#include <stdio.h>
#include <math.h>

#define PI 3,141592654

typedef struct {
    float lato;
} DatiQuadrato;

typedef struct {
    float raggio;
} DatiCerchio;

typedef struct {
    float base;
    float altezza;
} DatiRettangolo;

typedef struct {
    float lato1;
    float lato2;
    float lato3;
} DatiTriangolo;

typedef struct {
    enum {
        Quadrato,
        Cerchio,
        Rettangolo,
        Triangolo
    } tipoFigura;

    union {
        DatiQuadrato datiQuadrato;
        DatiCerchio datiCerchio;
        DatiRettangolo datiRettangolo;
        DatiTriangolo datiTriangolo;
    } datiFigura;
} Figura;

void quadrato (Figura *pf, float l) {
    pf->tipoFigura = Quadrato;
    pf->datiFigura.datiQuadrato.lato = l;
}

void cerchio (Figura *pf, float r) {
    pf->tipoFigura = Cerchio;
    pf->datiFigura.datiCerchio.raggio = r;
}

void rettangolo (Figura *pf, float b, float h) {
    pf->tipoFigura = Rettangolo;
    pf->datiFigura.datiRettangolo.base = b;
    pf->datiFigura.datiRettangolo.altezza = h;
}

void triangolo (Figura *pf, float l1, float l2, float l3) {
    pf->tipoFigura = Triangolo;
    pf->datiFigura.datiTriangolo.lato1 = l1;
    pf->datiFigura.datiTriangolo.lato2 = l2;
    pf->datiFigura.datiTriangolo.lato3 = l3;
}

float perimetro (Figura *pf) {
    switch (pf->tipoFigura) {
        case Quadrato: {
            return pf->datiFigura.datiQuadrato.lato * 4;
            break;
        }
        case Cerchio: {
            return pf->datiFigura.datiCerchio.raggio * 2 * PI;
            break;
        }
        case Rettangolo: {
            return pf->datiFigura.datiRettangolo.base * 2 + pf->datiFigura.datiRettangolo.altezza * 2; 
            break;
        }
        case Triangolo: {
            return (pf->datiFigura.datiTriangolo.lato1 + pf->datiFigura.datiTriangolo.lato2 + pf->datiFigura.datiTriangolo.lato3) / 2;
            break;
        }
    }
}

float area (Figura *pf) {
    switch (pf->tipoFigura) {
        case Quadrato: {
            return pf->datiFigura.datiQuadrato.lato * pf->datiFigura.datiQuadrato.lato;
            break;
        }
        case Cerchio: {
            return pf->datiFigura.datiCerchio.raggio * pf->datiFigura.datiCerchio.raggio * PI;
            break;
        }
        case Rettangolo: {
            return pf->datiFigura.datiRettangolo.base * pf->datiFigura.datiRettangolo.altezza;
            break;
        }
        case Triangolo: {
            // da fare
            break;
        }
    }
}

int main () {
    Figura f;
    quadrato (&f, 10);

    printf ("%0.2f", perimetro(&f));
    printf ("\n%0.2f", area(&f));

    printf ("\n");
    return 0;
}