#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "semodia_controlengine::controlengine_packed_static" for configuration "Release"
set_property(TARGET semodia_controlengine::controlengine_packed_static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(semodia_controlengine::controlengine_packed_static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libcontrolengine_packed_static.a"
  )

list(APPEND _cmake_import_check_targets semodia_controlengine::controlengine_packed_static )
list(APPEND _cmake_import_check_files_for_semodia_controlengine::controlengine_packed_static "${_IMPORT_PREFIX}/lib/libcontrolengine_packed_static.a" )

# Import target "semodia_controlengine::open62541_v1.3.11_static" for configuration "Release"
set_property(TARGET semodia_controlengine::open62541_v1.3.11_static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(semodia_controlengine::open62541_v1.3.11_static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libopen62541_v1.3.11_static.a"
  )

list(APPEND _cmake_import_check_targets semodia_controlengine::open62541_v1.3.11_static )
list(APPEND _cmake_import_check_files_for_semodia_controlengine::open62541_v1.3.11_static "${_IMPORT_PREFIX}/lib/libopen62541_v1.3.11_static.a" )

# Import target "semodia_controlengine::mbedcrypto_static" for configuration "Release"
set_property(TARGET semodia_controlengine::mbedcrypto_static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(semodia_controlengine::mbedcrypto_static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libmbedcrypto_static.a"
  )

list(APPEND _cmake_import_check_targets semodia_controlengine::mbedcrypto_static )
list(APPEND _cmake_import_check_files_for_semodia_controlengine::mbedcrypto_static "${_IMPORT_PREFIX}/lib/libmbedcrypto_static.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
