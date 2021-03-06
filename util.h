#ifndef _UTIL_H
#define _UTIL_H

#include <stdint.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/fcntl.h>

#include <string>

#define MEVENT_LOG_DEBUG_EXIT(...) mevent::util::LogDebug(__FILE__, __LINE__, -1, __VA_ARGS__)
#define MEVENT_LOG_DEBUG(...) mevent::util::LogDebug(__FILE__, __LINE__, 0, __VA_ARGS__)

namespace mevent {
namespace util {
    std::string GetGMTimeStr();
    
    void LogDebug(const char *file, int line, int opt, const char *fmt, ...);
    
    int GetAddrFromCIDR(int cidr, struct in_addr *addr);
    bool IsInSubNet(const struct in_addr *addr, const struct in_addr *netaddr, const struct in_addr *netmask);
    
    void RC4(const std::string &key, const std::string &src, std::string &dest);
    
    void Daemonize(const std::string &working_dir);
    
    int GetSysUid(const char *name);
    int GetSysGid(const char *name);
    
    std::string URLDecode(const std::string &str);
    std::string URLEncode(const std::string &str);
    
    std::string ExecutablePath();
}//namespace util
}//namespace mevent

#endif
