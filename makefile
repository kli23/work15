all: parse-args.o
	gcc -o parse-args parse-args.o
parse-args.o: parse-args.c
	gcc -c parse-args.c
run:
	./parse-args
clean:
	rm *.o
	rm parse-args