# lib_partageable_Linux

## Chargement dynamique des librairies
Le projet s'appuie sur  les fonctions dlOpen() et dlSym() pour charger les librairies.
Lors du lancement du main, veuillez spécifier le chemin des librairies en argumant (libComposant1 et libComposant2). il s'agit du chemin relatif depuis le main.

Exemple:
```
./main ../lib/libComposant1.so ../lib/libComposant2.so
```
Vous pouvez aussi tout simplement lancer le programme à l'aide de la commande make depuis le répertoire parent:
```
make
```
En effet, les argumants ont été spécifié dans le makefile.