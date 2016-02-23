/**
 *   SFCGAL
 *
 *   Copyright (C) 2012-2013 Oslandia <infos@oslandia.com>
 *   Copyright (C) 2012-2013 IGN (http://www.ign.fr)
 *
 *   This library is free software; you can redistribute it and/or
 *   modify it under the terms of the GNU Library General Public
 *   License as published by the Free Software Foundation; either
 *   version 2 of the License, or (at your option) any later version.
 *
 *   This library is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *   Library General Public License for more details.

 *   You should have received a copy of the GNU Library General Public
 *   License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _SFCGAL_DETAIL_COORDINATETOPOINT3VISITOR_H_
#define _SFCGAL_DETAIL_COORDINATETOPOINT3VISITOR_H_

namespace SFCGAL {
    class Coordinate ;
namespace detail {

    template < typename K >
    class CoordinateToPoint3Visitor : public boost::static_visitor<typename K::Point_3> {
    public:
        typedef typename K::Point_3 result_type ;

        result_type operator()( const Empty& ) const {
            return result_type( CGAL::ORIGIN );
        }

        result_type operator()( const Epick::Point_2& storage ) const {
            CGAL::Cartesian_converter<Epick,K> converter ;
            return converter(
                Epick::Point_3( storage.x(), storage.y(), 0.0 )
            );
        }
        result_type operator()( const Epick::Point_3& storage ) const {
            CGAL::Cartesian_converter<Epick,K> converter ;
            return converter(storage) ;
        }

        result_type operator()( const Epeck::Point_2& storage ) const {
            CGAL::Cartesian_converter<Epeck,K> converter ;
            return converter(
                Epeck::Point_3( storage.x(), storage.y(), 0.0 )
            );
        }
        result_type operator()( const Epeck::Point_3& storage ) const {
            CGAL::Cartesian_converter<Epeck,K> converter ;
            return converter(storage) ;
        }
    };

}//detail
}//SFCGAL

#endif
