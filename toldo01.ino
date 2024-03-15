/*Automatismo de un toldo que funciona con una fotorresistencia
* Autor: Juan Manuel Martínez Lojo
* Fecha: Marzo 2024
*/

// Definición de pines
#define MOTOR_PIN1 2
#define MOTOR_PIN2 4
#define MOTOR_ENABLE 5
#define LDR_PIN A0
#define FIN_DESPLIEGUE 6
#define FIN_PLEGADO 7
#define INICIO 8
#define POTENCIA2 1

// Variables globales
int luminosidad;
int velocidad;

void setup() {
  pinMode(MOTOR_PIN1, OUTPUT);
  pinMode(MOTOR_PIN2, OUTPUT);
  pinMode(MOTOR_ENABLE, OUTPUT);
  pinMode(FIN_DESPLIEGUE, INPUT);
  pinMode(FIN_PLEGADO, INPUT);
  pinMode(INICIO, INPUT);
  
  digitalWrite(MOTOR_PIN1, LOW);
  digitalWrite(MOTOR_PIN2, LOW);
}

void loop() {
  // Leer valor de luminosidad
  luminosidad = map(analogRead(LDR_PIN), 0, 1023, 5, 0);
  velocidad = luminosidad * 20;
  
  // Esperar a que se presione el botón de inicio
  while(digitalRead(INICIO) == LOW);
  
  // Despliegue
  digitalWrite(MOTOR_ENABLE, HIGH);
  while(digitalRead(FIN_DESPLIEGUE) == LOW) {
    digitalWrite(MOTOR_PIN1, HIGH);
    digitalWrite(MOTOR_PIN2, LOW);
    analogWrite(POTENCIA2, velocidad);
  }
  
  // Paro antes de invertir el giro
  digitalWrite(MOTOR_PIN1, LOW);
  digitalWrite(MOTOR_PIN2, LOW);
  
  // Plegado
  while(digitalRead(FIN_PLEGADO) == LOW) {
    digitalWrite(MOTOR_PIN1, LOW);
    digitalWrite(MOTOR_PIN2, LOW);
  }
  
  // Paro final
  digitalWrite(MOTOR_PIN1, LOW);
  digitalWrite(MOTOR_PIN2, LOW);
}
