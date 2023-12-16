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

#define BUF_SIZE 256

/**
 * compute_crc8
 * 
 * Given data and a polynomial, will calcuate the crc-8 and return the result
 * 
 * @param bytes Byte array of data to have crc calculated
 * @param len   Number of bytes in bytes array
 * @param poly 9 bit crc-8 polynomial to compute calculation
 * 
 * @return the result of the calculation
*/
uint8_t compute_crc8(uint8_t* bytes, int len, uint8_t poly) { 
   uint8_t crc = 0;                   // Crc register 

   for (int b = 0; b < len; b++) {
      uint8_t data = (uint8_t)(bytes[b] ^ crc);

      // Caclulate crc for this byte 
      for (int i = 0; i < 8; i++) { 
         if ((data & 0x80) != 0) { 
            data = (uint8_t)((data << 1)^poly);
         } else
            data = data << 1;
         crc = data;
      }
   }

   return crc;

}

int main() {
   uint8_t in_data[BUF_SIZE] = {0xDE, 0xAD, 0xBE, 0xEF}; // Input data
   int len = 4; // Get the length of byte array

   uint8_t poly = 0x1D;    // CRC-8 generator polynomial

   // Calculate the crc computation 
   printf("Calculate 0x%x with poly 0x%x...\n", in_data[0], poly);
   uint8_t result = compute_crc8(in_data, len, poly);

   printf("Remained: 0x%x\n", result);

   printf("Crc verification: ");
   in_data[len] = result;
   
   uint8_t rem = compute_crc8(in_data, len+1, poly);
   printf("%s --> 0x%x\n", rem ? "FAILED" : "PASSED", rem);
   
	return 0;   
}
