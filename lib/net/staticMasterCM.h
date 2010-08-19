
/* Copyright (c) 2007-2009, Stefan Eilemann <eile@equalizergraphics.com>
 *                    2010, Cedric Stalder <cedric.stalder@gmail.com> 
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License version 2.1 as published
 * by the Free Software Foundation.
 *  
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef EQNET_STATICMASTERCM_H
#define EQNET_STATICMASTERCM_H

#include <eq/net/objectCM.h> // base class
#include <eq/net/version.h>  // enum
#include <eq/base/idPool.h>  // for EQ_ID_INVALID
#include "objectInstanceDataOStream.h"

#include <deque>

namespace eq
{
namespace net
{
    class Node;

    /** 
     * An object change manager handling a static master instance.
     * @internal
     */
    class StaticMasterCM : public ObjectCM
    {
    public:
        StaticMasterCM( Object* object );
        virtual ~StaticMasterCM();

        virtual void init( const bool ){}

        /**
         * @name Versioning
         */
        //@{
        virtual uint32_t commitNB() { EQDONTCALL; return EQ_ID_INVALID; }
        virtual uint32_t commitSync( const uint32_t )
            { EQDONTCALL; return VERSION_NONE; }

        virtual void obsolete( const uint32_t ) { EQDONTCALL; }

        virtual void setAutoObsolete( const uint32_t ) { EQDONTCALL; }
        
        virtual uint32_t getAutoObsoleteCount() const
            { EQDONTCALL; return 0; }

        virtual uint32_t sync( const uint32_t )
            { EQDONTCALL; return VERSION_NONE; }

        virtual uint32_t getHeadVersion() const { return VERSION_NONE; }
        virtual uint32_t getVersion() const     { return VERSION_NONE; }
        virtual uint32_t getOldestVersion() const { return VERSION_NONE; }
        //@}

        virtual bool isMaster() const { return true; }
        virtual uint32_t getMasterInstanceID() const
            { EQDONTCALL; return EQ_ID_INVALID; }
        virtual uint32_t addSlave( Command& command );
        virtual void removeSlave( NodePtr ) {}

        virtual void applyMapData() { EQDONTCALL; }

    private:
        /** The managed object. */
        Object* _object;
        ObjectInstanceDataOStream _os;
    };
}
}

#endif // EQNET_STATICMASTERCM_H
