all:
	gcc crc-8.c -o crc8
	nasm -f elf64 -o crc8.o crc8.asm
	ld -o asm_crc8 crc8.o

clean:
	rm crc8
	rm crc8.o
	rm asm_crc8
	
