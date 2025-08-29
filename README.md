# SpaceShooter

Ce jeu est un space shooter, réalisé en quatrième année à ESIEE Paris, par Paul Kehlhoffner et Aymeric Martin.

Le joueur se retrouve dans l'espace avec son vaisseau spatial, et doit détruire un vaisseau mère sur sa route. Malheureusement, ce vaisseau mère appelle des vaisseaux ennemis pour se protéger, et vous attaquer en même temps. Votre but est donc de détruire tous les vaisseaux ennemis pour pouvoir gagner la partie.

Attention ! Le temps vous est compté pour réaliser cette tâche, le chrono tourne....

## Principe de conception

Ce projet est conçu autour du Entity Component System (ECS), un modèle de programmation très utilisé dans le développement de jeux vidéo.

### Qu'est-ce que l'ECS ?

* Entity (Entité) : un objet du jeu, comme le vaisseau du joueur, un missile ou un ennemi.
* Component (Composant) : une donnée pure qui décrit un aspect de l'entité, par exemple sa position, sa vitesse, ou son sprite.
* System (Système) : la logique qui agit sur les entités possédant certains composants. Par exemple, le MovementSystem déplace toutes les entités qui ont à la fois une position et une vitesse.

Cette architecture permet de séparer les données et la logique, rendant le code plus modulaire et facile à étendre. Chaque nouveau type d’entité ou de comportement peut être ajouté sans toucher au reste du code.

# Mise en place du Jeu

## Prérequis

__Ce projet s'execute sur Windows !__

* CMake >= 3.20
* Visual Studio 2022 (ou GCC/MSYS2 pour compiler avec MinGW)
* SFML 2.6 est inclus dans le projet (SFML-2.6.0)

### Compilation

* Ouvrir PowerShell ou terminal dans le dossier du projet.
* Créer le dossier de build et générer les fichiers de compilation :
```
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build . --target space-shooter
```
* Déplacez-vous dans le dossier Debug :
```
cd Debug
.\space-shooter.exe
```

Vous pouvez maintenant lancer le jeu !

Si vous souhaitez relancer le jeu après l'avoir fermé, faites seulement :
```
.\space-shooter.exe
``` 

Les autres commandes ne sont plus nécessaires. Si cela ne fonctionne pas, supprimez le dossier ```build``` et recommencez les étapes depuis le début.

## Contrôles et Gameplay

Le jeu propose deux configurations principales pour s’adapter aux joueurs.

#### Déplacements

Vous pouvez déplacer votre vaisseau dans toutes les directions :
* Flèches directionnelles : haut, bas, gauche, droite
* ZQSD : haut (Z), gauche (Q), bas (S), droite (D)

Vous pouvez combiner les touches pour vous déplacer en diagonale.

#### Tir

Pour tirer des projectiles :
* Maj (Shift gauche)
* Ou Clic gauche de la souris (assurez-vous que la fenêtre du jeu est active)

#### Objectif du jeu

* Détruire tous les vaisseaux ennemis et le vaisseau mère pour gagner.
* Surveillez votre barre de vie, affichée en haut de l’écran.
* Attention au chrono, le temps est limité pour finir le niveau.

### Fonctionnalités implémentées

Le jeu utilise le principe de Entity Component System (ECS) et comporte plusieurs scènes : Menu, Rules, Level, GameOver et Victory.

Les principaux systèmes et composants sont :

* __RenderingSystem__ : Affiche les textures et sprites à l'écran (background, vaisseaux, projectiles).
* __Background Image__ : Défini l'ambiance du jeu avec une image d'arrière-plan.
* __InputSystem__ : Détecte les touches du joueur.
* __MovementSystem__ : Déplace les entités (joueur, ennemis, missiles).
* __SceneSystem__ : Gère la transition entre les différentes scènes.
* __TagComponent__ : Classe les entités avec des Tag pour une gestion plus simple dans les systèmes.
* __ShootingSystem + EnemyShootingSystem__ : Permet au joueur et aux ennemis de tirer des missiles.
* __Cooldown Missile (ClockSystem)__ : Gestion du délai entre les tirs de missiles.
* __EnemySpawner + EnemySpawnerSystem__ : Le vaisseau mère produit des ennemis et se déplace pour augmenter la difficulté.
* __CollisionSystem + Health/Damage__ : Gère les collisions AABB entre missiles et vaisseaux et applique les dégâts.
* __Clean Killed Ship__ : Supprime les vaisseaux sans vie, et les détruits.
* __Clean Missile__ : Supprime les missiles qui passent en dehors de l'écran.
* __EnemyChasingSystem__ : Les ennemis suivent le joueur sur l’axe X.
* __Player Death Detection__ : Passe à la scène GameOver quand le joueur meurt.
* __VictorySystem__ : Déclenche la victoire lorsque tous les ennemis et le vaisseau mère sont détruits.
* __Health Bar__ : Affiche la barre de vie du joueur.
* __Timer__ : Limite le temps pour terminer le niveau.
* __Text Rendering System + Text Blink System__ : Affiche du texte et permet de le faire clignoter (timer, règles).
* __Scoring Mechanism__ : Compte les points en tuant les ennemis.
* __Music System__ : Ajoute de la musique pour de fond.
* __Audio System__ : Ajoute des effets sonores (missiles, vaisseaux détruits).
* __Clean Sounds__ : Supprime les sons terminés pour éviter les conflits.

### Bugs et Problèmes

* Il arrive que le vaisseau mère se bloque sur un des côtés pour une raison inconnue.

# Conclusion

SpaceShooter est un projet complet démontrant la puissance du Entity Component System pour structurer un jeu. Il combine des mécaniques de gameplay classiques (tir, ennemis, collisions, score) avec une interface simple et interactive.

Nous espérons que ce jeu vous offrira une expérience amusante et qu’il pourra servir d’exemple pour comprendre la conception d’un jeu ECS en C++.
