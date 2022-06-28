 # define LedR 13  // Led vermelho temperatura alta
 # define LedY 12 // Led amarelo temperatura media
 # define LedG 11   // Led verde temperatura baixa
 # define button 2  // Botão que define sistema em operação ou desligado
 # define carga 10  // Saída para carga
 # define sensor A5 // Entrada do sensor de temperatura
 # define vent 3  // Saída para controle do ventilador

 #include <LiquidCrystal.h>
  LiquidCrystal lcd(8,9,4,5,6,7);// sequencia dos pinos (RS,E,D4,D5,D6,D7)

  int systemStatus = 0; // Memória do botão
  int buttonSituation = 0; // Visualizar se o sistema está monitorando ou não
  
  float value_ADC = 0.0;//leitura do sensor
  float media =0.0;
  float volts = 0.0;
  float temp = 0.0;

  void setup()
  {
    pinMode(button, INPUT);
    pinMode(sensor, INPUT);

    pinMode(LedR, OUTPUT);
    pinMode(LedY, OUTPUT);
    pinMode(LedG, OUTPUT);
    pinMode(vent, OUTPUT);
    
    pinMode(carga, OUTPUT);
    
    lcd.begin(16, 2);// tamanho do LCD 16x2
    
    Serial.begin(9600);
  }

  void loop()
  {
    for(byte i=1; i<20;i++)
    {
        value_ADC = analogRead(sensor);
      media = media + value_ADC;
    }
      media = media/20;
    

      //Serial.print("O ADC eh: ");
      //Serial.println(value_ADC);

      volts = (media * 5.0) / 1023.0;

      Serial.print("A tensao eh: ");
      Serial.println(volts);

      temp = volts * 100.0;
    
  lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp=     C");
    lcd.setCursor(11, 0);
    lcd.print(char(176));//caracter °
    if(temp>=100||temp<=-10)//se 3 digitos 
    lcd.setCursor(5, 0);//posição inicial para dados com 3 digitos 
  else          //se não
    lcd.setCursor(6, 0);//posição inicial para dados com 2 digitos
  //imprime o conteudo da variável com uma casa após a vírgula.
  lcd.print(temp,1);
    
    delay(200);//espera por 200 ms 
    
    
    
    
  systemStatus = digitalRead(button);


    Serial.print(" O estado do sistema eh: ");
    Serial.println(buttonSituation);

    if (systemStatus == HIGH){
      buttonSituation = !buttonSituation;
      delay(300);
    }

    Serial.print("O botao esta em: ");
    Serial.println(buttonSituation);

    if (buttonSituation == HIGH)
  {

     Serial.println("Ativado!");
    
    
  

     Serial.print("A temperaura eh: ");
     Serial.println(temp);
    
        
   if (temp <= 30.0){
      digitalWrite(carga, HIGH);
      Serial.print("Carga Ligada!");
      }
    if (temp > 90.0){
      digitalWrite(carga, LOW);
      Serial.print("Carga Desligada!");
      }
      

      if (temp >= 40.0){
        analogWrite(vent, 51);

        Serial.println("Ventilador - Fase 1 ligada!");
      }
      
      if (temp >= 60.0){
        analogWrite(vent, 153);

        Serial.println("Ventilador - Fase 2 ligada!");
      }
      
      if (temp >= 80.0){
        analogWrite(vent, 255);

        Serial.println("Ventilador - Fase 3 ligada!");
      }
      if(temp < 40.0){
        digitalWrite(vent, LOW);
        Serial.println("Ventilador desligado!");
      }

      if (temp > 70.0){
        digitalWrite(LedR, HIGH);
        digitalWrite(LedY, LOW);
        digitalWrite(LedG, LOW);
      }

      if (temp > 40.0 && temp <= 70.0){
        digitalWrite(LedR, LOW);
        digitalWrite(LedY, HIGH);
        digitalWrite(LedG, LOW);
      }

      if (temp <= 40.0){
        digitalWrite(LedR, LOW);
        digitalWrite(LedY, LOW);
        digitalWrite(LedG, HIGH);
      }
    
    }
    else{

      Serial.println("Desativado!");
      digitalWrite(LedR, HIGH);
      digitalWrite(LedY, HIGH);
      digitalWrite(LedG, HIGH);
      digitalWrite(vent, LOW);
    }
    
    delay(3000);

  }
