# Conway's Game of Life 🎮

Une implémentation en C++ du célèbre automate cellulaire de John Conway avec interface console et graphique (SFML).

---

## Le Jeu de la Vie

Le **Jeu de la Vie** (Game of Life) est un automate cellulaire inventé par le mathématicien John Conway en 1970. Ce n'est pas un jeu au sens traditionnel, mais une simulation où des cellules évoluent selon des règles simples.

### Règles

Chaque cellule peut être **vivante** (■) ou **morte** (□). À chaque génération, l'état des cellules change selon ces règles :

1. **Survie** : Une cellule vivante avec 2 ou 3 voisins vivants survit
2. **Mort par isolement** : Une cellule vivante avec 0 ou 1 voisin meurt
3. **Mort par surpopulation** : Une cellule vivante avec 4+ voisins meurt
4. **Naissance** : Une cellule morte avec exactement 3 voisins vivants devient vivante


---

##  Architecture du projet
```
PROJECT-GAME-OF-LIFE/
├── core/                         # Cœur logique du jeu
│   ├── CellState.h
│   ├── CellState.cpp             
│   ├── AliveState.h
│   ├── AliveState.cpp            
│   ├── DeadState.h
│   ├── DeadState.cpp             
│   ├── Cell.h
│   ├── Cell.cpp                  
│   ├── Grid.h
│   ├── Grid.cpp                  
│   ├── Rule.h
│   ├── Rule.cpp                  
│   ├── Game.h
│   ├── Game.cpp                  
│   └── main.cpp                 
│
├── GUI/                          # Interface graphique (SFML)
│   ├── GameGraphics.h
│   └── GameGraphics.cpp          
│
├── test/                         
│   ├── test_cellstate.cpp
│   ├── test_cell.cpp
│   ├── test_grid.cpp
│   ├── test_rule.cpp
│   ├── test_game.cpp
│   └── run_all_tests.cpp         # Exécutable regroupant tous les tests
│
├── diagrams/                     # Diagrammes UML
│   ├── Class.mmd                 
│   ├── Activity.mmd              
│   └── Diagrams of Sequences/    # Diagrammes de séquence
│       ├── Console.mmd
│       ├── Graphics.mmd
│       └── One_generation.mmd    
│
└── README.md                     # Documentation

```

---

## Fonctionnement du programme

### Architecture Orientée Objet

Le programme utilise plusieurs design patterns :

- **State Pattern** : `CellState`, `AliveState`, `DeadState` pour gérer l'état des cellules
- **MVC Pattern** : Séparation logique (Game), modèle (Grid/Cell), vue (GameGraphics)
- **Strategy Pattern** : `Rule` pour permettre différentes règles de jeu

### Flux d'exécution

1. **Chargement** : Lecture d'un fichier texte contenant la grille initiale
2. **Initialisation** : Création des objets `Game`, `Grid`, `Cell`
3. **Simulation** :
   - Phase 1 : Calcul du prochain état de chaque cellule (`prepareNext()`)
   - Phase 2 : Application simultanée des changements (`update()`)
   - Incrémentation du compteur de génération
4. **Affichage** : Console (fichiers) ou graphique (SFML)

---

## Installation

### Prérequis

- **Compilateur C++17** (g++, clang++)
- **SFML 2.5+** (pour l'interface graphique)

### Installation de SFML

**Ubuntu/Debian :**
```bash
sudo apt-get install libsfml-dev
```

---

## Compilation


### Manuellement :
```bash

    g++ core/*.cpp GUI/*.cpp test/*.cpp -o game_of_life -lsfml-graphics -lsfml-window -lsfml-system

```

---

## 🎮 Utilisation

### Mode Graphique (par défaut)

Lance l'interface SFML interactive :
```bash
./game_of_life examples/glider.txt
# ou
./game_of_life examples/glider.txt graphics
```

**Contrôles :**
- `Space` : Pause/Play
- `↑` : Augmenter la vitesse
- `↓` : Diminuer la vitesse
- `→` : Avancer d'une génération (mode manuel)
- `R` : Reset (retour à l'état initial)
- `Échap` : Quitter

---

### Mode Console

Génère des fichiers pour chaque génération :
```bash
./game_of_life examples/glider.txt console 50
```

**Résultat :**
- Crée un dossier `glider_out/`
- Génère 51 fichiers : `generation_0.txt` à `generation_50.txt`
- Chaque fichier contient l'état de la grille à cette génération

---

### Tests Unitaires

Lance tous les tests automatiques :
```bash
./game_of_life test
```

**Tests inclus :**
- Tests des états (CellState, AliveState, DeadState)
- Tests des cellules (création, états, copie)
- Tests de la grille (chargement, voisins)
- Tests des règles de Conway
- Tests du jeu complet (step, reset, fichiers)

---



## Tests

Le projet inclut une suite complète de tests unitaires :
```bash
./game_of_life test
```

**Couverture :**
-  25+ tests unitaires
-  Toutes les classes testées
-  Scénarios réels (blinker, glider)
-  Gestion d'erreurs

---

## Technologies utilisées

- **C++17** : Standard moderne avec `filesystem`
- **SFML 2.5+** : Bibliothèque graphique multiplateforme
- **Design Patterns** : State, MVC, Strategy
- **Tests unitaires** : Framework custom avec `assert`

---

## 📚 Ressources

- [Wikipedia - Jeu de la Vie](https://fr.wikipedia.org/wiki/Jeu_de_la_vie)
- [Documentation SFML](https://www.sfml-dev.org/documentation/)
- [LifeWiki - Patterns](https://conwaylife.com/wiki/)

---

## 👨‍💻 Auteur

Projet réalisé par Théo PRIEUR et Pablo VILLEGAS-ALVAREZ


---

## 🎯 Fonctionnalités

- ✅ Simulation du Jeu de la Vie de Conway
- ✅ Interface graphique interactive (SFML)
- ✅ Mode console avec export fichiers
- ✅ Contrôle de la vitesse de simulation
- ✅ Pause/Play, Reset
- ✅ Modification manuelle des cellules (clic)
- ✅ Compteur de cellules vivantes
- ✅ Tests unitaires complets
- ✅ Support de grilles de toute taille
- ✅ Patterns classiques fournis

---

## Résolution de problèmes

### Police non trouvée

Le programme fonctionne sans police, mais le texte ne s'affichera pas. Pour corriger :
```bash
# Linux - installer les polices DejaVu
sudo apt-get install fonts-dejavu

# Ou télécharger une police .ttf dans le dossier du projet
```

Merci !
