/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 12:08:32 by bbecker           #+#    #+#             */
/*   Updated: 2015/06/21 16:59:36 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_HPP
# define SCREEN_HPP

# include <iostream>
# include <curses.h>

class	Screen {

public:
	Screen(void);
	Screen(Screen const&);
	~Screen(void);
	int				getMaxX( void ) const;
	int				getMaxY( void ) const;
	bool			Inited( void ) const;
	void			ft_refresh( void );
	void			ft_clear( void );
	void			ft_initscr( void );
	void			ft_noecho( void );
	void			ft_endwin( void );
	void			ft_keypad( void );
	void			ft_cbreak( void );
	void			ft_mvprintw(int, int, std::string shape);
	void			ft_mvaddch(int, int, const chtype shape);
	void			resize(void);

private:
	bool			_Inited;
	int				_MaxX;
	int				_MaxY;
	Screen &		operator=(Screen const&);
};

std::ostream&		operator<<(std::ostream& o, const Screen & rhs);

#endif
