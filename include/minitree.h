/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:59:13 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/23 19:22:48 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITREE_H
# define MINITREE_H

# include "libft.h"
# include "miniexecuter.h"

typedef struct s_minitree	t_minitree;

struct s_minitree
{
	void		*content;
	t_minitree	*leftchild;
	t_minitree	*rightchild;
};

t_minitree	*ft_create_treenode(void *content);
void		ft_destroytree(t_minitree **root);

t_minitree	*ft_insertleft(t_minitree *root, void *content);
t_minitree	*ft_insertright(t_minitree *root, void *content);
void		ft_treeinsert(t_minitree **root,
				void *leftcontent, void *rootcontent, void *rightcontent);

void		ft_postorder_traversal(t_minitree *root, void (*function)(void *));
void		ft_preorder_traversal(t_minitree *root, void (*function)(void *));
void		ft_inorder_traversal(t_minitree *root, void (*function)(void *));

t_minitree	*ft_get_lasttreenode(t_minitree *root, t_bool direction);

void		ft_printtree(t_minitree *root);

#endif