
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
int selectRPMs(const struct dirent *ent)
{
   const char *d = ent->d_name;
   return (*d != '.' && endswith(d, ".rpm"));
}

