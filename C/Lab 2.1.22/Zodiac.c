int Zodiac(int D, int M){
  if ( (M == 3 && D >= 21) || (M == 4 && D <= 20) ){
    return 1;
    /*Овен Aries*/
  }
  else if ( (M == 4 && D >= 21) || (M == 5 && D <= 21) ){
    return 2;
    /*Телец Taurus*/
  }
  else if ( (M == 5 && D >= 22) || (M == 6 && D <= 21) ){
    return 3;
    /*Близнецы Gemini*/
  }
  else if ( (M == 6 && D >= 22) || (M == 7 && D <= 22) ){
    return 4;
    /*Рак Cancer*/
  }
  else if ( (M == 7 && D >= 23) || (M == 8 && D <= 21) ){
    return 5;
    /*Лев Leo*/
  }
  else if ( (M == 8 && D >= 22) || (M == 9 && D <= 23) ){
    return 6;
    /*Дева Virgo*/
  }
  else if ( (M == 9 && D >= 24) || (M == 10 && D <= 23) ){
    return 7;
    /*Весы Libra*/
  }
  else if ( (M == 10 && D >= 24) || (M == 11 && D <= 22) ){
    return 8;
    /*Скорпион Scorpius*/
  }
  else if ( (M == 11 && D >= 23) || (M == 12 && D <= 22) ){
    return 9;
    /*Стрелец Sagittarius*/
  }
  else if ( (M == 12 && D >= 23) || (M == 1 && D <= 20) ){
    return 10;
    /*Козерог Capricornus*/
  }
  else if ( (M == 1 && D >= 21) || (M == 2 && D <= 19) ){
    return 11;
    /*Водолей Aquarius*/
  }
  else if ( (M == 2 && D >= 20) || (M == 3 && D <= 20) ){
    return 12;
    /*Рыбы Pisces*/
  }
}
