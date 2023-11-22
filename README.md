# SpaceShooter

### Introduction

Ce jeu est un space shooter, réaliser par Paul Kehlhoffner et Aymeric Martin.

Le joueur possède se retrouve dans l'espace avec son vaisseau spacial, et doit détruire le vaisseau mère sur sa route. Malheureusement, ce vaisseau mère appelle des vaisseaux ennemis pour se protéger, et vous attaquer en même temps. Votre but est donc de détruire tous les vaisseaux ennemis pour pouvoir gagner la partie.

Attention ! Le temps vous est compté pour réaliser cette tâche, le chrono tourne....

### Fonctionnalités implémentées

Ce jeu comporte de nombreuses fonctionnalités. Vous pourrez trouver différentes scènes pour parcourir le jeu, comme une scène Menu, Rules, Level, Exit et Victory.

Les autres systèmes présents sont :

RenderingSystem : Un système de rendu des textures et des sprites pour les afficher à l'écran, comme le background et les vaisseaux.  
Background Image : Défini l'ambiance du jeu en affichant une image d'arrière-plan.  
InputSystem : Permet d'avoir des touches pour jouer.  
MovementSystem : Permet de déplacer les entités, notamment notre vaisseau et ceux des ennemis, ainsi que les missiles.  
SceneSystem : Un système de transition entre les différentes scènes de jeu, plusieurs sceneSystem ont été créé pour chaque scène.
TagComponent : Classifie les entités à l'aide de Tag pour une meilleure gestion dans divers systèmes.
ShootingSystem : Permet au joueur, ainsi qu'aux ennemis de tirer des missiles.
Cooldown Missile : Permet d'avoir un delay entre les missiles, grâce à un ClockSystem.
Enemy Spawner : Un vaisseau mère, qui produit des vaisseaux ennemis tant qu'il est en vie.