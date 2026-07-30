#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define CAPTEUR_IR1 10  // Capteur d'entrée
#define CAPTEUR_IR2 9  // Capteur de sortie

LiquidCrystal_I2C lcd(0x20, 20, 4);  

int compteur = 0;
unsigned long dernierPassage = 0;  
const int delaiAntirebond = 500;  
bool capteurIR1Detecte = false;
bool capteurIR2Detecte = false;

void setup() {
    pinMode(CAPTEUR_IR1, INPUT);
    pinMode(CAPTEUR_IR2, INPUT);
    lcd.init();
    lcd.backlight();
    miseAJourLCD();
    Serial.begin(9600);
}

void loop() {
    unsigned long tempsActuel = millis();
    bool etatIR1 = digitalRead(CAPTEUR_IR1);
    bool etatIR2 = digitalRead(CAPTEUR_IR2);

    
    if (tempsActuel - dernierPassage > delaiAntirebond) {
        if (etatIR1 == LOW) {
            capteurIR1Detecte = true;
            dernierPassage = tempsActuel;
        } else if (etatIR2 == LOW) {
            capteurIR2Detecte = true;
            dernierPassage = tempsActuel;
        }

        
        if (capteurIR1Detecte && !capteurIR2Detecte) {
            delay(delaiAntirebond);  
            if (digitalRead(CAPTEUR_IR2) == LOW) {
                compteur++;
                capteurIR1Detecte = false;
                capteurIR2Detecte = false;
                Serial.println("Personne ENTREE");
                miseAJourLCD();
            }
        } else if (capteurIR2Detecte && !capteurIR1Detecte) {
            delay(delaiAntirebond);  
            if (digitalRead(CAPTEUR_IR1) == LOW) {
                compteur--;
                capteurIR1Detecte = false;
                capteurIR2Detecte = false;
                Serial.println("Personne SORTIE");
                miseAJourLCD();
            }
        }
    }

    
    if (tempsActuel - dernierPassage > delaiAntirebond) {
        capteurIR1Detecte = false;
        capteurIR2Detecte = false;
    }
}

void miseAJourLCD() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Compteur: ");
    lcd.print(compteur);
}








 

