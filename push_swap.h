#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>

typedef enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	OP_COUNT
}	t_op;

typedef struct s_list
{
	int				value;
	size_t			index;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	const char	*strategy;
	double		disorder;

	t_list		*a;
	t_list		*b;

	size_t		operations[OP_COUNT];
	size_t		total_ops;

	bool		bench;
}	t_stack;

#endif
