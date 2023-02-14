# Sensor_de_distancia

### Sebas Silva Tecnologia
¡Bienvenido a este mundo de la robótica! Aquí aprenderás paso a paso todo lo necesario para convertirte en un maestro de las maquinas del futuro.

En este GITHUB vas a encontrar varios proyectos de robotica, electronica y mecanica para la construccion de conocimiento juntos.


# Medidor de distancia

En este proyecto se indaga en el funcionamiento de las ondas de comunicacion y como el analisis de estas, realizando un medidor de distancia a partir de un sensor de ultrasonido. El codigo se deja como de fuente abierta ya que permitira realizar adiciones de mas elementos tanto electronicos como mecanicos en pro de construir un conocimiento mas profundo y complejo del mismo. Sientete libre de descargar este repositorio y mejorarlo!

Materiales
-------------
- Protoboard
>![board](https://user-images.githubusercontent.com/79547422/206582590-f091d6be-6f4f-4c22-9c90-18e982a1f83e.JPG)

- Pantalla LCD I2C
>![pantallaLCD](https://user-images.githubusercontent.com/79547422/206582760-9ee3093d-c4ed-4e09-a602-16abbbc88a66.JPG)
>![i2c](https://user-images.githubusercontent.com/79547422/206582933-da1d68bb-adaf-4093-8aee-a7066959bc0f.JPG)

- Sensor de ultrasonido HC-SR04
>![sensor](https://user-images.githubusercontent.com/79547422/206583151-45003958-78ac-4130-960c-c730b9f2a559.jpg)

- Arduino UNO 
>![arduino](https://user-images.githubusercontent.com/79547422/206583391-c520780f-7c52-415b-9109-3f37045955c3.JPG)

Procedimiento
-------------

Lo primero es realizar las conexiones entre el arduino y la protoboard, buscando los pines V5 y GND para asi conectarlos a las canaletas verticales, asi mismo vamos a conectar VCC y GND de nuestro sensor de ultrasonido a la protoboar y luego nuestro pin Trig al pin 9 del arduino y el pin Echo al pin 10 del arduino, para poder finalizar, lo siguiente es conectar VCC y GND de nuestra pantalla LCD  y el pin SCL al pin A5 y el pin SDA al pin A4 de nuestro arduino.

![conecttions](https://user-images.githubusercontent.com/79547422/206584620-f3da291c-28f0-43cc-9e8c-4b87832c2e7e.JPG)

Tras confirmar las correctas conexiones solo debes conectar el arduino y buscar la libreria [LiquidCrystal](https://www.arduinolibraries.info/libraries/liquid-crystal-i2-c) para poder utilizar nuestra pantalla LCD

-[Libreria LiquidCrystal](https://www.arduinolibraries.info/libraries/liquid-crystal-i2-c) 

Una vez descargada para instalarla debes abrir tu IDE de arduino, si no tienes lo tienes instalado puedes descararlo desde su web de [Software](https://www.arduino.cc/en/software), seleccionas el sistema operaivo en el que lo vas a instalar, lo bajas, y lo abres, siguiendo todas las instrucciones del instalador, no seria mucho mas.

[Descargar el IDE Arduino](https://www.arduino.cc/en/software)

Continuando con la instalacion de la libreria, debes dirigirte al apartado "Programa" en el menu superior y seleccionar "incluir libreria" y luego darle click a "Añadir biblioteca .ZIP", see te va a desplegar un buscador de archivos, deberas ubicar la libreria y seleccionarla, eso seria todo, ya tienes tu libreria instalada.

![libreria](https://user-images.githubusercontent.com/79547422/206586250-6a74be28-a28d-4b18-bc78-724f57af0c7b.JPG)
![lbreria2](https://user-images.githubusercontent.com/79547422/206586258-bab70188-d279-40f7-9561-eb14637e9967.JPG)
![libreria 3](https://user-images.githubusercontent.com/79547422/206586262-afd6d818-10d5-44ac-901a-1a7e0e9b10df.JPG)

Ahora debes utilizar el codigo [medidor_de_distancia.ino](https://github.com/FryFr/Sensor_de_distancia/blob/main/medidor_de_distancia.ino) en una sketch en blanco, compilar y subir y tendras tu sensor funcionando!

![funciona](https://user-images.githubusercontent.com/79547422/206586560-e2c6390a-c030-408c-a6db-ea35ac2b7f6d.JPG)

Ultima Actualizacion
-------------

#### Sensor de Distancia con Barra indicativa

En el codigo que tenemos en el archivo "medidor_distancia_con_barra.ino" podras ver un cambio en la presentación de los datos en nuestra pantalla LCD con comunicación I2C, para ello debemos mantener las mismas conexiones que en nuestra primera versión. Una vez encedido el arduino podremos ver el crecimiento de la barra dependiendo de la distancia capturada por nuestro sensor:

![aasdasda](https://user-images.githubusercontent.com/79547422/218630148-976afdb2-ad5b-487c-8a43-7a0ef3fa8b9e.JPG)
![fdasfasdf](https://user-images.githubusercontent.com/79547422/218630360-35b33837-8d9a-439c-9957-d10a5ac06c8d.JPG)
![qwerasdf](https://user-images.githubusercontent.com/79547422/218630365-daf53036-9481-4c57-b285-b823dc8d39e4.JPG)
![fasdfasdfa](https://user-images.githubusercontent.com/79547422/218630373-4bc42f78-dc2c-400f-aa26-bf327e0a1241.JPG)


#### Correccion caracteres al final del LCD

Declaramos una variable para guardar la ulltima distancia registrada
```C++
int ultimadistancia = 0;           //declaramos una variable para poder limpiar la pantalla LCD
```
Creamos un condicional para comparar las distancias registradas con las ultimas almacenadas y limpiamos la pantalla para evitar que se extiendan los caracteres, manteniendo el delay por fuera de la funcion
```C++
  if(distancia != ultimadistancia){   // realizamos un comparador de la distancia y la guardada de ultimo
    lcd.clear();                        //Limpiamos la pantalla por cada ciclo de datos encontrados
    lcd.setCursor(0,0);
    lcd.print("Distancia: ");
    lcd.print(distancia);              //Enviamos serialmente el valor de la distancia al LCD
    lcd.print("CM");
  }
```

## Creditos
- Nicolas Sanchez
- Juan Silva
