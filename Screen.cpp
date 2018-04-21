/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbecker <bbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 12:08:32 by bbecker           #+#    #+#             */
/*   Updated: 2015/06/21 10:39:11 by bbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//Yu

#include "Screen.hpp"

Screen::Screen(void)
{
	this->_Inited = false;
	this->_MaxX = 0;
	this->_MaxY = 0;
}

Screen::Screen(Screen const& inst)
{
	this->_Inited = inst.Inited();
	this->_MaxX = inst.getMaxX();
	this->_MaxY = inst.getMaxY();
}

Screen::~Screen(void)
{
	if (this->Inited() == true)
		this->ft_endwin();
}

void			Screen::resize(void)
{
	getmaxyx(stdscr,this->_MaxY,this->_MaxX);
}

int				Screen::getMaxX( void ) const
{
	return (this->_MaxX);
}

int				Screen::getMaxY( void ) const
{
	return (this->_MaxY);
}

bool			Screen::Inited( void ) const
{
	return (this->_Inited);
}

void			Screen::ft_refresh( void )
{
	if (this->Inited() == true)
		wrefresh(stdscr);
	else
		std::cerr << "Screen is not init." << std::endl;
}

void			Screen::ft_clear( void )
{
	if (this->Inited() == true)
	{
		clear();
	}
}

void			Screen::ft_cbreak( void )
{
	if (this->Inited() == true)
		cbreak();
	else
		std::cerr << "Screen is not init." << std::endl;
}

void			Screen::ft_keypad( void )
{
	if (this->Inited() == true)
	{
		keypad(stdscr, TRUE);
	}
}

void			Screen::ft_initscr( void )
{

	if (this->Inited() == false)
	{
		initscr();
		this->_Inited = true;
		getmaxyx(stdscr,this->_MaxY,this->_MaxX);
	}
}

void			Screen::ft_noecho( void )
{
	if (this->Inited() == true)
		noecho();
}

void			Screen::ft_endwin( void )
{
	if (this->Inited() == true)
	{
		endwin();
		this->_Inited = false;
	}
	else
		std::cerr << "Screen is not init." << std::endl;
}

void			Screen::ft_mvprintw(int x, int y, std::string shape)
{
	if (this->Inited() == true)
		mvprintw(x, y, shape.c_str());
	else
		std::cerr << "Screen is not init." << std::endl;
}

void			Screen::ft_mvaddch(int x, int y, const chtype shape)
{
	if (this->Inited() == true)
		mvaddch(x, y, shape);
	else
		std::cerr << "Screen is not init." << std::endl;
}

Screen &	Screen::operator=(Screen const& inst)
{
	this->_Inited = inst.Inited();
	this->_MaxX = inst.getMaxX();
	this->_MaxY = inst.getMaxY();
	return (*this);
}

std::ostream&	operator<<(std::ostream& o, const Screen & rhs)
{
	o << "Inited : " << rhs.Inited() << ", Max X " << rhs.getMaxX();
	o << ", Max Y " << rhs.getMaxY() << ".";
	return (o);
}
