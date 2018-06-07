TARGET = rsa
LIBS = 
CC = gcc
CFLAGS = -g -Wall -I.
STUDENT = student4

.PHONY: clean all default

default: $(TARGET)
all: default

HEADERS = 
OBJECTS = rsa.c

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $^ $(LIBS) -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)

install: default
	sudo cp ./$(TARGET) /usr/lib/cgi-bin/$(STUDENT)/
	sudo cp ./index.php /var/www/html/$(STUDENT)/
	sudo cp ./*.jpg /var/www/html/$(STUDENT)/
