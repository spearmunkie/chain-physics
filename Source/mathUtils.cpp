#include "mathUtils.h"
namespace math
{
    int randInt(int min,int max)
   {
      return  (rand()%(int)(max-min+1)+min);
   }
   
   float randFloat(float min,float max)
   {
      if (min==max)
         return min;
      return ( (float)(randInt( (int)min, (int)max)) +
         ((float)rand() / ((float)RAND_MAX + 1)));
   }
   
   double getAngle(double x1,double y1,double x2,double y2)
   {
    double opp = y2 - y1;
    double adj = x2 - x1;
    if (adj == 0)
        if (y2 > y1)
            return 270;
        else
            return 90;
    else if (opp >= 0 && adj > 0)
        return 360 - atan  (opp / adj)*DEG_TO_RAD;
    else if (adj < 0)
        return 180-atan  (opp / adj)*DEG_TO_RAD;
    else if (opp < 0 && adj > 0)
        return 360-atan  (opp / adj)*DEG_TO_RAD;
    return 0;
}

float distance(float x1,float y1,float x2,float y2)
   {
    return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}

float distance(vec3f v1,vec3f v2) {
		return distance(v1[0],v1[1], v2[0],v2[1]);
	}
	
	double getAngle(vec3f v1,vec3f v2){
		return getAngle(v1[0],v1[1], v2[0],v2[1]);
	}

}

std::ostream &operator<<(std::ostream &output, const math::vec3f &v)
{ 
	std::cout << "(" << v[0] << ", " << v[1] << ", " << v[2] << ")";
	return output;
}
