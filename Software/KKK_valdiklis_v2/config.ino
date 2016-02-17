
boolean LoadConfig(){
  if ((EEPROM.read(0) == 27) && (EEPROM.read(1) == 28)) {
    // Comprobamos que la eeprom tenga una 
    // configuracion valida con numeros concretos
    // solo cargamos el valor de la configuracion si los valores coinciden
    k_skirtumas_OFF = EEPROM.read(4);  
    k_skirtumas_ON = EEPROM.read(6);
    k_uzsalimas = EEPROM.read(8);
    lcd_pasvietimas = EEPROM.read(10);
//_____________ Akumuliacine talpa __________________
    at_ON_T = EEPROM.read(12);
    at_OFF_T = EEPROM.read(14);
//_____________ Boileris __________________
    b_ON_T = EEPROM.read(16);
    b_OFF_T = EEPROM.read(18);
//_____________ PamaiÅ�ymo voÅ¾tuvas __________________
    pv_palaikoma_T = EEPROM.read(20);  // PamaiÅ�ymo voÅ¾tuvo palaikoma temperatÅ«ra
    pv_ON_T = EEPROM.read(22);  // PamaiÅ�ymo voÅ¾tuvo palaikoma temperatÅ«ra
    pv_OFF_T = EEPROM.read(24);  // PamaiÅ�ymo voÅ¾tuvo siurblio iÅ�jungimo temperatÅ«ra
    pv_palaikoma_riba_T = EEPROM.readFloat(26); // PamaiÅ�ymo voÅ¾tuvo palaikomos temperatÅ«ros riba
    PV_pauzes_pertrauka = EEPROM.read(34);  // PamaiÅ�ymo voÅ¾tuvo pertraukos laikas po judesio
    PV_darinejimas = EEPROM.read(36);  // PamaiÅ�ymo voÅ¾tuvo pertraukos laikas po judesio
    PV_rezimas = EEPROM.read(38);  //pamaiÅ�ymo voÅ¾tuvo ir siurblio rankinis arba automatinis darbas 
    SK_apsauga_nuo_salcio = EEPROM.read(40);  //SK apsauga nuo uÅ¾Å�alimo 
    
    
    return true;
  }
  return false;
}

void SaveConfig(){
  EEPROM.write(0,27);
  EEPROM.write(1,28);
//  EEPROM.write(2,13);
//  EEPROM.write(3,18);
  // Ponemos nmeros concretos en el comienzo 
  // de la EEPROM para confirmar que tiene valores correctos.
  EEPROM.write(4,k_skirtumas_OFF);
//  EEPROM.write(5,k_skirtumas_OFF);  // almacenamos los valores 2 veces
  EEPROM.write(6,k_skirtumas_ON); 
//  EEPROM.write(7,k_skirtumas_ON);  // almacenamos los valores 2 veces
  EEPROM.write(8,k_uzsalimas); 
//  EEPROM.write(9,k_uzsalimas);  // almacenamos los valores 2 veces
  EEPROM.write(10,lcd_pasvietimas); 
//  EEPROM.write(11,lcd_pasvietimas);  // almacenamos los valores 2 veces
//_____________ Akumuliacine talpa __________________
  EEPROM.write(12,at_ON_T);   // AT siurblio ijungimo temperatura
  EEPROM.write(14,at_OFF_T);  // AT siurblio isjungimo temperatura
//_____________ Boileris __________________
  EEPROM.write(16,b_ON_T);  // Boilerio siurblio ijungimo temperatura
  EEPROM.write(18,b_OFF_T); // Boilerio siurblio isjungimo temperatura
  //_____________ PamaiÅ�ymo voÅ¾tuvas __________________
  EEPROM.write(20,pv_palaikoma_T);           // PamaiÅ�ymo voÅ¾tuvo palaikoma temperatÅ«ra
  EEPROM.write(22,pv_ON_T);                  // PamaiÅ�ymo voÅ¾tuvo palaikoma temperatÅ«ra
  EEPROM.write(24,pv_OFF_T);                 // PamaiÅ�ymo voÅ¾tuvo siurblio iÅ�jungimo temperatÅ«ra
  EEPROM.writeFloat(26,pv_palaikoma_riba_T); // PamaiÅ�ymo voÅ¾tuvo palaikomos temperatÅ«ros riba
  EEPROM.write(34,PV_pauzes_pertrauka);      // PamaiÅ�ymo voÅ¾tuvo pertraukos laikas po judesio
  EEPROM.write(36,PV_darinejimas);           // PamaiÅ�ymo voÅ¾tuvo pertraukos laikas po judesio
  EEPROM.write(38,PV_rezimas);               //pamaiÅ�ymo voÅ¾tuvo ir siurblio rankinis arba automatinis darbas
  EEPROM.write(40,SK_apsauga_nuo_salcio);    //SK apsauga nuo uÅ¾Å�alimo 
 
}

