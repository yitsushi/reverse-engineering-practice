all:
	gcc -fno-stack-protector \
		-o we_are_bad \
		-DSIZE=$$(( $$RANDOM % 500 )) \
		-DORIGINAL=$$(( $$RANDOM % 1000 + 1000 )) \
		-DEXPECTED=$$(( $$RANDOM % 1000 )) \
		main.c
