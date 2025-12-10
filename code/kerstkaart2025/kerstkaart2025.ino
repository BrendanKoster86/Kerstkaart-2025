// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <tinyNeoPixel.h>

bool changes = false;

byte kar_sneeuw[3] = {};
byte sneeuw_rood[2] = {};

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      3

// Which pin on the Arduino is connected to the NeoPixels?
#define LED1           12
#define KNOP           A2

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
tinyNeoPixel pixels1 = tinyNeoPixel(43, LED1, NEO_GRB + NEO_KHZ800);


#define ROOD         pixels1.Color(30, 0, 0)
#define PAARS        pixels1.Color(30, 0, 10)
#define BLAUW        pixels1.Color(0, 0, 30)
#define GROEN        pixels1.Color(0, 30, 0)
#define GEEL         pixels1.Color(12, 12, 0)
#define GOUD         pixels1.Color(31, 21, 0)
#define ORANJE       pixels1.Color(30, 3, 0)
#define WIT          pixels1.Color(30, 30, 30)
#define WARM_WIT     pixels1.Color(18, 14, 8)
#define UIT          pixels1.Color(0, 0, 0)


byte modus = 2;

byte fase_sl = 1;
unsigned long sl_change = 0;
byte modus_sl = 1;

byte fase_mu = 1;
byte modus_mu = 1;
byte modus_vo = 1;
byte modus_sn = 1;
byte modus_kr = 1;
unsigned long mu_change = 0;
unsigned long vo_change = 0;
unsigned long sn_change = 0;
unsigned long sn_change2 = 0;
unsigned long kr_change = 0;
unsigned long kr_change2 = 0;

uint32_t mu_kleur = GEEL;



int delayval = 500; // delay for half a second


void modus_1();
void modus_2();
void modus_3_7();
void modus_8();


void setup() {

  pixels1.begin(); // This initializes the NeoPixel library.
  pinMode(KNOP, INPUT);
  // knop_input();
}

void loop() {
  changes = false;
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  if (digitalRead(KNOP) == LOW) {
    knop_input();
  }
  if (modus == 1) {
    modus_1();
  } else if (modus == 2) {
    modus_2();
  } else if (modus <= 7) {
    modus_3_7();
  } else if (modus == 8) {
    modus_8();
  } else if (modus == 9) {
    modus_9();
  } else if (modus == 10) {
    modus_10();
  }
  if (changes){
    pixels1.show();
  }
}

uint32_t fade(uint32_t c, float f) {
  uint8_t r = ((c >> 16) & 0xFF) * f;
  uint8_t g = ((c >> 8) & 0xFF) * f;
  uint8_t b = (c & 0xFF) * f;
  return pixels1.Color(r, g, b);
}


void knop_input(){
  for (int i = 0; i< 43; i++){
    pixels1.setPixelColor(i, fade(GOUD, .5));
  }
  pixels1.show();
  while (digitalRead(KNOP) == LOW){
    delay(50);
  }
  modus ++;
  if (modus == 3) {
    modus = 8;
  } else if (modus == 11) {
    modus = 3;
  } else if (modus == 8) {
    modus = 1;
  }
  if (modus > 10) {
    // Op één of andere manier 
    modus = 2;
  }
}

void debug_kleur(uint32_t kleur){
  for (int i = 0; i < 43; i++){
    pixels1.setPixelColor(i, kleur);
  }
  pixels1.show();
}
void debug_kleur(uint32_t kleur, uint32_t achtergrond, int cnt){
  for (int i = 0; i < 43; i++){
    pixels1.setPixelColor(i, achtergrond);
  }
  for (int i = 0; i < cnt; i++){
    pixels1.setPixelColor(i, kleur);
  }
  pixels1.show();
}


void vonkel(){
  /* Het losse lampje op de muts (19)
   * En het lampje van de piek (32)
   */
  if (millis() > vo_change + 50){
    int tmp = random(1, 7);
    pixels1.setPixelColor(19, pixels1.Color(7*tmp, 7*tmp, 7*tmp));
    pixels1.setPixelColor(32, pixels1.Color(10*tmp, 7*tmp, 0));
    changes = true;
    vo_change = millis();
  }
}


