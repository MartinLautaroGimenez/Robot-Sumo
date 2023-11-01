int motor_A1 = 13 ;
int motor_A2 = 12;
int motor_B1 = 11;
int motor_B2 = 10;
int sensor_adelante_trig = 9;
int sensor_adelante_echo = 8;
bool bandera = true;

// by mario
#define pinDelBotonReLoco 4
bool yaEspereBro = false;

void funcbanderas();

void setup() {
  pinMode(pinDelBotonReLoco, INPUT);

  pinMode(motor_A1, OUTPUT);
  pinMode(motor_A2, OUTPUT);
  pinMode(motor_B1, OUTPUT);
  pinMode(motor_B2, OUTPUT);
  pinMode(sensor_adelante_trig, OUTPUT);
  pinMode(sensor_adelante_echo, INPUT);
  digitalWrite(sensor_adelante_trig, LOW);
  Serial.begin(9600);
}

void loop() {
  if ((yaEspereBro)&&(!digitalRead(pinDelBotonReLoco))){
    long tiempo;
    long distancia_delantera;
    
    // Lectura del sensor ultrasonido
    digitalWrite(sensor_adelante_trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(sensor_adelante_trig, LOW);
    tiempo = pulseIn(sensor_adelante_echo, HIGH);
    distancia_delantera = tiempo / 59;
    Serial.println(distancia_delantera);
    // Detección de obstáculo (si el objetivo está a menos de 20 cm)
    if (distancia_delantera < 60) {
      digitalWrite(motor_A1, LOW);
      digitalWrite(motor_A2, HIGH);
      digitalWrite(motor_B1, HIGH);
      digitalWrite(motor_B2, LOW);
    }
    // Si está a más de 20 cm que gire (siempre pensando en la bandera) 
    else if (distancia_delantera >= 20){
      digitalWrite(motor_A1, HIGH);
      digitalWrite(motor_A2, LOW);
      digitalWrite(motor_B1, HIGH);
      digitalWrite(motor_B2, LOW);
    }
    //  Si detecté la línea pues retrocedo por unos 2 segundos
    else if (bandera){
      digitalWrite(motor_A1, LOW);
      digitalWrite(motor_A2, HIGH);
      digitalWrite(motor_B1, HIGH);
      digitalWrite(motor_B2, LOW);
      delay(2000);
    }
  }   
  if (digitalRead(pinDelBotonReLoco)){        //  Si se presionó el botón
    while(digitalRead(pinDelBotonReLoco)){}   //  mantengo a pretado hasta que lo suelte
    if (!yaEspereBro){
      delay(5000);                              //  Espero 1000ms que serían 1 segundo
      yaEspereBro = true;
      Serial.println("Boton pulsado");
    } else {                     //  Espero 1000ms que serían 1 segundo
        yaEspereBro = false;
    }
     }  
}

void funcbanderas(){
  if (bandera){
    bandera = false;
  }
  else {
    bandera = true;
  }
}