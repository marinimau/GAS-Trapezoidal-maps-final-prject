#include "fill_color.h"

namespace FillColor {

   cg3::Color getRandomColor()
   {
       int color[3];
       int first = rand() % 3;
       int second = 0, third = 0;
       int avanti = rand() % 2;

       /* I have used 160 + random to obtain random color */
       color[first] = 160 + rand() % 96;

       if(avanti % 2 == 0){
           second = (first + 1) % 3;
           third = (first - 1) % 3;
       }
       else {
           second = (first -1) % 3;
           third = (first + 1) % 3;
       }

       /* third uses different random generation to obtain sufficient contrast */
       color[second] = 160 + rand() % 96;
       color[third] = 50 + rand() % 96;

       cg3::Color fillColor = cg3::Color(color[0], color[1], color[2]);

       return fillColor;

   }

}
