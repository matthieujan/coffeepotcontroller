# coffeepotcontroller

## Préambule
Ce programme représente le client et le server permettant de manipuler notre cafetière.
Il a été réalisé dans le cadre du cours Programmation Objet Avancée / Projet C++.

## Prérequis
- Un RaspberryPi (Ex : RaspberryPi 3, avec une distribution Debian modifié)
- Un servo moteur (Ex : HS 311)
- Quelques cables (3, en fait)

## Configuration
- Le makefile du projet ne fait pas de cross-compiling, et demande a build le projet sur le raspberry
- Installer les librairies (typiquement boost et wiringpi)
- Branchement (de RaspberryPi vers Servo)
    - Ground / Noir
    - 5V / Red
    - Pin7 / Yellow
- La mise au point des valeurs permettant de manipuler le Servo sont ajustés manuellement dans le fichier src/CoffeeDriver.cpp

## Usage
- Cloner le repo sur votre machine
`git clone https://github.com/matthieujan/coffeepotcontroller`

- Se déplacer dans le dossier
`cd coffeepotcontroller`

- Compiler le programme
`make`

- Pour lancer le serveur
`bin/cpc server host port`

- Pour lancer le client, cmd=(start|stop|get)
`bin/cpc client host port cmd`

- Et si vous le voulez, entrez l'adresse du serveur dans votre navigateur web

## Evaluation
- Le rapport est situé à rendu/Rapport_CPC.pdf
- La doc est : en dur dans les commentaires / Dans le ficher rendu/Doc_CPC.pdf
- Readme/Executable/Instructions de compilation : ... :)
- Classes et Heritage : Les classes Driver / LedDriver / CoffeeDriver présente des Drivers interchangeable dans le main
- Surdéfinition : Pas présent (un interet très artificiel dans notre projet utilisant beaucoup de librairies)
- STL : Rapide utilisation dans la classe BasicServerNetCtl, dans la fonction requestHandle pour split et retrouver l'instruction GET
- Qualité du projet et fonctionnalités : Réseau / Pseudo Web / Cafetière
- Vidéo : rendu/TODO
- Présentation : ouvrir dans votre navigateur le fichier rendu/prez/index.html
