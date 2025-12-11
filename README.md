Projekt przedstawia prostą grę typu Arkanoid napisaną w języku C++ z użyciem biblioteki SFML 2.6.2.
Program spełnia wymagania zadania dotyczące animacji, sterowania, kolizji, struktur danych oraz mechanizmu zapisu/odczytu stanu gry.
Funkcjonalności gry
 1. Menu główne:
Po skompilowaniu, gra uruchamia się i wyswuetla sie  menu, które pozwala wybrać:
-Nowa gra
-Ostatnie wyniki (nieaktywne)
-Wyjście (wylacza gre)
 2. Rozgrywka, trybie gry dostępne są:
-animowana pilka ipaletka,
-animowane bloki z punktami życia,
-system kolizji pilki z paletko, pilki z blokami
3. Snapshot system (zapis / odczyt stanu gry)

Gra umożliwia zatrzymanie i zapisanie pełnego stanu rozgrywki (pozycja paletki, pozycja piłki, prędkość piłki, stan wszystkich bloków (pozycja + HP).

Zapis snapshotu → klawisz P
Odczyt snapshotu → klawisz L

Można zapisać, wrócić do menu ESC, wejść ponownie w grę, nacisnąć L i gra wróci dokładnie do zapisanego momentu.
4. Pauza / powrót do menu, odczas gry, naciśnięcie ESC → powrót do menu bez resetu gry (stan jest zachowany).
5. Game Over- Jeśli piłka spadnie poniżej ekranu, wyświetlany jest komunikat w konsoli ,,GAME OVER Nacisnij ENTER" i po wcisniecie klawisza enter gra zaczyna sie od nowa 
Niestety nie udalo mi sie zrobic dynamicznego tekstu, ktory bym w wymogach projektu.
