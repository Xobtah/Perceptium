NAME	= NeuralTest

SOURCES	= ../src

SRC	= main.cpp \
	../src/NeuralNetwork.cpp \
	../src/Perceptron.cpp \

OBJ	= $(SRC:.cpp=.o)

CXXFLAGS	= -std=c++11 -W -Wall -Werror -pthread -lm

all: $(NAME)

$(NAME): $(OBJ)
	g++ -pthread -lm $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
