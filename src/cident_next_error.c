

extern int	g_cident_error;

void	cident_next_error(void)
{
	if (g_cident_error > 0)
		g_cident_error -= 1;
	return;
}
