CC       =c++
CCFLAGS  =-Wall

EXE      = out
DIR      = engine solver

SRC      = $(foreach d,$(DIR),$(wildcard $(d)/*.cpp))
OBJ      = $(SRC:.cpp=.o)


all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CCFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CCFLAGS) -o $@ -c $<

.PHONY: clean

run: $(EXE)
	./$(EXE)

clean:
	@$(foreach d,$(DIR),rm -rf $(d)/*.o;)
	@rm -rf $(EXE)
	@rm -rf $(EXE)
