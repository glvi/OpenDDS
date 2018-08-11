/*
 * Distributed under the OpenDDS License.
 * See: http://www.OpenDDS.org/license.html
 */

#ifndef OPENDDS_SECURITY_SSL_PRIVATEKEY_H
#define OPENDDS_SECURITY_SSL_PRIVATEKEY_H

#include "dds/DCPS/security/DdsSecurity_Export.h"
#include "dds/DCPS/unique_ptr.h"
#include "dds/DdsDcpsCoreC.h"
#include <string>
#include <vector>
#include <openssl/evp.h>

namespace OpenDDS {
namespace Security {
namespace SSL {

  class DdsSecurity_Export PrivateKey
  {
   public:
    typedef DCPS::unique_ptr<PrivateKey> unique_ptr;

    friend DdsSecurity_Export bool operator==(const PrivateKey& lhs,
                                              const PrivateKey& rhs);

    PrivateKey(const std::string& uri, const std::string password = "");

    PrivateKey();

    PrivateKey(const PrivateKey& other);

    virtual ~PrivateKey();

    PrivateKey& operator=(const PrivateKey& rhs);

    void load(const std::string& uri, const std::string& password = "");

    int sign(const std::vector<const DDS::OctetSeq*>& src,
             DDS::OctetSeq& dst) const;

   private:
    static EVP_PKEY* EVP_PKEY_from_pem(const std::string& path,
                                       const std::string& password = "");

    static EVP_PKEY* EVP_PKEY_from_pem_data(const std::string& data,
                                            const std::string& password);

    EVP_PKEY* k_;
  };

  DdsSecurity_Export bool operator==(const PrivateKey& lhs,
                                     const PrivateKey& rhs);

}  // namespace SSL
}  // namespace Security
}  // namespace OpenDDS

#endif
