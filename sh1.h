/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 18:31:41 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/10/30 12:46:24 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH1_H
# define SH1_H

# include "libft/libft.h"
# include <stdlib.h>
# include <sys/wait.h>
# include <signal.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/utsname.h>
# include <fcntl.h>

typedef struct		s_list
{
	char			*titre;
	char			*content;
	char			*old_content;
	int				is_active;
	struct s_list	*next;
}					t_list;

typedef struct		s_options
{
	int				options_i;
	int				nb_arg_real;
	int				nb_flag;
	int				nb_equal;
	int				nb_command;
	int				error;
}					t_options;

typedef struct		s_cd_options
{
	int				options_p;
	int				options_l;
	int				nb_arg_real;
	int				nb_flag;
}					t_cd_options;

t_options			*init_option(void);
t_cd_options		*init_cd_option(void);
t_list				*new_list_item(void);
t_list				*get_env(char **env);
t_list				*new_list_item_fill(const char *titre, const char *content,
						const char *old_content, int is_active);
t_list				*copy_list(t_list *source);
t_list				*ft_make_list(char *tab);
void				handler(unsigned long int sig);
void				remove_last(t_list **list);
void				add_to_list(t_list **list, t_list *to_add);
void				free_list(t_list *list);
void				del_to_list(t_list **list, const char *titre);
void				free_item2(t_list **list);
void				free_item(t_list *list);
void				init_env(char **env);
void				update_content_list(t_list **list, const char *titre,
						const char *content);
void				update_old_content_list(t_list **list,
						const char *titre, const char *content);
void				change_active_state(t_list **list,
						const char *titre, int value);
void				ft_error_parse_env(char c);
void				parsing(const char *gnl, t_list **list_env);
void				print_prompt(t_list *list);
void				free_options(t_options **options);
void				set_balise(t_list **list);
void				add_balise(t_list **list);
void				ft_remove_guillemet(char **str);
void				resolve_env_2(t_list **list, t_options *options,
						char **cmd);
char				get_type(char *path);
char				*find_content_list(t_list *list, const char *titre);
char				*find_old_content_list(t_list *list, const char *titre);
char				*found_path(char *cmd, char **path);
char				*ft_replace_orig(const char *gnl, t_list **list_env);
char				*get_pwd(void);
char				**ft_split_with_quote(const char *s, char c);
char				**make_env(t_list *list);
char				**parse_env(char **argv, t_options *options, int argc);
char				**ft_parse_cd(char **argv, t_cd_options *options);
char				***ft_clean_param(const char *source);
char				**ft_split_blank(const char *source);
char				**del_one_argv(char **argv, int i);
char				**get_valid_path(t_list *list_env);
int					ft_error(const char *str1, const char *str2,
						const char *str3);
int					is_binary(char **cmd, t_list **list_env);
int					is_path(char *cmd);
int					ft_exit_value(char **cmd);
int					check_flag_all(char c, t_options *options);
int					ft_bonus_tab(char **cmd);
int					ft_update_pwd(t_list **list_env, char *new_path, int flag);
int					print_to_list(t_list *list);
int					ft_setenv(char **cmd, t_list **list_env);
int					ft_unsetenv(char **cmd, t_list **list_env);
int					check_title(t_list *list, const char *title);
int					ft_env(char **cmd, t_list *list_env);
int					ft_star_wars(char **cmd, t_list **list_env);
int					ft_cd(char **cmd, t_list **list_env);
int					is_active(t_list *list, const char *titre);
int					permission_ok(char *cmd);
int					ft_cd(char **cmd, t_list **list_env);
int					if_titre_exist(t_list *list, const char *titre);
int					ft_len_list(t_list *list);
int					lunch_cmd(char **cmd, char **path, t_list **list_env);

#endif
