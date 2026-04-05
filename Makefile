# 1. Detetar o Sistema Operacional
ifeq ($(OS),Windows_NT)
    TARGET = onibus.exe
    CLEAN_CMD = del /Q $(TARGET)
    RUN_CMD = .\$(TARGET)
else
    TARGET = onibus
    CLEAN_CMD = rm -f $(TARGET)
    RUN_CMD = ./$(TARGET)
endif

# Flags de compilação
CXX = g++
CXXFLAGS = -I include -g

# 2. Regra para o Programa Principal
build:
	$(CXX) $(CXXFLAGS) main.cpp src/lista_itinerario.cpp -o $(TARGET)

run: build
	$(RUN_CMD)

# 3. Regra para os Testes
build_testes:
	$(CXX) $(CXXFLAGS) testes/testes.cpp src/lista_itinerario.cpp -o $(TARGET)

run_testes: build_testes
	$(RUN_CMD)

# 4. Limpar
clean:
	$(CLEAN_CMD)