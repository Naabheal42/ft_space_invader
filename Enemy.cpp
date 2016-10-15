/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 13:17:09 by nbrizini          #+#    #+#             */
/*   Updated: 2015/06/21 16:00:56 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(void) : AEntity("o", _x, _y, 1){
	this->setShape(this->randomShape());
	return ;
}

Enemy::Enemy(int x, int y) : AEntity("o", x, y, 1) {
	this->setShape(this->randomShape());
	return ;
}

Enemy::Enemy(Enemy const& inst) {
	*this = inst;
	return ;
}

Enemy &	Enemy::operator=(Enemy const& inst) {
	if (this != & inst) {
		this->setShape(inst.getShape());
		this->setX(inst.getX());
		this->setY(inst.getY());
		this->setHp(inst.getHp());
	}
	return (*this);
}

Enemy::~Enemy(void) {
	;
}

std::string		Enemy::randomShape()
{
	int			i;
	std::string shape;

	i = rand() % 6 + 1;

	if (i == 1)
		shape = "o";
	else if (i == 2)
		shape = "8";
	else if (i == 3)
		shape = "O";
	else if (i == 4)
		shape = "+";
	else if (i == 5)
		shape = "@";
	else if (i == 6)
		shape = "<";

	return (shape);
}

void Enemy::move(int x, int y) {
	this->_x = x;
	this->_y = y;
	return ;
}

void Enemy::takeDamage() {
	this->_hp -= 1;
	return ;
}

int Enemy::attack( Projectile *Projectile ) {
	if (this->getShape() == "<")
	{
		int i;
		i = rand() % 20 + 1;

		if (i == 20)
		{
			Projectile->move(this->getX() - 1, this->getY());
			Projectile->setbelongs(-2);
			return (1);
		}
	}
	return (0);
}


void Enemy::reset(int x, int y) {
	this->_hp = 1;
	this->_x = x;
	this->_y = y;
	return ;
}