// Declaração das variáveis dos LEDs e botões em seus respectivos pinos
int ledV1 = 4;
int ledV2 = 5;
int ledV3 = 6;
int ledA1 = 7;
int ledA2 = 8;
int ledA3 = 9;
int ledA4 = 10;
int buttonV = 11;
int buttonB = 12;
int buttonA = 13;
int buttonV_State = 0;
int buttonB_State = 0;
int buttonA_State = 0;
// Variáveis do jogo
int game = 0;
int gameSide = 2;
int gameLed = 0;
int gamePass = 2;
int ledPoint = ledA1;

void buttonState() {
    buttonV_State = digitalRead(buttonV) == HIGH ? 1 : 0;
    buttonB_State = digitalRead(buttonB) == HIGH ? 1 : 0;
    buttonA_State = digitalRead(buttonA) == HIGH ? 1 : 0;
}

void playGame() {
    gameLed = random(ledV1, ledV3 + 1); // Inclui o último LED
    digitalWrite(gameLed, HIGH);
    buttonState();
    delay(300);
    buttonState(); // Atualiza o estado dos botões
    if (gameLed == ledV1 && buttonV_State == HIGH) {
        gamePass = 1;
    } else if (gameLed == ledV2 && buttonB_State == HIGH) {
        gamePass = 1;
    } else if (gameLed == ledV3 && buttonA_State == HIGH) {
        gamePass = 1;
    }
    else{
        gamePass = 0;
    }
    if (gamePass == 1) {
        digitalWrite(ledPoint, HIGH); // Acende o LED Azul para indicar sucesso
        delay(200);
        ledPoint++;
    }
    digitalWrite(gameLed, LOW);
    gamePass = 0;
}
void ledBlinker() {
    // Piscar LEDs
    for(int cont = 0; cont <= 3; cont++){
    digitalWrite(ledA1, HIGH);
    digitalWrite(ledA2, HIGH);
    digitalWrite(ledA3, HIGH);
    digitalWrite(ledA4, HIGH);
    delay(200);
    digitalWrite(ledA1, LOW);
    digitalWrite(ledA2, LOW);
    digitalWrite(ledA3, LOW);
    digitalWrite(ledA4, LOW);
    delay(200);
    }
    }

void setup() {
    // Declara os pinos dos LEDs como OUTPUT
    for (int c = ledV1; c <= ledA4; c++) {
        pinMode(c, OUTPUT);
    }

    // Declara os pinos dos botões como INPUT
    for (int c = buttonV; c <= buttonA; c++) {
        pinMode(c, INPUT);
    }
    randomSeed(analogRead(0)); // Inicializa a semente do gerador de números aleatórios
}

void loop() {
    buttonState(); // Atualizar o estado dos botões

   playGame();
}
