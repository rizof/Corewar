.name		"Super_courgette_3000"
.comment	"Je galere, comme un aveugle qui se torche le cul."

1:	live		%:99999999
2:	ld		%:99999999,r5
3:	st		r1,:test
4:	add		r1,r1,r1
5:	sub		r1,r1,r1
6:	and		%:99999999,%:99999999,r1
7:	or		%:99999999,%:99999999,r1
8:	xor		%:99999999,%:99999999,r1
9:	zjmp		%:99999999
10:	ldi		%:99999999,%:99999999,r1
11:	sti		r1,%99999999,%99999999
12:	fork		%:99999999
13:	lld		%:99999999,r1
14:	lldi		%:99999999,%:99999999,r1
15:	lfork		%:99999999
16:	aff		r1
test:	live		%99
99999999:	live		%99
