NAME = 28B

CXX = c++
CXX_FLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp \
	   Bureaucrat.cpp \
	   AForm.cpp \
	   ShrubberyCreationForm.cpp \
	   RobotomyRequestForm.cpp \
	   PresidentialPardonForm.cpp
OBJS = $(SRCS:.cpp=.o)

SILENT ?=0
GREEN = \033[0;32m
PURPLE = \033[1;35m
CYAN = \033[0;36m
RED = \033[1;31m
RESET = \033[0m

all: header $(NAME)

%.o: %.cpp
	@$(CXX) $(CXX_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@if [ "$(SILENT)" = "0" ]; then echo "$(GREEN)compiling...$(RESET)"; fi
	@$(CXX) $(CXX_FLAGS) -o $(NAME) $(OBJS)
	@if [ "$(SILENT)" = "0" ]; then  echo "$(GREEN)ready to execute$(RESET)"; fi

clean:
	@if [ "$(SILENT)" = "0" ]; then echo "$(CYAN)deleting object files...$(RESET)"; fi
	@rm -f $(OBJS)
	@if [ "$(SILENT)" = "0" ]; then echo "$(CYAN)done$(RESET)"; fi

fclean:
	@rm -f $(NAME) $(OBJS)

re: fclean all

.PHONY: clean fclean all re info header

info: header
define HEADER
	@echo " _   _                                                  _ "
	@echo "| \ | | ___     _   _  ___  _   _   _ __   ___  ___  __| |"
	@echo "|  \| |/ _ \   | | | |/ _ \| | | | | '_ \ / _ \/ _ \/ _\` |"
	@echo "| |\  | (_) |  | |_| | (_) | |_| | | | | |  __/  __/ (_| |"
	@echo "|_| \_|\___( )  \__, |\___/ \__,_| |_| |_|\___|\___|\__,_|"
	@echo "  __       |/   |___/       ____  ___  ____               "
	@echo " / _| ___  _ __ _ __ ___   |___ \( _ )| __ )              "
	@echo "| |_ / _ \| '__| '_ \` _ \    __) / _ \|  _ \              "
	@echo "|  _| (_) | |  | | | | | |  / __/ (_) | |_) |             "
	@echo "|_|  \___/|_|_ |_| |_|_|_|_|_____\___/|____( )             "
	@echo " _ __   ___ | |_  |___ \( _ ) / ___|       |/              "
	@echo "| '_ \ / _ \| __|   __) / _ \| |                          "
	@echo "| | | | (_) | |_   / __/ (_) | |___ _ _ _                 "
	@echo "|_| |_|\___/ \__| |_____\___/ \____(_|_|_)                "
endef

export HEADER

header:
	$(HEADER)