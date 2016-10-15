/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ship.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbecker <bbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 13:16:18 by nbrizini          #+#    #+#             */
/*   Updated: 2015/06/21 11:58:27 by bbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHIP_HPP
# define SHIP_HPP

// # include "includes.hpp"
#include "AEntity.hpp"
#include "Projectile.hpp"

class	Ship : public AEntity {

public:
	Ship(void);
	Ship(int x, int y);
	Ship(Ship const&);
	Ship &	operator=(Ship const&);
	~Ship(void);
	unsigned long long int getScore( void ) const;
	void setScore(unsigned long long int i);
	void move(int x, int y);
	void takeDamage();
	Projectile * attack(void);

private:
	unsigned long int		_Score;
};

#endif
