// Producto de ZACETREX TECHNOLOGIES S.A.C
// Este código se hizo con fin de compartirlo con la comunidad y tiene fines educativos
// Más códigos en zacetrex.com


// ---------------------------
// Definición de pines del L298N
// ---------------------------
int ENA = 3;   // Pin PWM para controlar velocidad del motor A (izquierdo)
int IN1 = 5;   // Control de giro del motor A
int IN2 = 6;   // Control de giro del motor A
int IN3 = 7;   // Control de giro del motor B (derecho)
int IN4 = 8;   // Control de giro del motor B
int ENB = 9;   // Pin PWM para controlar velocidad del motor B

// ---------------------------
// Pines para los sensores TCRT5000 (modo DIGITAL)
// ---------------------------
int sensor1 = 11; // Sensor del lado izquierdo del carro
int sensor2 = 12; // Sensor del lado derecho del carro

// Variables donde guardamos los valores leídos
int valor1 = 0;   
int valor2 = 0;



// =====================================================
// ==================== CONFIGURACIÓN ===================
// =====================================================
void setup() {

  Serial.begin(9600);  // Activamos el monitor serial para ver mensajes

  // Pines del L298N como salidas para controlar motores
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Pines de los sensores como entrada
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);

  // ------------------------------------------------------
  // Velocidad inicial de los motores usando PWM
  // 0 = apagado
  // 255 = máxima velocidad
  // ------------------------------------------------------
  analogWrite(ENA, 110);  // Velocidad motor izquierdo
  analogWrite(ENB, 110);  // Velocidad motor derecho
}



// =====================================================
// ======================== LOOP ========================
// =====================================================
void loop() {

  // Leemos los valores de los sensores
  // 0 = línea negra
  // 1 = fondo blanco
  valor1 = digitalRead(sensor1);
  valor2 = digitalRead(sensor2);

  // ------------------------------------------------------
  // Interpretación de sensores:
  // sensor1 (izquierda), sensor2 (derecha)
  // ------------------------------------------------------
  // 0 - 0 : Ambos sensores ven negro → avanzar recto
  // 0 - 1 : Sólo el izquierdo ve negro → corregir derecha
  // 1 - 0 : Sólo el derecho ve negro → corregir izquierda
  // 1 - 1 : Ambos ven blanco → se perdió la línea → parar
  // ------------------------------------------------------

  if (valor1 == 0 && valor2 == 0) {
    Serial.println("Avanzar");
    Avanzar();
  }

  if (valor1 == 0 && valor2 == 1) {
    Serial.println("Derecha");
    Derecha();
  }

  if (valor1 == 1 && valor2 == 1) {
    Serial.println("Parar");
    Parar();
  }

  if (valor1 == 1 && valor2 == 0) {
    Serial.println("Izquierda");
    Izquierda();
  }
}



// =====================================================
// ================ FUNCIONES DE MOVIMIENTO ============
// =====================================================


// ---------------------
// Avanzar recto
// ---------------------
void Avanzar() {
  // Ambos motores hacia adelante
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}



// ---------------------
// Impulso fuerte
// ---------------------
// (No usado en loop, pero útil si el carro necesita arrancar con fuerza)
void Impulso() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  // Subimos la velocidad temporalmente
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
}



// ---------------------
// Parar completamente
// ---------------------
void Parar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}



// ---------------------
// Girar a la izquierda
// ---------------------
void Izquierda() {
  // Motor izquierdo se detiene
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  // Motor derecho avanza
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}



// ---------------------
// Girar a la derecha
// ---------------------
void Derecha() {
  // Motor izquierdo avanza
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  // Motor derecho se detiene
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
