/* Copyright (c) 2010, Cedric Stalder <cedric.stalder@gmail.com> 
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

#include "compressorData.h"
#include "eq/base/compressor.h"
#include "eq/base/global.h"
#include "eq/base/pluginRegistry.h"

namespace eq
{
namespace base
{

void CompressorData::reset()
{
    if ( _instance )
    {
        if ( _isCompressor )
           _plugin->deleteCompressor( _instance );
        else
           _plugin->deleteDecompressor( _instance );
    }

    _plugin = 0;
    _name = 0;
    _instance = 0;
}

void CompressorData::setName( uint32_t name )
{
    reset();
    _name = name;
}

base::Compressor* CompressorData::_findPlugin( uint32_t name )
{
    base::PluginRegistry& registry = base::Global::getPluginRegistry();
    return registry.findCompressor( name );
}

bool CompressorData::isValid( uint32_t name )
{
    if ( _name == 0 )
        return false;

    return ( _name == name && _plugin && ( !_isCompressor || _instance ) );
}

bool CompressorData::_initCompressor( uint32_t name )
{
    reset();
    
    if( name <= EQ_COMPRESSOR_NONE )
    {
        _name = name;
        return true;
    }

    _plugin = _findPlugin( name );

    EQASSERT( _plugin );
    if( !_plugin )
        return false;

    _isCompressor = true;
    _instance = _plugin->newCompressor( name );
    EQASSERT( _instance );
    
    _name = name;

    const CompressorInfos& infos = _plugin->getInfos();

    for( base::CompressorInfos::const_iterator j = infos.begin();
         j != infos.end(); ++j )
    {
        const EqCompressorInfo& info = *j;
        
        if ( info.name != name )
            continue;
        
        _info = info;
        return true;
    }
    return false;
}

bool CompressorData::_initDecompressor( uint32_t name )
{
    reset();
    if ( name <= EQ_COMPRESSOR_NONE )
    {
        _name = name;
        return true;
    }

    _plugin = _findPlugin( name );

    EQASSERT( _plugin );
    if( !_plugin )
        return false;

    _isCompressor = false;
    _instance = _plugin->newDecompressor( name );
    
    _name = name;
    return true; 
}

}
}
