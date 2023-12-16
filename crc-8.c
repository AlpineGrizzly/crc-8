/**
 * crc-8.c 
 *
 * C program that will compute a crc-8 calculation
 * 
 * Implementing following logic from http://www.sunshine2k.de/articles/coding/crc/understanding_crc.html
 * 
 * Author R3V
 * Dec. 15th, 2023
 */ 
#include <stdio.h>
#include <stdint.h>

/**
 * compute_crc8
 * 
 * Given data and a polynomial, will calcuate the crc-8 and return the result
 * 
 * @param data Data to be crc'd
 * @param poly 9 bit crc-8 polynomial to compute calculation
 * 
 * @return the result of the calculation
*/
uint8_t compute_crc8(uint8_t data, uint8_t poly) { 
   uint8_t crc = data; // Crc register 

   for (int i = 0; i < 8; i++) { 
      if ((crc & 0x80) != 0) { 
         crc = (uint8_t)((crc << 1)^poly);
      } else
         crc = crc << 1;
      printf("0x%x\n", crc);
   }

   return crc;

}

/**
 * crc8_verf 
 * 
 * Performs crc verification on data to check for any bit errors
 * 
 * @param data Data to perform crc verification over
 * @param result Crc-8 result to ensure there are not bit errors
 * 
 * @return Returns 1 if the data passes the crc, 0 otherwise
*/
int crc8_verf(uint8_t data, uint8_t result) { 
   return 1;
}

int main() {
   uint8_t in_data = 0xC2;      // Input data
   uint16_t poly = 0b00011101; // CRC-8 polynomial

   // Calculate the crc computation 
   printf("Calculate 0x%x with poly 0x%x...\n", in_data, poly);
   uint8_t result = compute_crc8(in_data, poly);

   printf("Result: 0x%x\n", result);
   // Do crc verification
   //printf("Performing CRC verification using 0x%x::STATUS::%s\n", result, crc8_verf(in_data, result) ? "PASSED" :"FAILED");

	return 0;   
}
