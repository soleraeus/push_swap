#include "push_swap.h"

t_moves	*cpy_move(t_moves *src)
{
	t_moves	*cpy;

	cpy = (t_moves *)malloc(sizeof(t_moves));
	cpy->target = src->target;
	cpy->block_end = src->block_end;
	cpy->dist = src->dist;
	cpy->size_block = src->size_block;
	cpy->nb = src->nb;
	cpy->nb_instructions = src->nb_instructions;
	cpy->ra = src->ra;
	cpy->rb = src->rb;
	cpy->rr = src->rr;
	cpy->rra = src->rra;
	cpy->rrb = src->rrb;
	cpy->rrr = src->rrr;
	cpy->sa = src->sa;
	cpy->sb = src->sb;
	cpy->ss = src->ss;
	cpy->pa = src->pa;
	cpy->pb = src->pb;
	return (cpy);
}
