# Óscar Gómez Borzdynski 

# Interfaz
NC = '\033[0m'
GREEN = '\033[0;32m'

# Compilador usado
CC = gcc

# Flex
CF = flex

# Bison
CB = bison 
BISONFLAGS = -dyv

# Carpeta donde se encuentran las librerias desarrolladas por nosotros
SRCLIBDIR = srclib/
SRCDIR = src/
LIBDIR = lib/
INCDIR = includes/
TESTDIR = test/
EXECDIR = executables/
FLEXDIR = flex/
BISONDIR = bison/

# Flags de compilacion
CFLAGS_AUX = $(addprefix -I, $(INCDIR) $(TESTDIR) $(BISONDIR))
CFLAGS = $(CFLAGS_AUX) -lpthread -lm -lrt -g -pedantic

#Modificamos los directorios de búsqueda para nuestro makefile
vpath %.c $(SRCDIR)
vpath %.c $(SRCLIBDIR)
vpath %.c $(TESTDIR)
vpath %.a $(LIBDIR)
vpath %.h $(INCDIR)
vpath %.c $(FLEXDIR)
vpath %.c $(BISONDIR)
vpath %.h $(BISONDIR)

#Creamos el directorio ejecutables
$(shell mkdir -p $(EXECDIR))

# Lista de ejecutables a compilar
EXE_AUX = $(shell find $(SRCDIR) -name '*.c' -printf "%P\n" | xargs)
EXE_AUX2 = $(EXE_AUX:.c=) 
EXE = $(addprefix $(EXECDIR), $(EXE_AUX2))

# Lista de ejecutables de pruebas
TEST_AUX = $(shell find $(TESTDIR) -name '*.c' -printf "%P\n" | xargs)
TEST_AUX2 = $(TEST_AUX:.c=)
TEST = $(addprefix $(EXECDIR), $(TEST_AUX2))

# Nombres de las dependencias
LIBS_AUX = $(shell find $(SRCLIBDIR) -name '*.c' -printf "%P\n" | xargs)
LIBS = $(LIBS_AUX:.c=.a)

# Nombre de los ficheros flex
FLEX_AUX = $(shell find $(FLEXDIR) -name '*.l' -printf "%P\n" | xargs)
FLEX = $(FLEX_AUX:.l=.yy.c)

# Lista de librerias flex
FLEXC_AUX2 = $(FLEX_AUX:.l=.yy.a)
FLEXC = $(addprefix $(LIBDIR), $(FLEXC_AUX2))

# Nombre de los ficheros bison
BISON_AUX = $(shell find $(BISONDIR) -name '*.y' -printf "%P\n" | xargs)
BISON = $(BISON_AUX:.y=.tab.c)
BISONHEADERS_AUX = $(BISON_AUX:.y=.tab.h)
BISONHEADERS = $(addprefix $(BISONDIR), $(BISONHEADERS_AUX))
INC += $(BISONHEADERS)

# Lista de librerias flex
BISON_AUX2 = $(BISON_AUX:.y=.tab.a)
BISONC = $(addprefix $(LIBDIR), $(BISON_AUX2))

# Lista de dependencias a compilar
CLIBS = $(addprefix $(LIBDIR), $(LIBS))

# Lista de elementos flex a tratar
CFLEX = $(addprefix $(FLEXDIR), $(FLEX))

# Lista de elementos bison a tratar
CBISON = $(addprefix $(BISONDIR), $(BISON))

# Realiza todas las acciones
all: bison flex test exec

# Compila solo los ejecutables principales
exec: bison flex $(EXE)

# Compila las librerias propias
libs: cleanlibs bison flex $(CLIBS) $(FLEXC)	

# Compila los ejecutables de test
test: bison flex $(TEST)

# Trata los elementos flex
flex: $(CFLEX) $(FLEXC)

# Trara los elementos bison
bison:  $(BISONHEADERS) $(CBISON)  $(BISONC)

# Compilacion de ejecutables
$(EXECDIR)% : %.c $(CLIBS)
	@echo Creando el ejecutable $@
	@ if grep -q -E 'yylex|yyparse' $<; then\
		$(CC) $(CFLAGS) $^ $(FLEXC) $(BISONC) -o $@ $(CFLAGS);\
      else\
        $(CC) $(CFLAGS) $^ -o $@ $(CFLAGS);\
fi
	@echo $(GREEN)[OK]$(NC)

# Compilacion de librerias
$(LIBDIR)%.a: %.c $(INC)
	@echo Compilando $< a $@
	@$(CC) -c $< $(CFLAGS) -o $@
	@echo $(GREEN)[OK]$(NC)

# Limpieza de ejecutables 
clean: 
	-rm -f $(EXE) $(TEST)

# Limpieza de librerias
cleanlibs: 
	-rm -f $(LIBDIR)*.a 

cleanflex:
	-rm -f $(FLEXDIR)*.c
	-rm -f $(FLEXC)

cleanbison:
	-rm -f $(BISONDIR)*.c
	-rm -f $(BISONC) $(BISONHEADERS)

# Limpieza completa
cleanall: clean cleanlibs cleanflex cleanbison

# Trata cada elemento flex
%.yy.c : %.l
	@echo Transformando flex $< a $@
	@$(CF) -o $@ $<
	@echo $(GREEN)[OK]$(NC)

%.tab.c: %.y
	@echo Transformando bison $< a $@
	@$(CB) $(BISONFLAGS) -o $@ $<
	@echo $(GREEN)[OK]$(NC)

%.tab.h: %.y
	@echo Transformando bison $< a $@
	@$(CB) $(BISONFLAGS) -o $@ $<
	@echo $(GREEN)[OK]$(NC)

#Ayuda del makefile
help:
	@echo "Opciones de este makefile:"
	@echo "all: Compila todo, tanto los ejecutables de entrega como los tests"
	@echo "exec: Compila solo los ejecutables de entrega"
	@echo "test: Compila solo los ejecutables de test"
	@echo "libs: Compila las librerias"
	@echo "clean: Borra los ejecutables (pero no las librerias)"
	@echo "cleanlibs: Borra las librerias"
	@echo "cleanflex: Borra todo lo generado por flex"
	@echo "cleanbison: Borra todo lo generado por bison"
	@echo "cleanall: Borra todo, ejecutables, librerias, bison y flex."
	@echo "help: Muestra esta ayuda"
