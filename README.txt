Piškvorky

Priebeh hry:
Po spustení hry sa vykreslí menu s buttonmi na štart a koniec. Po štarte hry sa do stredu obrazovky vykreslí 3x3 mriežka ktorá sa skladá
z 9 štvorcov. Po kliknutí na štvorec sa doňho vkreslí X alebo O, podľa toho kto je práve na rade. Cieľom hry je mať 3 rovnaké znaky v línií.
Po výhre jedného z hráčov, alebo pri remíze sa na obrazovku vypíše kto vyhral a vykreslia sa 2 buttony, buď na reštart hry alebo na koniec. 

Použité triedy:

Square
-pridáva vlastnosti, funkcie jednotlivím políčkam mriežky
-vlastnosti : Symbol - číslo 0/1/2, 0 je prázdne políčko, 1 je X, 2 je O
	      id - poradové číslo v Qliste
-funkcie : SetSymbol - nastaví squaru jeho symbol a podľa neho priradí znak X/O
           GetSymbol - getter pre symbol
           SetId - nastaví squaru poradové číslo
           GetId - getter pre id
           mousePressEvent - umožňuje squaru reagovať na kliknutie

Grid
-vytvorí mriežku 3x3 zo squarov
-vlastnosti : Squares - QList všetkých squarov mriežky
              numEmpty - počet prázdnych políčok, použité pre zistenie remízy
-funkcie : GetSquares - getter pre QList Squares
           CreateCol - funkcia ktorá vytvorí jeden stĺpec mriežky
           PlaceSquares - funkcia ktorá pomocou CreateCol vytvorí celú mriežku
           CheckWin - funkcia na zistenie výherných podmienok(3 rovnaké znaky v jednej línií)
           CheckDraw - funkcia na zistenie stavu remízy, kedy sú všetky políčka zaplnené ale nikto nevyhral

Game
-trieda ktorá sa stará a celý priebeh hry
-vlastnosti : turn - určuje kto je práve na rade
              playerText - textová správa aktuálneho kola
              grid - mriežka
              scene - scéna
-funkcie : menu - vykreslí herné menu s buttonmi hraj a koniec
           SetTurn - nastaví kto je práve na rade
           GetTurn - getter pre SetTurn
           GameOver - po konci hry vypíše kto vyhral a pridá buttony na hraj znovu a koniec
           start - začné hru
           restart - po konci hry znovu spustí hru
