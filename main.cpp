/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 10:39:47 by bbecker           #+#    #+#             */
/*   Updated: 2015/06/21 16:51:45 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <curses.h>
# include <iostream>

# include "AEntity.hpp"
# include "Projectile.hpp"
# include "Enemy.hpp"
# include "Ship.hpp"
# include "Screen.hpp"
# include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */

# define KEY_ESC 27
# define KEY_SPACE 32
# define ENEMIES 100
# define MAX_PROJECTILES 5000
# define COEF 1.002

#include <unistd.h>


void	ft_reset_enemy(Screen* screen, Enemy *Enemy)
{
	Enemy->move(screen->getMaxX() + rand() % (screen->getMaxX()), 2 + rand() % (screen->getMaxY() - 4));
}

void	ft_score(Screen* screen, Ship* Playership)
{
	screen->ft_mvprintw(screen->getMaxY() - 1, 2, "HP : " + std::to_string(Playership->getHp()));
	screen->ft_mvprintw(screen->getMaxY() - 1, 10, "Score : " + std::to_string(Playership->getScore()));
}

void	ft_exit(Screen* screen)
{
	screen->ft_clear();
	screen->ft_mvprintw(screen->getMaxY() / 2, screen->getMaxX() / 2 - 10, "THANK YOU COME AGAIN");
	screen->ft_refresh();
	usleep(2000000);
}

int	do_turn(int x, int y, Screen* screen, Ship* Playership, Enemy* Enemies, Projectile* Projectiles, int *cnt_proj)
{
	int i = 0;
	if (Playership->getX() + x > 9 && Playership->getY() + y > 1
		&& Playership->getX() + x < screen->getMaxX() - 1 && Playership->getY() + y < screen->getMaxY() - 2)
	{
		Playership->move(Playership->getX() + x, Playership->getY() + y);
	}
	i = 0;
	while(i < MAX_PROJECTILES)
	{
		int j = 0;
		if (Projectiles[i].getX() != -2)
		{
			if (Projectiles[i].belongs() == -2 && (Projectiles[i].getX() == Playership->getX() || Projectiles[i].getX() == Playership->getX() + 1) && Projectiles[i].getY() == Playership->getY())
			{
				Projectiles[i].reset();
				Playership->takeDamage();
				if (Playership->getHp() <= 0) {
					return 0;
				}
			}
			while (j < ENEMIES)
			{
				if (Projectiles[i].getX() == Enemies[j].getX() && Projectiles[i].getY() == Enemies[j].getY())
				{
					ft_reset_enemy(screen, &Enemies[j]);
					Projectiles[i].reset();
					if (Projectiles[i].belongs() == 1)
						Playership->setScore(Playership->getScore() * COEF + 100);
				}
				j++;
			}
			if (Projectiles[i].getX() != -2)
			{
				Projectiles[i].move(Projectiles[i].getX() + Projectiles[i].belongs() , Projectiles[i].getY());
			}
		}
		i++;
	}
	i = 0;
	while(i < ENEMIES)
	{
		if (Playership->getX() == Enemies[i].getX() && Playership->getY() == Enemies[i].getY())
		{
			Playership->takeDamage();
			if (Playership->getHp() <= 0) {
				return 0;
			}
			ft_reset_enemy(screen, &Enemies[i]);
		}
		else
		{
			int j = 0;
			while (j < MAX_PROJECTILES)
			{
				if (Enemies[i].getX() == Projectiles[j].getX() && Enemies[i].getY() == Projectiles[j].getY())
				{
					ft_reset_enemy(screen, &Enemies[i]);
					Projectiles[j].reset();
					if (Projectiles[j].belongs() == 1)
						Playership->setScore(Playership->getScore() * COEF + 100);
				}
				j++;
			}
			Enemies[i].move(Enemies[i].getX() - 1, Enemies[i].getY());
			if (Enemies[i].getX() < 0)
				ft_reset_enemy(screen, &Enemies[i]);
			if (*cnt_proj >= MAX_PROJECTILES)
					*cnt_proj = 0;
			if (Enemies[i].attack(&Projectiles[*cnt_proj]) == 1)
			{
				*cnt_proj = *cnt_proj + 1;
			}
		}
		i++;
	}
	screen->ft_clear();
	i = 0;
	screen->ft_mvprintw(Playership->getY() - 1, Playership->getX() - 4,   "(\\_");
	screen->ft_mvprintw(Playership->getY(), Playership->getX() - 6, Playership->getShape().c_str());
	screen->ft_mvprintw(Playership->getY() + 1, Playership->getX() - 4, "(/");
	while(i < ENEMIES)
	{
		if (Enemies[i].getX() < screen->getMaxX())
		{
			screen->ft_mvprintw(Enemies[i].getY(), Enemies[i].getX(), Enemies[i].getShape().c_str());
		}
		i++;
	}
	i = 0;
	while(i < MAX_PROJECTILES)
	{
		if (Projectiles[i].getX() < screen->getMaxX() && Projectiles[i].getX() > 0)
		{
			screen->ft_mvprintw(Projectiles[i].getY(), Projectiles[i].getX(), Projectiles[i].getShape().c_str());
		}
		i++;
	}
	return 1;
}

