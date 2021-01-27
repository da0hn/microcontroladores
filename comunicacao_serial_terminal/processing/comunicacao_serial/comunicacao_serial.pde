import processing.serial.*;

Serial myPort;  // Create object from Serial class
String readValue;      // Data received from the serial port
PFont f;
int segundos = 0;

void setup() 
{
  size(400, 400);
  String portName = "COM3";
  myPort = new Serial(this, portName, 9600);
  f = createFont("Arial",16,true);
}

void draw()
{
    readValue = myPort.readStringUntil(10);
    background(51);
    textAlign(CENTER);
    textFont(f,16);
    fill(#ffffff);
    
    if(readValue == null) {
      segundos++;
      text("Não há valores para ler", 200, 200);
      text("Espere " + segundos + "s", 200, 220);
    }
    else {
      segundos = 0;
      text("Valor lido = " + readValue, 200, 200);
    }
    delay(1000);
}
