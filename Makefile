
.SUFFIXES: .d

# Preprocessor

CPPFLAGS += -I./include

# C++ Compiler

CXX       = g++
CXXFLAGS ?= -O3 -Wall -Weffc++ -std=c++11 -pedantic

# Linker

LD        = g++
LDFLAGS  ?=

# Files

SRC_FILES := $(shell find src/ -type f -name '*.cpp')
OBJ_FILES := $(patsubst src/%.cpp,obj/%.o,$(SRC_FILES))
DEP_FILES := $(patsubst src/%.cpp,dep/%.d,$(SRC_FILES))

MAIN_EXE = genetic.exe

# Main Target

.PHONY: all
all: $(MAIN_EXE)

$(MAIN_EXE): $(OBJ_FILES)
	$(LD) $(LDFLAGS) -o $@ $^

obj/%.o: src/%.cpp dep/%.d
	@echo $@ prereqs $^
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

# Dependency Generation

dep/%.d: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -MM $< -MT $(patsubst dep/%.d,obj/%.o,$@) -MF $@

ifeq (0, $(words $(filter-out $(NODEPS),$(MAKECMDGOALS))))
-include $(DEP_FILES)
endif

# Clean

.PHONY: clean
clean:
	rm -rf $(MAIN_EXE) obj/ dep/
