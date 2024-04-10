CC = gcc
CFLAGS = -Ofast -Wall -Wextra
XXHASHDIR = third-party/xxhash
INCLUDES = -I./include -I./$(XXHASHDIR)
SRCDIR = src
OBJDIR = obj
EXECDIR = exec

# Gathering all .c files including xxhash.c
SOURCES = $(wildcard $(SRCDIR)/*.c) $(wildcard $(XXHASHDIR)/*.c)
# Mapping .c files to their respective .o object files in the OBJDIR
OBJECTS = $(patsubst %,$(OBJDIR)/%,$(notdir $(SOURCES:.c=.o)))
EXECUTABLE = $(EXECDIR)/freq

all: create_dirs $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

# Generic rule for compiling .c to .o
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
$(OBJDIR)/%.o: $(XXHASHDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

create_dirs:
	mkdir -p $(OBJDIR) $(EXECDIR)

clean:
	rm -rf $(OBJDIR) $(EXECDIR)
