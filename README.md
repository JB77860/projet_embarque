# Projet Embarqué

Une carte Raspberry pi3 est utilisée, sur cette carte nous avons un détecteur de mouvement, ainsi qu’un feu tricolore (diodes)

Principe de fonctionnement : 
* Sans détection de présence le feu est vert
* En passant la main devant le détecteur le feu devient orange
* En laissant la main devant le détecteur le feu est rouge.


## Configuration matérielle

1 Carte Raspberry Pi 3  
1 Capteur de mouvement
1 Feu tricolore (diodes)
1 Carte SD
1 Platine d'essai

## Collaborateurs du projet
Mirah - Stanislas - Jérôme

## Prérequis
1. Effectuer tous les branchements nécessaires sur la carte Raspberry Pi 3 : le capteur de présence ainsi que les 3 LED vert, orange, rouge 

Broche GPIO 20 : Utilisée comme entrée pour la capteur de mouvement  
Broches GPIO 13, 29, 26 : Utilisées comme sorties pour les LED 

![kit_composants_GPIO_01](https://github.com/JB77860/projet_embarque/assets/50988564/7df59933-a1eb-46ab-991b-3a7e55154b1a)

2. Télécharger un OS : et le mettre sur une carte SD pour pouvoir l'installer sur la carte Raspberry Pi 3
  
L'OS utilisé ici est : 2023-05-03-raspios-bullseye-armhf-lite

Raspberry Pi OS Lite  
Release date: May 3rd 2023  
System: 32-bit  
Kernel version: 6.1  
Debian version: 11 (bullseye)  
Size: 364MB  

Vous le trouverez sur ce lien :  
```
https://www.raspberrypi.com/software/operating-systems/
```

3. Mettre l'OS choisi sur une carte SD pour pouvoir l'installer sur la carte Raspberry Pi 3

Nous avons fait le choix de passer par raspeberry pi imager très facile d'utilisation

Vous le trouverez ici :  
```
https://www.framboise314.fr/installer-raspberry-pi-os-avec-la-nouvelle-version-1-7-1-de-raspberry-pi-imager/
```

4. Installation de l'OS sur la carte Raspeberry Pi 3 via le lecteur de carte SD

5. Installation de la bibliothèque WiringPi pour la lecture des ports GPIO

* Faire un git clone de ce repo :
  ```
  https://github.com/WiringPi/WiringPi.git
  ```
*Aller dans le fichier wiringpi et lancer la commande ./build

*Vérifier l'installation en tapant la commande gpio readall, vous obtiendrez alors ceci :  
![gpio_readall](https://github.com/JB77860/projet_embarque/assets/50988564/55ef0c64-3eff-4617-ad1f-f8e0d4d90df9)


## Liens utilisés

```
https://github.com/WiringPi/WiringPi
```


## Installation



## Tests



## Déploiement


## Technologies utilisées

* Langage C++ pour le code


