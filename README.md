 O'SIMLIKLAR PARVARISH TIZIMI
 Fayl va Funktsiyalar Ro'yhati
  
  Version: 1.0
  Sana: 2025-03-20
 

 ===== FAYLLAR TAVSIFI =====


 motor_control.h/cpp - Servo motorlarni boshqarish moduli
 
 Bu fayllar o'simlik platformalarini aylantirish uchun servo motorlarni 
 boshqarish logikasini o'z ichiga oladi.



 light_control.h/cpp - Yoritish tizimini boshqarish moduli
 
 Bu fayllar o'simliklar uchun yoritish tizimini boshqarish, yorug'lik darajasini 
 o'lchash va LED yoritgichlarni boshqarish logikasini o'z ichiga oladi.



 water_control.h/cpp - Sug'orish tizimini boshqarish moduli
  
  Bu fayllar tuproq namligini o'lchash va o'simliklarni avtomatik 
  sug'orish tizimini boshqarish logikasini o'z ichiga oladi.
 


  main.ino - Asosiy dastur fayli
  
  Bu fayl barcha modullarni birlashtiradi va asosiy dastur siklini o'z ichiga oladi.



 ===== ASOSIY FUNKTSIYALAR =====
 --- MOTOR CONTROL ---


  initMotors() - Servo motorlarni ishga tushirish
  
  Barcha 4ta servo motorni initsiallashtirib, ularga pinlar tayinlaydi
  va boshlang'ich holatga keltiradi.



  rotatePlatforms() - Platformalarni aylantirish
  
  Barcha platformalarni keyingi holatga aylantiradi.


 --- LIGHT CONTROL ---


  initLighting() - Yoritish tizimini ishga tushirish
  
  Yoritgich va yorug'lik sensorini initsiallashtirib, 
  yoritgichni boshlang'ich holatga keltiradi.



  updateLighting() - Yoritish holatini yangilash
  
  Yorug'lik darajasini o'lchab, kerak bo'lsa yoritgich yorqinligini sozlaydi.



  setLightBrightness(int brightness) - Yorqinlikni o'rnatish
  
  Berilgan qiymatga asoslanib yoritgich yorqinligini o'rnatadi.


 --- WATER CONTROL ---


  initWatering() - Sug'orish tizimini ishga tushirish
  
  Suv nasosi va tuproq namligi sensorini initsiallashtirib,
  nasos o'chirilgan holatda ekanligini ta'minlaydi.



  updateWatering() - Sug'orish holatini yangilash
  
  Agar sug'orish faol bo'lsa, uni to'xtatish kerakligini, aks holda
  namlikni tekshirish kerakligini aniqlaydi.



  startWatering() - Sug'orishni boshlash
  
  Suv nasosini yoqadi va sug'orish boshlanganini qayd etadi.



  stopWatering() - Sug'orishni to'xtatish
  
  Suv nasosini o'chiradi va sug'orish to'xtatilganini qayd etadi.


 --- MAIN ---


  setup() - Dastur boshlang'ich sozlamalari
  
  Barcha modullarni ishga tushiradi va seriyali port aloqasini o'rnatadi.



  loop() - Asosiy dastur sikli
  
  Yoritish va sug'orish tizimlarini yangilaydi, 
  shuningdek platformalarni jadval bo'yicha aylantiradi.
