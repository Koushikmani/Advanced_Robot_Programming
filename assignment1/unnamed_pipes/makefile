all: f p m t d

frontend: f.c
	gcc -o f f.c

addition: p.c
	gcc -o p p.c

subtraction: m.c
	gcc -o m m.c

multiplication: t.c
	gcc -o t t.c

division: d.c
	gcc -o d d.c


.PHONY: clean

clean:
		rm -f f.o
		rm -f p.o
		rm -f m.o
		rm -f t.o
		rm -f d.o


