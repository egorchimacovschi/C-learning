#include <stdio.h>

int main() {
    int n, i;
    int v[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &v[i]);

    int suma_curenta = v[0];
    int suma_maxima = v[0];
    int start_curent = 0;
    int start_max = 0, end_max = 0;

    for (i = 1; i < n; i++) {
        // Dacă adăugarea elementului scade suma, începem o nouă secvență
        if (suma_curenta + v[i] < v[i]) {
            suma_curenta = v[i];
            start_curent = i;
        } else {
            suma_curenta += v[i];
        }

        // Cazuri de actualizare a sumei maxime
        if (suma_curenta > suma_maxima) {
            suma_maxima = suma_curenta;
            start_max = start_curent;
            end_max = i;
        } else if (suma_curenta == suma_maxima) {
            // dacă suma e egală, alegem secvența care începe mai din stânga
            if (start_curent < start_max) {
                start_max = start_curent;
                end_max = i;
            } else if (start_curent == start_max) {
                // dacă începe în același loc, alegem secvența mai scurtă
                if (i - start_curent < end_max - start_max) {
                    end_max = i;
                }
            }
        }
    }

    // Afișăm secvența de sumă maximă
    for (i = start_max; i <= end_max; i++) {
        printf("%d", v[i]);
        if ( i < end_max) {printf(" ");}
    }

    return 0;
}