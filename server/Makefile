#compilação do projeto
# Makefile para compilar o projeto

# Compilador
CXX = g++

# Flags do compilador
CXXFLAGS = -std=c++17 -Wall
LDFLAGS=-lpq
# Diretório de saída para os binários
BUILD_DIR = build

# Nome do executável
TARGET = server

# Lista de todos os arquivos-fonte
SRCS = server.cpp client.cpp despaxante.cpp skeleton.cpp message.cpp login.cpp fornecedor.cpp database.cpp produto.cpp vendas.cpp

# Gere os nomes dos arquivos-objetos
OBJS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Alvo padrão
all: $(BUILD_DIR)/$(TARGET)

# Regra de construção do executável
$(BUILD_DIR)/$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Regra de construção dos arquivos-objetos
$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Cria o diretório de saída, se ele não existir
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Limpar arquivos temporários e o executável
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean

