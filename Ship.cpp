/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ship.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 13:16:18 by nbrizini          #+#    #+#             */
/*   Updated: 2015/06/21 14:26:08 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ship.hpp"

Ship::Ship(void) : AEntity("<))__)", 10, _y, 3) {
	this->setScore(0);
	return ;
}

Ship::Ship(int x, int y) : AEntity("<))__)", x, y, 3) {
	this->setScore(0);
	return ;
}

Ship::Ship(Ship const& inst) {
	this->setScore(inst.getScore());
	*this = inst;
	return ;
}

Ship &	Ship::operator=(Ship const& inst) {
	if (this != & inst) {
		this->setShape(inst.getShape());
		this->setX(inst.getX());
		this->setY(inst.getY());
		this->setHp(inst.getHp());
	}
	return (*this);
}

Ship::~Ship(void) {
	;
}

void Ship::move(int x, int y) {
	this->_x = x;
	this->_y = y;
	return ;
}

void Ship::takeDamage() {
	this->_hp -= 1;
	return ;
}

Projectile * Ship::attack() {
	Projectile * bullet = new Projectile(this->_x + 1, this->_y + 1);
	return bullet;
}

unsigned long long int			Ship::getScore( void ) const
{
	return (this->_Score);
}

void		Ship::setScore(unsigned long long int i)
{
	this->_Score = i;
}
