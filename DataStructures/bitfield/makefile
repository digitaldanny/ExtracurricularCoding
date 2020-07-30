all: app clean

app: 
	@echo "========= building userapp ========="
	gcc -std=c99 -o app bitfield_test.c

rem:
	@echo "========= deleting userapp ========="
	rm app

.PHONY : clean
clean:
	@echo "============= cleaning ============="
	$(shell find . -type f -iregex '.*\.\(tmp\|o\|mod\|cmd\|symvers\|order\|mod.*\)' -exec rm -f {} \;)
