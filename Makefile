EXEC=main-upper main-lower main-wide main-generic

main-upper: main.c
	gcc -o $@ $< -I./lib -L./lib -lprint-upper

main-lower: main.c
	gcc -o $@ $< -I./lib -L./lib -lprint-lower

main-wide: main.c
	gcc -o $@ $< -I./lib -L./lib -lprint-wide

main-generic: main-generic.c
	gcc -o $@ $< -I./lib -L./lib -lprint-generic
	
clean:
	rm -f $(EXEC)

all: $(EXEC)
