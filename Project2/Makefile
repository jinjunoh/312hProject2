# New Makefile that automatically depends itself
#
# $Id: Makefile,v 1.3 1996/12/17 19:52:37 chase Exp $
#

IFLAGS = 
DFLAGS = 
CXX = gcc #
CC  = $(GCC)
GCC = gcc #
LD  = $(CXX)

LIBS = 

WFLAGS = -Wall 
SYMFLAGS = -g

PROFILE = #-pg 
OPTFLAGS = #-O
CFLAGS = $(OPTFLAGS) $(PROFILE) $(WFLAGS) $(IFLAGS) $(SYMFLAGS)
CXXFLAGS = $(CFLAGS)
CPPFLAGS = $(IFLAGS) $(DFLAGS)
LDFLAGS = $(PROFILE) -g 

PROGRAM = proj2
CXXSRCS = $(shell ls *.c)

SRCS = $(CXXSRCS)
OBJS = $(CXXSRCS:.c=.o)

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(LD) -o $@ $(LDFLAGS) $(OBJS) $(LIBS)

test: $(PROGRAM)
	-@./$(PROGRAM) testMultiplyMatrixA
	-@./$(PROGRAM) testMultiplyMatrixB
	-@./$(PROGRAM) testMultiplyMatrixC
	-@./$(PROGRAM) testMultiplyMatrixD
	-@./$(PROGRAM) testTransposeA
	-@./$(PROGRAM) testTransposeB
	-@./$(PROGRAM) testTransposeC
	-@./$(PROGRAM) testMultiplyMatrixPtrA
	-@./$(PROGRAM) testMultiplyMatrixPtrB
	-@./$(PROGRAM) testMultiplyMatrixPtrC

clean:
	-rm -f $(OBJS) $(PROGRAM)

undepend:
	-rm -f $(OBJS:%.o=.%.d) 

spotless: clean undepend

# auto depend stuff for GNU make only
depend: undepend
	@echo ""
	@echo "Dependences are handled automatically, just \"make\""

ifneq ($(strip $(CSRCS)),)
.%.d: %.c 
	$(SHELL) -ec '$(GCC) -MM $(CPPFLAGS) $< > $@'


include $(CSRCS:%.c=.%.d)
endif 

ifneq ($(strip $(CXXSRCS)),)
.%.d: %.c
	$(SHELL) -ec '$(GCC) -MM $(CPPFLAGS) $< > $@'

include $(CXXSRCS:%.c=.%.d) 
endif 
