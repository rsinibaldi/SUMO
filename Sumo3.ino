//Ultrasonico1
int trigPin = A0;
int echoPin = A1;
int duracion;
int pingTravelTime;
int dist;
int distancia;

//Ultrasonico2
int trigPin2 = 12;
int echoPin2 = 11;
int duracion2;
int pingTravelTime2;
int dist2;
int distancia2;

//Motor
int in1 = 8;    // Pin que controla el sentido de giro Motor A
int in2 = 9;    // Pin que controla el sentido de giro Motor A
int EnA1 = 10;  // Pin que controla la velocidad del  Motor A
int in3 = 7;    // Pin que controla el sentido de giro Motor B
int in4 = 6;    // Pin que controla el sentido de giro Motor B
int EnA2 = 5;   // Pin que controla la velocidad del  Motor B


int rs = 2;  // right sensor pin
int ls = 3;  // left sensor pin
int leftValue;
int rightValue;


void setup() {
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  pinMode(rs, INPUT);
  pinMode(ls, INPUT);

  pinMode(in1, OUTPUT);  // Configura  los pines como salida
  pinMode(in2, OUTPUT);
  pinMode(EnA1, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(EnA2, OUTPUT);
  analogWrite(EnA1, 255);
  analogWrite(EnA2, 255);

  Serial.begin(9600);
}

void loop() {
  sensorReading();

  if (/*rightValue == 1 && */ leftValue == 0) {

    dist = distancia_medida();

    if (dist >= 20 /* && dist2 >= 20*/) {
      derecha();
      Serial.print("");
      Serial.print("==== BUSCANDO ===");
    } else {
      adelante();
      Serial.print("");
      Serial.print(" ADELANTE ==>");
    }


  } else {
    atras();
    Serial.print("");
    Serial.print(" ATRAS ");
  }  //FIN - Sensor linea

}  // FIN

//=================================================================
// FUNCIONES
//=================================================================

int distancia_medida() {
  digitalWrite(trigPin, LOW);
  ;
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  pingTravelTime = pulseIn(echoPin, HIGH);
  delay(25);
  digitalWrite(trigPin, LOW);
  distancia = pingTravelTime / 58;
  return distancia;
}

int distancia_medida2() {
  digitalWrite(trigPin2, LOW);
  ;
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  pingTravelTime2 = pulseIn(echoPin2, HIGH);
  delay(25);
  digitalWrite(trigPin2, LOW);
  distancia2 = pingTravelTime2 / 58;
  return distancia2;
}


void sensorReading() {
  leftValue = digitalRead(ls);  // read from left Sensor
  rightValue = digitalRead(rs);
}

void detener() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void izquierda() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void derecha() {
  digitalWrite(in2, HIGH);
  digitalWrite(in1, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(in3, LOW);
}
void atras() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void adelante() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}