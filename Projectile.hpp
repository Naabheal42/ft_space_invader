/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 13:58:30 by nbrizini          #+#    #+#             */
/*   Updated: 2015/06/21 15:24:12 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTILE_HPP
# define PROJECTILE_HPP

#include "AEntity.hpp"

class	Projectile : public AEntity {

public:
	Projectile(int x, int y);

	Projectile(void);
	Projectile(Projectile const&);
	Projectile &	operator=(Projectile const&);
	~Projectile(void);

	int	 belongs( void );
	void move(int x, int y);
	void takeDamage();
	void reset();
	void setbelongs(int i);

private:
	int		_belongs;
};

#endif
