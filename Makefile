PROG = project01
OBJS =  project01.o

%.o: %.c
	gcc -c -g -o $@ $<

$(PROG): project01.h $(OBJS)
	gcc -g -o $@ $^

clean:
	rm -rf $(PROG) $(OBJS)
