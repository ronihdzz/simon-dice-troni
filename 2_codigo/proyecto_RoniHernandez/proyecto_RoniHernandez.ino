/*
 * Nombre del programa:  simonTroni
 * 
 * Autor: David Roni Hernández Beltrán
 * 
 * Descripcción: Este proyecto se basa en el clasico
 * juego de memoria en el cual se te muestra una 
 * secuencia y tu tiene que tocarla, a medida que 
 * avanzas en el juego tienes que memorizar una nueva
 * posicion.
 * 
 */

//Lubreria que contiene definidas varias frecuencias de notas musicales
//de distinta octavas: 
#include "frecuenciasNotas.h"


//definiendo los pines de cada boton...
#define BOTON_1  2  
#define BOTON_2  4
#define BOTON_3  6
#define BOTON_4  8

//definiendo los pines de cada led...
#define LED_1 3 
#define LED_2 5
#define LED_3 7
#define LED_4 9


#define NO_BOTONES 4

//array que almacenara el numero de cada pin que sera boton...
byte G_arrayBotones[NO_BOTONES]={BOTON_1,BOTON_2,BOTON_3,BOTON_4};
//array que almacenara el numero de cada pin que sera led...
byte G_arrayLeds[NO_BOTONES]={LED_1,LED_2,LED_3,LED_4};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//     DATOS DE LA MELODIA: YESTERDAY
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//numero de notas de la melodia yesterday...
#define TAM_YESTERDAY 31

// Notas de la melodia de yesterday:
int G_notas_yesterday[TAM_YESTERDAY] = {
    G4,F4,F4,PAUSA,  A4,B4,CS5,D5,E5,F5,E5,D5,D5,PAUSA,  D5,D5,C5,AS4,A4,G4,AS4,A4,A4,    G4,F4,A4,G4,D4,F4,A4,A4  };

// Duración de las notas: 
// Estandar que utilize en los tiempos de las figuras musicales:  0.5=corchea  1=negra  2=blanca
float G_duracionNotas_yesterday[TAM_YESTERDAY] = {
    0.5,0.5,3,1,   0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,3,1,  0.5,0.5,0.5,0.5,0.5,0.5,1,0.5,1,    1,1,0.5,1,1,1,0.5,2.5 };

//pin al cual se conectara el buzzer para emitir sonidos...
const int PIN_BOCINA=11;



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  F  U  N   C  I  O   N   E  S       Q   U  E        C  R  E   E  :
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//declaracion de las funciones que cree,para modular de mejor
//manera el programa...

void mensajeGanador();
void mensajePerdedor();
void mensajeBienvenida();
char botonPresionan(byte* arrayBotones,byte noBotones,bool sonInputPullUp);
void tocarTono(int frecuencia,int duracion );
void maquinaEscribirTeclea(String elTexto,long tiempoEntreLetra);


void setup() {  
  //configurando pines de botones como pines INPUT_PULLUP
  int c;
  for(c=0;c<NO_BOTONES;c++){
    pinMode(G_arrayBotones[c],INPUT_PULLUP);
  }
  //configurando pines de leds como pines OUPUT(SALIDA)   
  for(c=0;c<NO_BOTONES;c++){
    pinMode(G_arrayLeds[c],OUTPUT);
  }
  //apagando todos los leds antes de empezar...   
  for(c=0;c<NO_BOTONES;c++){
    digitalWrite(G_arrayLeds[c],LOW);
  }
  //velocidad de comunicacion serial...
  Serial.begin(9600);
}

