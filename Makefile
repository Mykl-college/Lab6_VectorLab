CC=gcc
CFLAGS= -c -Wall
LDFLAGS= -lm
SOURCES= main.c vMath.c 
OBJECTS=$(SOURCES:.c=.o)
EXECUTABELE=main

all: $(SOURCES) $(EXECUTABELE)

-include $(OBJECTS:.o=.d)

$(EXECUTABELE):$(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@
	$(CC) -MM $<> $*.d

clean:
	rm -rf $(OBJECTS)$(EXECUTABELE) *.d