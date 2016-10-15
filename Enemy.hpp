/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 13:17:09 by nbrizini          #+#    #+#             */
/*   Updated: 2015/06/21 15:11:08 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

#include "Projectile.hpp"
#include "AEntity.hpp"

class	Enemy : public AEntity {

public:
	Enemy(int x, int y);

	Enemy(void);
	Enemy(Enemy const&);
	Enemy &	operator=(Enemy const&);
	~Enemy(void);

	void move(int x, int y);
	void takeDamage();
	int  attack(Projectile * Projectile);
	void reset(int x, int y);
private:
	std::string		randomShape();
};

#endif
