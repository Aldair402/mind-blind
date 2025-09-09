# Sensor de distancia con motor vibrador

Este proyecto utiliza un **sensor ultrasónico HC-SR04** y un **motor vibrador** conectado a un **Arduino Micro** para detectar obstáculos cercanos.
El objetivo es servir como **ayuda para personas ciegas**, permitiéndoles percibir la proximidad de objetos mediante vibraciones y así evitar golpes o accidentes.

---

## Descripción

El sistema mide la distancia frente al sensor.

* Cuando detecta que un objeto se acerca, activa el **motor vibrador**.
* La intensidad y frecuencia de la vibración pueden ajustarse según la distancia.

De esta manera, la persona puede identificar obstáculos sin necesidad de visión, únicamente a través de la vibración en el dispositivo.

---

## Materiales

* Cables con entradas para resistencias y salidas a Arduino
* Sensor de ultrasonido HC-SR04
  ![Sensor](https://user-images.githubusercontent.com/79547422/206583151-45003958-78ac-4130-960c-c730b9f2a559.jpg)
* Arduino Micro
![Arduino Micro](https://github.com/user-attachments/assets/ea544487-fcbf-4526-b601-1a3cc3c42e49)
* Motor vibrador (ejemplo: motor de celular)
* Resistencias según el montaje

---

## Conexiones

1. Conectar **VCC** y **GND** del sensor de ultrasonido al Arduino Micro usando cables con entradas para resistencias.
2. Conectar el pin **Trig** al pin digital **9** del Arduino Micro.
3. Conectar el pin **Echo** al pin digital **10** del Arduino Micro.
4. Conectar el **motor vibrador** a un pin digital **3** y a GND mediante una resistencia o un transistor según el modelo.

---

## Código

* Código para el **sensor de distancia**:
  [medidor\_de\_distancia.ino](https://github.com/FryFr/Sensor_de_distancia/blob/main/medidor_de_distancia.ino)

* Código para el **motor vibrador**:
  [Vibration Motor with Arduino](https://gist.github.com/techzeero/114976eec7675610bfc4fa905d73ee89/raw/a7c2fef2672c14187d2e1fe17f4be7c801362e9e/Vibration%20Motor%20with%20Arduino.ino)

---

## Créditos

Este repositorio es un **fork** del proyecto original para mostrar la distancia en una pantalla lcd.

**Autores originales (coautores):**

* Nicolas Sanchez
* Juan Silva

**Autor de este fork:**

* Aldair Gastelum

**Proyecto desarrollado en:**

* Taller de Administración

---

¿Quieres que haga eso?
