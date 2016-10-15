/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 15:35:02 by nbrizini          #+#    #+#             */
/*   Updated: 2015/06/20 19:04:35 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AEntity.hpp"

AEntity::AEntity(std::string const & shape, int x, int y, int hp) 
: _shape(shape), _x(x), _y(y), _hp(hp) {
	return ;
}

AEntity::AEntity(void) {
	;
}

AEntity::AEntity(AEntity const& inst) {
	*this = inst;
	return ;
}

AEntity &	AEntity::operator=(AEntity const & inst) {
	if (this != & inst) {
		this->_shape = inst.getShape();
		this->_x = inst.getX();
		this->_y = inst.getY();
		this->_hp = inst.getHp();
	}
	return (*this);
}

AEntity::~AEntity(void) {
	;
}

std::string const & AEntity::getShape(void) const {
	return this->_shape;
}

int AEntity::getX(void) const {
	return this->_x;
}

int AEntity::getY(void) const {
	return this->_y;
}

int AEntity::getHp(void) const {
	return this->_hp;
}

void AEntity::setShape(std::string shape) {
	this->_shape = shape;
	return ;
}

void AEntity::setX(int x) {
	this->_x = x;
	return ;
}

void AEntity::setY(int y) {
	this->_y = y;
	return ;
}

void AEntity::setHp(int hp) {
	this->_hp = hp;
	return ;
}
