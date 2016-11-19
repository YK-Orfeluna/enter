int flag = 0;
int sum = 0;

#define BEAT 400   // 音の長さを指定
#define PINNO 8   // 圧電スピーカを接続したピン番号

int i=0;
int len = 12;

int C1 = 262;//ド
int D1 = 294;//レ
int E1 = 330;//ミ
int F1 = 349;//ファ
int F1s = 370;
int G1 = 392;//ソ
int H1 = 440;//ラ
int I1 = 494;//シ

int C2 = 523;//ド
int D2 = 587;//レ
int E2 = 659;//ミ
int F2 = 698;//ファ
int F2s = 740;
int G2 = 784;//ソ
int H2 = 880;//ラ

int music[] = {F2s, D2, H1, D2, E2, H2, 0, H2, E2, F2s, E2, H1, D2};
int beat[] = {BEAT, BEAT, BEAT, BEAT, BEAT, BEAT, 100, BEAT, BEAT, BEAT, BEAT, BEAT, BEAT};

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);

  sum += sensorValue;
  flag ++;

  if(flag == 50){
    float distance = sum / 50;
    if (distance > 150){
      digitalWrite(7, HIGH);
      delay(100);
      for(i=0;i<=12;i++){
        tone(PINNO, music[i], beat[i]);
        delay(BEAT);
      }
      
    }
    else{
      digitalWrite(7, LOW);
    }
    flag = 0;
    sum = 0;
  }
  delay(1);        // delay in between reads for stability
}
