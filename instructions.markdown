# Descrições para executar o projeto

## 1. Certifique-se de ter o python instalado
    A implementação do lado cliente do projeto foi todo feito em python, então lembre-se que o seu sistema precisa reconhecer a linguagem python. Estou utilizando a versão 3

## 2. Crie o ambiente virtual para o seu projeto

Por facilidade e praticidade, o python utiliza ambientes para que cada um dos projetos estejam "conteinizados" facilitando que apenas o projeto atual tenha as libs, API e pre-requisitos para que a aplicação funcione.

### 2.1. Crie o ambiente

```
$ python3 -m venv "nome do ambiente"
```

por conversão utiliza-se "venv" para o nome do ambiente, entretanto não é obrigatório, ficaria algo assim:

```
$ python3 -m venv venv    
```
uma ambiente só precisa ser criado uma vez

## 3. Ative o ambiente
Depois que o ambiente foi criado, teremos agora que ativa-ló.
### 3.1. Ativando o ambiente
```
$ source venv/bin/activate
```

Lembre que toda vez que sair do ambiente é preciso ativar denovo

## 4. Dependências
para facilitar, o projeto conta com um arquivo que contém todas ad dependências necessarias para rodar o projeto. O arquivo chama-se __requirements.txt__
### 4.1. instalando as dependencias
```
$ pip3 install -r requirements.txt
```


