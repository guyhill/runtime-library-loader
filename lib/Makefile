CC=gcc
CFLAGS=-fPIC
CFLAGS_SO=-shared
RM = rm -f

libprint-upper.so: print-uppercase.o
	$(CC) $(CFLAGS_SO) -o $@ $<
	
libprint-lower.so: print-lowercase.o
	$(CC) $(CFLAGS_SO) -o $@ $<
	
libprint-wide.so: print-widecase.o
	$(CC) $(CFLAGS_SO) -o $@ $<

libprint-generic.so: print-generic.o
	$(CC) $(CFLAGS_SO) -o $@ $<

all: libprint-upper.so libprint-lower.so libprint-wide.so libprint-generic.so

clean:
	$(RM) *.o *.so
