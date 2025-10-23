#include <Wire.h>
const int Trigger = 9;             //Pin digital 2 para el Trigger del sensor
const int Echo = 10;               //Pin digital 3 para el Echo del sensor
int motorPin = 3; //motor al pin 3

void setup() {
  Serial.begin(9600);         //Inicializamos la comunicacion
  pinMode(Trigger, OUTPUT);   //definimos el Trigger como salida
  pinMode(motorPin, OUTPUT);  //definimos el Motor como salida
  pinMode(Echo, INPUT);       //definimos el Echo como entrada
  digitalWrite(Trigger, LOW); //Inicializamos el pin con un 0 digital   

}

void loop() {
  long tiempo;       //variable que definira el tiempo que demora en llegar el eco
  long distancia;    //variable que definira la distancia en CM

  digitalWrite(Trigger, HIGH);  
  delayMicroseconds(10);        //Enviamos un pulso de 10 microsegundos
  digitalWrite(Trigger, LOW);

  tiempo = pulseIn(Echo, HIGH);       //Obtenemos el ancho del pulso
  distancia = tiempo / 59;            //escalamos el tiempo a una distancia en CM por medio de una conversion directa

  Serial.print("Distancia: ");
  Serial.print(distancia);            //Enviamos serialmente el valor de la distancia
  Serial.print("CM");

  Serial.println();

  if(distancia <= 50){   // Como sabemos que medimos en CM podemos hacer esto w
   digitalWrite(motorPin, HIGH); // Vibramos w
  }
  delay(50);                        //Hacemos una pausa de 100ms

}
