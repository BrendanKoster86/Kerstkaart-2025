void modus_1(){
  slee_1();
  muts_1();
  vonkel();
  kar_1();
  sneeuw();
}

void slee_1() {
  if (millis() > sl_change + 250) {
    fase_sl ++;
    slee_lampjes_1();
    changes = true;
    sl_change = millis();
  }
}

void muts_1() {
  if (millis() > mu_change + 750) {
    fase_mu ++;
    muts_lampjes_1();
    changes = true;
    mu_change = millis();
  }
}



void kies_kar_sneeuw_1(){
  kar_sneeuw[0] = random(25, 43);
  kar_sneeuw[1] = random(25, 43);
  kar_sneeuw[2] = 15;//random(25, 43);
  for (int i = 0; i < 3; i++) {
    if (kar_sneeuw[i] < 30) {
      kar_sneeuw[i] = kar_sneeuw[i] - 15;
    } else if (kar_sneeuw[i] == 32) {
      kar_sneeuw[i] = 29;
    }
  }
}

void kar_1(){
  /* lampjes bovenop het karretje
   * lampjes 11 t/m 15,  29 t/m 31 en 33 t/m 42
   */
  if (millis() > kr_change + 60) {
    kies_kar_sneeuw_1();
    kr_change = millis();
  // }
  // if (millis() > kr_change2 + 500) {
    for (int i = 11; i <= 15; i++){
      kar_lampjes(i);
    }
    for (int i = 29; i <= 31; i++){
      kar_lampjes(i);
    }
    for (int i = 33; i <= 42; i++){
      kar_lampjes(i);
    }
    changes = true;
    sn_change = millis();
  }
}


void slee_lampjes_1() {
  /* De besturing van lampjes 0 t/m 10
   * 1 = het lampje boven voor en 11 het achterste lampje
   * Basis idee is om golven wit en geel/oranje af te wisselen
   * In modus 2 wordt de hele rand erbij betrokken
   */
  if (fase_sl > 10) {
    fase_sl = 1;
  }
  uint32_t kleuren[] = {fade(GOUD, .5), fade(GOUD, .75), GOUD, fade(GOUD, .75), fade(GOUD, .5), fade(WARM_WIT, .5), fade(WARM_WIT, .75), WARM_WIT, fade(WARM_WIT, .75), fade(WARM_WIT, .5)};
  byte j;
  for (int i = 0; i <= 10; i++) {
    j = i + 11 - fase_sl;
    while (j < 0) {
      j = j + 10;
    }
    while (j> 9) {
      j = j - 10;
    }
    pixels1.setPixelColor(i, kleuren[j]);
  }
}

void muts_lampjes_1(){
  /* De muts gaat om de lampjes op de rand van de muts... het bolletje is apart
   * Dit gaat om lampjes 20 t/m 24
   */
  if (fase_mu > 4) {
    fase_mu = 1;
  }
  if (fase_mu == 1) {
    pixels1.setPixelColor(22, fade(WIT, .75));
    pixels1.setPixelColor(20, UIT);
    pixels1.setPixelColor(24, UIT);
  } else if (fase_mu == 2) {
    pixels1.setPixelColor(22, UIT);
    pixels1.setPixelColor(21, fade(WIT, .75));
    pixels1.setPixelColor(23, fade(WIT, .75));
  } else if (fase_mu == 3) {
    pixels1.setPixelColor(21, UIT);
    pixels1.setPixelColor(23, UIT);
    pixels1.setPixelColor(20, fade(WIT, .75));
    pixels1.setPixelColor(24, fade(WIT, .75));
  } else if (fase_mu == 4) {
    pixels1.setPixelColor(20, UIT);
    pixels1.setPixelColor(24, UIT);
  }
}
