void Boileris(){
  #ifdef DEBUGboileris
  if (B_siurblys == true) Serial.println("Boilerio siublio busena: IJUNGTAS *** ON ***");
    if (B_siurblys == false) Serial.println("Boilerio siublio busena: ISUNGTAS *** OFF ***");
  #endif 

// Jei  boilerio virÅ�us Å�altesnis uÅ¾ boilerio Å�ildymo iÅ�jungimo temperatÅ«rÄ…, 
// o katilo iÅ�Ä—jime yra daugiau Å�ilumos, negu nustatyta boilerio Å�ildymo pradÅ¾ios  
// temperatÅ«ra +10 C, tai ÄÆjungiamas boilerio siurblys
     if ((BV < b_ON_T || BV < b_OFF_T) && KI > b_ON_T + 10 && B_siurblys == false){
       if (KI > BV + 10){
       digitalWrite(BSiurblys, LOW); B_siurblys = true;
#ifdef DEBUGboileris
Serial.println("Boilerio siublys IJUNGTAS ***_ON_ ***__PRIEZASTIS:");
Serial.print("B isjungimo temperatura- ");Serial.print(b_OFF_T);Serial.print(char(186));Serial.println("C");
Serial.print("B ijungimo temperatura- ");Serial.print(b_ON_T);Serial.print(char(186));Serial.println("C");
Serial.print("I isejime temperatura- ");Serial.print(KI);Serial.print(char(186));Serial.println("C");
#endif 
   }}
// Jei boilerio virÅ�uje yra tiek Å�ilumos, kiek nustatyta, arba katilo iÅ�Ä—jime yra maÅ¾iau Å�ilumos, 
// negu boilerio virÅ�uje, tai siurblys iÅ�jungiamas
     if ((BV >= b_OFF_T || KI <= BV + 8) && (B_siurblys == true)) { 
       digitalWrite(BSiurblys, HIGH); B_siurblys = false;
#ifdef DEBUGboileris
Serial.println("Boilerio siublys ISUNGTAS ***_OFF_***__PRIEZASTIS:");
Serial.print("B isjungimo temperatura- ");Serial.print(b_OFF_T);Serial.print(char(186));Serial.println("C");
Serial.print("B ijungimo temperatura- ");Serial.print(b_ON_T);Serial.print(char(186));Serial.println("C");
Serial.print("I isejime temperatura- ");Serial.print(KI);Serial.print(char(186));Serial.println("C");
#endif      
   }     
}

//**************************************************************************************************************
void Boilerio_termostatas(){
// Jei boilerio virÅ�us Å�altesnis negu nustatyta ijungimo temperatura, arba boilerio virÅ�us Å�altesnis
// uÅ¾ boilerio iÅ�jungimo temperatÅ«rÄ…, ir ijungtas termostatas, tai jungiamas elektrinis boilerio sildymas
if ((BV < b_ON_T ) && (B_termostat_ON == true)){
       digitalWrite(B_termostatas, LOW); 
       B_termostat_status = true; // zyme, kad termostatas dabar veikia
       B_termostat_ON = false;    // kai ijungiamas elektrinis boilerio sildymas, pakeiciama ijungimo zyme
#ifdef DEBUGboileris
Serial.print("Ijungtas boilerio sildymas elektra iki- "); 
Serial.print(b_OFF_T);Serial.print(char(186));Serial.println("C");
Serial.println();
#endif 
   }
// Jei boilerio virsuje yra tiek Å�ilumos, kiek nustatyta,  tai termostatas isjungia boilerio sildyma elektra
     if ((BV >= b_OFF_T)  && (B_termostat_status == true)) { 
       digitalWrite(B_termostatas, HIGH);
       B_termostat_status = false;
#ifdef DEBUGboileris
Serial.println("Ijungtas boilerio sildymas elektra I*S*J*U*N*G*T*A*S");
#endif      
   }     
}


