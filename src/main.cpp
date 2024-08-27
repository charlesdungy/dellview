#include "dellview.h"

int main(void)
{
  srand(time(NULL));
  Dellview dv{"../exp/config.txt"};
  dv.run();
  return 0;
}
