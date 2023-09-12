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

## Prérequis
1. Effectuer tous les branchements nécessaires sur la carte Raspberry Pi 3 : le capteur de présence ainsi que les 3 LED vert, orange, rouge 

  &emsp Broche GPIO 20 : Utilisée comme entrée pour la capteur de mouvement  
  &emsp Broches GPIO 13, 29, 26 : Utilisées comme sorties pour les LED 

![kit_composants_GPIO_01](https://github.com/JB77860/projet_embarque/assets/50988564/7df59933-a1eb-46ab-991b-3a7e55154b1a)

2. Télécharger un OS : et le mettre sur une carte SD pour pouvoir l'installer sur la carte Raspberry Pi 3
  
  &emspL'OS utilisé ici est : 2023-05-03-raspios-bullseye-armhf-lite

  &emsp Raspberry Pi OS Lite  
  &emsp Release date: May 3rd 2023  
  &emsp System: 32-bit  
  &emsp Kernel version: 6.1  
  &emsp Debian version: 11 (bullseye)  
  &emsp Size: 364MB  

  Vous le trouverez sur ce lien :  
```
https://www.raspberrypi.com/software/operating-systems/
```

3. Mettre l'OS choisi sur une carte SD pour pouvoir l'installer sur la carte Raspberry Pi 3

  &emsp Nous avons fait le choix de passer par raspeberry pi imager très facile d'utilisation

  Vous le trouverez ici :  
```
https://www.framboise314.fr/installer-raspberry-pi-os-avec-la-nouvelle-version-1-7-1-de-raspberry-pi-imager/
```

4. Installation de l'OS sur la carte Raspeberry Pi 3 via le lecteur de carte SD

5. Installation de la bibliothèque WiringPi pour la lecture des ports GPIO

 &emsp * Faire un git clone de ce repository :
  ```
  https://github.com/WiringPi/WiringPi.git
  ```
 &emsp * Aller dans le fichier wiringpi et lancer la commande ./build

 &emsp * Vérifier l'installation en tapant la commande gpio readall, vous obtiendrez alors ceci :   
  
![gpio_readall](https://github.com/JB77860/projet_embarque/assets/50988564/55ef0c64-3eff-4617-ad1f-f8e0d4d90df9)




## Utilisation

Vous pouvez alose compiler le code en utilisant le compilateur C++
```
g++ custom.cpp
```





## Technologies utilisées

* Langage C++ pour le code


