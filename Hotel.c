#include <stdio.h>
#include <stdlib.h>
#include "Hotel.h"
#include <string.h>


Hotel criar_hotel(){
	Hotel premiumResort;
	
	premiumResort.presidencial = 5;
	
	premiumResort.valorPresidencial = 1200;
	
	premiumResort.luxoSimples = 5;
	premiumResort.valorLuxoSimples = 520;
	
	premiumResort.luxoDuplo = 15;
	premiumResort.valorLuxoDuplo = 570;
	
	premiumResort.luxoTriplo = 20;
	premiumResort.valorLuxoTriplo = 620;
	
	premiumResort.executivoSimples = 5;
	premiumResort.valorExecutivoSimples = 360;
	
	premiumResort.executivoDuplo = 15;
	premiumResort.valorExecutivoDuplo = 385;
	
	premiumResort.executivoTriplo = 20;
	premiumResort.valorExecutivoTriplo = 440;
	
	
	return premiumResort;
}



