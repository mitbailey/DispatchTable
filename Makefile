CC = gcc
CFLAGS = -g -Wall -I include/

main: src/dispatch_table.c
		$(CC) $(CFLAGS) src/dispatch_table.c -o dispatch_table $(LDFLAGS)

clean:
		$(RM) dispatch_table


