
# WALLCHESS

**WALLCHESS** est une variante innovante du jeu d'échecs classique, développée dans le cadre d'un projet universitaire. Cette version enrichit la dynamique du jeu traditionnel avec l'ajout d'une pièce neutre : **le Mur**.

---

## 🚀 Présentation du projet

**Principe du jeu :**  
En plus des pièces classiques, une pièce spéciale appelée **le Mur** est ajoutée.  
Le Mur n’appartient ni aux noirs, ni aux blancs.  
À **chaque tour**, après avoir déplacé une de leurs propres pièces, les joueurs doivent également déplacer le Mur sur une **case vide** de l'échiquier.

**Particularités :**
- Le Mur **ne peut pas être capturé**.
- Il **bloque les mouvements** des fous, tours, reines et des pions.
- Il devient un **outil stratégique majeur** pour perturber l'adversaire.

---

## 🎯 Objectifs

- Proposer une **expérience d’échecs inédite** tout en respectant l’esprit du jeu classique.
- Créer une **interface graphique** intuitive (SFML + C++).
- Implémenter les **règles classiques** et **spécifiques** de WALLCHESS.
- Ajouter un **mode jouer contre l'ordinateur**, un **mode multijoueur local**, et un **joker** de retour en arrière.

---

### 📸 Aperçu du Jeu


<p align="center">
  <img src="assets/captures/menu.png" alt="Menu Principal" width="800"/>
  <img src="assets/captures/partie.png" alt="Déplacement du Mur" width="900"/>
  <img src="assets/captures/debut.png" alt="init" width="900"/>
  
</p>


---

## 🛠️ Arborescence du projet

```bash
WALLCHESS/
├── assets/
│   ├── images/        # Sprites des pièces, du mur, de l'échiquier
│   ├── captures/       # captures d'écran pour la documentation
│   └── sons/          # Effets sonores
│        
├── build/             # Dossier de compilation
├── sauvegarde/        # Sauvegardes de la dernière partie
├── src/               # Code source du projet
├── CMakeLists.txt     # Configuration CMake
└── README.md          # Ce fichier
```

---

## 🔧 Technologies utilisées

- **C++**  
- **SFML** (Simple and Fast Multimedia Library)  
- **CMake**

---

## 🧩 Fonctionnalités principales

- Déplacement standard des pièces + déplacement stratégique du Mur.
- Gestion complète des règles classiques.
- Interface graphique simple et intuitive avec SFML.
- Historique complet pour revenir en arrière.
- Mode multijoueur local.
- Mode individuel contre l'ordianateur avec des coups aléatoires.
- Joker : possibilité de revenir une fois en arrière pendant la partie.

---

## 🖥️ Comment installer le projet

1. Assurez-vous d’avoir installé **CMake** et **SFML** sur votre machine.
2. Depuis un terminal, exécutez les commandes suivantes :

```bash
cd WALLCHESS/build
cmake ..
make
```

3. Lancez l’exécutable généré depuis le dossier **build** `./Echec`

---

## ⚡ Difficultés rencontrées

- **Gestion du Mur** : Empêcher les pièces de traverser ou de capturer cette nouvelle pièce sans casser les règles de mouvement normales a été complexe.
- **Implémentation du roque et de la prise en passant** avec la prise en compte de l'obstacle Mur.
- **Historique des coups** et possibilité de retour arrière sans bug sur l'état du plateau.


---

## ✍️ Auteurs & Contributions

| Nom                | Rôle et Contributions                                                 |
|--------------------|-----------------------------------------------------------------------|
| **Rayen Ben Ammar (moi)**        | Développement du moteur du jeu + Interface dans le terminal (CLI)     |
| **Romain Aillaud**| Développement de l'interface graphique (GUI)                         |

Ce projet a été réalisé dans le cadre du projet de fin d'année en **PEIP** (Parcours des écoles Polytech).

---



**Merci d’avoir découvert notre projet !**  
**Bon jeu et à vous d'apprivoiser le Mur ! 🧱♟️**

---
