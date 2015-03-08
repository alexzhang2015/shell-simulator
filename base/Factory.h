/*
 * Shell Simulator
 * 2010.08.18 by alex
 */

/*
 * Copyright (C) 2009 Niek Linnenbank
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef BASE_FACTORY_H_
#define BASE_FACTORY_H_
#pragma once 

/**
 * Abstract Factory design pattern.
 */
template <class T> class Factory
{
    public:

    /**
     * Create an instance of T.
     * @return Pointer to T.
     */
    static T * instance()
    {
	    return new T();
	}
};


#endif /* BASE_FACTORY_H_ */
