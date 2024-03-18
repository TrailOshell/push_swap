# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 23:06:09 by tsomchan          #+#    #+#              #
#    Updated: 2024/02/27 23:27:52by tsomchan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
INC_PTH	=	inc/
INC		=	$(addprefix $(INC_PTH), push_swap.h)

SRC_PTH	=	src/
#SRC		=	$(addprefix $(SRC_PTH), push_swap.c)
SRC		=	push_swap.c stack.c node.c util.c error.c sorting.c \
			check.c find_value.c sort_3.c sort_5.c\
			do_swap.c do_push.c do_rotate.c do_reverse.c \
			debug.c log.c

OBJ_PTH	=	obj/
#OBJ		=	$(SRC:%.c=$(OBJ_PTH)%.o)
OBJ		=	$(SRC:%.c=$(OBJ_PTH)%.o)

AR		=	ar rc
CC		=	cc
#CFLAGS	=	-Wall -Wextra -Werror
CFLAGS	=	-g
RM		=	rm -f
RM_RF	= 	rm -rf

NC			=	\033[0;0m
BLACK		=	\033[0;30m
D_RED		=	\033[0;31m
D_GREEN		=	\033[0;32m
D_YELLOW	=	\033[0;33m
D_BLUE		=	\033[0;34m
D_PURPLE	=	\033[0;35m
D_CYAN		=	\033[0;36m
L_GRAY		=	\033[0;37m
D_GRAY		=	\033[1;30m
L_RED		=	\033[1;31m
L_GREEN		=	\033[1;32m
L_YELLOW	=	\033[1;33m
L_BLUE		=	\033[1;34m
L_PURPLE	=	\033[1;35m
L_CYAN		=	\033[1;36m
WHITE		=	\033[1;37m

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@
	@echo "$(D_GREEN)$(NAME) compiled$(NC)"

$(OBJ_PTH)%.o: $(SRC_PTH)%.c $(INC)| $(OBJ_PTH)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@
	@echo "$(D_YELLOW)compiled $<$(NC)"

$(OBJ_PTH):
	mkdir -p $(OBJ_PTH)
	@echo "$(D_YELLOW)compiled $@$(NC)"

clean:
	$(RM) $(OBJ)
	$(RM_RF) $(OBJ_PTH)
	@echo "$(D_GRAY)removed object files$(NC)"

fclean: clean
	$(RM) $(NAME)
	@echo "$(D_GRAY)removed $(NAME)$(NC)"

re: fclean all

.PHONY: clean fclean re all

#	my additional rules

clear:
	@clear

norm: clear
	@norminette $(addprefix $(SRC_PTH), $(SRC))

TRASH = .DS_Store

clean_more:
	$(RM_RF) $(TRASH)

#	git

log: clear
	@git log --name-status -3

push:
	@git push
	@git push intra
	@clear && git log --name-status -1

git_add:
	@git add .
ifdef m
	@git commit -m "$(m)"
endif

git: clean_more git_add push

.PHONY += clear norm clean_more log push git_add git

# testing

# for minimalist, on 100 numbers there should be... < 700 operations
# for maximalist, 500 numbers have... <= 5500 operations

input_basic	=	5 3 2 42 0 -1
input_20	=	13 3 19 17 16 14 2 10 9 15 8 5 11 7 20 18 1 12 4 6
input_50	=	41 7 14 2 34 28 33 44 46 15 42 49 22 39 27 8 36 13 10 23 26 6 1 45 17 38 43 31 25 4 5 11 18 30 47 16 35 19 24 20 50 9 12 3 29 40 48 37 32 21
input_100	=	97 48 63 52 96 26 75 86 59 10 20 53 46 58 9 42 27 76 60 43 38 14 23 51 18 84 2 22 49 72 34 35 40 100 44 39 47 68 88 85 73 11 1 66 98 16 21 94 95 62 89 7 83 17 82 19 31 30 79 74 54 37 24 56 25 41 3 61 92 93 50 8 91 64 90 32 15 6 4 12 67 55 5 71 57 77 36 13 70 33 81 78 29 69 80 45 99 65 28 87
input_500	=	334 355 186 473 336 151 275 324 171 298 229 489 67 402 424 35 205 416 202 249 365 383 400 245 100 230 190 44 404 240 191 51 11 451 407 366 266 248 285 21 353 395 234 169 364 379 293 103 317 286 195 30 162 441 403 420 83 469 165 329 89 444 486 2 37 170 207 475 279 64 172 95 394 327 12 375 434 478 349 201 495 71 124 185 328 213 140 237 66 316 108 357 174 164 265 63 79 135 136 350 56 464 92 381 390 10 241 62 348 221 278 4 323 115 440 425 437 167 480 182 123 345 68 99 399 257 472 231 175 236 255 280 397 454 181 189 368 256 55 126 356 18 129 291 417 301 465 93 411 268 179 70 359 330 408 370 339 388 58 142 243 233 38 246 204 242 307 222 414 287 105 449 128 210 59 184 16 398 77 96 499 322 20 69 152 430 36 488 352 358 361 147 335 138 178 198 183 387 347 247 14 109 433 31 369 154 42 45 3 274 41 333 377 74 378 224 363 283 32 467 1 112 187 61 163 60 468 7 199 137 87 474 303 25 17 150 314 214 118 496 235 197 340 392 209 173 284 281 39 220 319 484 312 447 415 421 294 9 288 127 196 453 200 144 456 436 409 374 481 148 463 410 426 277 121 193 65 40 458 111 346 466 448 168 94 134 27 471 24 382 53 476 282 491 302 498 459 8 492 119 26 188 262 477 310 413 462 107 244 297 269 203 351 29 423 325 52 435 50 271 362 28 72 304 332 157 371 227 405 385 6 122 104 212 180 412 120 253 308 406 497 419 460 373 88 292 493 54 218 141 401 47 372 311 494 49 43 296 267 145 155 215 149 90 393 290 326 34 106 384 273 57 75 260 159 153 500 117 427 470 225 130 342 276 13 177 226 238 232 446 160 338 161 485 289 33 156 81 487 295 482 431 318 251 98 192 125 19 166 439 309 143 422 380 85 452 331 443 432 131 73 176 389 113 252 270 354 376 116 211 429 299 91 228 321 78 264 263 219 15 386 343 391 360 300 258 22 250 132 483 450 80 254 261 110 86 208 341 479 272 367 84 344 320 396 438 217 455 315 461 337 102 139 305 82 206 133 313 158 114 239 306 223 23 5 418 490 194 46 97 76 442 259 216 146 48 428 457 445 101

t: test

test: all
	clear
	./$(NAME) $(input_basic)
#	./$(NAME) $(input_100)

20: all
	clear
	./$(NAME) $(input_20)

50: all
	clear
	./$(NAME) $(input_50)

100: all
	clear
	./$(NAME) $(input_100)

500: all
	clear
	./$(NAME) $(input_500)

v: val

val: all
	clear
	valgrind ./$(NAME) $(input_basic)
#	valgrind ./$(NAME) $(input_100)

#L	:= $(shell ./$(NAME) $(input_500))
#L	:= $(shell ./$(NAME) $(input_500) | wc -l)
#L	= $(shell  | wc -l)

l: all
	clear
	./$(NAME) $(input_100) | wc -l

L: all
	clear
	./$(NAME) $(input_500) | wc -l
	
.PHONY += t test