// Producto de ZACETREX TECHNOLOGIES S.A.C
// Este código se hizo con fin de compartirlo con la comunidad y tiene fines educativos
// Encuentre otros codigos en zacetrex.com o comuniquese con nosotros.

int ENA = 3;
int IN1 = 5;
int IN2 = 6;
int IN3 = 7;
int IN4 = 8;
int ENB = 9;
int sensor1 = 11;
int sensor2 = 12;
int valor1 = 0;
int valor2 = 0;

void setup() {
  Serial.begin(9600);
 pinMode(IN1,OUTPUT);
 pinMode(IN2,OUTPUT);
 pinMode(IN3,OUTPUT);
 pinMode(IN4,OUTPUT);
 pinMode(ENA,OUTPUT);
 pinMode(ENB,OUTPUT);
 pinMode(sensor1,INPUT);
 pinMode(sensor2,INPUT);

// ENA y ENB se utilizan para controlar la velocidad del motor (PWM)
// Puede modificarlo, el rango es de 0 a 255, donde 255 es la maxima velocidad.
// No todos los motores son exactamente iguales, algunos no se moveran por lo 
// que necesitan aumentar la velocidad, tambien si coloca mucho peso, 
// no se moveran y tendra que aumentar la velocidad
 analogWrite(ENA,110);
 analogWrite(ENB,110);
}

void loop() {
  valor1 = digitalRead(sensor1);
  valor2 = digitalRead(sensor2);

  if(valor1 == 0 && valor2 == 0) {
    Serial.println("Avanzar");
    Avanzar();
  }

  if(valor1 == 0 && valor2 == 1) {
    Serial.println("Derecha");
    Derecha();
  }

  if(valor1 == 1 && valor2 == 1) {
    Serial.println("Parar");
    Parar();
  }

  if(valor1 == 1 && valor2 ==0) {
    Serial.println("Izquierda");
    Izquierda();
  }

}

void Avanzar(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void Impulso(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA,200);
  analogWrite(ENB,200);
}

void Parar(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void Izquierda(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void Derecha(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
