questao = h5

all:	remove

remove:	run
	rm *.out
run:	main
	./$(questao).out
main:
	gcc $(questao).c -o $(questao).out
	
clean:
	rm *.out