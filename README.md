# **Strukture podataka**

## Laboratorijske vježbe

Ovdje možete pronaći riješene laboratorijske vježbe iz kolegija Strukture podataka, na 2. godini prediplomskog studija računarstva na FESB-u.

## Motivacija

Svrha ovog repozitorija jest da studentima pomogne pri učenju gradiva iz predavanja, te kao podsjetnik za laboratorijske vježbe. Kod je napisan na ispravan način, te je razdvojen u više funkcija, koje su raspodijeljene u više datoteka (.h i .c file). Također, veći dio koda je popraćen komentarima, u svrhu lakšeg čitanja i razumijevanja.

## Neki savjeti za pisanje koda

- Sve varijable moraju biti inicijalizirane (0, "0", 0.0, NULL, ...)
  ```
  int a = 0;
  char c = '\0';
  int* p = NULL;
  ```

- Sve varijable moraju imati logična imena
  ```
  char ime[50]; // sadržava ime osobe
  position previous; // pokazivač na prethodni element
  ```

- Sve funkcije moraju imati logična imena
  ```
  int Insert(position previous) {...} // Unosi novi element u listu
  ```

- Sve funkcije moraju vraćati vrijednost (NE smije biti void), jer na taj
  način možemo provjeriti je li se funkcija ispravno izvršila

- Provjeriti je li se alokacija memorije ispravno izvršila

- Provjeriti je li se datoteka ispravno otvorila

- Ne ponavljati isti kod 2 puta (ukoliko 2 puta pišete isti kod,
  onda taj kod napisati u zasebnu funkciju)

## Primjedbe, savjeti i upiti

Za sve upite možete mi se javiti na laboratorijskim vježbama, ili na mail (josip.seric@icloud.com), kao i kolegi Duji Senti i profesoru Crnjcu.
