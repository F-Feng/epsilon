// vim: set expandtab shiftwidth=4 tabstop=4:

/*
 *  include/Eigenvalues.h
 *
 *  Copyright (C) 2016 Mario Prausa
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __EIGENVALUES_H
#define __EIGENVALUES_H

#include <map>
#include <FermatArray.h>
#include <Fraction.h>

typedef struct _eigen {
    Fraction u;
    Fraction v;

    bool operator<(const struct _eigen &other) const {
        return (u < other.u) || (u == other.u && v < other.v);
    }
} eigen_t;

typedef std::map<eigen_t,int> eigenvalues_t;

extern int EVdenom;
eigenvalues_t findEigenvalues(const FermatArray &array, int max);

#endif //__EIGENVALUES_H


