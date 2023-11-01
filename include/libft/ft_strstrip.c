#include "libft.h"

static int	ft_countalpha(const char *string)
{
	int		alphacount;
	int		count;

	alphacount = 0;
	count = 0;
	if (string == NULL)
		return (0);
	while (string[count] != '\0')
	{
		if (ft_isalpha(string[count]) != 0)
			alphacount++;
		count++;
	}
	return (alphacount);
}

char	*ft_strstrip(const char *string)
{
	int		i;
	char	*cleanedstring;
	int		alphacount;

	i = 0;
	cleanedstring = NULL;
	if (string == NULL)
		return (NULL);
	alphacount = ft_countalpha(string);
	cleanedstring = malloc(sizeof(char) * (alphacount + 1));
	if (!cleanedstring)
		return (NULL);
	alphacount = 0;
	while (string[i] != '\0')
	{
		if (ft_isalpha(string[i]) != 0)
		{
			cleanedstring[alphacount] = string[i];
			++alphacount;
		}
		++i;
	}
	cleanedstring[alphacount] = '\0';
	return (cleanedstring);
}
