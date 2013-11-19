#ifndef VEC3F_H
#define VEC3F_H

#include <vector>
#include <cmath>
#include <iostream>
#include <cstdlib>

namespace math
{
	static const double DEG_TO_RAD=57.29578;
	
	float randFloat(float min,float max);

	int randInt(int min,int max);
	
	float distance(float x1,float y1,float x2,float y2);
	
	double getAngle(double x1,double y1,double x2,double y2);
	
	template <class TYPE>
	class vec: public std::vector<TYPE>
	{
		public:
			TYPE dotProduct(vec<TYPE> other)
			{
				TYPE ans=(*this)[0]*other[0];
				for(unsigned int i=1;i<other.size();i++)
					ans+=(*this)[i]*other[i];
				return ans;
			}
			TYPE magnitude()
			{
				TYPE ans=(*this)[0]*(*this)[0];
				for(unsigned int i=1;i<this->size();i++)
					ans+=(*this)[i]*(*this)[i];
				return sqrt (ans);
			}
			void normalize()
			{
				TYPE mag=magnitude();
				if (mag==0) return;
				for(unsigned int i=0;i<this->size();i++)
					(*this)[i]=(*this)[i]/mag;
			}
	};
	
	class vec3f : public vec<float>
	{
		public:
			vec3f() {resize(3);}
			vec3f(float x, float y, float z)
			{
				resize(3);
				(*this)[0]=x;
				(*this)[1]=y;
				(*this)[2]=z;
			}
			vec3f cross(const vec3f &other) const
			{
				return vec3f(	(*this)[1] * other[2] - (*this)[2] * other[1],
							(*this)[2] * other[0] - (*this)[0] * other[2],
							(*this)[0] * other[1] - (*this)[1] * other[0]);
			}
			
			vec3f operator*(float scale) const 
			{ return vec3f((*this)[0] * scale, (*this)[1] * scale, (*this)[2] * scale);}
			
			vec3f operator+(const vec3f &other) const
			{return vec3f((*this)[0] + other[0], (*this)[1] + other[1], (*this)[2] + other[2]);}
			
			vec3f operator-(const vec3f &other) const 
			{return vec3f((*this)[0] - other[0], (*this)[1] - other[1], (*this)[2] - other[2]);}

			vec3f operator-() const 
			{return vec3f(-(*this)[0], -(*this)[1], -(*this)[2]);}
			
			const vec3f operator*=(float scale) 
			{
				(*this)[0] *= scale;
				(*this)[1] *= scale;
				(*this)[2] *= scale;
				return *this;
			}
			const vec3f operator+=(const vec3f &other) 
			{
				(*this)[0] += other[0];
				(*this)[1] += other[1];
				(*this)[2] += other[2];
				return *this;
			}
			const vec3f operator-=(const vec3f &other) 
			{
				(*this)[0] -= other[0];
				(*this)[1] -= other[1];
				(*this)[2] -= other[2];
				return *this;
			}

	};
	
	float distance(vec3f v1,vec3f v2) ;
	
	double getAngle(vec3f v1,vec3f v2);
}
std::ostream &operator<<(std::ostream &output, const math::vec3f &v);

#endif
