HPGCC000.000: hpgccaplet.lr

%.lr: %.m %.o
	sload -H $*.m
	cat $@

%.o %.l: %.a
	sasm -E -B -W -a $*.l -o $*.o $<

%.a: %.s
	rplcomp $< $@

clean:
	rm *.l *.lr
