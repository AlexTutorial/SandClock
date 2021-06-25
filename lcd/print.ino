void draw(String border) {

  if (millis() - tmr > 1000) {

    if (seconds % 10 == 0 && seconds != 0 && j1 < 19 && line1ends == false) {
      line1[j1] = 0;
      line1[j1 - 1] = 1;
      j1++;
      fallSand1 = j1;

    }

    
    if (fallSand1 > 0 && line1ends != true) {
      line1[fallSand1] = 0;
      line1[fallSand1 - 1] = 1;
      if (line1[9] == 1 && line1[8] == 1) line1ends = true;
      fallSand1--;
    }
    else
    {
      line1ends = true;
    }

    lcd.clear();
    //  draw();
    tmr = millis();
    seconds++;

    String line1symbols = "";
    //    lcd.clear();
    lcd.print(border);
    
    for (int i = 0; i < 20; i++) {
      if (line1[i] == 0) {
        line1symbols += String(" ");
      }
      else
      {
        line1symbols += String("*");
      }
    }
    lcd.print(line1symbols);

    lcd.print(line1symbols);
    lcd.print(border);

  }
}

void setO(){
 j1 = 11;
 fallSand1 = j1;
 line1ends = false;
 border =  "---------XX---------";

 for(int r = 0; r < 12; r++) line1[r] = 0;
 for(int w = 12; w < 20; w++) line1[w] = 1;
// line1 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
}
