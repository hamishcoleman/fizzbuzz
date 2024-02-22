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

SCRIPT += python_noif
SCRIPT += python_simple

COMPILE += c_div
COMPILE += c_fast
COMPILE += c_noif
COMPILE += c_simple

ASM_X86_64 += asm_x86_64_div
ASM_X86_64 += asm_x86_64_noif
ASM_X86_64 += asm_x86_64_simple
ASM_ARM64 += asm_arm64_simple

ASM += $(ASM_X86_64)
#ASM += $(ASM_ARM64)

IMPLEMENTATIONS += $(ASM)
IMPLEMENTATIONS += $(COMPILE)
IMPLEMENTATIONS += $(SCRIPT)

CLEANFILES += $(ASM)
CLEANFILES += $(COMPILE)

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
