#if defined(__APPLE__)
#include <Availability.h>
#endif

static inline
bool endswith(const char *str, const char *suffix)
{
   size_t len1 = strlen(str);
   size_t len2 = strlen(suffix);
   if (len1 < len2)
      return false;
   str += (len1 - len2);
   if (strcmp(str, suffix))
      return false;
   return true;
}

static
#if defined(__FREEBSD__) || ( defined(__APPLE__) && defined(__MAC_OS_X_VERSION_MIN_REQUIRED) &&  __MAC_OS_X_VERSION_MIN_REQUIRED <= 1070)
int selectRPMs(struct dirent *ent)
#else
int selectRPMs(const struct dirent *ent)
#endif
{
   const char *d = ent->d_name;
   return (*d != '.' && endswith(d, ".rpm"));
}

