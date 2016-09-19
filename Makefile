.PHONY: test clean

CC	?= c99
CFLAGS	?= -Wall -Wno-unused-value -O3 -D__USE_MINGW_ANSI_STDIO

test: hp2aplet
test: hpgccaplet.apt

%.apt: %.lr
	./hp2aplet $(subst .apt,.m,$@) $@ x

%.lr: %.m %.o
	sload -H $*.m
	cat $@

%.o %.l: %.a
	sasm -E -B -W -a $*.l -o $*.o $<

%.a: %.s
	rplcomp $< $@

%.c: %.c.k
	milky -o $@ $<

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.apt *.lr *.o *.l *.a *.c
