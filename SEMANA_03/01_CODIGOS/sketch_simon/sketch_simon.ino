int BotaoR = 25;
int BotaoAzul = 33;
int BotaoAmare = 35;
int BotaoVerde = 34;
int BotaoVerme = 32;
int LedAzul = 17;
int LedAmare = 19;
int LedVerde = 18;
int LedVerme = 16;
int Botoes[4] = {BotaoAzul, BotaoAmare, BotaoVerde, BotaoVerme};
int Leds[4] = {LedAzul, LedAmare, LedVerde, LedVerme};
const int Max_r = 4;
int sequencia[Max_r];
int rodadas = 1;
bool lose = 0;


void resetargame() {
  Serial.println("Estou resetando");
  delay(1000);
  rodadas = 0;
  lose = 0;
  delay(500);
  criar_sequencia();
}

void setup() {
  Serial.begin(9600);
  pinMode(BotaoR, INPUT);
  criar_sequencia();
  for(int i = 0; i < 4; i++){
    pinMode(Botoes[i], INPUT);
    pinMode(Leds[i], OUTPUT);
  }
  attachInterrupt(digitalPinToInterrupt(BotaoR), resetargame, RISING);
}

void jogo(){
  while(rodadas <= Max_r && lose == 0) {
    mostrar_sequencia();
    checar_sequencia();
  }
}


void loop() {
  Serial.println("Estou Loopando");
  delay(500);
  while (digitalRead(BotaoR) == LOW){
    Serial.println("Estou Jogando");
    jogo();
  }
}


void criar_sequencia() {
  Serial.println("Estou CRIANDO");
  randomSeed(analogRead(0));
  for (int i = 0; i < Max_r; i++){
    sequencia[i] = Leds[random(0,4)];
  }
}

void mostrar_sequencia() {
  for (int i = 0; i < rodadas ; i++) {
    digitalWrite(sequencia[i], HIGH);
    Serial.println("Acende");
    delay(600);
    digitalWrite(sequencia[i], LOW);
    delay(200);
  }
}

void checar_sequencia() {
  Serial.println("Estou CHECANDO");
  int i = 0;
  while ( i < rodadas && rodadas <= Max_r) {
    if (digitalRead(BotaoAzul) == HIGH){
      if(LedAzul != sequencia[i]){
        lose = 1;
        resetargame();
      }
      delay(700);
      Serial.println(i);
      i++;
    }
    if (digitalRead(BotaoAmare) == HIGH){
      if(LedAmare != sequencia[i]){
        lose = 1;
        resetargame();
      }
      delay(700);
      Serial.println(i);
      i++;
    }
    if (digitalRead(BotaoVerde) == HIGH){
      if(LedVerde != sequencia[i]){
        lose = 1;
        resetargame();
      }
      delay(700);
      Serial.println(i);
      i++;
    }
    if (digitalRead(BotaoVerme) == HIGH){
      if(LedVerme != sequencia[i]){
        lose = 1;
        resetargame();
      }
      delay(700);
      Serial.println(i);
      i++;
    }
  }
  if(lose == 0){
    rodadas++;
  } 
}
 