// void sneeuw(){
//   /* lampjes bovenop het karretje
//    * lampjes 16, 17, 18 en 25 t/m 28
//    */
  
//   if (modus_sn == 1){
//     if (millis() > sn_change + 500) {
//       sneeuw_rood[0] = random(16, 20);
//       sneeuw_rood[1] = random(25, 30);
//       sn_change = millis();
//     }
//     if (millis() > sn_change2 + 500) {
//       for (int i = 16; i <= 18; i++){
//         sneeuw_lampjes(i);
//       }
//       for (int i = 25; i <= 28; i++){
//         sneeuw_lampjes(i);
//       }
//       changes = true;
//       sn_change2 = millis();
//     }
//   }
// }

void sneeuw(){
  sneeuw(true);
}

void sneeuw(bool force){
  /* lampjes bovenop het karretje
   * lampjes 16, 17, 18 en 25 t/m 28
   */
  
  if (millis() > sn_change + 1000) {
    sneeuw_rood[0] = random(22, 30);
    sneeuw_rood[1] = random(22, 30);
    for (int i = 0; i < 2; i++) {
      if (sneeuw_rood[i] < 25) {
        sneeuw_rood[i] = sneeuw_rood[i] - 6;
      }
    }
    sn_change = millis();
  // }
  // if (millis() > sn_change2 + 40) {
    for (int i = 16; i <= 18; i++){
      sneeuw_lampjes(i);
    }
    for (int i = 25; i <= 28; i++){
      sneeuw_lampjes(i);
    }
    changes = true;
    sn_change2 = millis();
  }
}

void kar_lampjes(int lampje){
  // int i = random(1, 5);
  if ((lampje == kar_sneeuw[0]) || (lampje == kar_sneeuw[1]) || (lampje == kar_sneeuw[2])) {
    pixels1.setPixelColor(lampje, fade(WIT, .5));
    // if (i == 1) {
    //   pixels1.setPixelColor(lampje, fade(WIT, .25));
    // } else if (i == 2) {
    //   pixels1.setPixelColor(lampje, fade(WIT, .5));
    // } else if (i == 3) {
    //   pixels1.setPixelColor(lampje, fade(WIT, .75));
    // } else if (i == 4) {
    //   pixels1.setPixelColor(lampje, WIT);
    // }
  } else {
    pixels1.setPixelColor(lampje, fade(ROOD, .5));
    // if (i == 1) {
    //   pixels1.setPixelColor(lampje, fade(ROOD, .25));
    // } else if (i == 2) {
    //   pixels1.setPixelColor(lampje, fade(ROOD, .5));
    // } else if (i == 3) {
    //   pixels1.setPixelColor(lampje, fade(ROOD, .75));
    // } else if (i == 4) {
    //   pixels1.setPixelColor(lampje, ROOD);
    // }
  }
}

void sneeuw_lampjes(int lampje){
  // int i = random(1,5);
  if ((lampje == sneeuw_rood[0]) || (lampje == sneeuw_rood[1])) {
    pixels1.setPixelColor(lampje, fade(ROOD, .5));
    // if (i == 1) {
    //   pixels1.setPixelColor(lampje, fade(ROOD, .25));
    // } else if (i == 2) {
    //   pixels1.setPixelColor(lampje, fade(ROOD, .5));
    // } else if (i == 3) {
    //   pixels1.setPixelColor(lampje, fade(ROOD, .75));
    // } else if (i == 4) {
    //   pixels1.setPixelColor(lampje, ROOD);
    // }
  } else {
    pixels1.setPixelColor(lampje, fade(WIT, .5));
    // if (i == 1) {
    //   pixels1.setPixelColor(lampje, fade(WIT, .25));
    // } else if (i == 2) {
    //   pixels1.setPixelColor(lampje, fade(WIT, .5));
    // } else if (i == 3) {
    //   pixels1.setPixelColor(lampje, fade(WIT, .75));
    // } else if (i == 4) {
    //   pixels1.setPixelColor(lampje, WIT);
    // }
    
  }
}