#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int Trigger = 9;             //Pin digital 2 para el Trigger del sensor
const int Echo = 10;               //Pin digital 3 para el Echo del sensor
int ultimadistancia = 0;           //declaramos una variable para poder limpiar la pantalla LCD
LiquidCrystal_I2C lcd(0x27,16,2); //definimos la matris LCD de nuestra pantalla

void setup() {
  Serial.begin(9600);         //Inicializamos la comunicacion
  pinMode(Trigger, OUTPUT);   //definimos el Trigger como salida
  pinMode(Echo, INPUT);       //definimos el Echo como entrada
  digitalWrite(Trigger, LOW); //Inicializamos el pin con un 0 digital   
  lcd.init();                 //inicializamos el LCD
  lcd.backlight();            //creamos un fondo para el LCD

}

void loop() {
  long tiempo;       //variable que definira el tiempo que demora en llegar el eco
  long distancia;    //variable que definira la distancia en CM

  digitalWrite(Trigger, HIGH);  
  delayMicroseconds(10);        //Enviamos un pulso de 10microsegundos
  digitalWrite(Trigger, LOW);

  tiempo = pulseIn(Echo, HIGH);       //Obtenemos el ancho del pulso
  distancia = tiempo / 59;            //escalamos el tiempo a una distancia en CM por medio de una conversion directa

  Serial.print("Distancia: ");
  Serial.print(distancia);            //Enviamos serialmente el valor de la distancia
  Serial.print("CM");

  Serial.println();

  if(distancia != ultimadistancia){   // realizamos un comparador de la distancia y la guardada de ultimo
    lcd.clear;                        //Limpiamos la pantalla por cada ciclo de datos encontrados
    lcd.setCursor(0,0);
    lcd.print("Distancia: ");
    lcd.print(distancia);              //Enviamos serialmente el valor de la distancia al LCD
    lcd.print("CM");
  }
  delay(50);                        //Hacemos una pausa de 100ms

}
