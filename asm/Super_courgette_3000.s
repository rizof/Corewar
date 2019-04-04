.name		"Super_courgette_3000"
.comment	"Je galere, comme un aveugle qui se torche le cul."

qwe:		zjmp		%:aze
aze:		zjmp		%:qwe
test2:		live		%42
		live		%:test2
		ld		:test,r5
test:		st		r1,r1
		add		r1,r1,r1
		sub		r1,r1,r1
		and		r1,r1,r1
pouet:		or		r1,r1,r1
		xor		r1,r1,r1
		zjmp		%42
		ldi		r1,r1,r1
encore:		sti		r1,r1,r1
		fork		%42
		lld		%42,r1
		lldi		r1,r1,r1
		lfork		%42
		aff		r1
