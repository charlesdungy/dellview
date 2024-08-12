#include "dellview.h"

int main(void)
{
  Dellview dv{"../exp/config.txt"};
  dv.run();
  return 0;
}
