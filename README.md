Jeu de la Vie - Conway's Game of Life
📋 Description du Projet
Implémentation en C++ orientée objet du célèbre Jeu de la Vie de John Conway, un automate cellulaire qui simule l'évolution d'une population de cellules selon des règles simples mais fascinantes.

🎯 Règles du Jeu
Le jeu se déroule sur une grille 2D où chaque cellule peut être vivante ou morte. À chaque itération, l'état des cellules évolue selon ces règles :

Naissance : Une cellule morte avec exactement 3 voisines vivantes devient vivante
Survie : Une cellule vivante avec 2 ou 3 voisines vivantes reste vivante
Mort : Dans tous les autres cas, la cellule meurt (solitude ou surpopulation)
Le voisinage d'une cellule est constitué de ses 8 cellules adjacentes (horizontales, verticales et diagonales).

🏗️ Architecture (Principes POO & SOLID)