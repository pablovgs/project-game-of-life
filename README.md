# **Jeu de la Vie – Conway's Game of Life**

*Projet réalisé par **Théo** et **Pablo***  
*Une implémentation orientée objet en C++ du célèbre automate cellulaire conçu par John Conway.*

---

## **📋 Description du Projet**

Ce projet propose une version C++ moderne et orientée objet du **Jeu de la Vie**, un automate cellulaire simple en apparence mais capable de générer des comportements émergents complexes.  
*L’objectif est de simuler l’évolution d’une grille de cellules vivantes et mortes selon un ensemble de règles immuables.*

Il sert à :  
- comprendre la manipulation de grilles en 2D  
- pratiquer l’architecture orientée objet (classes, méthodes, encapsulation)  
- expérimenter la simulation itérative  
- visualiser un système dynamique évolutif  

---

## **🎯 Règles du Jeu**

Le jeu se déroule sur une **grille 2D** où chaque cellule peut être :  
- **vivante (1)**  
- **morte (0)**  

À chaque itération, chaque cellule évolue selon les règles suivantes :

### **1️⃣ Naissance**  
Une **cellule morte** ayant **exactement 3 voisines vivantes** devient vivante.

### **2️⃣ Survie**  
Une **cellule vivante** ayant **2 ou 3 voisines vivantes** reste vivante.

### **3️⃣ Mort**  
Dans tous les autres cas, la cellule **meurt** :  
- *solitude* (moins de 2 voisines vivantes)  
- *surpopulation* (plus de 3 voisines vivantes)

### **Voisinage**  
Chaque cellule possède un voisinage composé de **8 cellules adjacentes** :  
- horizontales  
- verticales  
- diagonales  

*Ce modèle simple permet pourtant de produire des motifs célèbres comme les oscillateurs, planeurs (gliders), ou structures stables.*

---

## **🛠️ Technologies / Concepts Utilisés**

- **C++ orienté objet (classes et encapsulation)**  
- manipulation de tableaux 2D  
- gestion d’itérations et d’états successifs  
- logique d’automate cellulaire  
- affichage console simple  
- séparation du code en fichiers `.hpp` et `.cpp`

---

## **🚀 Objectifs Pédagogiques**

- Approfondir la conception orientée objet  
- Apprendre à structurer une simulation  
- Utiliser de manière efficace les boucles, conditions et tableaux  
- *Comprendre comment des règles très simples peuvent produire des comportements complexes*

---

## **📜 Auteurs**

Projet réalisé par :  
- **Théo**  
- **Pablo**

---

*Merci d’avoir consulté ce projet ! Toute suggestion ou amélioration est bienvenue.*  