-- Kompilacja na systemach Linuxowych --
Program Cmake spr�buje sam znale�� potrzebne mu biblioteki w systemie. Jednak�e,  prawdopodobie�stwo udanej instalacji zostanie zwi�kszone, je�eli biblioteki oraz ich pliki nag��wkowe znajd� si� w standardowych lokacjach,
czyli folderach /usr/lib oraz /usr/include.
Plik wykonywalny nazwany pwAsteroids utworzy� mo�na, wykonuj�c nast�puj�ce komendy:

cd build
cmake ..
make

Testy skompilowane zostan� je�eli do wywo�ania programu cmake dodamy flag� -DBuildTests=ON

-- Kompilacja na systemie Windows --
Przed rozpocz�ciem kompilacji nale�y zainstalowa� biblioteki boost, Allegro 5 oraz Python 2.7, zbudowane wed�ug ich w�asnych instrukcji. W razie problem�w ze zbudowaniem biblioteki Allegro mo�na u�y� bibliotek prekompilowanych pod starsze wersje programu Visual Studio, one r�wnie� powinny zadzia�a�: https://www.allegro.cc/files/
Kompilacja aplikacji w systemie Windows odbywa si� w Visual Studio (domy�lnie w wersji 14 - zmiany mo�na dokona� w 24 linii pliku install.bat). Projekt do zbudowania �r�de� jest tworzony przy pomocy programu CMake, z kt�rego korzysta prosty skrypt install.bat. Skrypt ten przyjmuje dwa argumenty:
folder, w kt�rym zainstalowany zosta� boost,
folder, w kt�rym zainstalowane zosta�o Allegro
Przyk�ad: install.cmd "C:\boost\boost_1_59_0" "C:\allegro\allegro-5.0.10-msvc-11.0" (Allegro w wersji prekompilowanej pod Visual Studio 11).
    Po wywo�aniu skryptu w folderze VSProject znajdowa� si� b�dzie projekt pwAsteroids.sln, w kt�rym nale�y dokona� nast�puj�cych zmian:
z panelu Solution Explorer usun�� projekty ALL_BUILD i ZERO_CHECK
doda� �cie�k� do folderu libs Pythona w pwAsteroids -> Properties -> Linker -> Additional Library Directories (domy�lnie �C:\Python27\libs�)
doda� �cie�k� do folderu stage\lib boosta w pwAsteroids -> Properties -> Linker -> Additional Library Directories (np.�C:\boost\boost_1_59_0\stage\lib�)
