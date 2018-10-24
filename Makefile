# Óscar Gómez Borzdynski 

# Interfaz
NC = '\033[0m'
GREEN = '\033[0;32m'

# Compilador usado
CC = gcc

# Flex
CF = flex

# Carpeta donde se encuentran las librerias desarrolladas por nosotros
SRCLIBDIR = srclib/
SRCDIR = src/
LIBDIR = lib/
INCDIR = includes/
TESTDIR = test/
EXECDIR = executables/
FLEXDIR = flex/

# Flags de compilacion
CFLAGS_AUX = $(addprefix -I, $(INCDIR) $(TESTDIR))
CFLAGS = $(CFLAGS_AUX) -lpthread -lm -lrt -g -pedantic

#Modificamos los directorios de búsqueda para nuestro makefile
vpath %.c $(SRCDIR)
vpath %.c $(SRCLIBDIR)
vpath %.c $(TESTDIR)
vpath %.a $(LIBDIR)
vpath %.h $(INCDIR)
vpath %.c $(FLEXDIR)

#Creamos el directorio ejecutables
$(shell mkdir -p $(EXECDIR))

# Nombre de todos los ficheros de cabecera
INC = $(shell find $(INCDIR) -name '*.h' -printf "%P\n" | xargs)

# Lista de ejecutables a compilar
EXE_AUX = $(shell find $(SRCDIR) -name '*.c' -printf "%P\n" | xargs)
EXE = $(EXE_AUX:.c=) 

# Lista de ejecutables de pruebas
TEST_AUX = $(shell find $(TESTDIR) -name '*.c' -printf "%P\n" | xargs)
TEST = $(TEST_AUX:.c=)

# Nombres de las dependencias
LIBS_AUX = $(shell find $(SRCLIBDIR) -name '*.c' -printf "%P\n" | xargs)
LIBS = $(LIBS_AUX:.c=.a)

# Nombre de los ficheros flex
FLEX_AUX = $(shell find $(FLEXDIR) -name '*.l' -printf "%P\n" | xargs)
FLEX = $(FLEX_AUX:.l=.yy.c)

# Lista de librerias flex
FLEXC_AUX2 = $(FLEX_AUX:.l=.yy.a)
FLEXC = $(addprefix $(LIBDIR), $(FLEXC_AUX2))

# Lista de dependencias a compilar
CLIBS = $(addprefix $(LIBDIR), $(LIBS))

# Lista de elementos flex a tratar
CFLEX = $(addprefix $(FLEXDIR), $(FLEX))

# Realiza todas las acciones
all: flex libs test exec

# Compila solo los ejecutables principales
exec: $(EXE)

# Compila las librerias propias
libs: cleanlibs $(CLIBS) $(FLEXC)

# Compila los ejecutables de test
test: $(TEST)

# Trata los elementos flex
flex: $(CFLEX)

# Compilacion de ejecutables
% : %.c $(CLIBS) $(FLEXC)
	@echo Creando el ejecutable $@
	@$(CC) $(CFLAGS) $^ -o $(EXECDIR)$@ $(CFLAGS)
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

# Limpieza completa
cleanall: clean cleanlibs cleanflex

# Trata cada elemento flex
%.yy.c : %.l
	@echo Transformando a flex $< a $@
	@$(CF) -o $@ $<
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
	@echo "cleanall: Borra todo, ejecutables y librerias."
@echo "help: Muestra la ayuda"
