#include "minishell.h"

static int	ft_len(const char *s)
{
	int t;

	t = 0;
	while (*s)
	{
		t++;
		s++;
	}
	return (t);
}

char		*ft_strchr(const char *s, int c)
{
	int				size;
	unsigned char	a;

	size = ft_len(s);
	a = (unsigned char)c;
	s = s + size;
	while (size >= 0)
	{
		if (*s == a)
			return ((char *)s);
		s--;
		size--;
	}
	return (NULL);
}

int	ft_nbtoken(char *s)
{
	int	nbtoken;
	int quote;

	nbtoken = 0;
	quote = 0;
	while (*s)
	{
		while (*s && (*s == ' ' || *s == 11))
			s++;
		if (ft_strchr("'\"", *s))
		{
			nbtoken++;
			quote = (int)*s;
			s++;
			while (*s != (char)quote && *s)
			{
				s++;
			}
			if (*s)
			{
				quote = 0;
				s++;
			}
		}
		if (*s && *s == '|')
		{
			nbtoken++;
			s++;
		}
		if (ft_strchr("<>", *s) && *s)
		{
			nbtoken++;
			quote = (int)*s;
			s++;
			if ((int)*s == quote)
				s++;
			quote = 0;
		}
		if (*s && !ft_strchr("\"'| <>", *s))
		{
			nbtoken++;
			while (!ft_strchr("\"'| <>", *s))
				s++;
		}
		while (*s == ' ' && *s)
			s++;
	}
	if (quote != 0)
		return (-1);
	return (nbtoken);
}

char	*ft_fillsplit(char *mot, char *str, int len)
{
	int	i;

	i = 0;
	if (ft_strchr("'\"", *str))
		str++;
	while (*str && len)
	{
		mot[i] = *str;
		i++;
		len--;
		str++;
	}
	mot[i] = 0;
	return (mot);
}

int	ft_lenmot(char *s)
{
	int	n;
	int token;
	int i;

	n = 0;
	i = 0;
	token = 0;
	if (ft_strchr("><", s[i]))
	{
		token = (int)s[i];
		if (s[i+1] && s[i+1] == (char)token)
			return(2);
		else
			return(1);
	}
	if (ft_strchr("'\"", s[i]))
	{
		token = (int)s[i];
		i++;
		while (s[i] && s[i] != (char)token)
		{
			n++;
			i++;
		}
		return (n);
	}
	if (s[i] == '|')
		return(1);
	while (s[i] && !ft_strchr("'\">< |", s[i]))
	{
		n++;
		i++;
	}
	return (n);
}

char	**ft_free(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

char	**ft_split(char const *s)
{
	char	*str;
	char	**split;
	int		mot;
	int		len;
	int		k;

	str = (char *)s;
	if (!str)
		return (NULL);
	mot = ft_nbtoken(str);
	if (mot < 0)
		return (NULL);
	k = 0;
	split = (char **)malloc(sizeof(char *) * (mot + 1));
	if (!split)
		return (NULL);
	while (*str && k < mot)
	{
		while ((*str == ' ' || *str == 11) && *str)
			str++;
		len = ft_lenmot(str);
		split[k] = (char *)malloc(sizeof(char) * (len + 1));
		if (!split[k])
			return (ft_free(split));
		split[k] = ft_fillsplit(split[k], str, len);
		if (ft_strchr("'\"", *str))
			len = len + 2;
		str = str + len;
		k++;
	}
	split[k] = NULL;
	return (split);
}