void loop() {
  mensajeBienvenida();
  //mientras no presionen un boton no los dejare iniciar el juego
  //y por lo tanto no podran salir de este ciclo while anidado
  while( botonPresionan(G_arrayBotones,4,true) == 0 ){
  }
  //void simonDice_byRoni(String secuenciaJuego,byte* arrayLeds, byte* arrayBotones,byte noBotones    )
  int noNiveles=simonDice_byRoni("1234123412341234",G_arrayLeds,G_arrayBotones,NO_BOTONES);
  if(noNiveles<=0){//significa que perdio el juego...
    mensajePerdedor();
  }else{//significa que gano el juego....  
    mensajeGanador();  
  }   
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//   P  R  O   G  R  A  M  A  C  I  O  N       D  E L    J  U  E  G  O  :
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*   int simonDice_byRoni (String secuenciaJuego,byte* arrayLeds, byte* arrayBotones,byte noBotones  )
 *    
 *    Creara un juego de simon clasico el cual seguira la secuencia del parametro de tipo
 *    string cuyo nombre es 'secuenciaJuego', tambien recibe un array de los pines de botones
 *    y de leds debido a que la funcion necesita saber que botones controlaran a los leds
 *    y que leds son los que prendera para el juego
 *    
 *    La funcion returna el puntaje obtenido por el jugador como numero negativo en caso
 *    de que el jugador no haya conseguido ganar...
 *    
 *    La funcion returna el puntaje obtenido por el jugador como numero positivo en caso
 *    de que el jugador haya terminado todo el juego completo...
 * 
 * 
 */

int simonDice_byRoni(String secuenciaJuego,byte* arrayLeds, byte* arrayBotones,byte noBotones    ){
      int noNiveles=secuenciaJuego.length();
      int nivelesLogrados=-1;
      for(int nivel=0;nivel<noNiveles;nivel++){
          if(nivel>0){
            Serial.println("LOGRADO :) ");
          }
          //MOSTRANDO SECUENCIA DE LEDS....
          Serial.print("\tNivel ");Serial.print(nivel+1);Serial.print(": ");
          for(int ledPrender=0;ledPrender<nivel+1;ledPrender++){
              //prendemos foco
              //codigo ascii 49 = 1 ( Número uno )
              digitalWrite(arrayLeds[  byte(secuenciaJuego[ledPrender])-49   ]   ,HIGH);
              tocarTono(500,400);
              digitalWrite(arrayLeds[  byte(secuenciaJuego[ledPrender])-49   ]   ,LOW);
          }
          //PREGUNTANDO SECUENCIA DE LEDS...  
          byte botonEsPresionado=0;
          for(int ledPrender=0;ledPrender<nivel+1;ledPrender++){
              //HASTA QUE SE PRECIONE UN BOTON...
              botonEsPresionado=0;
              while(botonEsPresionado==0){
                botonEsPresionado=botonPresionan(arrayBotones,4,true);
              }
              digitalWrite(arrayLeds[botonEsPresionado-1],HIGH);
              //¿el boton pulsado fue el incorrecto?....
              if(botonEsPresionado  !=  ( byte(secuenciaJuego[ledPrender])-48 )   ){
                nivelesLogrados=nivel;
                nivel=noNiveles;
                digitalWrite(arrayLeds[botonEsPresionado-1],LOW);
                Serial.println("PERDIDO :(");
                break;
              }
              tocarTono(500,400);
              digitalWrite(arrayLeds[botonEsPresionado-1],LOW);
          }  
          delay(1000);
      }
      if(nivelesLogrados==-1){//el usuario logro terminar el juego satisfactoriamente
        Serial.print("LOGRADO :)");
        return noNiveles;
      }else{//el usuario no consiguio terminar el juego satisfactoriamente
          Serial.print("Niveles logrados: ");
          Serial.println(nivelesLogrados);
          return nivelesLogrados*-1;//regresando el numero de niveles logrados con numeros negativos
                                    //para que sepan que no paso el juego 
      }
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//      O    T     R     A      S         F      U       N     C       I      O      N       E       S     :
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
 *    void tocarTono(int frecuencia,int duracion )
 *    
 *    Esa funcion sirve para tocar un frecuencia durante un tiempo por el pin que esta conectado a un buzer...
 * 
 */

void tocarTono(int frecuencia,int duracion ){
    tone(PIN_BOCINA, frecuencia, duracion);
    delay(duracion);
    noTone(PIN_BOCINA);
    delay(100);  
}  


/*
 * Retornara el numero de boton que haya sido presionado, en caso de no haber detectado 
 * ningun boton presionado retornara cero
 * 
 */
char botonPresionan(byte* arrayBotones,byte noBotones,bool sonInputPullUp){
  bool unBotonPresionado=!sonInputPullUp;
  char botonEsPresionado=-1; //valor default el cual permanecera
                          //en caso de no detectarse ningun boton
  for(int c=0;c<4;c++){
    if( digitalRead(arrayBotones[c])== unBotonPresionado ){
      botonEsPresionado=c;
      break;
    }
  }
  botonEsPresionado++;
  return botonEsPresionado;
}

/*
 *  void maquinaEscribirTeclea(String elTexto,long tiempoEntreLetra)
 *   Esta funcion escribira como una maquina de escribir a traves del puerto serial
 *   el texto que se le pone, y entre cada caracter de este, esperara 'timeEntreLetra'
 *   milisegundos...
 * 
 */
void maquinaEscribirTeclea(String elTexto,long tiempoEntreLetra){
  for(int c=0;c<elTexto.length();c++){
    Serial.print( elTexto[c] );
    delay(tiempoEntreLetra);
  }
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// M  E  N  S  A  J   E  S            D   E   L              J  U  E  G  O  
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
 *  void mensajeBienvenida()
 *    Preguntara el nombre del jugador, y despues dara las instrucciones basicas del juego...
 *    
 */

void mensajeBienvenida(){
  Serial.setTimeout(100000); //100 segundos de espera
  Serial.print("\n********************************************************************************************************************************+\n");
  Serial.println("\nEscribe tu nombre y posteriormente da enter: ");
  String nombre=Serial.readStringUntil('\n');
  maquinaEscribirTeclea("Bienvenido jugador: "+nombre+"\nEl juego simon dice comenzara ya! \nMucha suerte! :D \nP R E S I O N A     C U A L Q U I E R     B O T O N      P A R A     I N I C I A R    :)\n\n",50);
}

/*
 *  void mensajeGanador()
 *    Encendera los leds en forma de escalerita acendiendo y bajando varias veces y cada vez emitiendo un pitido
 *    despues escribira el mensaje de victoria y finalmente tocara una melodia con leds prendiendo aleatoriamente
 *    simulando que tocan cada nota, y de esa manera festejo al ganador de mi juego...
 *    
 */

void mensajeGanador(){
  //semilla atraves del ruido del pin analogico 0...
  randomSeed( analogRead(A0) );
  byte ledPrender=0;

  int c,repetir;
  for(repetir=0;repetir<10;repetir++){
      //configurando pines como pines OUPUT(SALIDA)   
      for(c=0;c<NO_BOTONES;c++){
        digitalWrite(G_arrayLeds[c],HIGH);
        delay(50);
        digitalWrite(G_arrayLeds[c],LOW);
      }
      tocarTono(500,150);
      //configurando pines como pines OUPUT(SALIDA)   
      for(c=NO_BOTONES-2;c>=0;c--){
        digitalWrite(G_arrayLeds[c],HIGH);
        delay(50);
        digitalWrite(G_arrayLeds[c],LOW);
      }
      tocarTono(500,150);
  }

   maquinaEscribirTeclea("\nFELICIDADES HAS TERMINADO EL JUEGO,\nPOR FAVOR DISFRUTA ESTA BONITA CANCION\n",50);
   for(repetir=0;repetir<2;repetir++){
        for (int noNotaTocar = 0; noNotaTocar < TAM_YESTERDAY; noNotaTocar++) {
              int duracionDeEsaNota = 600*G_duracionNotas_yesterday[noNotaTocar];
              ledPrender=random(NO_BOTONES);
              digitalWrite(G_arrayLeds[ledPrender],HIGH);
              tone(PIN_BOCINA, G_notas_yesterday[noNotaTocar],duracionDeEsaNota);
              delay(duracionDeEsaNota);
              noTone(PIN_BOCINA);
              digitalWrite(G_arrayLeds[ledPrender],LOW );
         }
   }
}

/*
 * void mensajePerdedor()
 *    Encendera los leds al mismo tiempo y luego los apagara, y entre cada ciclo que hace eso, emitira un pitido
 *    y de esa manera le hago saber al jugador que no ha podido pasar mi juego...
 */

void mensajePerdedor(){
  int c,repetir;
  for(repetir=0;repetir<8;repetir++){
      //configurando pines como pines OUPUT(SALIDA)   
      for(c=0;c<NO_BOTONES;c++){
        digitalWrite(G_arrayLeds[c],HIGH);
      }
      tocarTono(250,150);
      //configurando pines como pines OUPUT(SALIDA)   
      for(c=0;c<NO_BOTONES;c++){
        digitalWrite(G_arrayLeds[c],LOW);
      }
      delay(250);
  }

}
