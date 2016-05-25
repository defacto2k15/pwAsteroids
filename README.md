# pwAsteroids
Gra z prost� logik� zainspirowan� klasycznymi asteroids z lat 70tych. Celem projektu by�a pr�ba zaimplementowania prostego programu z u�yciem wzorca Enriry-component-system, inspirowanego tym u�ywanym w Unity3D. Dodatkowym (i osi�gni�tym) celem by�o dodanie wbudowanego intepretera j�zyka Python, kt�ry dzia�a� jak konsola do debugowania. W pierwotnych za�o�eniach projekt mia� by� tworzony u�ywaj�c technik TDD z dodatkowymi testami "regresyjnymi" sterowanymi przez konsol�, ale z powodu braku czasu oraz innych trudno�ci ten punkt opuszczono.

## Kompilacja na systemach Linuxowych 
Program Cmake spr�buje sam znale�� potrzebne mu biblioteki w systemie. Jednak�e,  prawdopodobie�stwo udanej instalacji zostanie zwi�kszone, je�eli biblioteki oraz ich pliki nag��wkowe znajd� si� w standardowych lokacjach,
czyli folderach /usr/lib oraz /usr/include.
Plik wykonywalny nazwany pwAsteroids utworzy� mo�na, wykonuj�c nast�puj�ce komendy:

cd build
cmake ..
make

Testy skompilowane zostan� je�eli do wywo�ania programu cmake dodamy flag� -DBuildTests=ON, jednak jest ich b.ma�o

