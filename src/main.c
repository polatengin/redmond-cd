#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  if (argc == 1)
  {
    const char *home = getenv("HOME");
    if (home == NULL)
    {
      fprintf(stderr, "Could not find HOME environment variable.\n");
      return 1;
    }

    if (chdir(home) != 0)
    {
      perror("chdir");
      return 1;
    }
  }
  else if (argc > 2)
  {
    fprintf(stderr, "Usage: %s [directory]\n", argv[0]);
    return 1;
  }
  else
  {
    const char *dir = argv[1];

    if (strcmp(dir, "-") == 0)
    {
      const char *oldpwd = getenv("OLDPWD");
      if (oldpwd == NULL)
      {
        fprintf(stderr, "No previous directory found.\n");
        return 1;
      }

      if (chdir(oldpwd) != 0)
      {
        perror("chdir");
        return 1;
      }

      printf("%s\n", oldpwd);
    }
    else
    {
      if (chdir(dir) != 0)
      {
        perror("chdir");
        return 1;
      }
    }
  }

  return 0;
}