void	init_map(Enemy* Enemies, Projectile* Projectiles,Screen* screen)
{
	int i = 0;

	while (i < ENEMIES)
	{
		Enemies[i].setX(screen->getMaxX() + rand() % (screen->getMaxX()));
		Enemies[i].setY(2 + rand() % (screen->getMaxY() - 4));
		i++;
	}
	i = 0;
	while (i < MAX_PROJECTILES)
	{
		Projectiles[i].setX(-2);
		Projectiles[i].setY(-2);
		i++;
	}
}

int	main(void)
{
	int i;
	int cnt_proj = 0;
	int flg = 0;
	Screen *screen = new Screen;
	srand(time(0));
	screen->ft_initscr();
	screen->ft_noecho();
	timeout(25);
	screen->ft_keypad();
	screen->ft_cbreak();
	curs_set(FALSE);
	Ship*  Playership =  new Ship(10, screen->getMaxY() / 2);
	Enemy*	Enemies = new Enemy[ENEMIES];
	Projectile*	Projectiles = new Projectile[MAX_PROJECTILES];
	init_map(Enemies, Projectiles, screen);
	while (42)
	{
		i = getch();
		if (i == ERR)
		{
			flg = do_turn(0, 0, screen, Playership, Enemies, Projectiles, &cnt_proj);
		}
		else
		{
			if (i == KEY_ESC || flg == 0)
			{
				ft_exit(screen);
				break ;
			}
			else if (i == KEY_RESIZE)
			{
				screen->ft_endwin();
				screen->ft_initscr();
				screen->resize();
				Playership->move(10, screen->getMaxY() / 2);
			}
			else if (i == KEY_DOWN)
				flg = do_turn(0, 1, screen, Playership, Enemies, Projectiles, &cnt_proj);
			else if (i == KEY_UP)
				flg = do_turn(0, -1, screen, Playership, Enemies, Projectiles, &cnt_proj);
			else if (i == KEY_RIGHT)
				flg = do_turn(1, 0, screen, Playership, Enemies, Projectiles, &cnt_proj);
			else if (i == KEY_LEFT)
				flg = do_turn(-1, 0, screen, Playership, Enemies, Projectiles, &cnt_proj);
			else if (i == KEY_SPACE)
			{
				if (cnt_proj >= MAX_PROJECTILES)
					cnt_proj = 0;
				Projectiles[cnt_proj].move(Playership->getX() + 1, Playership->getY());
				Projectiles[cnt_proj].setbelongs(1);
				cnt_proj++;
				flg = do_turn(0, 0, screen, Playership, Enemies, Projectiles, &cnt_proj);
			}
		}
		if (flg == 0) {
			ft_exit(screen);
			break ;
		}
		wborder(stdscr, '|', '|', '-', '-', '+', '+', '+', '+');
		ft_score(screen, Playership);
		screen->ft_refresh();
		usleep(50000);
	}
	delete[] Enemies;
	delete[] Projectiles;
	delete Playership;
	delete screen;
	return(0);
}
