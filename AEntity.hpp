/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 12:39:19 by nbrizini          #+#    #+#             */
/*   Updated: 2015/06/20 19:04:44 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AENTITY_HPP
# define AENTITY_HPP

# include <iostream>

class AEntity {

protected:
	std::string _shape;
	int _x;
	int _y;
	int _hp;

public:
	AEntity(std::string const & shape, int x, int y, int hp);

	AEntity(void);
	AEntity(AEntity const&);
	AEntity &	operator=(AEntity const&);
	virtual ~AEntity(void);

	void setShape(std::string shape);
	void setX(int x);
	void setY(int y);
	void setHp(int hp);

	std::string const & getShape() const;
	int getX(void) const;
	int getY(void) const;
	int getHp(void) const;

	virtual void move(int x, int y) = 0;
	virtual void takeDamage() = 0;
};

#endif
