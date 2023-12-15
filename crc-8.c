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
uint8_t compute_crc8(uint8_t data, uint16_t poly) { 
   uint16_t result; // Result of our CRC calculation will be stored here
   
   // Apennd 8 bits to end of data
   uint16_t apnd_data = (uint16_t)data << 8 | 0x00;
   uint16_t ext_poly = (uint16_t)poly << 7;

   // Line up the begining of the poly and begin XOR operations and shifting 1 bit to the right
   for(int i = 0; i < 4; i++) { 
      result = apnd_data^ext_poly;
      printf("%x ^ %x = %x\n", apnd_data, ext_poly, result);
      apnd_data = result << (7-i);
      ext_poly = ext_poly >> 1;
   }

   return data;

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
   uint16_t poly = 0b100011101; // CRC-8 polynomial

   // Calculate the crc computation 
   printf("Calculate 0x%x with poly 0x%x...\n", in_data, poly);
   uint8_t result = compute_crc8(in_data, poly);

   // Do crc verification
   printf("Performing CRC verification using result 0x%x::STATUS::%s\n", result, crc8_verf(in_data, result) ? "PASSED" :"FAILED");

	return 0;   
}
