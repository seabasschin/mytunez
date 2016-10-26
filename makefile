everything: llist.c llist.h tunes.c tunes.h main.c
	gcc llist.c llist.h tunes.c tunes.h main.c

clean:
	rm *~

run: a.out
	./a.out