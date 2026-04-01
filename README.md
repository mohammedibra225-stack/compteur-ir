# 🚶‍♂️ Compteur de personnes avec capteurs IR et Arduino

## 📌 Description

Ce projet permet de compter automatiquement le nombre de personnes qui entrent et sortent d’un espace (salle, magasin, etc.) à l’aide de deux capteurs infrarouges et d’un écran LCD I2C.

Le système détecte le sens de passage :

* Entrée → incrémente le compteur
* Sortie → décrémente le compteur

---

## ⚙️ Fonctionnalités

* 🔢 Comptage automatique des personnes
* 🔄 Détection du sens (entrée / sortie)
* 📺 Affichage en temps réel sur écran LCD I2C
* 🛡️ Anti-rebond logiciel pour éviter les erreurs

---

## 🧰 Matériel utilisé

* Arduino (UNO / Mega)
* 2 capteurs IR (détection d’obstacle)
* Écran LCD I2C (20x4 ou 16x2)
* Fils de connexion

---

## 🔌 Connexions

### Capteurs IR

| Capteur      | Arduino |
| ------------ | ------- |
| IR1 (Entrée) | Pin 10  |
| IR2 (Sortie) | Pin 9   |
| VCC          | 5V      |
| GND          | GND     |

---

### LCD I2C

| LCD | Arduino |
| --- | ------- |
| VCC | 5V      |
| GND | GND     |
| SDA | SDA     |
| SCL | SCL     |

* Adresse utilisée : `0x20` (à vérifier selon ton module)

---

## 🧠 Principe de fonctionnement

1. Une personne passe devant **IR1 puis IR2** → **Entrée**
2. Une personne passe devant **IR2 puis IR1** → **Sortie**
3. Le système utilise un **délai anti-rebond** pour éviter les erreurs
4. Le compteur est mis à jour sur le LCD

---

## 💻 Installation

1. Installer Arduino IDE
2. Installer la bibliothèque :

   * `LiquidCrystal_I2C`
3. Connecter le matériel
4. Téléverser le code Arduino
5. Observer le compteur sur le LCD

---

## ⚠️ Remarques importantes

* Vérifier l’adresse I2C du LCD (`0x20`, `0x27`, etc.)
* Les capteurs IR donnent souvent `LOW` lorsqu’ils détectent un objet
* Ajuster le délai anti-rebond si nécessaire (`500 ms`)

---

## 📊 Exemple de sortie série

```
Personne ENTREE
Personne SORTIE
```

---

## 🚀 Améliorations possibles

* Ajouter une limite maximale de personnes
* Ajouter une alarme (buzzer)
* Sauvegarde du compteur (EEPROM)
* Interface mobile ou web

---


