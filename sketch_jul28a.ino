int motor_A1 = 13;
int motor_A2 = 12;
int motor_B1 = 11;
int motor_B2 = 10;
int sensor_adelante_trig = 9;
int sensor_adelante_echo = 8;
int seguidordelinealect;
int seguidor_de_linea = 2;
bool bandera = false;

void funcbanderas();

void setup() {
  pinMode(motor_A1, OUTPUT);
  pinMode(motor_A2, OUTPUT);
  pinMode(motor_B1, OUTPUT);
  pinMode(motor_B2, OUTPUT);
  pinMode(sensor_adelante_trig, OUTPUT);
  pinMode(sensor_adelante_echo, INPUT);
  digitalWrite(sensor_adelante_trig, LOW);
  Serial.begin(9600);
  pinMode(seguidor_de_linea, INPUT);
  attachInterrupt(digitalPinToInterrupt(seguidor_de_linea), funcbanderas, CHANGE);
}

void loop() {
  long tiempo;
  long distancia_delantera;
  
  // Lectura del sensor ultrasonido
  digitalWrite(sensor_adelante_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensor_adelante_trig, LOW);
  tiempo = pulseIn(sensor_adelante_echo, HIGH);
  distancia_delantera = tiempo / 59;

  seguidordelinealect = digitalRead(seguidor_de_linea);  // Lectura del seguidor de línea
 
  // Detección de obstáculo
  if ((distancia_delantera < 20) && (bandera == false)) {
    digitalWrite(motor_A1, HIGH);
    digitalWrite(motor_A2, LOW);
    digitalWrite(motor_B1, LOW);
    digitalWrite(motor_B2, HIGH);
  }
  else{
    digitalWrite(motor_A1, LOW);
    digitalWrite(motor_A2, LOW);
    digitalWrite(motor_B1, LOW);
    digitalWrite(motor_B2, HIGH);
  }

  // Seguimiento de línea si el seguidor está en HIGH
  if (seguidor_de_linea == 0) {
    digitalWrite(motor_A1, HIGH);
    digitalWrite(motor_A2, LOW);
    digitalWrite(motor_B1, LOW);
    digitalWrite(motor_B2, HIGH);
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
