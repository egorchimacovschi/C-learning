    #include "Produs.h"

    void crearea_fisier(const char *nume_fisier)
    {
        int times  = 0, X = 0;
        Produs p;
        FILE *f = fopen(nume_fisier, "wb");

        if (!f) {
            return;
        }

        srand(time(NULL));

        while (times != 100) {
            X = rand() % 1000;
            sprintf(p.nume_produs, "Produs%d", X % 100);
            p.cantitate = X % 100;
            p.pret_produs = (X <= 100) ? X : (X / 100.0f);
            fwrite(&p, sizeof(Produs), 1, f);
            times++;
        }
        fclose(f);
    }

    void afisare_ecran(const char * nume_fisier) {
        FILE *f = fopen(nume_fisier, "rb");
        Produs p;
        for (int i = 0; i < 100; i++) {
            fread(&p, sizeof(p), 1, f);
            printf ("produs: %s; cantitate: %d; pret: %1.2f\n",\
                p.nume_produs, p.cantitate, p.pret_produs);
        }
        fclose(f);
    }

    void sortare(const char * nume_fisier) {

        FILE *f = fopen(nume_fisier, "rb");

        int i = 0, j = 0;
        Produs P[100];
        Produs temp = {"", 0 , 0.0f};

        if (!f) return;

        for (i = 0; i < 100; i++) {
            fread (&P[i], sizeof (Produs), 1, f);
        }
        fclose(f);
        for (i = 0; i < 100; i++) {
            for (j = 0; j < 100; j++) {
                if (strcmp (P[i].nume_produs, P[j].nume_produs) > 0) {
                    temp = P[i];
                    P[i] = P[j];
                    P[j] = temp;
                }
            }
        }
        f = fopen(nume_fisier, "wb");
        if (!f) return;
        fwrite(P, sizeof(Produs), i, f);
        fclose(f);

    }

    void cautare(const char * nume_fisier) {

        char text_cautat[50];
        FILE *f = fopen(nume_fisier, "rb");
        Produs p;
        int count = 0;

        scanf("%s", text_cautat);

        for (int i = 0; i < 100; i++) {
            fread(&p, sizeof(Produs), 1, f);
            if (strstr(p.nume_produs, text_cautat)) {
                printf ("produs: %s; cantitate: %d; pret: %1.2f\n",\
                    p.nume_produs, p.cantitate, p.pret_produs);
                count++;
            }
        }
        if (!count) printf("Nu a fost gasit\n");

        fclose(f);
    }

    void cautare2(const char * nume_fisier) {

        char text_cautat[50];
        FILE *f = fopen(nume_fisier, "r+b");
        Produs p;
        char nume_nou[50];
        int cantitate_noua = 0, count  = 0;
        float pret_nou = 0;

        scanf("%s", text_cautat);

        for (int i = 0; i < 100; i++) {
            fread(&p, sizeof(Produs), 1, f);
            if (strstr(p.nume_produs, text_cautat)) {
                printf ("produs: %s; cantitate: %d; pret: %1.2f\n",\
                    p.nume_produs, p.cantitate, p.pret_produs);
                scanf("%s %d %f", nume_nou, &cantitate_noua, &pret_nou);
                strcpy(p.nume_produs, nume_nou);
                p.cantitate = cantitate_noua;
                p.pret_produs = pret_nou;
                fseek(f, -sizeof(Produs), SEEK_CUR);
                fwrite(&p, sizeof(Produs), 1, f);
                fflush(f);
                count++;
            }
        }

        if (!count) printf ("Nu a fost gasit\n");

        fclose(f);
    }

    int main(int argc, char *argv[])
    {
        //crearea_fisier(argv[1]);
        //sortare(argv[1]);
        //cautare2(argv[1]);
        //cautare(argv[1]);
        //afisare_ecran(argv[1]);

        return 0;
    }