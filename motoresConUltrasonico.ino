//Driver para motores
//motor A conectado a A01y A02
//motor B conectado a B01 y B02

/*Para detener los motores se utiliza la funcion stop(); colocandolo en el 
void loop, recordar que void loop es un ciclo                           */
int STBY = 10;        // definimos el pin de standby

//para el motor A
int PWMA = 3;        // control de velocidad
int AIN1 = 9;                           // dirección
int AIN2 = 8;                           // dirección

// para el motor B
int PWMB = 5;        // control de velocidad
int BIN1 = 11;                         // dirección
int BIN2 = 12;                         // dirección

//Ultrasonico
int eco = 6;
int trig = 7;

int distancia, duracion;  

void setup(){
  //Motores
  pinMode(STBY, OUTPUT);  // definimos esos pines como salidas
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  
  //Ultrasonico   Preparamos los pines para utilizar el ultrasonico
  pinMode(eco, INPUT);
  pinMode(trig,OUTPUT);
  digitalWrite(trig, LOW);
}
void loop(){
  //Ultrasonico
 digitalWrite(trig,HIGH); 
 delay(200);
 digitalWrite(trig,LOW);
 duracion = pulseIn(eco,HIGH);
distancia = ((duracion * 0.34) / 2);
  //Detenemos el veiculo cuando este el objeto a 10 cm, esperamos un segundo y empeiza a moverce hacia la derecha hasta que no detecte un objeto
 if (distancia > 10){
  //Avanzar
  mover(1,180,1);
  mover(2,180,1);
  }
  else{
    //Mover a la derecha
  mover(1,150,1);
  mover(2,150,0);
    }
}

//Movimiento de los motores
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
