
# Copyright (c) 2010 Cedric Stalder <cedric.stalder@gmail.ch>
#               2011-2012 Stefan Eilemann <eile@eyescale.ch>

set(CO_PUBLIC_HEADERS
  api.h
  array.h
  barrier.h
  bufferConnection.h
  co.h
  command.h
  commandFunc.h
  commandQueue.h
  commands.h
  compressor.h
  compressorInfo.h
  connection.h
  connection.ipp
  connectionDescription.h
  connectionSet.h
  connectionType.h
  cpuCompressor.h
  dataIStream.h
  dataOStream.h
  dataOStreamArchive.h
  dataOStreamArchive.ipp
  dataStreamArchiveException.h
  defines.h
  dispatcher.h
  exception.h
  global.h
  init.h
  instanceCache.h
  localNode.h
  log.h
  node.h
  nodeICommand.h
  nodeOCommand.h
  nodeType.h
  object.h
  objectFactory.h
  objectHandler.h
  objectICommand.h
  objectOCommand.h
  objectMap.h
  objectVersion.h
  packets.h
  plugin.h
  pluginRegistry.h
  queueCommand.h
  queueMaster.h
  queuePackets.h
  queueSlave.h
  serializable.h
  types.h
  worker.h
  worker.ipp
  zeroconf.h
  dataIStreamArchive.h
  dataIStreamArchive.ipp
  )

set(CO_HEADERS
  barrierCommand.h
  commandCache.h
  connectionListener.h
  dataIStreamQueue.h
  deltaMasterCM.h
  eventConnection.h
  fullMasterCM.h
  nodeCommand.h
  nodePackets.h
  nullCM.h
  objectCM.h
  objectDataIStream.h
  objectDataOStream.h
  objectDeltaDataOStream.h
  objectInstanceDataOStream.h
  objectPackets.h
  objectSlaveDataOStream.h
  pipeConnection.h
  rspConnection.h
  socketConnection.h
  staticMasterCM.h
  staticSlaveCM.h
  unbufferedMasterCM.h
  versionedMasterCM.h
  versionedSlaveCM.h
  )

set(CO_SOURCES
  barrier.cpp
  bufferConnection.cpp
  command.cpp
  commandCache.cpp
  commandQueue.cpp
  compressor.cpp
  connection.cpp
  connectionDescription.cpp
  connectionSet.cpp
  cpuCompressor.cpp
  dataIStream.cpp
  dataIStreamQueue.cpp
  dataOStream.cpp
  deltaMasterCM.cpp
  dispatcher.cpp
  eventConnection.cpp
  fullMasterCM.cpp
  global.cpp
  init.cpp
  instanceCache.cpp
  localNode.cpp
  node.cpp
  nodeICommand.cpp
  nodeOCommand.cpp
  object.cpp
  objectCM.cpp
  objectDataIStream.cpp
  objectDataOStream.cpp
  objectDeltaDataOStream.cpp
  objectICommand.cpp
  objectOCommand.cpp
  objectInstanceDataOStream.cpp
  objectMap.cpp
  objectSlaveDataOStream.cpp
  objectStore.cpp
  objectVersion.cpp
  packets.cpp
  pipeConnection.cpp
  plugin.cpp
  pluginRegistry.cpp
  queueMaster.cpp
  queueSlave.cpp
  serializable.cpp
  socketConnection.cpp
  staticSlaveCM.cpp
  unbufferedMasterCM.cpp
  version.cpp
  versionedMasterCM.cpp
  versionedSlaveCM.cpp
  worker.cpp
  zeroconf.cpp
  )

set(CO_COMPRESSORS
  compressor/compressor.cpp
  compressor/compressor.h
  compressor/compressorFastLZ.cpp
  compressor/compressorFastLZ.h
  compressor/compressorLZF.cpp
  compressor/compressorLZF.h
  compressor/compressorRLE.ipp
  compressor/compressorRLE10A2.cpp
  compressor/compressorRLE10A2.h
  compressor/compressorRLE4B.cpp
  compressor/compressorRLE4B.h
  compressor/compressorRLE4BU.cpp
  compressor/compressorRLE4BU.h
  compressor/compressorRLE4HF.cpp
  compressor/compressorRLE4HF.h
  compressor/compressorRLE565.cpp
  compressor/compressorRLE565.h
  compressor/compressorRLEB.cpp
  compressor/compressorRLEB.h
  compressor/compressorRLEYUV.cpp
  compressor/compressorRLEYUV.h
  compressor/compressorSnappy.cpp
  compressor/compressorSnappy.h
  compressor/fastlz/fastlz.c
  compressor/fastlz/fastlz.h
  compressor/liblzf/lzf.h
  compressor/liblzf/lzf_c.c
  compressor/liblzf/lzf_d.c
  compressor/snappy/snappy.h
  compressor/snappy/snappy.cc
  compressor/snappy/snappy-sinksource.cc
  )

set(PLUGIN_HEADERS
  plugins/compressor.h
  plugins/compressorTokens.h
  plugins/compressorTypes.h
  )

if(WIN32)
  list(APPEND CO_HEADERS namedPipeConnection.h)
  list(APPEND CO_SOURCES namedPipeConnection.cpp)
else()
  list(APPEND CO_HEADERS fdConnection.h)
  list(APPEND CO_SOURCES fdConnection.cpp)
endif()
