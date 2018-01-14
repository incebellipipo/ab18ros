enum {
 SUB=1,
 ADD=2,
 MUL=3,
 DIV=4
};

String input;

void setup(){
  Serial.begin(9600);
}

void loop(){
//  Serial.println(input);
  delay(10);
}

void serialEvent(){
  float a, b;
  if( Serial.available() > 0){
    char recieved = Serial.read();
    input += recieved;
    if( recieved != ';' ){
      return;
    }
  }
  char calc_char;
  int current_calculation;
  for(int i = 0; i < input.length(); i++){
    char a = input.charAt(i);
    switch(a){
      case '-':
        current_calculation = SUB;
        calc_char = '-';
        break;
      case '+':
        current_calculation = ADD;
        calc_char = '+';
        break;
      case '/':
        current_calculation = DIV;
        calc_char = '/';
        break;
      case '*':
        current_calculation = MUL;
        calc_char = '*';
        break;
      default:
        break;
    }
  }


  for (int i = 0; i < input.length(); i++) {
    if (input.charAt(i) == calc_char) {
      a = input.substring(0, i).toInt();
      b = input.substring(i+1).toInt();
      break;
    }
  }
  
  input = "";
  switch(current_calculation){
    case SUB:
      Serial.println(a - b);
      break;
    case ADD:
      Serial.println(a + b);
      break;
    case MUL:
      Serial.println(a * b);
      break;
    case DIV:
      Serial.println(a / b);
      break;
    default:
      break;
  }
  Serial.flush();
  

}

