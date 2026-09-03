NAME = coffee-making

CXX = c++
CXX_FLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp \
	   Bureaucrat.cpp \
	   AForm.cpp \
	   ShrubberyCreationForm.cpp \
	   RobotomyRequestForm.cpp \
	   PresidentialPardonForm.cpp \
	   Intern.cpp
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
	@echo "_   _     _                _     _   _     _                      "
	@echo "   / \ | |_  | | ___  __ _ ___| |_  | |_| |__ (_)___                  "
	@echo "  / _ \| __| | |/ _ \/ _\` / __| __| | __| '_ \| / __|                 "
	@echo " / ___ \ |_  | |  __/ (_| \__ \ |_  | |_| | | | \__ \                 "
	@echo "/_/   \_\__| |_|\___|\__,_|___/\__|  \__|_| |_|_|___/                 "
	@echo "| |__   ___  __ _| |_ ___                                             "
	@echo "| '_ \ / _ \/ _\` | __/ __|                                            "
	@echo "| |_) |  __/ (_| | |_\__ \                                            "
	@echo "|_.__/ \___|\__,_|\__|___/                         _    _             "
	@echo "  ___ ___  / _|/ _| ___  ___       _ __ ___   __ _| | _(_)_ __   __ _ "
	@echo " / __/ _ \| |_| |_ / _ \/ _ \_____| '_ \` _ \ / _\` | |/ / | '_ \ / _\` |"
	@echo "| (_| (_) |  _|  _|  __/  __/_____| | | | | | (_| |   <| | | | | (_| |"
	@echo " \___\___/|_| |_|  \___|\___|     |_| |_| |_|\__,_|\_|\_\_|_| |_|\__, |"
	@echo "                                                                |___/ "
endef

export HEADER

header:
	$(HEADER)