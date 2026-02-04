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

.PHONY: all bonus clean fclean re setup help

# 📚 Basic project variables
#
PROJECT		= megaphone
P_BONUS		= $(PROJECT)_bonus

NAME		= $(PROJECT).a
N_BONUS		= $(P_BONUS).a

# 🔧 Compiler and flags
#
CXX				= c++
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
# If there is bonus
#
BONUS_DIR		= bonus/
B_SRC_DIR		= bonus/src/
B_INCL_DIR		= bonus/include/
B_OBJS_DIR		= bonus/objs/
B_DEPS_DIR		= bonus/deps/

# 🎯 Sources, Objects and Deps	! Remember to update the list every project
#
SRCS = megaphone.cpp
OBJS = $(SRCS:%.cpp=$(OBJS_DIR)%.o)
DEPS = $(OBJS:$(OBJS_DIR)%.o=$(DEPS_DIR)%.d)
# And if there is bonus...
#
B_SRCS	= $(SRCS)
B_OBJS  = $(B_SRCS:%.cpp=$(B_OBJS_DIR)%.o)
B_DEPS  = $(B_OBJS:$(B_OBJS_DIR)%.o=$(B_DEPS_DIR)%.d)

-include $(DEPS)
-include $(B_DEPS)

#------------------------------------------------#
#   BASIC RULES										               #
#------------------------------------------------#

#	Basic options
#
all: setup $(NAME) $(PROJECT)

bonus: setup $(N_BONUS) $(P_BONUS)

#	Headers compilers
#
$(NAME): $(OBJS)
	@if [ -n "$(OBJS)" ]; then \
		$(AR) $(NAME) $(OBJS); \
		echo "📦 Library $(NAME) created"; \
	fi

$(N_BONUS): $(B_OBJS)
	@if [ -n "$(B_OBJS)" ]; then \
		$(AR) $(N_BONUS) $(B_OBJS); \
		echo "📦 Bonus library $(N_BONUS) created"; \
	fi

#	Objects & bonus objects Compilers
#
$(OBJS_DIR)%.o: $(SRC_DIR)%.cpp
	@echo "🔨 Compiling $<..."
	$(CXX) $(CPPFLAGS) -MMD -MP $(HEADERS) -MF $(DEPS_DIR)$*.d -c $< -o $@

$(B_OBJS_DIR)%.o: $(B_SRC_DIR)%.cpp
	@echo "🔨 Compiling bonus $<..."
	$(CXX) $(CPPFLAGS) -MMD -MP $(HEADERS) -MF $(B_DEPS_DIR)$*.d -c $< -o $@

#	Cleaners
#
clean:
	@$(RM) $(OBJS_DIR) $(B_OBJS_DIR) $(DEPS_DIR) $(B_DEPS_DIR)

fclean: clean
	@$(RM) $(NAME) $(N_BONUS) $(PROJECT) $(P_BONUS)

#	Reworks from zero
#
re: fclean all

re_bonus: fclean bonus

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

$(P_BONUS): $(N_BONUS)
	@if [ -n "$(B_OBJS)" ]; then \
		$(CXX) $(CPPFLAGS) $(N_BONUS) -o $(P_BONUS); \
		if [ -f $(P_BONUS) ]; then \
			echo "✅ $(P_BONUS) was built"; \
		else \
			echo "⚠️ Failed to build $(P_BONUS)"; \
		fi; \
	fi

# ------------------------------------------------ #
#  Setup rule: normalize project structure         #
# ------------------------------------------------ #

setup:
	@mkdir -p $(SRC_DIR) $(INCL_DIR) $(OBJS_DIR) $(DEPS_DIR)
	@if [ -d $(BONUS_DIR) ]; then \
		mkdir -p $(B_SRC_DIR) $(B_INCL_DIR) $(B_OBJS_DIR) $(B_DEPS_DIR); \
		find . -maxdepth 1 -name "*_bonus.cpp" ! -path "./$(B_SRC_DIR)*" -exec mv -n {} $(B_SRC_DIR)/ \;; \
		find . -maxdepth 1 -name "*_bonus.hpp" ! -path "./$(B_INCL_DIR)*" -exec mv -n {} $(B_INCL_DIR)/ \;; \
		find . -maxdepth 1 -name "*_bonus.o" ! -path "./$(B_OBJS_DIR)*" -exec mv -n {} $(B_OBJS_DIR)/ \;; \
		find . -maxdepth 1 -name "*_bonus.d" ! -path "./$(B_DEPS_DIR)*" -exec mv -n {} $(B_DEPS_DIR)/ \;; \
	fi
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
	@echo "  bonus				-> build $(N_BONUS) and $(P_BONUS)"
	@echo ""
	@echo "🧹 Cleaning:"
	@echo "  clean				-> remove .o and .d files (objs and deps)"
	@echo "  fclean			-> clean + remove binaries and .a"
	@echo "  re				-> full rebuild (fclean + all)"
	@echo "  re_bonus			-> full rebuild (fclean + bonus)"
	@echo ""
	@echo "📁 Project setup:"
	@echo "  setup				-> create normalized folder structure"
	@echo ""
	@echo "==============================================="
	@echo ""
