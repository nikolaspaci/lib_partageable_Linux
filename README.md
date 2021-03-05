# lib_partageable_Linux

## Installation de la VM
![Image installation vm](/images/vm.png)

## Objdump
![Image objdump](/images/objdump.png)

## Chargement dynamique des librairies
Le projet s'appuie sur  les fonctions dlOpen() et dlSym() pour charger les librairies.
Lors du lancement du main, veuillez spécifier le chemin des librairies en argumant (libComposant1 et libComposant2). il s'agit du chemin relatif.

Exemple:
```
./main libComposant1.so libComposant2.so
```
Vous pouvez aussi tout simplement lancer le programme à l'aide de la commande make depuis le répertoire parent:
```
make
```
En effet, les argumants ont été spécifié dans le makefile.

![Image resultat](/images/dynamique.png)