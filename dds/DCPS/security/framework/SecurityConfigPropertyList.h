/*
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

#ifndef OPENDDS_DCPS_SECURITY_CFG_PROPERTY_LIST_H
#define OPENDDS_DCPS_SECURITY_CFG_PROPERTY_LIST_H

#include "dds/DCPS/PoolAllocator.h"

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace OpenDDS {
namespace Security {


typedef std::pair<OPENDDS_STRING, OPENDDS_STRING> ConfigProperty;
typedef OPENDDS_VECTOR(ConfigProperty) ConfigPropertyList;


} // namespace Security
} // namespace OpenDDS

OPENDDS_END_VERSIONED_NAMESPACE_DECL

#endif
