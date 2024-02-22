#
#
#

# TODO
# - code coverage
# - timed runs
# - generated dependancies
# - CI

all: outputs

BUILD_DEPENDS := \
    build-essential

CFLAGS := -g -coverage
ASFLAGS := -g -coverage

IMPLEMENTATIONS := \
    c_div \
    c_fast \
    c_noif \
    c_simple \
    python_noif \
    python_simple \

#IMPLEMENTATIONS += asm_arm64_simple
IMPLEMENTATIONS += asm_x86_64_div
IMPLEMENTATIONS += asm_x86_64_noif
IMPLEMENTATIONS += asm_x86_64_simple

# TODO: The implicit rules should cover this ?
asm_arm64_simple: asm_arm64_simple.S
asm_x86_64_div: asm_x86_64_div.S
asm_x86_64_simple: asm_x86_64_simple.S
c_div: c_div.c
c_fast: c_fast.c
c_noif: c_noif.c
c_simple: c_simple.c

OUTFILES := $(addsuffix .out,$(IMPLEMENTATIONS))
CLEANFILES += $(OUTFILES)

.PHONY: outputs
outputs: $(OUTFILES)

.coverage: ./python_simple
	python-coverage run $< >/dev/null
CLEANFILES += .coverage

python_simple.cov: .coverage
	python-coverage report >$@
	cat $@
CLEANFILES += python_simple.cov

%.out: %
	./$< >$@.tmp
	diff -u Expected.txt $@.tmp
	mv $@.tmp $@

%.gcno: %.out

%.c.gcov: %.gcno
	gcov $(basename $<).c

build-depends:
	sudo apt install $(BUILD_DEPENDS)

clean:
	rm -f $(CLEANFILES)
	rm -f *.gcda *.gcno
