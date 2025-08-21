# SpaceShooter

Ce jeu est un space shooter, réalisé en quatrième année à ESIEE Paris, par Paul Kehlhoffner et Aymeric Martin.

Le joueur se retrouve dans l'espace avec son vaisseau spatial, et doit détruire un vaisseau mère sur sa route. Malheureusement, ce vaisseau mère appelle des vaisseaux ennemis pour se protéger, et vous attaquer en même temps. Votre but est donc de détruire tous les vaisseaux ennemis pour pouvoir gagner la partie.

Attention ! Le temps vous est compté pour réaliser cette tâche, le chrono tourne....

# Mise en place du Jeu

## Prérequis

__Ce projet s'execute sur Windows !__

* CMake >= 3.20
* Visual Studio 2022 (ou GCC/MSYS2 pour compiler avec MinGW)
* SFML 2.6 est inclus dans le projet (SFML-2.6.0)

### Compilation

* Ouvrir PowerShell ou terminal dans le dossier du projet.
* Créer le dossier de build et générer les fichiers de compilation :
  * mkdir build
  * cd build
  * cmake .. -DCMAKE_BUILD_TYPE=Debug
  * cmake --build . --target space-shooter
* Déplacez-vous dans le dossier Debug :
  * cd Debug
  * .\space-shooter.exe

Vous pouvez maintenant lancer le jeu !

Si vous souhaitez relancer le jeu après l'avoir fermé, faites seulement ```.\space-shooter.exe```, les autres commandes ne servent plus. Si cela ne marche pas, supprimez le dossier build et recommencez les commandes depuis le début.

### Fonctionnalités implémentées

Ce jeu comporte de nombreuses fonctionnalités. Vous pourrez trouver différentes scènes pour parcourir le jeu, comme une scène Menu, Rules, Level, GameOver et Victory.

Les autres systèmes présents sont :

__RenderingSystem__ : Un système de rendu des textures et des sprites pour les afficher à l'écran, comme le background et les vaisseaux.  
__Background Image__ : Défini l'ambiance du jeu en affichant une image d'arrière-plan.  
__InputSystem__ : Permet d'avoir des touches pour jouer.  
__MovementSystem__ : Permet de déplacer les entités, notamment notre vaisseau et ceux des ennemis, ainsi que les missiles.  
__SceneSystem__ : Un système de transition entre les différentes scènes de jeu, plusieurs sceneSystem ont été créé pour chaque scène.  
__TagComponent__ : Classifie les entités à l'aide de Tag pour une meilleure gestion dans divers systèmes.  
__ShootingSystem + EnemyShootingSystem__ : Permet au joueur, ainsi qu'aux ennemis de tirer des missiles.  
__Cooldown Missile__ : Permet d'avoir un delay entre les missiles, grâce à un ClockSystem.  
__Enemy Spawner__ : Un vaisseau mère, qui produit des vaisseaux ennemis à intervalle régulier, tant qu'il est en vie.  
__CollisionSystem + Health/Damage__ : Mécanisme dans lequel les missiles et les vaisseaux entrent en collision (format AABB), causant des dégâts.  
__Clean Killed Ship__ : Système qui détecte les vaisseaux sans vie, et les détruits.  
__Clean Missile__ : Système qui détruit les missiles une fois les bordures de l'écran franchi.  
__EnemyChasingSystem__ : Les navires ennemis suivent uniquement le joueur sur l'axe des x, pour une difficulté raisonnable.  
__EnemySpawnerSystem__ : Le vaisseau mère ennemi bouge sur l'axe des x, pour ajouter de la difficulté au joueur.  
__Player Death Detection__ : Un système qui passe à la scène de GameOver quand le joueur est mort.  
__VictorySystem__ : Permet de gagner la partie, si tous les ennemis et le vaisseau mère sont détruits.  
__Health Bar__ : Ajout d'un bar de vie du joueur à l'écran, pour connaitre l'étendue des dégâts du vaisseau.  
__Timer__ : Ajout un timer, qui oblige le joueur à gagner la partie avant la fin du temps.  
__Text Rendering System__ : Système permettant d'afficher un texte à l'écran, comme le timer, ou les règles dans la scène Rules.  
__Text Blink System__ : Système permettant de faire clignoter un texte.  
__Scoring Mechanism__ : Mécanisme permettant d'avoir un score en tuant les ennemis.  
__Music System__ : Ajout de musique pour les backgrounds.  
__Audio System__ : Ajout de différents bruits, par exemple pour les missiles et les vaisseaux détruits.  
__Clean Sounds__ : Permet de détruire les sons une fois qu'ils ont été joué.  

Toutes les fonctionnalités proposées pour notre projet ont été réalisé, sauf celle pour mettre le jeu en pause.

### Bugs et Problèmes

Il arrive que le vaisseau mère se bloque sur un des côtés pour une raison inconnue.  
Nous avons eu également des bugs de son, quand il y avait trop de missiles créés. L'ajout de la fonctionnalité Clean Sounds à permit de résoudre le problème.

### Commandes

Pour jouer au jeu, vous pouvez vous déplacer à l'aide des touches directionnelles du clavier, et la touche Espace permet de tirer les missiles.