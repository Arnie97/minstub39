HPGCC000.000: hpgccaplet.s
	rplcomp hpgccaplet.s hpgccaplet.c
	sasm -E -B -W -a hpgccaplet.l -o hpgccaplet.o hpgccaplet.c
	sload -H hpgccaplet.m
	tail hpgccaplet.lr
clean:
	rm hpgccaplet.l
	rm hpgccaplet.lr
	rm hpgccaplet.o
	rm HPGCC000.000
