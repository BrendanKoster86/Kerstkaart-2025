void modus_3_7() {
  slee_1();
  muts_3_7();
  vonkel();
  kar_3_7();
  sneeuw_3_7();
}

void muts_3_7() {
  if (millis() > mu_change + 250) {
    fase_mu ++;
    muts_lampjes_3_7();
    changes = true;
    mu_change = millis();
  }
}

void kar_3_7() {
  uint32_t kleur;
  if (modus == 3){
    kleur = fade(ROOD, .5);
  } else if (modus == 4) {
    kleur = fade(GOUD, .5);
  } else if (modus == 5) {
    kleur = fade(GROEN, .5);
  } else if (modus == 6) {
    kleur = fade(BLAUW, .5);
  } else if (modus == 7) {
    kleur = fade(PAARS, .5);
  }

  for (int i = 11; i <= 15; i++) {
    pixels1.setPixelColor(i, kleur);
  }
  for (int i = 29; i <= 31; i++) {
    pixels1.setPixelColor(i, kleur);
  }
  for (int i = 33; i <= 42; i++) {
    pixels1.setPixelColor(i, kleur);
  }
}


void sneeuw_3_7(){
  /* lampjes bovenop het karretje
   * lampjes 16, 17, 18 en 25 t/m 28
   */
  
  if (millis() > sn_change + 500) {
    sneeuw_rood[0] = random(16, 20);
    sneeuw_rood[1] = random(25, 30);
    sn_change = millis();
  }
  if (millis() > sn_change2 + 500) {
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

void muts_lampjes_3_7(){
  /* De muts gaat om de lampjes op de rand van de muts... het bolletje is apart
   * Dit gaat om lampjes 20 t/m 24
   */
  if (fase_mu > 5) {
    fase_mu = 1;
  }
  if (fase_mu == 1) {
    pixels1.setPixelColor(20, GOUD);
    pixels1.setPixelColor(24, fade(GOUD, .25));
  } else if (fase_mu == 2) {
    pixels1.setPixelColor(21, GOUD);
    pixels1.setPixelColor(20, fade(GOUD, .25));
  } else if (fase_mu == 3) {
    pixels1.setPixelColor(22, GOUD);
    pixels1.setPixelColor(21, fade(GOUD, .25));
  } else if (fase_mu == 4) {
    pixels1.setPixelColor(23, GOUD);
    pixels1.setPixelColor(22, fade(GOUD, .25));
  } else if (fase_mu == 5) {
    pixels1.setPixelColor(24, GOUD);
    pixels1.setPixelColor(23, fade(GOUD, .25));
  }
}