

extern int	g_ciden_error;

void	ciden_int_next_error(void)
{
	if (g_ciden_error > 0)
		g_ciden_error -= 1;
	return;
}
