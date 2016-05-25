# pwAsteroids
Gra z prost¿ logik¿ zainspirowan¿ klasycznymi asteroids z lat 70tych. Celem projektu by¿a próba zaimplementowania prostego programu z u¿yciem wzorca Enriry-component-system, inspirowanego tym u¿ywanym w Unity3D. Dodatkowym (i osi¿gni¿tym) celem by¿o dodanie wbudowanego intepretera j¿zyka Python, który dzia¿a¿ jak konsola do debugowania. W pierwotnych za¿o¿eniach projekt mia¿ by¿ tworzony u¿ywaj¿c technik TDD z dodatkowymi testami "regresyjnymi" sterowanymi przez konsol¿, ale z powodu braku czasu oraz innych trudno¿ci ten punkt opuszczono.

## Kompilacja na systemach Linuxowych 
Program Cmake spróbuje sam znaleœæ potrzebne mu biblioteki w systemie. Jednak¿e,  prawdopodobieñstwo udanej instalacji zostanie zwiêkszone, je¿eli biblioteki oraz ich pliki nag³ówkowe znajd¹ siê w standardowych lokacjach,
czyli folderach /usr/lib oraz /usr/include.
Plik wykonywalny nazwany pwAsteroids utworzyæ mo¿na, wykonuj¹c nastêpuj¹ce komendy:

cd build
cmake ..
make

Testy skompilowane zostan¹ je¿eli do wywo³ania programu cmake dodamy flagê -DBuildTests=ON, jednak jest ich b.ma¿o

