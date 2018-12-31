PRODUCT := rollem.exe
BINDIR := bin
INCDIR := inc
SRCDIR := src
OBJDIR := obj

CXX := g++
LINKER := g++
INCDIRS := #-I$(INCDIR)
CXXFLAGS :=

SRCFILES := $(wildcard $(SRCDIR)/*.cpp)
OBJFILES := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCFILES))
DEPFILES := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.d,$(SRCFILES))

$(BINDIR)/$(PRODUCT): $(OBJFILES)
	$(LINKER) $(CXXFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCDIRS) -c $< -o $@

$(OBJDIR)/%.d: $(SRCDIR)/%.cpp
	$(CXX) $(INCDIRS) -MM $< \
	| sed -e 's%^%$@ %' -e 's% % $(OBJDIR)/%'\ > $@

-include $(DEPFILES)
