PROG = basec
OBJS = basec.o base.o

%.o: %.c
	gcc -c -g -o $@ $<

$(PROG): basec.h $(OBJS)
	gcc -g -o $@ $^

clean:
	rm -rf $(PROG) $(OBJS)
