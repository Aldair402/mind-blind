#include <Wire.h>
#include <LiquidCrystal_I2C.h>


const int Trigger = 9;             //Pin digital 2 para el Trigger del sensor
const int Echo = 10;               //Pin digital 3 para el Echo del sensor
int ultimadistancia = 0;           //declaramos una variable para poder limpiar la pantalla LCD
LiquidCrystal_I2C lcd(0x27,16,2);

byte distancia_vacia[8] = {B11111, B00000, B00000, B00000, B00000, B00000, B00000, B11111};
byte distancia_llena_1[8] = {B11111, B10000, B10000, B10000, B10000, B10000, B10000, B11111};
byte distancia_llena_2[8] = {B11111, B11000, B11000, B11000, B11000, B11000, B11000, B11111};
byte distancia_llena_3[8] = {B11111, B11100, B11100, B11100, B11100, B11100, B11100, B11111};
byte distancia_llena_4[8] = {B11111, B11110, B11110, B11110, B11110, B11110, B11110, B11111};
byte distancia_llena_5[8] = {B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111};
byte distancia_derecha[8] = {B11111, B00001, B00001, B00001, B00001, B00001, B00001, B11111};
byte distancia_izquierda[8] = {B11111, B10000, B10000, B10000, B10000, B10000, B10000, B11111};

byte distancia_mascara_izquierda[8] = {B01111, B11111, B11111, B11111, B11111, B11111, B11111, B01111};
byte distancia_mascara_derecha[8] = {B11110, B11111, B11111, B11111, B11111, B11111, B11111, B11110};

byte distancia_izquierda_dinamica[8];
byte distancia_derecha_dinamica[8];
int mover_desplazamiento = 0;

int cpu_distancia;

const int distancia_tamano_character = 16;
char distancia_string[distancia_tamano_character+1];

void setup() {

  Serial.begin(9600);         //Inicializamos la comunicacion
  pinMode(Trigger, OUTPUT);   //definimos el Trigger como salida
  pinMode(Echo, INPUT);       //definimos el Echo como entrada
  digitalWrite(Trigger, LOW); //Inicializamos el pin con un 0 digital 
  
  lcd.init();
  lcd.createChar(7, distancia_vacia);
  lcd.createChar(1, distancia_llena_1);
  lcd.createChar(2, distancia_llena_2);
  lcd.createChar(3, distancia_llena_3);
  lcd.createChar(4, distancia_llena_4);
  lcd.backlight(); 

}

void loop() {

   float tiempo;       //variable que definira el tiempo que demora en llegar el eco
   float distancia;    //variable que definira la distancia en CM
   float distancia_mostrar;

   digitalWrite(Trigger, HIGH);  
   delayMicroseconds(10);        //Enviamos un pulso de 10microsegundos
   digitalWrite(Trigger, LOW);

   tiempo = pulseIn(Echo, HIGH);       //Obtenemos el ancho del pulso
   distancia = tiempo / 58;   
   distancia_mostrar = tiempo / 58;

   float unidades_por_pixel = (distancia_tamano_character*5.0)/400.0;
   int valor_en_pixeles = round(cpu_distancia * unidades_por_pixel);

   int posicion_puntual = 0; //0=no definida, 1= en primer caracter, 2= en el medio, 3= ultimo caracter

   if(valor_en_pixeles < 5){
      posicion_puntual = 1;
   }else if(valor_en_pixeles > distancia_tamano_character*5.0-5){
      posicion_puntual = 3;
   }else{
      posicion_puntual = 2;
   }

   mover_desplazamiento = 4 - ((valor_en_pixeles - 1) % 5);

  for(int i=0; i<8; i++){
     if(posicion_puntual == 1){
         distancia_izquierda_dinamica[i] = (distancia_llena_5[i] << mover_desplazamiento) | distancia_izquierda[i];
     }else{
        distancia_izquierda_dinamica[i] = distancia_llena_5[i];
     }

     distancia_izquierda_dinamica[i] = distancia_izquierda_dinamica[i] & distancia_mascara_izquierda[i];
  }

  for(int i=0; i<8; i++){
     if (posicion_puntual == 3){
         distancia_derecha_dinamica[i] = (distancia_llena_5[i] << mover_desplazamiento) | distancia_derecha[i];
     }else{
        distancia_derecha_dinamica[i] = distancia_derecha[i];
     }

     distancia_derecha_dinamica[i] = distancia_derecha_dinamica[i] & distancia_mascara_derecha[i];
  }

   lcd.createChar(5, distancia_izquierda_dinamica);
   lcd.createChar(6, distancia_derecha_dinamica);

   for(int i=0; i<distancia_tamano_character; i++){
      if(i==0){
         distancia_string[i] = byte(5);
      }else if(i == distancia_tamano_character-1){
         distancia_string[i] = byte(6);
      }else{
         if(valor_en_pixeles <= i*5){
            distancia_string[i] = byte(7);
         }else if(valor_en_pixeles > i*5 && valor_en_pixeles< (i+1)*5){
             distancia_string[i] = byte(5 - mover_desplazamiento);
         }else{
            distancia_string[i] = byte(255);
         }
      }
   }


   lcd.setCursor(0,1);
   lcd.print(distancia_string); 

   if(distancia != ultimadistancia){   // realizamos un comparador de la distancia y la guardada de ultimo
    lcd.setCursor(0,0);
    lcd.print("Medida: ");
    lcd.print(distancia);              //Enviamos serialmente el valor de la distancia al LCD
    lcd.print("CM  ");
  }

   cpu_distancia = distancia;
   

   delay(100);
 }
