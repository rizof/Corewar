

/*
** Donc on a un parser qui prend argv[1] ou whatever en parametre,
** C'est a dire le path du fichier .s a compiler
*/

int			parser(char *file_name)
{
	int		fd;
	char	input[CHAMP_MAX_SIZE + 1];
	t_tok	token;

	// Pas besoin de malloc puisqu'on a une taille max de champion deja definie
	// Suffit de faire un read de cette taille et de verifier que le champion
	// entre entier dans le buffer
	if ((fd = open(file_name, O_RDONLY)) < 0 || !read(fd, input, CHAMP_MAX_SIZE)
		|| input[CHAMP_MAX_SIZE - 1] != 0)
		return (0);
	input[CHAMP_MAX_SIZE] = 0;
	while (lexer(input, &token))
	{
		// Faire quelque chose avec ces tokens
	}
}

/*
** Si on veut faire un truc vraiment efficace, le scanner va fonctionner
** avec une table de transition, c'est a dire un tableau en 2 dimensions
** qui indique pour chaque combinaison d'etat et de caractere dans quel nouvel
** etat on va etre.
** (voir Finite State Machine ou Finite State Automaton)
*/

int			scanner(char c, t_tok *token)
{
	static int		state;

	state = transition_table[c, state];
}

/*
** Le lexer lit l'input, ou plutot emvoi chaque caractere de l'input au scanner
** Puis, une fois que le scanner signale la fin d'un lexeme,
** rempli les membres du token.
*/

int			lexer(char *input, t_tok *token)
{
	static int	i = 0;
	static int	line = 0;
	static int	col = 0;

	token->line = line;
	token->col = col;
	while (input[i] && scanner(input[i], token))
	{
		++i;
	}
}