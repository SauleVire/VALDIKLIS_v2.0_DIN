
void Akumuliacine_talpa () {
  // jei katilo iÅ�Ä—jime yra daugiau Å�ilumos, negu nustatyta akumuliacinÄ—s talpos Å�ildymo ÄÆjungimo temperatÅ«ra,
  // tai ÄÆjungiamas akumuliacinÄ—s talpos siurblys
 if ((KI >= at_ON_T) && (AT_siurblys == false))  {
   digitalWrite(ATSiurblys, LOW); // Ä®jungiamas akumuliacinÄ—s talpos siurblys
   AT_siurblys = true;
// jei AT iÅ�jungimo temperatÅ«ra nustatoma didesnÄ—, negu ÄÆjungimo, tai ji keiÄ¨iama ÄÆ maÅ¾esnÄ™
if (at_OFF_T > at_ON_T) at_OFF_T = at_ON_T - 1;
#ifdef DEBUGakumuliacine
Serial.print("AT ijungimo temperatura- ");Serial.print(at_ON_T);Serial.print(char(186));Serial.println("C");
Serial.println("Akumuliacines talpos siublys IJUNGTAS *** ON ***");
#endif
              }
              // jei katilo iÅ�Ä—jime yra maÅ¾iau Å�ilumos, negu nustatyta akumuliacinÄ—s talpos Å�ildymo iÅ�jungimo temperatÅ«ra,
              // tai iÅ�jungiamas akumuliacinÄ—s talpos siurblys
              if ((KI <= at_OFF_T) && (AT_siurblys == true)){
              digitalWrite(ATSiurblys, HIGH); // IÅ�jungiamas akumuliacinÄ—s talpos siurblys
              AT_siurblys = false;
              #ifdef DEBUGakumuliacine
              Serial.print("AT isjungimo temperatura- ");Serial.println(at_OFF_T);Serial.print(char(186));Serial.println("C");
              Serial.println("Akumuliacines talpos siublys ISJUNGTAS *** OFF ***");
              #endif
                   } 
}
/*
// PraÄ—jus nustatytam laikui ir jei tenkinama sÄ…lyga iÅ�jungimui pagal temperatÅ«ras
// ÄÆraÅ�oma Å¾ymÄ—, kad baigÄ—si rankinio siurblio ÄÆjungimo veikimas
void Akumuliacine_talpa_rankinis (){
  if ((millis() < AT_rankinio_ijungimo_laikas + AT_rankinio_ijungimo_trukme ) && (KI <= at_OFF_T)){
  } else {AT_rankinis_ijungimas = false;}
}
*/

