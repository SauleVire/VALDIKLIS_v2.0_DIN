
void Saules_kolektorius ()

{if (SK >= BA + k_skirtumas_ON) {
   digitalWrite(SKSiurblys, LOW);  // Ä®jungiamas saulÄ—s kolektoriaus siurblys
   SK_siurblys = true;
#ifdef DEBUGkolektorius
Serial.print("SK ijungimo temperaturos skirtumas- ");Serial.print(k_skirtumas_ON);Serial.print(char(186));Serial.println("C");
Serial.println("Saules kolektoriaus siublys IJUNGTAS *** ON ***");
#endif
}
              if (SK <= BA + k_skirtumas_OFF) {
              digitalWrite(SKSiurblys, HIGH); // IÅ�jungiamas akumuliacinÄ—s talpos siurblys
              SK_siurblys = false;
#ifdef DEBUGkolektorius
Serial.print("SK isjungimo temperaturos skirtumas- ");Serial.print(k_skirtumas_OFF);Serial.print(char(186));Serial.println("C");
Serial.println("Saules kolektoriaus siublys ISJUNGTAS *** OFF ***");
#endif
                   } 
 
}

/*
void Saules_kolektorius_rankinis (){
  if ((millis() < SK_rankinio_ijungimo_laikas + SK_rankinio_ijungimo_trukme ) && (SK <= BA + k_skirtumas_OFF)){
  } else {SK_rankinis_ijungimas = false;
          digitalWrite(SKSiurblys, HIGH);
        }
}
*/

