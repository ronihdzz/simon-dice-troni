
<hr>

# **SIMONTRONI**
#### **Autor: David Roni Hernández Beltrán**
<hr>
<br>
<br>


### **Este pequeño proyecto es de mi autoria y lo desarrolle para completar el curso: Programación física con Arduino de CODE IOT iniciativa de Nokia a continuación ajunto mi certificado obtenido trar terminar el curso.**


<div style="text-align: center;">
<img  src="recursos_readme/certificado/Programacion_fisica_con_Arduino_1.jpg" style="width:80%;"  />
</div>


<div style="text-align: center;">
<img  src="recursos_readme/certificado/Programacion_fisica_con_Arduino_2.jpg" style="width:80%;"  />
</div>



### **Video de youtube de mi autoria explicando el proyecto:**


[![Alt text](https://img.youtube.com/vi/YSqHKkHPByw/0.jpg)](https://www.youtube.com/watch?v=YSqHKkHPByw)


### **Menu**


* [1) Prerrequisitos](#1-prerrequisitos)
    * [1.1) Materiales](#11-materiales)


* [2) Funcionamiento](#2-funcionamiento)

    * [2.0) Explicacion detallada](#20-explicacion-detallada)
    * [2.1) Explicacion breve](#21-explicacion-breve)
    * [2.2) Como jugar simon troni](#22-como-jugar-simon-troni)
    * [2.3) Explicacion del hadware del proyecto](#23-explicacion-del-hadware-del-proyecto)

* [3) Ensamble del proyecto](#3-ensamble-del-proyecto)
    * [3.1) Paso 1](#31-paso-1)
    * [3.2) Paso 2](#32-paso-2)
    * [3.3) Paso 3](#33-paso-3)


<hr>


## **1) Prerrequisitos**
<div class="myWrapper" markdown="1" align="center">

[Regresar al menu principal](#menu)
</div>

<hr>

A continuación se enlistan los prerrequisitos para poder ejecutar el proyecto:

### **1.1) Materiales**
<div class="myWrapper" markdown="1" align="center">

[Regresar al menu principal](#menu)
</div>


* 1-. Un buzzer pasivo

<!--style="margin-left:auto;margin-right:auto;width:100%;"-->
<div style="text-align: center;">
<img  src="recursos_readme/materiales/1_buzzerPasivo.jpg" style="width:40%;"  />
</div>

* 2-. Un potenciometro de 5k

<!--style="margin-left:auto;margin-right:auto;width:100%;"-->
<div style="text-align: center;">
<img  src="recursos_readme/materiales/2_potenciometro5k.jpg" style="width:40%;"  />
</div>


* 3-. Una resistencia de 220 [Ω] 

<!--style="margin-left:auto;margin-right:auto;width:100%;"-->
<div style="text-align: center;">
<img  src="recursos_readme/materiales/3_resistencia22_ohms.jpg" style="width:40%;"  />
</div>


* 4-. Cuatro resistencias de 330 [Ω]  o de 220 [Ω]  

<!--style="margin-left:auto;margin-right:auto;width:100%;"-->
<div style="text-align: center;">
<img  src="recursos_readme/materiales/4_resistencias330_ohms.jpg" style="width:40%;"  />
</div>


* 5-. Cuatro push button de 2 pines cada uno

<!--style="margin-left:auto;margin-right:auto;width:100%;"-->
<div style="text-align: center;">
<img  src="recursos_readme/materiales/5_pushButton_2pines.jpg" style="width:40%;"  />
</div>



* 6-. Cuatro leds

<!--style="margin-left:auto;margin-right:auto;width:100%;"-->
<div style="text-align: center;">
<img  src="recursos_readme/materiales/6_led.jpg" style="width:40%;"  />
</div>



* 7-. Un arduino uno con su cable respectivo

<!--style="margin-left:auto;margin-right:auto;width:100%;"-->
<div style="text-align: center;">
<img  src="recursos_readme/materiales/7_arduinoUno.jpg" style="width:40%;"  />
</div>


* 8-. Alambre de diferentes colores calibre 22(para conexiones en la protoboard) o jumpers macho, pero preferiblemente alambres

<!--style="margin-left:auto;margin-right:auto;width:100%;"-->
<div style="text-align: center;">
<img  src="recursos_readme/materiales/5_pushButton_2pines.jpg" style="width:40%;"  />
</div>


* 9-. Una computadora

<!--style="margin-left:auto;margin-right:auto;width:100%;"-->
<div style="text-align: center;">
<img  src="recursos_readme/materiales/9_computadora.jpg" style="width:40%;"  />
</div>


* 10-. Una protoboard

<!--style="margin-left:auto;margin-right:auto;width:100%;"-->
<div style="text-align: center;">
<img  src="recursos_readme/materiales/10_protoboard.png" style="width:40%;"  />
</div>




## **2) Funcionamiento** 

### **2.0) Explicacion detallada** 
<div class="myWrapper" markdown="1" align="center">

[Regresar al menu principal](#menu)
</div>

Para ver una explicación mas detallada de todo lo que puede hacer este proyecto, puedes leer el siguiente pdf el cual es el reporte que realice de mi proyecto:
[Reporte de simon roni](1_reporte/Reporte_simonTroni_byDavidRoniHernandezBeltran.pdf)




### **2.1) Explicacion breve** 
<div class="myWrapper" markdown="1" align="center">

[Regresar al menu principal](#menu)
</div>

<hr>

El funcionamiento del juego es muy sencillo, se prende una secuencia de leds y el usuario debe repetir dicha secuencia pulsando los botones respectivos, a medida que avanzamos, por cada secuencia correcta digitada en la siguiente secuencia que se muestre se prendera 1 led más, y así sucesivamente hasta terminar el juego o perder el juego.


Para ver una explicación mas detallada de todo lo que puede hacer este proyecto, puedes leer el siguiente pdf el cual es el reporte que realice de mi proyecto:
[Reporte de simon roni](1_reporte/Reporte_simonTroni_byDavidRoniHernandezBeltran.pdf)




### **2.2) Como jugar simon troni** 
<div class="myWrapper" markdown="1" align="center">

[Regresar al menu principal](#menu)
</div>


**PASO 1:** Para poder jugar con simonTroni debemos conectar el  Arduino a la computadora, pues el juego se comunica vía serial

<div style="text-align: center;">
<img  src="recursos_readme/reporte/paso_1_1.png" style="width:50%;"  />
</div>

**PASO 2:** Debemos abrir el  IDE de Arduino, y cerciorar  que esta seleccionado el  puerto del Arduino uno  que conectamos:

<div style="text-align: center;">
<img  src="recursos_readme/reporte/paso_2.png" style="width:80%;"  />
</div>


**PASO 3:** Necesitamos abrir el monitor serie del IDE de Arduino, así que damos clic  izquierdo sobre la lupa

<div style="text-align: center;">
<img  src="recursos_readme/reporte/paso_3.png" style="width:80%;"  />
</div>


**PASO 4:** Antes de  hacer cualquier  cosa, lo primero que  debemos hacer es  maximizar la  pantalla, así que proseguiremos a darle clic izquierdo sobre el icono de maximizar:


<div style="text-align: center;">
<img  src="recursos_readme/reporte/paso_4.png" style="width:80%;"  />
</div>


**PASO 5:** Podemos observar que nos pide que escribamos nuestro nombre y posteriormente tecleamos ENTER, pues eso  haremos…

<div style="text-align: center;">
<img  src="recursos_readme/reporte/paso_5.png" style="width:80%;"  />
</div>

**PASO 6:** Seguir las siguientes instrucciones.

<div style="text-align: center;">
<img  src="recursos_readme/reporte/paso_6.png" style="width:80%;"  />
</div>

<div style="text-align: center;">
<img  src="recursos_readme/reporte/paso_6_2.png" style="width:80%;"  />
</div>

<div style="text-align: center;">
<img  src="recursos_readme/reporte/paso_6_3.png" style="width:80%;"  />
</div>


**PASO 7:** Observar que una vez realizado lo anterior, nos aparecerá el siguiente mensaje, diciéndonos que presionemos cualquier botón del juego para poder   iniciar el juego

<div style="text-align: center;">
<img  src="recursos_readme/reporte/paso_7.png" style="width:80%;"  />
</div>


**PASO 8:** Presionamos cualquier botón del juego para poder iniciar el juego:

<div style="text-align: center;">
<img  src="recursos_readme/reporte/paso_8.png" style="width:60%;"  />
</div>

**PASO 9:** Finalmente el juego comenzara prendiendo un led al mismo tiempo que la bocina da un pitido. Nosotros deberemos presionar el botón del led que se prendió.

<div style="text-align: center;">
<img  src="recursos_readme/reporte/paso_9.png" style="width:60%;"  />
</div>


<div style="text-align: center;">
<img  src="recursos_readme/reporte/paso_9_1.png" style="width:80%;"  />
</div>


**PASO 10:** Si pulsamos el botón correcto del led que se prendió, pasaremos al siguiente nivel del  juego, el cual consistirá en presionar los botones en el orden respectivo de los 2 leds que se prenderán de forma cronológica. 


<div style="text-align: center;">
<img  src="recursos_readme/reporte/paso_10.png" style="width:80%;"  />
</div>


**PASO 11:** Si pulsamos los botones correctos en el orden correcto, pasaremos al siguiente nivel del  juego, el cual consistirá en presionar los botones en el orden respectivo, pero ahora de los 3 leds que se prenderán de forma cronológica.


<div style="text-align: center;">
<img  src="recursos_readme/reporte/paso_11.png" style="width:80%;"  />
</div>


**PASO 12:** Y así seguirá el juego a medida que pasemos al siguiente nivel aumentará un led más el cual debemos memorizar.


**PASO 13:** Si perdemos el juego nos avisará que perdimos y nos dirá nuestra puntuación lograda, y si queremos volver a jugar debemos seguir los mismos pasos a partir del paso número 5.

<div style="text-align: center;">
<img  src="recursos_readme/reporte/paso_13.png" style="width:80%;"  />
</div>


**PASO 14:** Si pasamos todos los niveles del juego, el juego nos avisara, y nos tocara una pieza musical  como recompensa de que hemos ganado, si queremos volver a jugar debemos seguir los mismos pasos a partir del paso número 5.

<div style="text-align: center;">
<img  src="recursos_readme/reporte/paso_14.png" style="width:80%;"  />
</div>


**PASO 15:** Si deseamos bajar el volumen del juego basta con girar el potenciómetro para ajustar el 
volumen del juego

<div style="text-align: center;">
<img  src="recursos_readme/reporte/paso_15.png" style="width:80%;"  />
</div>


### **2.3) Explicación del hadware del proyecto**

<div class="myWrapper" markdown="1" align="center">

[Regresar al menu principal](#menu)
</div>

<hr>


El funcionamiento del juego es muy sencillo, se prende una secuencia de leds y el usuario debe repetir dicha secuencia pulsando los botones respectivos, a medida que avanzamos, por cada secuencia correcta digitada en la siguiente secuencia que se muestre se prendera 1 led más, y así sucesivamente hasta terminar el juego o perder el juego.

¿Explicación del hadware del proyecto hadware?


<div style="text-align: center;">
<img  src="3_circuito/diagrama_simonTroni_byDavidRoniHernandezBeltran.jpg" style="width:80%;"  />
</div>


* Las resistencias de los leds son para limitar la corriente que pasa a través de ellos y así evitar dañar la placa Arduino o los leds por un flujo grande de corriente.

* El potenciómetro lo utilice para limitar la corriente que le llega al zumbador, de tal manera que si lo movemos alteramos la resistencia de este, lo cual ocasiona una alteración en la corriente, lo que 
significa una alteración en la potencia que recibe el zumbador, lo cual significa una variación en la intensidad del volumen del juego, es decir gracias al potenciometro se puede subir o bajar el volumn del juego. 

* La resistencia que une al potenciómetro con el zumbador sirve como medida de protección en caso de que el jugador decida subirle todo el volumen al juego (tener un potenciómetro con un resistencia de 0 [Ω] ) y así evitar que la corriente que fluya por el zumbador nunca sea muy grande pues no importando como gire el potenciómetro el jugador, la resistencia mínima siempre serán 
22[Ω].

* Todos los botones están conectados de un pin de Arduino al GND de Arduino, debido a que active 
la resistencia interna de los pines que van conectados a los botones, declarando esos pines como 
pines: INPUT_PULLUUP

<div style="text-align: center;">
<img  src="recursos_readme/reporte/1_pushButton.png" style="width:60%;"  />
</div>


De esa manera me ahorro el trabajo extra de colocar resistencias externas para los botones:

<div style="text-align: center;">
<img  src="recursos_readme/reporte/2_pushButton2.png" style="width:60%;"  />
</div>

Las imágenes fueron obtenidas de las siguientes fuentes de información: 

* https://slideplayer.com/slide/4469076/
* https://forum.arduino.cc/index.php?topic=575915.0




## **3) Ensamble del proyecto**
<div class="myWrapper" markdown="1" align="center">

[Regresar al menu principal](#menu)
</div>


<hr>


### **3.1) Paso 1**
<div class="myWrapper" markdown="1" align="center">

[Regresar al menu principal](#menu)
</div>

Cumplir con todos los prerrequisitos ya mencionados anteriormente, es decir **conseguir el material**

  * [1) Ir al apartado de  prerrequisitos](#1-prerrequisitos)
      * [1.1) Ir al apartado de materiales](#11-materiales)




### **3.2) Paso 2**
<div class="myWrapper" markdown="1" align="center">

[Regresar al menu principal](#menu)
</div>

* Cargar el script  que se encuentra en: <<**2_codigo/proyecto_RoniHernandez**>>  en el arduino uno

  [dar clic aqui para ver el script proyecto_RoniHernandez](2_codigo/proyecto_RoniHernandez)





### **3.3) Paso 3**
<div class="myWrapper" markdown="1" align="center">

[Regresar al menu principal](#menu)
</div>

Armar el **diagrama del circuito del proyecto**:

[dar clic aqui para ver circuito de manera mas legible](3_circuito/diagrama_simonTroni_byDavidRoniHernandezBeltran.pdf)



<div style="text-align: center;">
<img  src="3_circuito/diagrama_simonTroni_byDavidRoniHernandezBeltran.jpg" style="width:80%;"  />
</div>
