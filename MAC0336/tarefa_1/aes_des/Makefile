all: aes des

aes: aes.c
	gcc -ansi -Wall -Werror aes.c -o aes

des: des.c
	gcc -ansi -Wall -Werror -g des.c -o des

clean:
	rm -f aes des
