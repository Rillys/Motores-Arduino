//motor A conectado a A01y A02
//motor B conectado a B01 y B02

int STBY = 10;        // definimos el pin de standby

//para el motor A
int PWMA = 3;        // control de velocidad
int AIN1 = 9;                           // dirección
int AIN2 = 8;                           // dirección

// para el motor B
int PWMB = 5;        // control de velocidad
int BIN1 = 11;                         // dirección
int BIN2 = 12;                         // dirección

void setup(){
  pinMode(STBY, OUTPUT);  // definimos esos pines como salidas
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
}
void loop(){
/*mover(el motor el cual se quiere mover, la velocidad del motor, 1 para adelante y 0 hacia atras)*/
  
  mover(1,180,1);
  mover(2,180,1);
  //stop(); para detener los 2 motores si excepciones
  stop();
}

void mover(int motor, int velocidad, int direccion){
digitalWrite(STBY, HIGH);          //deshabilitar standby para mover
 boolean inPin1 = LOW;             // creamos la variable booleana (solo puede ser HIGH/LOW) inpin1
 boolean inPin2 = HIGH;             // y le asignamos el valor LOW. A inPin2 le damos el valor HIGH
if(direccion == 1){
inPin1 = HIGH;
inPin2 = LOW;
}
if(motor == 1){
  digitalWrite(AIN1, inPin1);
  digitalWrite(AIN2, inPin2);
  analogWrite(PWMA, velocidad);
}
 else{
    digitalWrite(BIN1, inPin1);
    digitalWrite(BIN2, inPin2);
    analogWrite(PWMB, velocidad);
  }
}
void stop(){                                        //ahora si, accionamos el standby 
  digitalWrite(STBY, LOW);
}
