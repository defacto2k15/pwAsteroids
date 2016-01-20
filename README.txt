-- Kompilacja na systemach Linuxowych --
Program Cmake spróbuje sam znaleœæ potrzebne mu biblioteki w systemie. Jednak¿e,  prawdopodobieñstwo udanej instalacji zostanie zwiêkszone, je¿eli biblioteki oraz ich pliki nag³ówkowe znajd¹ siê w standardowych lokacjach,
czyli folderach /usr/lib oraz /usr/include.
Plik wykonywalny nazwany pwAsteroids utworzyæ mo¿na, wykonuj¹c nastêpuj¹ce komendy:

cd build
cmake ..
make

Testy skompilowane zostan¹ je¿eli do wywo³ania programu cmake dodamy flagê -DBuildTests=ON

-- Kompilacja na systemie Windows --
Przed rozpoczêciem kompilacji nale¿y zainstalowaæ biblioteki boost, Allegro 5 oraz Python 2.7, zbudowane wed³ug ich w³asnych instrukcji. W razie problemów ze zbudowaniem biblioteki Allegro mo¿na u¿yæ bibliotek prekompilowanych pod starsze wersje programu Visual Studio, one równie¿ powinny zadzia³aæ: https://www.allegro.cc/files/
Kompilacja aplikacji w systemie Windows odbywa siê w Visual Studio (domyœlnie w wersji 14 - zmiany mo¿na dokonaæ w 24 linii pliku install.bat). Projekt do zbudowania Ÿróde³ jest tworzony przy pomocy programu CMake, z którego korzysta prosty skrypt install.bat. Skrypt ten przyjmuje dwa argumenty:
folder, w którym zainstalowany zosta³ boost,
folder, w którym zainstalowane zosta³o Allegro
Przyk³ad: install.cmd "C:\boost\boost_1_59_0" "C:\allegro\allegro-5.0.10-msvc-11.0" (Allegro w wersji prekompilowanej pod Visual Studio 11).
    Po wywo³aniu skryptu w folderze VSProject znajdowaæ siê bêdzie projekt pwAsteroids.sln, w którym nale¿y dokonaæ nastêpuj¹cych zmian:
z panelu Solution Explorer usun¹æ projekty ALL_BUILD i ZERO_CHECK
dodaæ œcie¿kê do folderu libs Pythona w pwAsteroids -> Properties -> Linker -> Additional Library Directories (domyœlnie “C:\Python27\libs”)
dodaæ œcie¿kê do folderu stage\lib boosta w pwAsteroids -> Properties -> Linker -> Additional Library Directories (np.“C:\boost\boost_1_59_0\stage\lib”)
