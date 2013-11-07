#
# sample makefile
#

#
# The following directives let make know that you may be using files
# with a cpp extension.
#

.SUFFIXES: .cpp 

#
# You may have to set the directories so that are appropiate for
# your account.
#

CC       = g++

# EZWINDIR = /users/courses/cs101/public_html/Demos/EzWindows/EzWindows

# If you downloaded EzWindows to your local machine, use the following
# definition instead of the above; delete the above 
# definition of EZWINDIR, and uncomment the following line

EZWINDIR = ../EzWindows
X11DIR   = /usr/X11R6

# The CPPFLAGS macro lets the compiler know where to find include files

CPPFLAGS=-I$(X11DIR)/include -I$(EZWINDIR)/include

# The LDFLAGS macro lets the linker know where to find library files

LDFLAGS=-L$(X11DIR)/lib -lX11 -L$(EZWINDIR)/lib -lezwin  -lXpm
LDFLAGS=-L$(X11DIR)/lib -lX11 -L$(EZWINDIR)/lib -lezwin /usr/lib/libXpm.so.4 


# The OBJS macro tells the compiler which object files need to be present
# to link your program into an executable.
# For every C++ file you use in your program, add a file.o here.

OBJS=PocketTanks.o


#
# The following sequence of commands defines a target for the program
# executable.  Replace both occurrences of PocketTanks here by the name you 
# want to use for your executable program
#

PocketTanks: $(OBJS)
	$(CC) -o PocketTanks $(OBJS) $(LDFLAGS)

#
# The target below indicates to make how to process files with a cpp 
# extension. Normally this is necessary but the cpp extension isn't 
# defined for make.
#

.cpp.o:
	$(CC) $(CPPFLAGS) -c $< 


#
# As a standard practice, a clean target is included in most make files.
# By executing 'make clean', all object files, backup files, and the 
# executable are deleted.
#

clean:
	rm -f *.o *~ PocketTanks


# 
# And some more rules for making other sample programs in this directory
# You can delete these lines if you don't need them.
	
	
sample2: sample2.o
	$(CC) -o sample2 sample2.o $(LDFLAGS)
	
sample3: sample3.o 
	$(CC) -o sample3 sample3.o $(LDFLAGS)

sample4: sample4.o 
	$(CC) -o sample4 sample4.o $(LDFLAGS)

sample5: sample5.o 
	$(CC) -o sample5 sample5.o $(LDFLAGS)

sample6: sample6.o 
	$(CC) -o sample6 sample6.o $(LDFLAGS)
	
kaleido: kaleido.o 
	$(CC) -o kaleido kaleido.o $(LDFLAGS)
	
bitmapExample: bitmapExample.o
	$(CC) -o bitmapExample bitmapExample.o $(LDFLAGS)
