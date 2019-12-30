#include <Arduino.h>

void setup() {
  pinMode(10,INPUT);
  digitalWrite(10,HIGH);
  for (int i = 22; i < 30; i++) {
    pinMode(i,OUTPUT);
    digitalWrite(i,LOW);
  }
}
void playnote(int note,int dur) {
                //C,  D,  E,  F,  G,  A,  c,  d,  Bb
                //0,  1,  2,  3,  4,  5,  6,  7,  8
  int notes[9] = {262,294,330,349,392,440,523,587,466};
  tone(8,notes[note],dur);
  delay(dur);
}
void playAuldLangSyne() {
  int LEDArray[8] = {22,23,24,25,26,27,28,29};
  int note[58] = {0,3,2,3,5,4,3,4,5,4,3,3,5,6,7,
                  7,6,5,5,3,4,3,4,5,4,3,1,1,0,3,
                  7,6,5,5,3,4,3,4,7,6,5,5,6,7,
                  7,6,5,5,3,4,3,4,5,4,3,1,1,0,};
  int beat[58] = {2,3,1,2,2,3,1,2,1,1,3,1,2,2,6,
                  2,3,1,2,2,3,1,2,1,1,3,1,2,2,6,
                  2,3,1,2,2,3,1,2,2,3,1,2,2,6,
                  2,3,1,2,2,3,1,2,1,1,3,1,2,2,};
  for (int i = 0; i < 58; i++) {
    digitalWrite(22+note[i], HIGH);
    playnote(note[i],beat[i]*225);
    digitalWrite(22+note[i], LOW);
  }
}


void lick() {
  int note[8] = {4,5,8,6,4,5,3,4};
  int beat[8] = {4,2,4,2,1,5,4,6};
  int LEDs[8] = {1,2,3,4,1,2,0,1};
  for (int i = 0; i < 8; i++) {
    digitalWrite(22+LEDs[i],HIGH);
    playnote(note[i],beat[i]*63);
    digitalWrite(22+LEDs[i],LOW);
  }
}
void loop() {
  if (digitalRead(10) == LOW) {
    // Should auld acquaintance be forgot, and never brought to mind?
    // Should auld acquaintance be forgot, and days of auld lang syne?
    // For auld lang syne, my jo, for auld lang syne,
    // We'll tak a cup of kindness yet, for auld lang syne.
    playAuldLangSyne();
    lick();
  }
}