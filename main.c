#include <stdio.h>
#include <stdlib.h>

/*deklaracja funkcji wypelnijTablice*/
void wypelnijTablice(int *tab, int rozmiar);

/*deklaracja funkcji znajdzCiag*/
void znajdzCiag(int *tab, int rozmiar);

int main(void) /*funkcja glowna*/
{
    int rozmiar;
    int *tab;

    /*wyswietlenie komunikatu dla uzytkownika*/
    printf("Podaj rozmiar tablicy: ");

    /*pobranie rozmiaru tablicy*/
    scanf("%d", &rozmiar);

    /*rezerwacja miejsca na tablice jednowymiarowa*/
    tab = (int *)malloc(sizeof(int) * rozmiar);

    /*wywolanie funkcji*/
    wypelnijTablice(tab, rozmiar);
    znajdzCiag(tab, rozmiar);

    free(tab); /*zwolnienie miejsca w pamieci zarezerwowanego przez tablice*/

    return 0;
}

/*definicja funkcji wypelniajacej tablice*/
void wypelnijTablice(int *tab, int rozmiar)
{
    int i;

    for (i = 0; i < rozmiar; i++)
    {
        printf("Podaj element nr %d:\t", i);
        scanf("%d", &tab[i]);
    }

    /*wypisanie tablicy na ekranie*/
    printf("\nCiag: ");
    for (i = 0; i < rozmiar; i++)
    {
        printf("%d,", tab[i]);
    }
    printf("\n");
}

/*definicja funkcji znajdujacej najdluzszy ciag w tablicy*/
void znajdzCiag(int *tab, int rozmiar)
{
    /*deklaracja struktury ciag*/
    struct ciag
    {
        int poczatek;
        int koniec;
        int dlugosc;
    };

    int i, poc, kon, dl;

    struct ciag podciag;

    /*inicjalizacja zmienych*/
    podciag.dlugosc = 0;
    podciag.koniec = 0;
    podciag.poczatek = 0;
    poc = 0;
    kon = 0;

    /*petla wyszukujaca ciagu*/
    for (i = 0; i < rozmiar - 1; i++)
    {
        if (tab[i] < tab[i + 1])
        {
            kon = i + 1;
            dl = kon - poc;

            if (dl >= podciag.dlugosc)
            {
                podciag.dlugosc = dl + 1;
                podciag.koniec = kon;
                podciag.poczatek = poc;
            }
        }
        else
            poc = i + 1;
    }
    printf("\nNajdluzszy podciag to: ");
    for (i = podciag.poczatek; i <= podciag.koniec; i++)
    {
        printf("%d,", tab[i]);
    }
    printf("\nPoczatek = %d, koniec = %d, dlugosc = %d\n", podciag.poczatek, podciag.koniec, podciag.dlugosc);
}
