# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/08 13:07:54 by kebris-c          #+#    #+#              #
#    Updated: 2025/12/02 19:07:00 by kebris-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re setup help

# 📚 Basic project variables
#
PROJECT		= bsp
NAME		= $(PROJECT).a

# 🔧 Compiler and flags
#
CXX			= c++
CPPFLAGS	= -Wall -Werror -Wextra -std=c++98

# 📄 Headers
#
HEADERS = -I$(INCL_DIR)

# 🔨 Tools
#
AR	= ar rcs
RM	= rm -rf

# 📂 Fast path variables / dirs
#
SRC_DIR		= src/
INCL_DIR	= include/
OBJS_DIR	= objs/
DEPS_DIR	= deps/

# 🎯 Sources, Objects and Deps	! Remember to update the list every project
#
SRCS = main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJS = $(SRCS:%.cpp=$(OBJS_DIR)%.o)
DEPS = $(OBJS:$(OBJS_DIR)%.o=$(DEPS_DIR)%.d)

-include $(DEPS)

#------------------------------------------------#
#   BASIC RULES										               #
#------------------------------------------------#

#	Basic options
#
all: setup $(NAME) $(PROJECT)

$(NAME): $(OBJS)
	@if [ -n "$(OBJS)" ]; then \
		$(AR) $(NAME) $(OBJS); \
		echo "📦 Library $(NAME) created"; \
	fi

#	Objects & bonus objects Compilers
#
$(OBJS_DIR)%.o: $(SRC_DIR)%.cpp
	@echo "🔨 Compiling $<..."
	$(CXX) $(CPPFLAGS) -MMD -MP $(HEADERS) -MF $(DEPS_DIR)$*.d -c $< -o $@

#	Cleaners
#
clean:
	@$(RM) $(OBJS_DIR) $(DEPS_DIR)

fclean: clean
	@$(RM) $(NAME) $(PROJECT)

#	Reworks from zero
#
re: fclean all

#------------------------------------------------#
#   PROJECT COMPILATION                          #
#------------------------------------------------#

$(PROJECT): $(NAME)
	@if [ -n "$(OBJS)" ]; then \
		$(CXX) $(CPPFLAGS) $(NAME) -o $(PROJECT); \
		if [ -f $(PROJECT) ]; then \
			echo "✅ $(PROJECT) was built"; \
		else \
			echo "⚠️ Failed to build $(PROJECT)"; \
		fi; \
	fi

# ------------------------------------------------ #
#  Setup rule: normalize project structure         #
# ------------------------------------------------ #

setup:
	@mkdir -p $(SRC_DIR) $(INCL_DIR) $(OBJS_DIR) $(DEPS_DIR)
	@find . -maxdepth 1 -name "*.cpp" ! -path "./$(SRC_DIR)*" -exec mv -n {} $(SRC_DIR)/ \;
	@find . -maxdepth 1 -name "*.hpp" ! -path "./$(INCL_DIR)*" -exec mv -n {} $(INCL_DIR)/ \;
	@find . -maxdepth 1 -name "*.o" ! -path "./$(OBJS_DIR)*" -exec mv -n {} $(OBJS_DIR)/ \;
	@find . -maxdepth 1 -name "*.d" ! -path "./$(DEPS_DIR)*" -exec mv -n {} $(DEPS_DIR)/ \;

# ------------------------------------------------ #
#  Help rule: Be user-friendly			           #
# ------------------------------------------------ #
# Make sure this rule is updated with correct data
#
help:
	@echo ""
	@echo "==================== HELP ===================="
	@echo ""
	@echo "📦 Basic build:"
	@echo "  all				-> build $(NAME) and $(PROJECT) (default)"
	@echo ""
	@echo "🧹 Cleaning:"
	@echo "  clean				-> remove .o and .d files (objs and deps)"
	@echo "  fclean			-> clean + remove binaries and .a"
	@echo "  re				-> full rebuild (fclean + all)"
	@echo ""
	@echo "📁 Project setup:"
	@echo "  setup				-> create normalized folder structure"
	@echo ""
	@echo "==============================================="
	@echo ""
