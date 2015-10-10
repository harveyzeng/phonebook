CC ?= gcc
CFLAGS_common_orig ?= -O0 -Wall -std=gnu99
CFLAGS_common ?= -O3 -Wall -std=gnu99 -pipe
EXEC = phonebook_orig phonebook_opt 
all: $(EXEC)

SRCS_common = main.c

phonebook_orig: $(SRCS_common) phonebook_orig.c phonebook_orig.h
	$(CC) $(CFLAGS_common_orig) -DIMPL="\"$@.h\"" -o $@ \
		$(SRCS_common) $@.c

phonebook_opt: $(SRCS_common) phonebook_opt.c phonebook_opt.h
	$(CC) $(CFLAGS_common) -DIMPL="\"$@.h\"" -o $@ \
		$(SRCS_common) $@.c

run: $(EXEC)
	echo "echo 1 > /proc/sys/vm/drop_caches" | sudo sh
	perf stat  -e cache-misses,cache-references,instructions,cycles,branches,branch-misses ./phonebook_orig
	echo "echo 1 > /proc/sys/vm/drop_caches" | sudo sh
	perf stat  -e cache-misses,cache-references,instructions,cycles,branches,branch-misses ./phonebook_opt

clean:
	$(RM) $(EXEC) *.o perf.*
