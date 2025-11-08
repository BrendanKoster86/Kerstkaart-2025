void modus_8() {
  if (millis() > kr_change + 40) {
    glow_slee();
    glow_muts();
    sparkle_boom();
    changes = true;
    kr_change = millis();
  }
}


void glow_slee(){
  static uint16_t t = 0;
  t++;

  // Slee randen voor/achter
  for(int i = 0; i <= 10; i++){
    float f = (sin((i + t * 0.05) ) + 1) * 0.5;  // 0..1
    pixels1.setPixelColor(i, fade(GOUD, f));
  }

  for(int i = 25; i <= 31; i++){
    float f = (sin((i + t * 0.05) ) + 1) * 0.5;
    pixels1.setPixelColor(i, fade(GOUD, f));
  }
}


void glow_muts(){
  static uint16_t t = 0;
  t++;

  float f = (sin(t * 0.03) + 1) * 0.5; // langzaam ademen

  for(int i = 20; i <= 24; i++){
    pixels1.setPixelColor(i, fade(ROOD, f));
  }

  pixels1.setPixelColor(19, fade(WARM_WIT, f)); // bollentje wit
}

void sparkle_boom(){
  // Basis: boom blijft groen
  for(int i = 33; i <= 42; i++){
    pixels1.setPixelColor(i, GROEN);
  }

  // Soms kleine sneeuw-klinster
  int s = random(33, 43);
  pixels1.setPixelColor(s, WIT);

  // Piek altijd goud zacht pulserend
  static uint16_t t = 0;
  t++;
  float f = (sin(t * 0.04) + 1)*0.5;
  pixels1.setPixelColor(32, fade(GOUD, f));
}