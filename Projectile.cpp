/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 13:57:58 by nbrizini          #+#    #+#             */
/*   Updated: 2015/06/21 15:37:49 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Projectile.hpp"

Projectile::Projectile(void) : AEntity("-", _x, _y, 1) {
	this->setbelongs(0);
	return ;
}

Projectile::Projectile(int x, int y) : AEntity("-", x, y, 1) {
	this->setbelongs(0);

}

Projectile::Projectile(Projectile const& inst) {
	*this = inst;
	return ;
}

Projectile &	Projectile::operator=(Projectile const& inst) {
	if (this != & inst) {
		this->setShape(inst.getShape());
		this->setX(inst.getX());
		this->setY(inst.getY());
		this->setHp(inst.getHp());
	}
	return (*this);
}

Projectile::~Projectile(void) {
	;
}

void Projectile::move(int x, int y) {
	this->_x = x;
	this->_y = y;
	return ;
}

void Projectile::takeDamage() {
	this->_hp -= 1;
	return ;
}

void Projectile::setbelongs(int i)
{
	this->_belongs = i;
}

int	 Projectile::belongs( void )
{
	return (this->_belongs);
}

void Projectile::reset() {
	this->setY(-2);
	this->setX(-2);
}